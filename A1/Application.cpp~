#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Application.h"
#include <stdlib.h>
#include <sstream>
using namespace std;

Application::Application(string newCourse, int stat, Student* newStudent,
	CourseRelatedQueue* CR)	: applicationNum(AppNum()), course(newCourse), status(stat), student(newStudent),
	CRHead(CR)
{
	
}

Application::~Application()
{

}

string Application::getApplicationNumber(){

  stringstream convert;
  convert << applicationNum;
  return convert.str();
}

string Application::getCourse(){
  return course;
}

int Application::getStatus(){
  return status;
}

string Application::getStudentName(){
  return student->getName();
}

string Application::getCourseRelated(){
  
  return CRHead->stringOut();
    
}

int Application::AppNum()
{

	int applicationNumber;

	ifstream number("applicationCounter.txt", ios::in);

	if(!number){
		cout << "Could not open file" << endl;
		exit(1);
	}

	char tmpText[10];

	number.getline(tmpText, 10);
	applicationNumber = atoi(tmpText);

	number.close();

	ofstream writeNumber("applicationCounter.txt", ios::trunc);

	applicationNumber++;

	writeNumber << applicationNumber << endl;

	writeNumber.close();

	return applicationNumber;

}
