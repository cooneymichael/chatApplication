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

  WINDOW* CreateWindow(int height, int width, int yStart, int xStart,\
		       char vertChar, char horizChar){
    //create a window using the ncurses api
    WINDOW* win = newwin(height, width, yStart, xStart);
    box(win, vertChar, horizChar);
    wrefresh(win);
    return win;

  }

  void AddMessage(std::tuple<std::string, std::string> messageAndUser, \
		  int iterator, WINDOW *win) {
    std::string message = messageAndUser[0];
    int numLines = 0;

    while (message.length > n){
      std::string substr = message.substr(0, iterator);
          
      std::list<std::string> messageList;
      messageList.push_back(substr);
      message.erase(0, iterator);
      numLines += 1;
    }

    messageList.push_back(message);
    
    //print to window
    
    for(numLines; numLines >=0; numLines--){
      mvwaddstr(win, linesUsedInWindow + 1, 1, messageList.front());
      lineUsedInWindow += 1;

    }
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

private:
  //the amount of lines that text has been printed to in the whole window.
  int linesUsedInWindow = 0; 

};


#endif
