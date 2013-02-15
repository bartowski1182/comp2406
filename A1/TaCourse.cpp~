#include "TaCourse.h"
#include <string>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

TaCourse::TaCourse(std::string cc, std::string tm, int yr, string s) 
	: courseCode(cc), term(tm), year(yr), supervisor(s)
{
	cout<<"TaCourse constructor" << endl;
}

CourseRelated::~CourseRelated()
{
	cout<<"TaCourse deconstructor" << endl;
}

string TaCourse::getCourseCode()
{
	return courseCode;
}

string TaCourse::print()
{
	return courseCode;
}

bool TaCourse::canSetCourseCode (string cc)
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

bool canSetSupervisor(string s)
{

	string letters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";

	if(s.find_first_not_of(letters) != string::npos){
		return false;
	}

	return true;

}
