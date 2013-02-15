#ifndef TAQUEUE_H
#define TAQUEUE_H

#include <string>
#include "TaCourse.h"

class TaCourseQueue
{
  class Node
  {
    friend class TaCourseQueue;
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
    
  private:
    Node *head;

};
#endif


