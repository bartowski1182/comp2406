#ifndef GSTUDENT_H
#define GSTUDENT_H

#include "Student.h"
using namespace std;
#include <string>

class GradStudent : public Student
{
  public:
    GradStudent(string="unknown", string = "unknown", string="000000000", string="unknown@carleton.ca", string="", string="unknown", string="unknown");
    ~GradStudent();

    static bool canSetYear(string);

    static bool canSetMajor(string);
    static bool canSetMGPA(string);

    void setMajor(string);

    void setYear(string);

    void setCGPA(string);

    string getResearch();

    string getProgram();

    string getSuper();
    
  private:
    string mResearch;
    string program;
    string supervisor;





};

#endif
