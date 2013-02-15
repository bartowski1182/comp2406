#ifndef APPLICATION_H
#define APPLICATION_H
using namespace std;
#include <string>
#include "Student.h"
#include "CourseRelatedQueue.h"

class Application{

	public:
		Application (string = "", int = 0, Student* = NULL, CourseRelatedQueue* = NULL);
		~Application();
		int AppNum ();
		string getApplicationNumber();
		string getCourse();
		int getStatus();
		string getStudentName();
		string getCourseRelated();
		
	private:
		int applicationNum;
		string course;
		int status;
		Student* student;
		CourseRelatedQueue* CRHead;

		/*
		TaCourseQueue* TCHead;
		WorkExpQueue* WEHead;*/
};

#endif
