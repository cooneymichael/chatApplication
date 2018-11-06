#ifndef NCURSES_UI_CHAT
#define NCURSES_UI_CHAT

#include "guiFactory.h"
#include "chatModel.h"
#include <curses.h>
#include <vector>
#include <tuple>
#include <list>

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
    //TODO: don't forget to print username with message
    std::string message = std::get<0>(messageAndUser);
    std::list<std::string> messageList;
    int numLines = 0;

    while (message.length() > iterator){
      std::string substr = message.substr(0, iterator);
          
      messageList.push_back(substr);
      message.erase(0, iterator);
      numLines += 1;
    }

    messageList.push_back(message);
    
    /*print to window*/
    //convert string to c_str
    
    // std::string user = std::get<1>(messageAndUser);
    // const char* cstr = user.c_str();

    const char* userAsCstr = convertFromStringToCstr(std::get<1>(messageAndUser));

    try{
      mvwaddstr(win, linesUsedInWindow + 1, 1, userAsCstr);
      linesUsedInWindow += 1;		
      for(numLines; numLines >=0; numLines--){
	mvwaddstr(win, linesUsedInWindow + 1, 1, convertFromStringToCstr(messageList.front()));
	linesUsedInWindow += 1;
	
      }
    }catch(int errorCode){
      ScrollMessages(win, messageList.size() + 2);
      mvwaddstr(win, linesUsedInWindow + 1, 1, userAsCstr);
      linesUsedInWindow += 1;		
      for(numLines; numLines >=0; numLines--){
	mvwaddstr(win, linesUsedInWindow + 1, 1, convertFromStringToCstr(messageList.front()));
	linesUsedInWindow += 1;
	
      }
    }
  }

  const char* convertFromStringToCstr(std::string str){
     const char* cstr = str.c_str();
     return cstr;
  }

  void UpdateUsers(std::vector<std::string> usernamesInVector, WINDOW* win, int numberOfCharactersToWrite){
    //when list of users changes, rewrite list of users. 
    int yCoord = 0;
    for(int i=0; i<usernamesInVector.size(); i++){
      yCoord +=1;
      std::string usernameAsString = convertFromStringToCstr(usernamesInVector.front());
      mvwaddnstr(win, yCoord, 1, convertFromStringToCstr(usernameAsString), numberOfCharactersToWrite);
      
    }
  }

  // void GetMessage(){
  //   //part of controller -> should be removed from this class later? yes
  //   //should be declared in code
  //   nocbreak();
  //   char* localUserMessage;
  //   getstr(localUserMessage);
  //   _chatModel->setLocalUserMessage(localUserMessage);
    
  // }

  void ScrollMessages(WINDOW* win, int numLinesToScroll){
    //scrolling ncurses when needed
    scrollok(win, TRUE);
    wscrl(win, numLinesToScroll);
    
  }

private:
  //the amount of lines that text has been printed to in the whole window.
  int linesUsedInWindow = 0;
  //hack because ncurses ERR was causing compiler error
  int errorCode = -1;
  //chatModel* _chatModel;
};


#endif
