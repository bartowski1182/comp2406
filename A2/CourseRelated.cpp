#include "CourseRelated.h"
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

CourseRelated::CourseRelated(std::string cc, std::string tm, std::string yr, std::string fg) 
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

std::string CourseRelated::print()
{
	std::stringstream outYear;
	outYear << year;
	std::stringstream outGrade;
	outGrade << finalGrade;
	return courseCode + "#" + term + "#" + outYear.str() + "#" + outGrade.str();
}

bool CourseRelated::canSetCourseCode (string cc)
{
	
	if (cc.size() != 9){
		return false;
	}
	
	string letters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
	string numbers = "1234567890";
	
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
	int size = 0;
	size = tm.size();
	char newTerm[size+1];
	
	char c;
	for(int i = 0; i < tm.size(); i++){
		c = tm.at(i);
		newTerm[i] = tolower(c);
	}
	tm = newTerm;
	if(tm == "winter" || tm == "summer" || tm == "fall"){
		return true;
	}

	return false;

}

bool CourseRelated::canSetYear(string yr)
{

	if(yr.size() != 4)
		return false;

	char newYear[4];

	char c;
	for(int i = 0; i < 4; i++){
		c = yr.at(i);
		newYear[i] = tolower(c);
	}

	string numbers = "1234567890";

	if(yr.find_first_not_of(numbers) != string::npos)
		return false;

	int yearInt = atoi(newYear);

	if(yearInt < 2008 || yearInt > 2013)
		return false;

	return true;

}

bool CourseRelated::canSetFinalGrade(string fg)
{
	if(fg.size() < 5)
		return false;

	char newFinalGrade[fg.size()];

	char c;
	for(int i = 0; i < 4; i++){
		c = fg.at(i);
		newFinalGrade[i] = tolower(c);
	}

	string numbers = "1234567890.";

	if(fg.find_first_not_of(numbers) != string::npos)
		return false;

	double finalGradeDoub = atof(newFinalGrade);

	if(finalGradeDoub < 0.0 || finalGradeDoub > 12.0)
		return false;

	return true;

}
