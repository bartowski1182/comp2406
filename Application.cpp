#include <fstream>
#include <iostream>

Application::Application(Application::AppNum(), Course* newCourse, int stat, Student* newStudent
	CourseRelevantQueue* CR, TaCourseQueue* TC, WorkExpQueue* WE) 
	: applicationNum(AppNum), course(newCourse), status(stat), student(newStudent),
	CRHead(CR), TCHead(TC), WEHead(WE)
{
	
}

Application::~Application()
{

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
	tmpText>>applicationNumber;

	number.close();

	ofstream number("applicationCounter.txt", ios::trunc);

	number << applicationNumber + 1 << endl;

	return applicationNumber;

}