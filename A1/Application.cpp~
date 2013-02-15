#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Application.h"
#include <stdlib.h>
#include <sstream>
using namespace std;

Application::Application(string newCourse, int stat, string newStudent, CourseRelatedQueue* CR,  TaCourseQueue* TC, WorkExpQueue* WE) : applicationNum(AppNum()), course(newCourse), status	(stat), student(newStudent), CRHead(CR), TCHead(TC), WEHead(WE)
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

int Application::getApplicationNumberInt(){
  return applicationNum;
}

string Application::getCourse(){
  return course;
}

int Application::getStatus(){
  return status;
}

string Application::getStudentName(){
  return student;
}

string Application::getCourseRelated(){
  
  return CRHead->stringOut();
    
}

string Application::getTaCourse(){
  return TCHead->stringOut();
}

string Application::getWorkExp(){
  return WEHead->stringOut();
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
