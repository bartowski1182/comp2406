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
