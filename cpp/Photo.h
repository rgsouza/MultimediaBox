#ifndef PHOTO_H
#define PHOTO_H

/*!
 * \file Photo.h
 * \brief Creates a  multimedia Photo
 * \author Rayanne Souza
 * \version 1
 * \date 10/2015
 */


#include"Multimedia.h"


/**
 * @brief The Photo class is derived from Multimedia class.  It creates a object Photo, gives the height and width of a photo,
 * does output operation and plays a multimedia file type photo,
 * @see Multimedia
 */
class Photo : public Multimedia
{
private:

    /**
     * @brief height: photo heigth.
     */
    double height;

    /**
     * @brief width: photo width.
     */
    double width;

public:


    /**
     * @brief Photo constructor: inicializes a photo multimedia with the give photo name, path name,
     * height and width. This constructor call the multimedia constructor.
     * @param Height: photo height is 0.0 for default.
     * @param Width: photo width is 0.0 for default.
     * @param name: photo name is empty for default.
     * @param pathName: photo path name is empty for default.
     */
    Photo( double Height=0.0, double Width=0.0, string name = "", string pathName = "" );


    /**
     * @brief Photo: constructor copy for a photo.
     */
    Photo(const Photo&);


    /**
     * @brief ~Photo: destructor called when a photo is destroyed.
     */
    virtual ~Photo();


    /**
     * @brief operator =: overload for object copy.
     * @return reference for the photo.
     */
    Photo& operator=(const Photo &);


    /**
     * @brief get_height: this function is responsible for get photo heigth.
     * @return a photo height
     */
    virtual double get_height() const;


    /**
     * @brief get_width: this function is responsible for get photo width.
     * @return a photo width.
     */
    virtual double get_width() const;


    /**
     * @brief set_height: this function set the photo heigth with the give height.
     * @param height: photo heigth for set.
     */
    virtual void set_height(const double height);


    /**
     * @brief set_height: this function set the photo width with the give width.
     * @param height: photo width for set.
     */
    virtual void set_width(const double width);


    /**
     * @brief output: this function charge a stream buffer for output and call the method Multimedia output.
     * @param cout: is the buffer for charge.
     */
    virtual void output(ostream &cout) const;


    /**
     * @brief loadMultimedia: this method is responsible for play a file photo.
     */
    virtual void loadMultimedia();



};

#endif // PHOTO_H
