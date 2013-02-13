#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include "courseLoader.h"

#define MAX_BUF 80

courseLoader::courseLoader(const char* filein) : file(filein)
{
  cout<<"courseLoad ctor" << endl;
}

courseLoader::~courseLoader()
{
  cout<<"courseLoad dtor" << endl;
}


int courseLoader::loadCourses(std::string **pointer){
  
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

  cout<< "About to close" << endl;
  courses.close();

  ifstream courses2(file, ios::in);
  
  cout<< "Successfully opened... i = "<< i << endl;

  *pointer = new string[i];
 
  i = 0;
  while (i < 5) {
    courses2.getline(text, 80);
    (*pointer)[i] = text;
    i++;
  }


  return i;

}


