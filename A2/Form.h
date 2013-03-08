#ifndef FORM_H
#define FORM_H

#include <curses.h>
#include <iostream>
#include <string>

#include "ApplicationQueue.h"

#include "USGenInfo.h"
#include "GGenInfo.h"
#include "RCourses.h"
#include "TCourses.h"
#include "RWExp.h"

#include "Student.h"
#include "CourseRelatedQueue.h"
#include "TaCourseQueue.h"
#include "WorkExpQueue.h"

class Form
{
  public:
    //In constructor, take in a CourseQueue pointer
    Form(ApplicationQueue ** = 0);
    ~Form();

    void initForm();

  private:
    //Member Functions
    int update();
    int allValid();
    int notValid();

    //Data Members
    bool cont;
    int index, which_menu, stuType;
    int nBreaker;
    std::string course;

    ApplicationQueue **applications;
    Application *newApp;

    Student *newStu;
    CourseRelatedQueue *cRQueue;
    TaCourseQueue *tACQueue;
    WorkExpQueue *wEQueue;

    USGenInfo  *page1_1;
    GGenInfo *page1_2;
    RCourses *page2;
    TCourses *page3;
    RWExp    *page4;

};

#endif
