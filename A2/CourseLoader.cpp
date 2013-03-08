#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include "CourseLoader.h"

#define MAX_BUF 80

CourseLoader::CourseLoader(const char* filein) : file(filein)
{
}

CourseLoader::~CourseLoader()
{
}

//Dynamically allocates memory to make string array the size of lines from the txt file
int CourseLoader::loadCourses(std::string **pointer){
  
  ifstream courses(file, ios::in);
  if(!courses){
    cout << "Could not open file" << endl;
    exit(1);
  }

  int i = 0;

  char text[80];

  while (!courses.eof()) {
    courses.getline(text, 80);
    i++;
  }

  courses.close();

  ifstream courses2(file, ios::in);

  *pointer = new string[i];
 
  int max = i;
  i = 0;
  while (i < max) {
    courses2.getline(text, 80);
    (*pointer)[i] = text;
    i++;
  }


  return i;

}


