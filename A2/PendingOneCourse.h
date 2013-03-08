#ifndef PENDONECOURSE_H
#define PENDONECOURSE_H

#include <string>
#include <curses.h>
#include "CourseLoader.h"
#include "Application.h"
#include "ApplicationQueue.h"
using namespace std;

class PendingOneCourse
{
  public:
    PendingOneCourse(ApplicationQueue**);
    ~PendingOneCourse();

    void initPendOCourse();


  private:
    void drawPendOCourse(int);
    int handleInput(char);
    int handleSelection(int);
    int initCourseView();
    int drawCourseView(int);

    int index;
    int nBreaker;
    int courseIndex;
    int startViewApp, endViewApp, currViewApp;
    std::string course;
    std::string *courseList;
    
    Application **appArray;
    ApplicationQueue **applications;
    int arraySize;
    
    std::string labels[3];
    CourseLoader *load;




};
#endif
