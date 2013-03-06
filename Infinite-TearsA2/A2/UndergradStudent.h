#ifndef UGSTUDENT_H
#define UGSTUDENT_H

#include "Student.h"
using namespace std;
#include <string>

class UndergradStudent : public Student
{
  public:
    UndergradStudent(string="unknown", string = "unknown", string="000000000", string="unknown@carleton.ca", string="", string="0", string="0.0", string="0.0");
    ~UndergradStudent();

    static bool canSetYear(string);

    static bool canSetMajor(string);
    static bool canSetMGPA(string);

    static bool canSetCGPA(string);

    void setMajor(string);

    void setYear(string);

    void setCGPA(string);

    void setMGPA(string);

    string getMajor();

    string getYear();

    string getCGPA();

    string getMGPA();
    
  private:
    string sMajor;
    string yearStanding;
    string cgpa;
    string mgpa;





};

#endif
