//
// Groupe.cpp for create a group of multimedia files.
// Rayanne Souza - 10/2015
//

#include "Groupe.h"


Groupe::Groupe( const string name, ptr_multimedia object):list()
{
    this->name = name;
    this->push_back(object);
}




Groupe::Groupe():list(){  this->name = "Undefined name"; }




Groupe::~Groupe()
{
    cout<<"Object Groupe is destroyed"<<endl<<endl;
}




string Groupe::get_GroupeName() const
{
    return this->name;
}



void Groupe :: set_GroupeName( const string name )
{
    this->name = name;
}




void Groupe::output(ostream &cout) const
{
    cout<<"-----------------"<<this->get_GroupeName()<<"-----------------"<<endl<<endl;


    // Traverse the list and call the method output from multimedia objects.
    for (list<ptr_multimedia>::const_iterator i = this->begin(); i != this->end(); ++i)
    {
        (*i)->output(cout);
    }

}
