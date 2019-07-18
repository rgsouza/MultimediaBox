/**
 * \file main.cpp
 * \brief  Main Program Server.
 * \author  Eric Lecolinet (TP C++) Telecom Paristech/ Rayanne Souza
 * \version 1
 * \date 11/2015
 */

#include"test_multimedia.h"
#include <iostream>
#include <string>
#include "TCPServer.h"
#include"Management.h"
#include"MultimediaBox.h"


using namespace std;


int main(int argc, char* argv[])
{
  TCPServer * server = new TCPServer();
  MultimediaBox *app = new MultimediaBox();


  server->setCallback(app, &MultimediaBox::processRequest);


  // test for all step of project
 /*test_tableau();
 test_film();
 test_group();
 test_copy_overload();
 test_copy_constructor();
  test_management();
*/

  int port = (argc >= 2) ? atoi(argv[1]) : DEFAULT_PORT;
  cout << "Starting Server on port " << port << endl;
  int status = server->run(port);




  if (status < 0) {
    cerr << "Could not start Server on port " << port << endl;
    return 1;
  }
  else return 0;
}

