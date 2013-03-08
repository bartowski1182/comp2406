#ifndef CRQUEUE_H
#define CRQUEUE_H

#include <string>
#include "CourseRelated.h"

class CourseRelatedQueue
{
  friend class ApplicationIO;
  class Node
  {
    friend class CourseRelatedQueue;
    friend class ApplicationIO;
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
    Node *getHead();
    
  private:
    Node *head;

};
#endif


