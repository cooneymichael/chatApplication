#include <iostream>
#include <vector>
#include <tuple>

class chatModel{
public:
  void setUsername(std::string name){
    this->username = name;
  }

  std::string getUsername(){
    return this->username;
  }
  
  void setNewUser(std::string user){
    this->users.push_back(user);
  }

  std::vector<std::string> getUsers(){
    return this->users;
  }

  void setLocalUserMessage(std::string message){
    this->message = message;
  }

  //add new messages (from network.h) to messages vector
  void setRemoteUserMessage(std::tuple<std::string, std::string> message){
    //accepts tuple of message content and sender (in that order)
    this->messagesToAdd.push_back(message);
  }

  //access first element in vector (to be printed)
  //then erase element from vector
  std::tuple<std::string, std::string> getRemoteUserMessage(){
    //takes tuple of content and user who sent it, returns it.
    std::tuple<std::string, std::string> returnValue =  messagesToAdd.front();
    messagesToAdd.erase(messagesToAdd.begin());
    return returnValue;
  }
  
private:
  std::string username;
  std::string message;
  std::vector<std::string> users;
  std::vector<std::tuple<std::string, std::string>> messagesToAdd;
  int numberOfUsers;
  
};
