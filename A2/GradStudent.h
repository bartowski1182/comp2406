#ifndef GSTUDENT_H
#define GSTUDENT_H

#include "Student.h"
using namespace std;
#include <string>

class GradStudent : public Student
{
  public:
    GradStudent(string="unknown", string = "unknown", string="000000000", string="unknown@carleton.ca", string="unknown", string="unknown", string="unknown");
    ~GradStudent();

    static bool canSetResearch(string);

    static bool canSetProgram(string);
    static bool canSetSuper(string);

    void setResearch(string);

    void setProgram(string);

    void setSuper(string);

    string getResearch();

    string getProgram();

    string getSuper();
    
  private:
    string mResearch;
    string program;
    string supervisor;





};

#endif

