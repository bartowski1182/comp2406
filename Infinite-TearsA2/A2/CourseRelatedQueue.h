#ifndef CRQUEUE_H
#define CRQUEUE_H

#include <string>
#include "CourseRelated.h"

class CourseRelatedQueue
{
  class Node
  {
    friend class CourseRelatedQueue;
    private:
      CourseRelated* data;
      Node*    next;
  };

  public:
    CourseRelatedQueue();
    CourseRelatedQueue(CourseRelatedQueue&);
    ~CourseRelatedQueue();

    void pushBack(CourseRelated *);
    bool popFront();
    CourseRelated* front();
    bool empty();
    std::string stringOut();
    
  private:
    Node *head;

};
#endif


