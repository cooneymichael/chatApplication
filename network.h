#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <Poco/Net/WebSocket.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPMessage.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>
#include <tuple>
#include <fstream>
#include <sstream>
#include "chatModel.h"

using Poco::Net::WebSocket;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;
using Poco::Net::HTTPMessage;
using Poco::Net::HTTPClientSession;
using Poco::Net::SocketAddress;
using Poco::JSON::Parser;
using Poco::JSON::Object;
using Poco::Dynamic::Var;

class Client {
private:
  std::string username;
  std::string message;
  chatModel _model;

 public:
  /// Not working on this code right now, it already compiles

  /* UNTESTED CODE, TRY CONNECTING TO SERVER, HANDLE ERRORS*/
  /* DOES COMPILE*/
  // void ConnectToServer(std::string socket, std::string uri){
  //   //create http connection as base for websockets
  //   SocketAddress address(socket);
  //   HTTPClientSession httpConnection(address);
  //   // Lack of uri because person didn't have example one at hand 
  //   HTTPRequest request(HTTPRequest::HTTP_GET, uri, HTTPMessage::HTTP_1_1);
  //   // This should also be a variable (maybe)
  //   request.set("origin", "192.168.1.124"); 
  //   HTTPResponse response;

  //   //try upgrading connection to websockets
  //   try{
  //     WebSocket* webSock = new WebSocket(httpConnection, request, response);
  //     //sends simple message to server 
  //     char const *testStr = "Hello Websocket Server";
  //     //where response from server (json) is held
  //     char receiveBuff[256];

  //     int len = webSock->sendFrame(testStr, strlen(testStr), WebSocket::FRAME_TEXT);
  //     //tells user how many bytes were sent
  //     std::cout << "Sent bytes " << len << std::endl;
  //     int flags = 0;

  //     int recLen = webSock->receiveFrame(receiveBuff, 256, flags);
  //     //tells user how meny bytes were received
  //     std::cout << "Received bytes " << recLen << std::endl;
  //     std::cout << receiveBuff << std::endl;

  //     //closes websocket
  //     webSock->close();

  //   }catch(std::exception& e){
  //     std::cout << "Error: " << e.what() << std::endl;
  //   }
  // }    

  void JsonParser(std::istream json){
    Parser parser;
    Var result = parser.parse(json);
    Object::Ptr object;
    object = result.extract<Object::Ptr>();
    
    if (!object->has("Type") || object->get("Type") == ""){
      //create or write to file 'error.txt'
      //summarize error, print json object to file
      //CODE IS UNTESTED
      std::ofstream error;
      std::string file = "error.txt";
      error.open(file);
      error << "[Error in network.h]" << std::endl;
      error << "Either json object does not have a 'type' key or 'type' value is not set."\
	    << std::endl;

      object->stringify(error, 1, -1);
      error << std::endl;
      error.close();

    }
    else if (object->get("Type") == "Message"){
      //verify that message and name are strings and form a tuple of them
      //pass that tuple to chatModel, which can pass to controller and view
      std::string message = object->get("Message");
      std::string name = object->get("Name");
      std::tuple<std::string, std::string> messageAndUser = std::make_tuple(message, name);
      _model.setRemoteUserMessage(messageAndUser);

    }
    else if (object->get("Type") == "NewMember"){
      //pass the name of the user to chatModel, which can pass it to 
      //controller and view
      _model.setNewUser(object->get("User"));
      
    }

  }
};


#endif
