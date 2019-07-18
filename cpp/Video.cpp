//
// Video.cpp for create a multimedia video
// Rayanne Souza - 10/2015
//

#include "Video.h"
const string PATH = "/usr/bin/vlc";

Video::Video(const string name, const string pathName, int duration):Multimedia(name, pathName)
{
    this->duration = duration;
}



Video::Video()
{
    this->set_name("caneta.mp4");
    this->set_pathName("/cal/homes/rdesouza/Desktop/");
    this->duration = 9;
}



Video ::Video(const Video& video)
{
    this->set_name(video.get_name());
    this->set_pathName(video.get_pathName());
    this->set_duration(video.get_duration());
}



Video::~Video()
{
    cout<<"Object Video is destroyed"<<endl<<endl;
}



Video& Video :: operator=(const Video& video)
{
    this->set_name(video.get_name());
    this->set_pathName(video.get_pathName());
    this->set_duration(video.get_duration());
    return *this;

}



int Video::get_duration()const
{
    return duration;
}



void Video::set_duration(const int duration)
{
    if (duration >0)
    {
        this -> duration = duration;
    }
}



void Video::output(ostream &cout)const
{
    cout<<"VIDEO"<<endl;
    Multimedia::output(cout);
    cout << "Duration: " << this->get_duration()<<endl;
}

void Video::loadMultimedia()
{
    string name;

    if (this->get_name().find(" ") != string :: npos)
    {
        name = "'" + this->get_name() + "'";
    }
    else
    {
        name = this->get_name();
    }


    string file = PATH + " " + this->get_pathName() + name + " &";
    system(file.c_str());
}
