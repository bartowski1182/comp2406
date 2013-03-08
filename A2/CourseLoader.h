#ifndef COURSELOAD_H
#define COURSELOAD_H
using namespace std;
#include <string>

class CourseLoader
{
  public:
    CourseLoader (const char* = NULL);
    ~CourseLoader();
    int loadCourses(std::string **pointer);

  private:
    const char* file;

};

#endif
