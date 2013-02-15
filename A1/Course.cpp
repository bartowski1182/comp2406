#include "Course.h"
#include "ApplicationQueue.h"
#include <string>

Course::Course (string n, ApplicationQueue* h) : courseName(n), AHead(h)
{
	
}

Course::~Course(){

}

void Course::setCourseName(string n){

	courseName = n;

}

string Course::getCourseName(){

	return courseName;

}

ApplicationQueue* Course::getHead(){

	return AHead;

}
