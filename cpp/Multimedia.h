#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H


/*!
 * \file Multimedia.h
 * \brief Creates a multimedia with name and path name.It is a abstract class of base.
 * \author Rayanne Souza
 * \version 1
 * \date 10/2015
 */


#include<iostream>
#include<string>
#include<sstream>
#include<fstream>


using namespace std;


/**
 * @brief The Multimedia class is a abstract class of base for classe Film, Video and Photo.
 * The method virtual pure is loadMultimedia().
 * @see Film
 * @see Video
 * @see Photo
 */
class Multimedia
{
private:

    /**
     * @brief name: Multimedia name.
     */
    string name;


    /**
     * @brief pathName: Multimedia path name.
     */
    string pathName;


public:

    /**
     * @brief constructor default: initializes the Multimedia with name and path name empty.
     */
    Multimedia();


    /**
     * @brief constructor: initializes the Multimedia with name and path name received.
     * @param name: Multimedia name.
     * @param pathName: Multimedia path name.
     */
    Multimedia(const string name, const string pathName);


    /**
    * @brief destructor: destructor called when a multimedia is destroyed.
    */
    virtual ~Multimedia();


    /**
     * @brief get_name: this function is responsible for get the multimedia name.
     * @return a multimedia name.
     */
    virtual string get_name()const;


    /**
     * @brief get_pathName: this function is responsible for get the multimedia path name.
     * @return a multimedia path name.
     */
    virtual string get_pathName()const;


    /**
     * @brief set_name: this function set the multimedia name with the give name.
     * @param name: multimedia name for set.
     */
    virtual void set_name( const string name);


    /**
     * @brief set_pathName: this function set the multimedia path name with the give path name.
     * @param pathName multimedia path name for set.
     */
    virtual void set_pathName(const string pathName );


    /**
     * @brief output: this function charge a stream buffer for output
     * @param cout: is the buffer for charge.
     */
    virtual void output(ostream &cout) const;


    /**
     * @brief loadMultimedia:  pure virtual method or abstract method for play a multimedia file.
     */
    virtual void loadMultimedia()=0;

};

#endif // MULTIMEDIA_H
