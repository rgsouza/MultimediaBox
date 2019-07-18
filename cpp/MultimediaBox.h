#ifndef MULTIMEDIABOX_H
#define MULTIMEDIABOX_H


/*!
 * \file MultimediaBox.h
 * \brief Process a request and send a response to client.
 * \author Eric Lecolinet (TP C++) Telecom Paristech/ Rayanne Souza
 * \version 1
 * \date 11/2015
 */



#include <iostream>
#include <string>
#include "TCPServer.h"
#include"Management.h"


using namespace std;

const int DEFAULT_PORT = 3331;


class MultimediaBox {

private:



    /**
     * @brief multimedia: all multimedia files must be managed through it.
     */
    Management multimedia;

    /**
     * @brief playMultimedia: if playMultimedia is true a multimedia file must be played.
     */
    bool playMultimedia = false;


    /**
     * @brief outPutObject: if outPutObject  is true a  multimedia file must be printed.
     */
    bool outPutObject = false;


    /**
     * @brief search: if search is true a multimedia file must be searched.
     */
    bool search = false;


    /**
     * @brief addPhoto: if addPhoto is true a multimedia photo must be added.
     */
    bool addPhoto = false;


    /**
     * @brief addVideo: if addVideo is true a multimedia video must be added.
     */
    bool addVideo = false;


    /**
     * @brief addFilm: if addFilm is true a multimedia film must be added.
     */
    bool addFilm = false;


public:

  /// Cette fonction est appelée chaque fois qu'il y a une requête à traiter.
  /// - 'request' contient la requête
  /// - 'response' sert à indiquer la réponse qui sera renvoyée au client
  /// - si la fonction renvoie false la connexion est close.
  //
  // Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
  // un thread par client).
  // Si le verrou 'lock' est bloqué en mode WRITE, les autres appels sont bloqués
  // jusqu'à la fin l'appel qui a bloqué le verrou.
  //
  bool processRequest(TCPServer::Cnx& cnx, const string& request, string& response);


};
#endif // MULTIMEDIABOX_H
