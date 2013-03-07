#include "ApplicationIO.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

ApplicationIO::ApplicationIO()
{
  
}

ApplicationIO::~ApplicationIO()
{
  
}

void ApplicationIO::saveApplications(ApplicationQueue* appQ) const
{

  if(appQ== 0)
    return;

  ApplicationQueue::Node* current = appQ->getHead();


  while(current != 0){
    
    ofstream application("./Applications/" + current->getCourse()->getCourseName(), ios::trunc);
    if(!application)
      cout << "Could not open file\n";


    application << "General info" << endl;
    application << current->getApplicationNumber() << endl;
    application << current->getCourse()->getCourseName() << endl;
    application << current->getStatus() << endl;
    application << current->getStudentNum() << endl;
    application << current->getStudentFirstName() << endl;
    application << current->getStudentLastName() << endl;
    application << current->getStudentEmail() << endl;
 
    if(current->getStudentType() == 0){
      application << ((UndergradStudent)(current->getStudent()))->getMajor() << endl;
      application << ((UndergradStudent)(current->getStudent()))->getYear() << endl;
      application << ((UndergradStudent)(current->getStudent()))->getCGPA() << endl;
      application << ((UndergradStudent)(current->getStudent()))->getMGPA() << endl;
    }
    else{
      application << ((GradStudent)(current->getStudent()))->getResearch() << endl;
      application << ((GradStudent)(current->getStudent()))->getProgram() << endl;
      application << ((GradStudent)(current->getStudent()))->getSuper() << endl;
    }

  }

  ofstream applications("applications.txt", ios::app);
  if(!applications){
    cout << "applications.txt could not be opened" << endl;
    exit(1);
  }

  applications.precision(2);
  applications<<fixed;

  int headAppNum = appQ->front()->getApplicationNumberInt();

  bool running;

  while(headAppNum != appQ->front()->getApplicationNumberInt()){
    applications<<appQ->front()->getApplicationNumber() << "%" << appQ->front()->getCourse() << "%" << appQ->front()->getStatus() << "%" << appQ->front()->getStudentName() << "%" << appQ->front()->getCourseRelated() << "%" << appQ->front()->getTaCourse() << "%" << appQ->front()->getWorkExp() << endl;
    appQ->pushBack(appQ->front());
    running = appQ->popFront();
  }

}
/*
void ApplicationIO::loadApplications(ApplicationQueue* appQ) const
{
  ifstream applications("applications.txt", ios::in);
  
  if(!applications){
    cout<<"Could not open file applications.txt" << endl;
    exit(1);
  }

  char input[500];
  int appNum;
  string course;
  int status;
  string student;
  CourseRelatedQueue* CRHead;
  TaCourseQueue* TCHead;
  WorkExpQueue* WEHead;
  string tempString;
  
  while(!applications.eof()){
	applications.getline(input, 500, '%');
	appNum = atoi(input);
        applications.getline(input, 500, '%');
	course = input;
	applications.getline(input, 500, '%');
	status = atoi(input);
	applications.getline(input, 500, '%');
	student = input;
	applications.getline(input, 500, '%');
	tempString = input;
	int i = 0;
	while(tempString.at(i) != '\0'){
	  tempString.first_first_of("#"
	}
	
	
  }

}*/

