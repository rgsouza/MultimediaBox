//
// test_multimedia.cpp for check the methods from Multimedia.h, Photo.h
// Video.h, Film.h, Groupe.h et  Management.h.
// Rayanne Souza - 10/2015
//

#include"test_multimedia.h"



void test_tableau()
{
    cout<<"----------------TEST TABLEAU----------------"<<endl;

    Multimedia *multimedia[4];

    stringstream ss;

    multimedia[0] = new Video("tomada.mp4","/cal/homes/rdesouza/Desktop/",45) ;
    multimedia[1] = new Photo(1139,1079,"estudo.jpg","/cal/homes/rdesouza/Desktop/") ;
    multimedia[2] = new Video("tomada.mp4","/cal/homes/rdesouza/Desktop/",45) ;
    multimedia[3] = new Photo(1456,2592,"estudo.jpg","/cal/homes/rdesouza/Desktop/" ) ;


    for(int i = 0; i < 4; i++)
    {

         multimedia[i]->loadMultimedia();
         multimedia[i]->output(ss);

         cout << endl << ss.str() << endl;
    }
}




void test_film()
{
    cout<<"----------------TEST FILM----------------"<<endl;
    stringstream ss;

    // Creates a new film.
    Film *film = new Film();

    // Creates 2 shared pointer for vector of integers
    ptr_int duration (new int[TAM]);
    ptr_int test (new int[TAM - 1]);


    //Fill
    for(int i=0; i< TAM;i++)
    {
        duration.get()[i] = 3;

        if( i < TAM -1)
        {
            test.get()[i] = 2;
        }

    }

    // Films for vector duration
    film->setChapterDuration(duration,6);
    film->set_name("tomada.mp4");
    film->set_pathName("/cal/homes/rdesouza/Desktop/");


    //Output
    film->output(ss);
    cout << endl << ss.str() << endl;
    film->loadMultimedia();

    ss.str("");

    duration.reset();
    // After destroying the vector duration
    film->output(ss);
    cout << endl << ss.str() << endl;
    ss.str("");


    // Modifiant tableau
    cout << "Modifiant un tableau" << endl;

    // Film for vector test
    film->setChapterDuration(test,TAM -1);

    //Output
    film->output(ss);
    cout << endl << ss.str() << endl;
    film->loadMultimedia();

    delete film;
}


void test_group()
{
     cout<<"----------------TEST GROUP----------------"<<endl;

     shared_ptr <Multimedia> def(new Video("tomada.mp4","/cal/homes/rdesouza/Desktop/",45));

     //Creates two groups: one constructor with name and shared pointer multimedia as parameter and two constructor default
     Groupe g1 = Groupe("GROUP", def);
     Groupe g2;

     //Creates multimedia objects
     shared_ptr<Multimedia> a(new Photo(1139,1079,"estudo.jpg","/cal/homes/rdesouza/Desktop/"));
     shared_ptr<Multimedia> b(new Video());
     shared_ptr<Multimedia> c(new Film());

     stringstream ss;

     // g1 and g2 are the same.
     g1.push_back(a);
     g1.push_back(b);
     g1.push_back(c);

     g2.push_back(a);
     g2.push_back(b);
     g2.push_back(c);


     //output
     cout<<endl;
     g1.output(ss);

     g2.output(ss);
     cout << endl << ss.str() << endl;

     stringstream s;

     a = nullptr;
     b = nullptr;
     c = nullptr;

     cout<<"After destroying the object c from group 1 "<<endl;
     g1.pop_back();
     g1.output(s);
     g2.output(s);
     cout << endl << s.str() << endl;


     // After destroying the object c from all groups, the object will destroy and call the destructor.
     s.str("");
     cout<<"After destroying the object c from all groups "<<endl;
     g2.pop_back();
     g1.output(s);
     g2.output(s);

     cout << endl << s.str() << endl;

     //Any destructors must be called.
     cout<<"After destroying the objects from group 2 "<<endl;
     g2.pop_back();
     g2.pop_back();


     s.str("");
     g2.output(s);
     g1.output(s);
     cout << endl << s.str() << endl;


     //The video destructor must be called.
     cout<<"After destroying the object b from group 1 "<<endl;
     s.str("");
     g1.pop_back();
     g1.output(s);
     cout << endl << s.str() << endl;


}




void test_copy_overload()
{
    cout<<"----------------TEST OVERLOAD----------------"<<endl;


    Video video("tomada.mp4","/cal/homes/rdesouza/Desktop/",45) ;
    Video video_copy;

    Film film_copy;
    Film art = Film("tomada.mp4","/cal/homes/rdesouza/Desktop/",45 );

    Photo photo = Photo(1139,1079,"estudo.jpg","/cal/homes/rdesouza/Desktop/");
    Photo planet_photo;

    stringstream ss;

    //Copy of video objects with overloading operator
    video_copy = video;
    video_copy.output(ss);
    cout << endl << ss.str() << endl;
    video.loadMultimedia();

    ptr_int duration(new int[TAM]);
    for (int i ; i<TAM; i++)
    {
        duration.get()[i] = 3;
    }

    ss.str("");
    art.setChapterDuration(duration,TAM);
    art.loadMultimedia();


    // Copy of film object with overloading operator
    film_copy = art;

    film_copy.output(ss);
    cout << endl << ss.str() << endl;
    film_copy.loadMultimedia();

    //Copy of photo object with overloading operator
    ss.str("");
    planet_photo = photo;

    planet_photo.output(ss);
    cout << endl << ss.str() << endl;
    planet_photo.loadMultimedia();

}




void test_copy_constructor()
{

    cout<<"----------------TEST COPY CONSTRUCTOR----------------"<<endl;
    //Copy of objects with Copy constructor

    Video *prt_video =  new Video("tomada.mp4","/cal/homes/rdesouza/Desktop/",45) ;
    Video video;

    //Copy of object that is pointed for  prt_video using video copy constructor
    Video video_copy(*prt_video);

    //Copy of object video using video copy constructor
    Video video_copy_two(video);

    stringstream ss;

    // Output of video copy is the same output that prt_video->output
    video_copy.output(ss);
    cout << endl << ss.str() << endl;
    video_copy.loadMultimedia();

    //Output of video_copy_two is the same output that video.output
    ss.str("");
    video_copy_two.output(ss);
    cout << endl << ss.str() << endl;
    video_copy_two.loadMultimedia();

    ss.str("");



    Film action;

    //Copy of object film using video copy constructor
    Film film_copy(action);

    //Output of film_copy is the same output that action
    film_copy.output(ss);
    cout << endl << ss.str() << endl;
    film_copy.loadMultimedia();

    ss.str("");

    //Copy of object photo using photo copy constructor
    Photo photo = Photo(1139,1079,"estudo.jpg","/cal/homes/rdesouza/Desktop/");
    Photo photo_copy(photo);

    //Output of photo_copy is the same output that photo
    photo_copy.output(ss);
    cout << endl << ss.str() << endl;
    photo_copy.loadMultimedia();

    delete prt_video;
}



void test_management()
{
    //Object test for class Management
    Management test;

    stringstream ss;

    //createPhoto, createVideo and createFilm return a copy of objects created
    shared_ptr< Multimedia > a(test.createPhoto(1139,1079,"estudo.jpg","/cal/homes/rdesouza/Desktop/"));
    test.playObject("estudo.jpg");
    test.searchObject("estudo.jpg",ss);
    cout<<ss.str()<<endl;
    ss.str("");

    shared_ptr<Multimedia> video_action(test.createVideo("tomada.mp4","/cal/homes/rdesouza/Desktop/",45));
    test.playObject("tomada.mp4");
    test.searchObject("tomada.mp4", ss);
    cout<<ss.str()<<endl;



    ptr_int duration(new int[TAM]);
    for (int i ; i<TAM; i++)
    {
        duration.get()[i] = 3;
    }


    //Check the method searchObject
    shared_ptr< Multimedia > film(test.createFilm("caneta.mp4", "/cal/homes/rdesouza/Desktop/", 9,  duration, TAM));
    test.playObject("caneta.mp4");
    test.searchObject("caneta.mp4",ss);
    cout<<ss.str()<<endl;


    //Created two groups
    shared_ptr< Groupe > list_group(test.createGroup("group_one"));
    shared_ptr< Groupe > list_test_group(test.createGroup("group_two"));



    ss.str("");
    cout<<"Group creé"<<endl;
    test.searchGroup("group_one",ss);
    cout<<ss.str()<<endl;

    //Add elements to group one
    list_group->push_back(a);
    list_group->push_back(video_action);
    list_group->push_back(a);


    //Add elements to group two
    list_test_group->push_back(a);
    list_test_group->push_back(a);
    list_test_group->push_back( video_action );

    a = nullptr;
    video_action = nullptr;

    ss.str("");
    // Check the method of searchGroup
    cout<<"Group one mise à jour"<<endl;
    test.searchGroup("group_one",ss);
    test.searchGroup("group_two",ss);
    cout<<ss.str()<<endl;


    //Check the method deleteObject
    //The photo destructor must be called.
    ss.str("");
    cout<<"suppression d'un objet"<<endl;
    test.deleteObject("estudo.jpg");
    test.searchObject("estudo.jpg",ss);
    cout<<ss.str()<<endl;
    ss.str("");


    test.searchGroup("group_one",ss);
    test.searchGroup("group_two",ss);
    cout<<ss.str()<<endl;
    ss.str("");

    list_group = nullptr;
    //Check the method deleteGroup
    cout<<"Check delete goupe"<<endl;
    test.deleteGroup("group_one");
    cout<<"Group one has been deleted"<<endl;
    test.searchGroup("group_one",ss);
    cout<<ss.str()<<endl;
    ss.str("");

    list_test_group->push_back(film);
    test.searchGroup("group_two",ss);
    cout<<ss.str()<<endl;


}
