#ifndef COURSEQUEUE_H
#define COURSEQUEUE_H

#include <string>
#include "Course.h"

class CourseQueue
{
  class Node
  {
    friend class CourseQueue;
    private:
      Course* data;
      Node*    next;
  };

  public:
    CourseQueue();
    CourseQueue(CourseQueue&);
    ~CourseQueue();

    void pushBack(Course *);
    bool popFront();
    Course* front();
    bool empty();
    
  private:
    Node *head;

};
#endif


