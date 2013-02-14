#include "CourseRelated.h"
#include <string>

CourseRelated::CourseRelated(string cc, int tm, int yr, int fg) 
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

bool CourseRelated::canSetCourseCode (string cc)
{
	
	if (cc.size() != 9){
		return false;
	}
	
	unsigned letters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
	unsigned numbers = "1234567890";
	
	for(int i = 0; i < 3; i++){		
		if (cc.find_first_of(letters, i) != i + 1){
			return false;
		}
	}
	if (cc.find_first_of(" ") != 5){
		return false;
	}
	for(int i = 5; i < 8; i++){
		if (cc.find_first_of(numbers, i) != i + 1){
			return false;
		}
	}
	return true;
}

bool CourseRelated::canSetTerm (string tm)
{

	unsigned numbers = "1234567890";
	if(tm.find_first_of(numbers) == string::npos){
		return false;
	}

	int newTerm = std::stoi(tm);

	if(newTerm < 1 || newTerm > 4)
		return false;
	
	return true;

}


