#include "CourseRelated.h"
#include <string>

CourseRelated::CourseRelated(string cc, string tm, int yr, int fg) 
	: courseCode(cc), term(tm), year(yr), finalGrade(fg)
{

	cout<<"RelatedCourse constructor" << endl;

}

CourseRelated::~CourseRelated()
{

	cout<<"RelatedCourse deconstructor" << endl;

}

string CourseRelated::getCourseCode()
{

	return courseCode;

}

string CourseRelated::print()
{

	return courseCode;

}

bool CourseRelated::canSetCourseCode ()
{
	
	if (courseCode.size() != 9){
		return false;
	}
	
	unsigned letters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
	unsigned numbers = "1234567890"";
	
	for(int i = 0; i < 3; i++){		
		if (courseCode.find_first_of(letters, i) != i + 1){
			return false;
		}
	}
	if (courseCode.find_first_of(" ") != 5){
		return false;
	}
	for(int i = 5; i < 8; i++){
		if (courseCode.find_first_of(numbers, i) != i + 1){
			return false;
		}
	}
	return true;
	
	
	
}
