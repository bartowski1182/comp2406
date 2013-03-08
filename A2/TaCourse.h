#ifndef TC_H
#define TC_H
#include <string>
using namespace std;
class TaCourse
{
  public:
    TaCourse(std::string = "", std::string = "", string = "0", std::string = "");
    ~TaCourse();
    std::string getCourseCode();
    std::string print();
    bool canSetCourseCode(std::string);
    bool canSetTerm(std::string);
    bool canSetYear(std::string);
    bool canSetSupervisor(std::string);

  private:

    std::string courseCode;
    std::string term;
    string year;
    std::string supervisor;

};
#endif
