#ifndef VIDEO_H
#define VIDEO_H


/*!
 * \file Video.h
 * \brief Creates a  multimedia Video
 * \author Rayanne Souza
 * \version 1
 * \date 11/2015
 */


#include"Multimedia.h"



/**
 * @brief The Video class is derived from Multimedia class.  It creates a object Video, gives the video duration,
 * does output operation and plays a multimedia file type video,
 * @see Film
 * @see Multimedia
 */
class Video : public Multimedia
{
    private:

        /**
         * @brief duration: filme duration.
         */
        int duration;

    public:


        /**
         * @brief Video:  initializes the multimedia video with video name, path name and duration.
         * This constructor call the multimedia constructor.
         * @param name: video name.
         * @param pathName: video path name.
         * @param duration: video duration.
         */
        Video( const string name,const string pathName, int duration);

        /**
         * @brief Video: constructor copy for a video
         */
        Video(const Video&);


        /**
         * @brief Video: constructor default for a video.
         * a video name, path name and duration was determined.
         */
        Video();


        /**
         * @brief ~Video: destructor called when a video object is destroyed.
         */
        virtual ~Video();


        /**
         * @brief operator = overload for object copy
         * @return reference for the video.
         */
        Video& operator=(const Video&);


        /**
         * @brief get_duration: this function is responsible for get video duration.
         * @return video duration.
         */
        virtual int get_duration() const;


        /**
         * @brief set_duration: this function set the video duration with the give duration.
         * @param duration: video duration for set.
         */
        virtual void set_duration(const int duration);


        /**
         * @brief output: this function charge a stream buffer for output and call the method Multimedia output.
         * @param cout: is the buffer for charge.
         */
        virtual void output(ostream &cout)const;


        /**
         * @brief loadMultimedia: this method is responsible for play a file video.
         */
        virtual void loadMultimedia();
};

#endif // VIDEO_H
