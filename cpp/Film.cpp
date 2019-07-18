//
// Film.cpp for create a multimedia film
// Rayanne Souza - 10/2015
//

#include "Film.h"


Film::Film(const string name, const string pathName, const int duration ):Video(name,pathName, duration)
{
    this->duration = NULL;
    this->qChapter = 0;
}




Film :: Film( const string name, const string pathName, const int duration, ptr_int p_duration, const int qChapter):Video(name, pathName, duration)
{
    this->duration = p_duration;
    this->qChapter = qChapter;
}




Film::Film():Video()
{
    this->qChapter = 5;
    this->duration.reset(new int (this->getChapter()));


    for (int i=0; i < qChapter; i++)
    {
        this->duration.get()[i] = 2;
    }


}




Film :: Film(const Film& film)
{
    this->set_duration(film.get_duration());
    this->set_name(film.get_name());
    this->set_pathName(film.get_pathName());
    this->setChapterDuration(film.getDuration(),film.getChapter());

}




Film::~Film()
{
    cout<<"Object Film is destroyed"<<endl<<endl;
}




Film& Film :: operator=(const Film& film)
{
    Video ::operator=(film);

    this->setChapterDuration(film.getDuration(),film.getChapter());


    return *this;
}




ptr_int Film :: getDuration() const
{
    return this->duration;
}




int Film :: getChapter() const
{
    return this->qChapter;
}




void Film :: setChapterDuration( ptr_int duration, const int qChapter)
{
    this->qChapter = qChapter;
    this->duration = duration;
}




void Film :: output(ostream &cout) const
{
    cout<<"FILM"<<endl;
    cout << "-----------" << this->get_name() <<"-----------" << endl;

    Video::output(cout);
    cout<<"Number of chapters: "<<this->qChapter<<endl;

    for(int i = 0; i < qChapter; i++)
    {
        cout << "Chapter " << i <<": "<<" ";
        cout << this->duration.get()[i]<< endl;
    }

}


