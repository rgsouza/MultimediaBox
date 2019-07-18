//
// Multimedia.cpp for create a multimedia file
// Rayanne Souza - 10/2015
//


#include "Multimedia.h"


Multimedia::Multimedia()
{
    this->name ="";
    this->pathName ="";
}




Multimedia::Multimedia(const string name, const string pathName)
{
    this->name = name;
    this->pathName = pathName;
}




string Multimedia::get_name()const
{
    return this->name;
}




string Multimedia::get_pathName()const
{
    return this->pathName;
}




void Multimedia::set_name(const string name)
{
    this->name = name;
}




void Multimedia::set_pathName( const string pathName)
{
    this->pathName = pathName;
}




void Multimedia::output(ostream & cout) const
{
    cout << "File name: " << this->get_name() << endl;
    cout << "Path name: " << this->get_pathName() << endl;
}



void Multimedia::loadMultimedia()
{

}




Multimedia::~Multimedia()
{
    cout<<"Object Multimedia is destroyed"<<endl<<endl;
}
