#ifndef STUDENT_H
#define STUDENT_H

class Student
{
  public:
    Student(string="unknown", int=000000000, string="unknown@carleton.ca", string="", int=0, int=0, int=0);
    ~Student();
    string getName();

    int getNum();

    string getEmail();

    string getMajor();

    int getYear();

    int getCGPA();

    int getMGPA();

    void setName(string);

    void setNum(int);

    void setEmail(string);

    void setMajor(string);

    void setYear(int);

    void setCGPA(int);

    void setMGPA(int);

    //Student getStudent(int, studentnode);

  private:

    int number;
    string name;
    string email;
    string major;
    int yearStanding;
    int cgpa;
    int mgpa;

};


#endif


