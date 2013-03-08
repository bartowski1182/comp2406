#ifndef PENDCHOOSE_H
#define PENDCHOOSE_H

#include <string>
#include <curses.h>
using namespace std;

class PendingChoose
{
  public:
    PendingChoose();
    ~PendingChoose();

    int initPendChoose();

  private:
    void drawPendChoose(int);
    int handleInput(char);
    int handleSelection(int);
    int index;
    int nBreaker;
    
    std::string labels[2];
};
#endif
