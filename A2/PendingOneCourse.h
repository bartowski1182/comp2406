#ifndef PENDONECOURSE_H
#define PENDONECOURSE_H

#include <string>
#include <curses.h>
#include "CourseLoader.h"
using namespace std;

class PendingOneCourse
{
  public:
    PendingOneCourse();
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
    std::string course;
    std::string *courseList;
    
    std::string labels[3];
    CourseLoader *load;




};
#endif
