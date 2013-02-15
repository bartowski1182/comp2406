#ifndef APPLICATION_H
#define APPLICATION_H
using namespace std;
#include <string>
#include "Student.h"
#include "CourseRelatedQueue.h"
#include "TaCourseQueue.h"
#include "WorkExpQueue.h"

class Application{

	public:
		Application (string = "", int = 0, string = "", CourseRelatedQueue* = NULL, TaCourseQueue* = NULL, WorkExpQueue* = NULL);
		~Application();
		int AppNum ();
		string getApplicationNumber();
		string getCourse();
		int getStatus();
		string getStudentName();
		string getCourseRelated();
		int getApplicationNumberInt();
		string getTaCourse();
		string getWorkExp();
		
	private:
		int applicationNum;
		string course;
		int status;
		string student;
		CourseRelatedQueue* CRHead;
		TaCourseQueue* TCHead;
		WorkExpQueue* WEHead;

		/*
		TaCourseQueue* TCHead;
		WorkExpQueue* WEHead;*/
};

#endif
