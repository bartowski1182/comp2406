#ifndef RCOURSE_H
#define RCOURSE_H

using namespace std;
#include <curses.h>
#include <string>
#include "CourseRelatedQueue.h"
#include "CourseRelated.h"
#include "CourseLoader.h"

#define RCNUM_CHOI 6
#define RCMAX_BUF 15


class RCourses
{
  public:
    RCourses(std::string, CourseRelatedQueue**);
    ~RCourses();
    
    bool initRCourses();

  private:
    //Member Functions
    void drawRCourses(int);
    int handleInput(char);
    int handleSelection(int);
    int handleAccept();
    int handleAdd();
    int initCourseView(int);
    int drawCourseView(int);
    CourseRelated* checkValid();

    //Data Members
    bool cancel;
    int index;
    int courseIndex;
    int nBreaker;
    std::string course; 
    std::string *courseList;
    std::string relatedCourse;

    CourseLoader *load;
    CourseRelatedQueue **cRHead;
    CourseRelated *newCR;

    std::string labels[RCNUM_CHOI];
    std::string textFields[RCNUM_CHOI - 3];

};
#endif
