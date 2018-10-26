#ifndef NCURSES_UI_CHAT
#define NCURSES_UI_CHAT

#include "guiFactory.h"
#include <curses.h>
#include <tuple>

class NcursesUI : public GuiFactory{
public:

  virtual void Draw() override {
    //draw the screen
  }

  virtual void Erase() override {
    //erase the screen when done
  }

  void CreateWindow(){
    //create a window using the ncurses api
  }

  void AddMessage(std::tuple<std::string, std::string> messageAndUser, \
			    WINDOW *win) {
    //use waddwstr to print message from a user 
  }
  
  void UpdateUsers(){
    //add new users to chat, add usernames to screen, or remove from chat and from screen
    //adding new user done by network; but making them visible is done by this
  }

  void GetMessage(){
    //get message from model
    //part of controller
  }

  void ScrollMessages(){
    //I don't know if I actually need this method
    //I thought I read something about ncurses not scrolling automatically,
    //so if I need to do it manually, this will do
  }

};


#endif
