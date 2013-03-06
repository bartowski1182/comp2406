#ifndef APPQUEUE_H
#define APPQUEUE_H

#include <string>
#include "Application.h"

class ApplicationQueue
{
  class Node
  {
    friend class ApplicationQueue;
    private:
      Application* data;
      Node*    next;
  };

  public:
    ApplicationQueue();
    ApplicationQueue(ApplicationQueue&);
    ~ApplicationQueue();

    void pushBack(Application *);
    bool popFront();
    Application* front();
    bool empty();
    Node *getHead();
    
  private:
    Node *head;

};
#endif


