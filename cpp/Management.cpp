//
// Management.cpp for manipulate a group of objects multimedia and an ensemble of objects multimedia
// Rayanne Souza - 11/2015
//

#include "Management.h"
#include"Photo.h"
#include"Film.h"
#include <algorithm>



Management::Management(Map_object object, Map_group group )
{
    this->objects = object;
    this->groups =  group;

}




Management :: Management()
{

}



Management :: ~Management() {}



shared_ptr< Multimedia > Management::createPhoto( const double Height, const double Width, const string name, const string pathName )
{
    shared_ptr< Multimedia > photo(new Photo(Height, Width,name, pathName));

    this->objects[ name ] = photo;

    photo = nullptr;

    return this->objects[ name ];
}




shared_ptr< Multimedia > Management :: createFilm( string name, string pathName, const int duration, ptr_int p_duration, const int qChapter)
{
    shared_ptr< Multimedia > film ( new Film( name, pathName, duration, p_duration, qChapter ));

    this->objects[ name ] = film;

    film = nullptr;
    return this->objects[ name ];
}





shared_ptr<Multimedia> Management :: createVideo( const string name, const string pathName, const int duration )
{

    shared_ptr<Multimedia> video(new Video( name,pathName, duration ));

    this->objects[ name ] = video ;

    video = nullptr;
    return this->objects[ name ];

}




shared_ptr<Groupe>  Management :: createGroup( const string name  )
{
    shared_ptr< Groupe > group( new Groupe( ) );
    group ->set_GroupeName(name);

    this->groups[ name ] = group;


    group = nullptr;


    return this->groups[ name ];

}




bool Management :: deleteObject( const string object_name)
{
    if(this->objects.find(object_name) != this->objects.end() )
    {
        Map_group::iterator iter;

        for (iter = this->groups.begin(); iter != this->groups.end(); ++iter)
        {
            shared_ptr<Groupe> it = iter->second;
            for (list<ptr_multimedia>::iterator i = it->begin(); i != it->end(); )
             {
                if ( (*i)->get_name() == object_name )
                {
                    list<ptr_multimedia>::iterator k = i;
                    k++;
                    *i = nullptr;
                    it->erase(i);

                    i = k;
                }
                else
                    ++i;
             }
        }
        this->objects.erase(object_name);

        return true;

    }
     else
        cout<<"Object not found"<<endl;

     return false;
}




void Management :: deleteGroup(const string object_name)
{

    if( this->groups.find(object_name) != this->groups.end() )
    {
        this->groups.at(object_name) = nullptr;
        this->groups.erase(object_name);

    }
    else
        cout<<"Group not found"<<endl;

}




bool Management :: searchObject( const string object_name , ostream& cout ) const
{
    if(this->objects.find(object_name) != this->objects.end() )
    {

        this->objects.at(object_name)->output(cout);
        return 1;
    }
     else
    {
        cout<<"Object not found"<<endl;
        return 0;
    }
}




bool Management :: searchGroup(const string object_name, ostream& cout) const
{
    if( this->groups.find(object_name) != this->groups.end() )
    {

        this->groups.at(object_name)->output(cout);

        return true;
    }
    else
    {
        cout<<"Group not found"<<endl;
        return false;
    }
}




bool Management :: playObject(const string object_name) const
{
    if(this->objects.find(object_name) != this->objects.end() )
    {
        this->objects.at(object_name)->loadMultimedia();
        return true;
    }
     else
     {
        cout<<"Object not found"<<endl;
        return false;
     }
}


void Management::output(ostream &cout) const
{
    Map_object::const_iterator iter;
    shared_ptr<Multimedia> it;

    for (iter = this->objects.begin(); iter != this->objects.end(); ++iter)
    {
        it = iter->second;
        cout<<it->get_name()<<endl;
    }

   it = nullptr;

}



void Management :: objectOutPut(const string object_name, ostream &cout) const
{
    if(this->objects.find(object_name) != this->objects.end() )
    {
        this->objects.at(object_name)->output(cout);
    }
     else
    {
        cout<<"Object not found"<<endl;
    }
}
