//
// MultimediaBox.cpp for process a request and send a response to client.
// Eric Lecolinet (TP C++) Telecom Paristech
// Rayanne Souza - 11/2015
//


#include "MultimediaBox.h"



bool MultimediaBox :: processRequest(TCPServer::Cnx& cnx, const string& request, string& response)
{


  // mettre cette variable à true si la commande modifie les donnees du programme
  bool changeData = false;
  if (request == "delMedias" || request == "delGroups") changeData = true;

  // suivant le cas on bloque le verrou en mode WRITE ou en mode READ
  TCPServer::Lock lock(cnx, changeData);

  cerr << "request: '" << request << "'" << endl;

  //simule un traitement long (décommenter pour tester le verrou)
  //if (changeData) sleep(10); else sleep(5);


  // pour verifier si la request est delete+filename
  stringstream buffer(request);
  string request_delete;
  getline(buffer,request_delete,'+');

  response = "OK: " + request +"\n";

  cerr << "response: '" << response << "'" << endl;


  //Show the options for play and put playMultimedia as true, if there is a multimedia list.
  if(request == "1")
  {
      stringstream ss;
      multimedia.output(ss);
      response = ss.str();

      if(response.length() == 0)
          response = "The multimedia list is empty. Return to main menu and add a multimedia file \n";
      else
          playMultimedia = true;

  }


  //Returns to main menu
  // The main menu is :
  // 1 to play a multimedia file
  // 2 - Information about a multimedia file
  // 3 - Search a multimedia file
  // 4 - Add a photo
  // 5 - Add a video
  // 6 - Add a film
  // delete + file name for delete a multimedia file from map multimedia
  // show - for show all multimedia file"

  else if (request == "return" )
  {
      response = "OK: Show the menu\n";

      if( playMultimedia ) { playMultimedia = false; }
      else if( outPutObject ) { outPutObject = false; }
      else if ( search ) { search = false; }
      else if( addPhoto ) { addPhoto = false; }
      else if ( addVideo ) { addVideo = false; }
      else if ( addFilm ) { addFilm = false; }
  }



  // Plays the multimedia file required.
  else if( playMultimedia )
  {
      if( multimedia.playObject(request) == false)
           response = request + " is not found\n";
  }


  // Shows the options for output and put outPutObject as true if there is a multimedia list.
  else if( request == "2")
  {
      stringstream ss;
      multimedia.output(ss);
      response = ss.str();

      if(response.length() == 0)
          response = "The multimedia list is empty. Return to main menu and add a multimedia file \n";
      else
          outPutObject = true;

  }



  // Puts search as true.
  else if( request == "3")
  {
      response = "Give the file name\n";
      search = true;
  }



  //Output operation for a multimedia file required.
  else if ( outPutObject )
  {
      stringstream ss;
      multimedia.objectOutPut(request,ss);
      response = ss.str();

  }



  // Searches the multimedia file required and does the output operation if it'is found
  else if( search )
  {

      stringstream ss;
      if ( multimedia.searchObject(request,ss) )
          response = ss.str();

      else
          response = request + " is not found \n";

  }




  // Shows the options for output
  else if ( request == "show" )
  {
      stringstream ss;
      multimedia.output(ss);
      response = ss.str();

      if(response.length() == 0)
          response = "The multimedia list is empty. Add a multimedia file \n";
  }


  // Puts addPhoto as true for add photo operation.
  else if ( request == "4" )
  {
      response = "Give the file name, the path name, height and width: \n";
      addPhoto = true;
  }


  //  Puts addVideo as true for add video operation
  else if( request == "5" )
  {
      response = "Give the video file name, the path name and duration: \n";
      addVideo = true;
  }


  //  Puts addFilm as true for add film operation
  else if( request == "6" )
  {
      response = "Give the film file name, the path name, duration (seconds) and the numbers of chapters: \n";
      addFilm = true;
  }


  // Adds a photo with the given informations
  // The model for give the insformations is name;path name;height;width
  else if (addPhoto)
  {
      string name = "";
      string pathName = "";
      string height = "";
      string width = "";

      stringstream ss(request);
      getline(ss,name,';');
      getline(ss,pathName,';');
      getline(ss, height, ';');
      getline(ss, width);

      if(multimedia.createPhoto(atof(height.c_str()), atof(width.c_str()), name, pathName) != nullptr)
        response = "The photo was added\n";

      else
          response = "Error! The photo was not added \n";


  }


  // Adds a video with the given informations
  // The model for give the insformations is name;path name;duration
  // The duration is in seconds.
  else if ( addVideo )
  {
      string name = "";
      string pathName = "";
      string duration = "";


      stringstream ss(request);
      getline(ss,name,';');
      getline(ss,pathName,';');
      getline(ss, duration);


      if( multimedia.createVideo( name, pathName, atoi(duration.c_str()) ) != nullptr)
            response = "The video was added \n";

      else
          response = "Error! The video was not added \n";
  }



  // Adds a film with the given informations
  // The model for give the insformations is name;path name;duration;number of chapters
  // The duration is in seconds.
  // The vector of chapter duration is completed according to the number of chapters.
  else if ( addFilm )
  {
      string name = "";
      string pathName = "";
      string duration = "";
      string qChapter = "";

      stringstream ss(request);
      getline(ss,name,';');
      getline(ss,pathName,';');
      getline(ss, duration, ';');
      getline(ss, qChapter);

      int chapters =  atoi(qChapter.c_str());
      int duration_second= atoi(duration.c_str());

      ptr_int p_chapterDuration(new int [chapters]);

      if( p_chapterDuration != nullptr )
      {
          for (int i = 0 ; i < chapters ; i++)
          {
              p_chapterDuration .get()[i] = duration_second/chapters;
          }

          if( multimedia.createFilm( name, pathName, atoi(duration.c_str()), p_chapterDuration, chapters) != nullptr)
                response = "The film was added \n";

          else
              response = "Error! The film was not added \n";

      }

      else
          response = "Error! It is not possible add it \n";

  }


  // deletes a multimedia file
  // the model is delete+file name
  else if ( request_delete == "delete")
  {
        string name;
        getline(buffer, name);

       if( multimedia.deleteObject(name) )
           response = "The file " + name + " was deleted \n";
       else
           response = "The file " + name + " is not found \n";

  }



  // If a request is not correct it returns a error message.
  else
  {
      response += " incorrect \n";
  }

  cerr << "response: '" << response << "'" << endl;
  // renvoyer false pour clore la connexion avec le client
  return true;
}




