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

  Node *currNode = appQ->getHead();

   

  while(currNode != 0){
    applications<<currNode->getData->getApplicationNumber() << "%" << currNode->data->getCourse() << "%" << currNode->data->getStatus() << "%" << currNode->data->getStudentName() << "%" << currNode->data->getCourseRelated() << endl;
    currNode = currNode->next;
  }
  

}
