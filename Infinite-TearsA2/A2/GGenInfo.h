#ifndef GGENINFO_H
#define GGENINFO_H

#include <curses.h>
#include <string>
#include "Student.h"
#include "GradStudent.h"
#include "CourseLoader.h"

#define GGINUM_CHOI 9
#define GGIMAX_BUF 50


class GGenInfo
{
  public:
    GGenInfo(std::string*, Student**);
    ~GGenInfo();

    //Function
    bool initGenInfo();

  private:
    //Member Functions
    void drawGenInfo(int);
    int handleInput(char);
    int handleSelection(int);
    int initCourseView(int);
    int drawCourseView(int);
    int handleAccept();

    //Data Members
    bool cancel;
    int index;
    int courseIndex, researchIndex;
    int nBreaker;
    std::string *course, *researchArea;
    std::string *courseList, *researchAreaList;

    Student **newStu;
    CourseLoader *load;

    std::string labels[GGINUM_CHOI];
    std::string textFields[GGINUM_CHOI - 3];

};
#endif
