#include "GradStudent.h"
using namespace std;


GradStudent::GradStudent(string fn, string ln, string nu, string em, string ra, string pr, string sv) : Student(fn, ln, nu, em), mResearch(ra), program(pr), supervisor(sv)
{

}

GradStudent::~GradStudent()
{

}

string GradStudent::getResearch() {return mResearch;}

string GradStudent::getProgram() {return program;}

string GradStudent::getSuper() {return supervisor;}

void GradStudent::setResearch(string m) {mResearch = m;}

void GradStudent::setProgram(string year) {program = year;}

void GradStudent::setSuper(string cg) {supervisor = cg;}


bool GradStudent::canSetResearch(string m)
{

  if(m.size() == 0){
    return false;
  }

  string letters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm- ";
  if(m.find_first_not_of(letters) != string::npos){
    return false;
  }

  return true;

}

bool GradStudent::canSetProgram(string y){

  if(y.size() != 1){
    return false;
  }

  string numbers = "1234";
  
  if(y.find_first_not_of(numbers) != string::npos){
    return false;
  }

  return true;

}

bool GradStudent::canSetSuper(string c){

  if(c.size() == 0){
    return false;
  }

  string numbers = "1234567890.";
 
  if(c.find_first_not_of(numbers) != string::npos){
    return false;
  }

  char ch[c.size()];
  for(int i = 0; i < 4; i++){
    ch[i] = tolower(c.at(i));
  }

  double cumul = atof(ch);

  if(cumul < 0.0 || cumul > 12.0){
    return false;
  }

  return true;

}

