//
// Photo.cpp for create a multimedia photo
// Rayanne Souza - 10/2015
//


#include "Photo.h"
string const PATH = "/usr/bin/eog";



Photo :: Photo( double height, double width, string name, string pathName):Multimedia(name,pathName)
{
    this->height = height;
    this->width = width;

}




Photo::Photo(const Photo& photo)
{
    this->set_height(photo.get_height());
    this->set_width(photo.get_width());
    this->set_name(photo.get_name());
    this->set_pathName(photo.get_pathName());
}




Photo :: ~Photo()
{
    cout<<"Object Photo is destroyed"<<endl<<endl;
}




Photo& Photo::operator =(const Photo& photo)
{
    this->set_height(photo.get_height());
    this->set_width(photo.get_width());
    this->set_name(photo.get_name());
    this->set_pathName(photo.get_pathName());

    return *this;
}




double Photo :: get_height() const
{
    return height;
}




double Photo :: get_width() const
{
    return width;
}



void Photo :: set_height(const double height)
{
    this->height = height;
}




void Photo :: set_width(const double width)
{
    this->width = width;
}




void Photo :: output(ostream &cout) const
{
    cout<<"PHOTO"<<endl;
    Multimedia :: output(cout);
    cout << "Height: "<< this->get_height() << endl;
    cout <<"Width: "<< this->get_width()<<endl;
}




void Photo :: loadMultimedia()
{
   string file = PATH + " " + this->get_pathName() + this->get_name() + " &";
   system(file.c_str());
}
