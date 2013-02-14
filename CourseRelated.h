#ifndef CR_H
#define CR_H
class CourseRelated
{
  public:
    CourseRelated(std::string = "", std::string = "", int = 0, int = 0);
    ~CourseRelated();
    std::string getCourseCode();
    std::string print();
    bool canSetSourceCode(string);
    bool canSetTerm(string);

  private:

    std::string courseCode;
    std::string term;
    int year;
    int finalGrade;

};
#endif
