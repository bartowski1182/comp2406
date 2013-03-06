#ifndef WEQUEUE_H
#define WEQUEUE_H

#include <string>
#include "WorkExp.h"

class WorkExpQueue
{
  class Node
  {
    friend class WorkExpQueue;
    private:
      WorkExp* data;
      Node*    next;
  };

  public:
    WorkExpQueue();
    WorkExpQueue(WorkExpQueue&);
    ~WorkExpQueue();

    void pushBack(WorkExp *);
    bool popFront();
    WorkExp* front();
    bool empty();
    std::string stringOut();
    
  private:
    Node *head;

};
#endif


