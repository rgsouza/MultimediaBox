#ifndef TEST_MULTIMEDIA_H
#define TEST_MULTIMEDIA_H


/*!
 * \file test_multimdeia.h
 * \brief for check the methods from Multimedia.h, Photo.h Video.h, Film.h, Groupe.h et  Management.h.
 * \author Rayanne Souza
 * \version 1
 * \date 10/2015
 */


#include"Video.h"
#include"Photo.h"
#include<sstream>
#include"Film.h"
#include"Management.h"


// Is the size of vector used.
#define TAM 6


/**
 * @brief test_tableau: function responsible for fill a vector of ponter multimedia, play each object multimedia and
 * print informations from multimedia object.
 */
void test_tableau();


/**
 * @brief test_film: function responsible for check a modification of vector of chapters duration.
 */
void test_film();


/**
 * @brief test_group: function responsible for check the destruction of object que ne font plus partie d'un group
 */
void test_group();


/**
 * @brief test_copy_overload: check the overload operator = for video, film and photo.
 */
void test_copy_overload();


/**
 * @brief test_copy_constructor: check the copy constructor for video, film, and photo.
 */
void test_copy_constructor();


/**
 * @brief test_management: check the methods searchObject, searchGroup, deleteObject and deleteGroup from class Management.
 */
void test_management();

#endif // TEST_MULTIMEDIA_H
