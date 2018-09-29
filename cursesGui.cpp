#include <ncurses.h>
#include <iostream>

int main(){

  initscr();
  if (!has_colors() && !can_change_color()){
      endwin();
      std::cout << "Terminal does not support colors" << std::endl;
    }

  //write a string to screen; white foreground, red background

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_RED);
  attron(COLOR_PAIR(1));

  addstr("Hello World");
  refresh();
  getch();

  endwin();

  return 0;

}
