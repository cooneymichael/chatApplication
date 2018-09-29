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
  std::string username;
  std::string message;
  

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
    Object::Ptr object = result.extract<Object::Ptr>();

    if (!object->has("Type") || object->get("Type") == ""){
      //message doesn't have type key, or key doesn't match
      //available options.  Error Handling.  Should probably come
      //before other stuff.
      

    }

    else if (object->get("Type") == "Message"){
      //what to do if received message
      //parse for name, content
      

    }
  }
    else if (object->get("Type") == "NewMember"){
      //what to do if new user joined server
      //parse for name (,time?)
      Model::setNewUser(object->get("User"));
      
    }

  }
};


#endif
