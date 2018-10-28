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
    //use waddwstr to print message from a user
    //TODO: unpack tuple, mv to window, mv cursor to correct position, rename vars

    std::string x2 = x.substr(0, iterator);
    std::cout << "\"" << x <<"\"" << " ::: " << "\"" << x2 << "\"" << std::endl;
    
    std::list<std::string> messageList;
    messageList.push_back(x2);
    x.erase(0, iterator);
    std::cout << "\"" << x <<"\"" << " ::: " << "\"" << x2 << "\"" << std::endl;
    
    // for addMessage
    //   -> need a way of keeping track of where to place next message in window
    // 	   -> how?
    // 	   -> go n chars into string, then backtrack to first space found
    // 	   -> create a substring from that point forward (while str.length !> n)
    // 	   -> assign to variable, assign all substrings to a vector (?)
    // 	   -> print each vector element to screen
	   
    // 	   -> cut string from 0 to n chars in
    // 	   -> add that portion to vector


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
