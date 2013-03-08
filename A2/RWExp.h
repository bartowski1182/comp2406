#ifndef RWEXP_H
#define RWEXP_H

#include <curses.h>
#include <string>
#include "WorkExp.h"
#include "WorkExpQueue.h"

#define RWNUM_CHOI 7
#define RWMAX_BUF 50


class RWExp
{
  public:
    RWExp(std::string, WorkExpQueue **);
    ~RWExp();

    //Function
    int initRWExp();

  private:
    //Member Functions
    void drawRWExp(int);
    int handleInput(char);
    int handleSelection(char);
    int handleAccept();
    int handleAdd();
    WorkExp* checkValid();
    int postAccept();

    //Data Members
    bool cancel, reset;
    int index;
    int nBreaker;
    std::string course;

    WorkExpQueue **wEHead;
    WorkExp *newWE;

    std::string labels[RWNUM_CHOI];
    std::string textFields[RWNUM_CHOI - 3];

};
#endif
