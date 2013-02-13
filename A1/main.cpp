/*  Yugo Brunet
**  Main.cpp
**  run to start the application
**
***/
#include "Form.h"

int main()
{
  //Preliminary stuff
  initscr();
  raw();
  nonl();
  noecho();
  keypad(stdscr, TRUE);

  //actual code
  Form form("Science");
  form.initForm();

  endwin();
  return 0;
}
