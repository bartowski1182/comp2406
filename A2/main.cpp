/*  Yugo Brunet
**  Main.cpp
**  run to start the application
**
***/
#include "Mainmenu.h"

int main()
{
  //Preliminary stuff
  initscr();
  raw();
  nonl();
  noecho();
  keypad(stdscr, TRUE);

  //actual code
  /*
  Form form("Science");
  form.initForm();*/

  Mainmenu *cutaes = new Mainmenu();
  cutaes -> initCutaes();
  delete cutaes;

  endwin();
  return 0;
}
