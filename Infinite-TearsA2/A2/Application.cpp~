#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Application.h"
#include <stdlib.h>
#include <sstream>
using namespace std;

Application::Application(string newCourse, string stat, Student* newStudent, int type, CourseRelatedQueue* CR,  TaCourseQueue* TC, WorkExpQueue* WE) : applicationNum(AppNum()), course(newCourse), status	(stat), student(newStudent), studentType(type), CRHead(CR), TCHead(TC), WEHead(WE)
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

string Application::getStudentTypeString(){
  stringstream convert;
  convert << studentType;
  return convert.str();
}

int Application::getApplicationNumberInt(){
  return applicationNum;
}

string Application::getStudentEmail(){
  return student->getEmail();
}

int Application::getStudentType(){
  return studentType;
}

string Application::getCourse(){
  return course;
}

string Application::getStatus(){
  return status;
}

string Application::getStudentFirstName(){
  if(student != 0)
  return student -> getFirstName();
}

string Application::getStudentLastName(){
  if(student != 0)
  return student -> getLastName();
}

string Application::getStudentNum(){
  return student->getNum();
}

CourseRelatedQueue* Application::getCourseRelated(){
  return CRHead;
}

TaCourseQueue* Application::getTaCourse(){
  return TCHead;
}

WorkExpQueue* Application::getWorkExp(){
  return WEHead;
}

Student* Application::getStudent(){
  return student;
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
