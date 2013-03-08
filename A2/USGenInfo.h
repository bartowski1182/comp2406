#ifndef USGENINFO_H
#define USGENINFO_H

#include <curses.h>
#include <string>
#include "Student.h"
#include "UndergradStudent.h"
#include "CourseLoader.h"

#define GINUM_CHOI 10
#define GIMAX_BUF 50


class USGenInfo
{
  public:
    USGenInfo(std::string*, Student**);
    ~USGenInfo();

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
    int courseIndex;
    int nBreaker;
    std::string *course;
    std::string *courseList;

    Student **newStu;
    CourseLoader *load;

    std::string labels[GINUM_CHOI];
    std::string textFields[GINUM_CHOI - 2];

};
#endif
