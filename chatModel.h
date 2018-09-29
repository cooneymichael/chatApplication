#include <iostream>
#include <vector>

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

  //need event handler function to handle
  //remoteUserMessage (send to view through controller)

private:
  std::string username;
  std::string message;
  std::vector<std::string> users;
  int numberOfUsers;
  
};
