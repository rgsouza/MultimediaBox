#ifndef Groupe_H
#define Groupe_H


/*!
 * \file Groupe.h
 * \brief Creates a group of multimedia files.
 * \author Rayanne Souza
 * \version 1
 * \date 10/2015
 */


#include<list>
#include"Multimedia.h"
#include<memory>

typedef shared_ptr<Multimedia> ptr_multimedia;

using namespace std;



/**
 * @brief The Groupe class creates a multimedia group which can have the objects Film, Video and/or Photo.
 * It gives the group name and does output operation for the group.
 * @see Film
 * @see Video
 * @see Photo
 */
class Groupe : public list<ptr_multimedia>
{
    private:


        /**
         * @brief name: is the Groupe name.
         */
        string name;

    public:


        /**
         * @brief Groupe: inicializes the Groupe of multimedias with a shared pointer multimedia and the Groupe name.
         * @param name: Groupe name.
         * @param object: shared pointer multimedia for a multimedia object.
         */
        Groupe(const string name, ptr_multimedia object);


        /**
         * @brief Groupe: constructor deafult. This constructor call the list constructor.
         */
        Groupe();


        /**
         * @brief ~Groupe: destructor called when a Groupe is destroyed.
         */
        virtual ~Groupe();


        /**
         * @brief get_GroupeName:  this function is responsible for get the Groupe name.
         * @return the Groupe name.
         */
        virtual string get_GroupeName() const;


        /**
         * @brief set_GroupeName: this function set the Groupe name with the give name.
         * @param name: Groupe name for set.
         */
        virtual void set_GroupeName( const string name );


        /**
         * @brief output: this function charge a stream buffer for output and call the method output from multimedia objects .
         * @param cout: is the buffer for output operation.
         */
        virtual void output(ostream &cout) const;
};

#endif // Groupe_H
