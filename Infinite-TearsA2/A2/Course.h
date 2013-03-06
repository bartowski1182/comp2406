#ifndef COURSE_H
#define COURSE_H
using namespace std;
#include <string>
#include "ApplicationQueue.h"

class Course{

	public:
		Course (string, ApplicationQueue*);
		~Course();
		void setCourseName(string);
		string getCourseName();
		ApplicationQueue* getHead();
	private:
		string courseName;
		ApplicationQueue* AHead;

};

#endif
