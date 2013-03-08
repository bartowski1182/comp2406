#ifndef TAQUEUE_H
#define TAQUEUE_H

#include <string>
#include "TaCourse.h"

class TaCourseQueue
{
  friend class ApplicationIO;
  class Node
  {
    friend class TaCourseQueue;
    friend class ApplicationIO;
    private:
      TaCourse* data;
      Node*    next;
  };

  public:
    TaCourseQueue();
    TaCourseQueue(TaCourseQueue&);
    ~TaCourseQueue();

    void pushBack(TaCourse *);
    bool popFront();
    TaCourse* front();
    bool empty();
    std::string stringOut();
    Node *getHead();
    
  private:
    Node *head;

};
#endif


