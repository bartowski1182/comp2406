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

  if(appQ->getHead() == 0)
    return;

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
    applications<<appQ->front()->getApplicationNumber() << "%" << appQ->front()->getCourse() << "%" << appQ->front()->getStatus() << "%" << appQ->front()->getStudentName() << "%" << appQ->front()->getCourseRelated() << endl;
    appQ->pushBack(appQ->front());
    running = appQ->popFront();
  }

}
