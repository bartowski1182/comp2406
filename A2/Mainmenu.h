#ifndef MMENU_H
#define MMENU_H

#include <curses.h>
#include <string>
#include "CutaesStudentMenu.h"
#include "CutaesAdminMenu.h"
#include "ApplicationQueue.h"
#include "ApplicationIO.h"
using namespace std;

#define MAX_BUF 20
#define MNUM_CHOI 3

class Mainmenu
{
  public:
    Mainmenu();
    ~Mainmenu();

    void initCutaes();

  private:
    ApplicationQueue *applications;
    ApplicationIO *saving;

    void drawMainMenu(int);
    int handleInput(char);
    int handleSelection(int);
    void studentMenu(ApplicationQueue **);
    void adminMenu(ApplicationQueue **);

    int index;
    int nBreaker;

    CutaesStudentMenu *sMenu;
    CutaesAdminMenu *aMenu;

    string labels[MNUM_CHOI];

    

};
#endif
