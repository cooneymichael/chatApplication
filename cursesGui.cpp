#include <curses.h>
#include <list>
#include <string>
#include <iostream>

int count();
//don't forget to link -lncurses

int main(){

  initscr();
  nocbreak();
  if (!has_colors() && !can_change_color()){
      endwin();
      std::cout << "Terminal does not support colors" << std::endl;
    }
  
  //write a string to screen; white foreground, red background

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_RED);
  attron(COLOR_PAIR(1));

  // WINDOW* myWin = newwin(20, 20, 6, 6);
  // box(myWin, '#', 0);
  
  // mvwaddstr(myWin, 1, 1, "Hello World, I am a string longer than 10 characters :)");
  // wrefresh(myWin);
  // wgetch(myWin);

  addstr("Please Enter Something about 10 characters long: ");
  refresh();
  keypad(stdscr, TRUE);
  char *input;
  while (getch() != 10){
    getnstr(input, 5);
    
  }

  addstr(input);
  refresh();

  getch();

  endwin();
  
  // int i =5;
  // for(i; i>=0; i--){
  //   std::cout << i << std::endl;
  // }
  
  

  return 0;

}

int count(){
  int x = 0;
  int i = 5;
  while (i>=0){
    x += 1;
    i -= 1;
    std::cout << "inside block: " << x << std::endl;
  }
  std::cout << "outside block: " << x << std::endl;

  return 0;

}
