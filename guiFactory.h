#ifndef GUI_FACTORY_CHAT
#define GUI_FACTORY_CHAT

#include <curses.h>
#include <tuple>

class GuiFactory{
public:
  virtual void Draw() =0;

  virtual void Erase() =0;
  
};

#endif
