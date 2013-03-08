#ifndef CR_H
#define CR_H
#include <string>
using namespace std;
class CourseRelated
{
  public:
    CourseRelated(std::string = "", std::string = "", std::string = "0", std::string = "0");
    ~CourseRelated();
    std::string getCourseCode();
    std::string print();
    bool canSetCourseCode(std::string);
    bool canSetTerm(std::string);
    bool canSetYear(std::string);
    bool canSetFinalGrade(std::string);

  private:

    std::string courseCode;
    std::string term;
    string year;
    string finalGrade;

};
#endif
