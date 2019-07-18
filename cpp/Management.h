#ifndef MANAGEMENT_H
#define MANAGEMENT_H


/*!
 * \file Management.h
 * \brief Manipulates a group of objects multimedia and an ensemble of objects multimedia
 * \author Rayanne Souza
 * \version 1
 * \date 11/2015
 */


#include<map>
#include"Groupe.h"
#include<string>


using namespace std;

typedef shared_ptr<int> ptr_int;
typedef map<string,shared_ptr< Multimedia > > Map_object;
typedef map<string,shared_ptr<Groupe>> Map_group;


/**
 * @brief The Management class allow to manipulate a group of objects multimedia and an ensemble
 * of objects multimedia with a group map and multimedia map, respectively. It is possible
 * create a new groups and objects multimedia and add this into map. For manipulation the user
 * can delete an object from the multimedia map, search, play and do output operation for an object
 * multimedia, delete a group from the group map and search a group into group multimedia.
 * @see Groupe
 * @see Multimedia
 */
class Management
{
    private:

        /**
         * @brief objects: it is a map of shared pointer of Multimedia.
         */
        Map_object objects;

        /**
         * @brief groups: it is a map of shared pointer of Groupe
         */
        Map_group groups;

    public:


        /**
         * @brief Management: inicializes with a multimedia map and a group map.
         * @param object: is a map of shared pointer of Multimedia.
         * @param group: is a map of shared pointer of Groupe.
         */
        Management(Map_object object, Map_group group);


        /**
         * @brief Management: constructor default. Nothing is initialized.
         */
        Management();


        /**
         * @brief ~Management: destructor called when a Management is destroyed.
         */
        virtual ~Management();


        /**
         * @brief createPhoto: creates a new photo multimedia and add this file in Multimedia map. The key is the photo name.
         * @param Height: photo height.
         * @param Width: photo width.
         * @param name: photo name.
         * @param pathName: photo path name.
         * @return a shared pointer multimedia of object photo created.
         */
        shared_ptr< Multimedia > createPhoto( const double Height, const double Width, const string name, const string pathName );


        /**
         * @brief createFilm: creates a new film multimedia and add this file in Multimedia map. The key is the film name.
         * @param name: film name
         * @param pathName: film path name.
         * @param duration: film duration.
         * @param p_duration: vector with each chapter duration
         * @param qChapter: chapters number of the film.
         * @return a shared pointer multimedia of object film created.
         */
        shared_ptr< Multimedia > createFilm( const string name, const string pathName, const int duration, ptr_int p_duration, const int qChapter);


        /**
         * @brief createVideo: creates a new video multimedia and add this file in Multimedia map. The key is the video name.
         * @param name: video name.
         * @param pathName: video path name.
         * @param duration: video duration.
         * @return a shared pointer multimedia of object video created.
         */
        shared_ptr< Multimedia > createVideo( const string name, const string pathName, const int duration );


        /**
         * @brief createGroup: creates a new group and add this file in Groupe map. The key is the group name.
         * @param name: group name.
         * @return a shared pointer Groupe of object groupe created.
         */
        shared_ptr<Groupe> createGroup( const string name );


        /**
         * @brief deleteObject: firstly, this function search in all groups into Groupe map the object name and remove it.
         * After, remove it from multimedia map.
         * @param object_name: name of multimedia file.
         * @return true if the object was deleted or false if the object is not found
         */
        virtual bool deleteObject(const string object_name);


        /**
         * @brief deleteGroup: this function search into Groupe map the groupe name and remove it.
         * @param object_name: group name used for search.
         */
        virtual void deleteGroup(const string object_name);


        /**
         * @brief playObject: this function search into Multimedia map the multimedia name and play it.
         * @param object_name: multimedia file name.
         * @return true if it's find or false if it's not found.
         */
        virtual bool playObject(const string object_name) const;


        /**
         * @brief searchObject: this function search into Multimedia map the multimedia name and charge the
         * stream buffer with the informations about this file.
         * @param object_name: multimedia file name.
         * @param cout: it is the buffer for output operation.
         * @return 1 if it's find or 0 if it's not found.
         */
        virtual bool searchObject(const string object_name, ostream& cout) const;


        /**
         * @brief searchGroup: this function search into Groupe map the give group name and charge the stream buffer with
         * informations about the group found.
         * @param object_name: group name for search.
         * @param cout: it is the buffer for output operation.
         * @return true if the group name is found or false if the group name is not found.
         */
        virtual bool searchGroup(const string object_name, ostream& cout) const;


        /**
         * @brief output: is an output operation of all multimedia into Multimedia map. It's charge the stream buffer for output operation.
         * @param cout: is the buffer for charge.
         */
        virtual void output(ostream &cout) const;


        /**
         * @brief objectOutPut: it's find a multimedia file from the give name and charge the stream buffer for output operation.
         * @param object_name: name of multimedia file.
         * @param cout: is the buffer for charge.ss
         */
        virtual void objectOutPut(const string object_name, ostream &cout) const;




};

#endif // MANAGEMENT_H
