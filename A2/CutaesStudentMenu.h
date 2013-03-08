#ifndef CSMENU_H
#define CSMENU_H

#include <string>
#include <curses.h>
#include "ApplicationQueue.h"
#include "Form.h"
using namespace std;

class CutaesStudentMenu
{
  public:
    CutaesStudentMenu(ApplicationQueue **);
    ~CutaesStudentMenu();

    int initStudentMenu();

  private:
    void drawStudentMenu(int);
    int handleInput(char);
    int handleSelection(int);
    int index;
    int nBreaker;
    
    ApplicationQueue **applications;
    Form *form;
    std::string labels[3];
};
#endif
