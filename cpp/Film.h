#ifndef FILM_H
#define FILM_H

/*!
 * \file Film.h
 * \brief Creates a  multimedia Film
 * \author Rayanne Souza
 * \version 1
 * \date 10/2015
 */

#include"Video.h"
#include<memory>

typedef shared_ptr<int> ptr_int;


/**
 * @brief The Film class is derived from Video class. It creates an object film, gives the film duration and numbers of chapters and
 * does output operation.
 * @see Video
 */
class Film : public Video
{
    private:

        /**
         * @brief duration: vector with the chapter duration. This is also a shared pointer.
         */
        ptr_int duration;


        /**
         * @brief qChapter: number of chapters of the film.
         */
        int qChapter;

    public:


        /**
         * @brief Film: initializes the multimedia filme with film name, path name and duration.
         * This constructor call the video constructor.
         * @param name: film name.
         * @param pathName: film path name.
         * @param duration: film duration
         */
        Film( const string name, const string pathName, const int duration );


        /**
         * @brief Film: initializes the multimedia filme with film name, path name, duration, chapters number and vector with the each chapter duration.
         * @param name: film name.
         * @param pathName: film path name.
         * @param duration: film duration.
         * @param p_duration: vector with each chapter duration.
         * @param qChapter: chapters number of the film.
         */
        Film( const string name, const string pathName, const int duration, ptr_int p_duration, const int qChapter);


        /**
         * @brief Film: constructor copy for a film.
         */
        Film(const Film&);


        /**
         * @brief Film: constructor default for a film.
         * This constructor call the video constructor default and set the chapters number as 5 and the vector with the each chapter duration as 2.
         */
        Film();


        /**
         * @brief ~Film: destructor called when a multimedia film is destroyed.
         */
        virtual ~Film();


        /**
         * @brief operator =: verload for object copy.
         * @return reference for the film.
         */
        Film& operator=(const Film&);


        /**
         * @brief getDuration:  this function is responsible for get the vector of chapter duration. This vector is a shared pointer of integers.
         * @return a shared pointer of integers with the each chapter duration.
         */
        virtual ptr_int getDuration() const;


        /**
         * @brief getChapter: this function is responsible for get the number of chapters from film.
         * @return the number of chapters.
         */
        virtual int getChapter() const;


        /**
         * @brief setChapterDuration: this function set the vector of chapter duration with the give vector duration and set the chapters number.
         * @param duration: this is a vector of chapter duration. This vector is a shared pointer of integers.
         * @param qChapter: chapters numbers from a film.
         */
        virtual void setChapterDuration(ptr_int duration, const int qChapter);


        /**
         * @brief output: this function charge a stream buffer for output and call the method video output.
         * @param cout: is the stream buffer for output operation.
         */
        virtual void output(ostream &cout) const;



};

#endif
