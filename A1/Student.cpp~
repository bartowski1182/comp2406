#include <iostream>
using namespace std;
#include <string>
#include "Student.h"

Student::Student(string fn, string ln, int nu, string em, string m, int y, int cg, int mg)
	: firstName(fn), lastName(ln), number(nu), email(em), major(m), yearStanding(y), cgpa(cg), mgpa(mg)
{
  cout<<"Student constructor" << endl;
}

Student::~Student()
{
  cout<<"Student deconstructor\n";
}
    

string Student::getFirstName() {return firstName;}

string Student::getLastName() {return lastName;}

int Student::getNum() {return number;}

string Student::getEmail() {return email;}

string Student::getMajor() {return major;}

int Student::getYear() {return yearStanding;}

int Student::getCGPA() {return cgpa;}

int Student::getMGPA() {return mgpa;}

void Student::setFirstName(string fn) {firstName = fn;}

void Student::setLastName(string ln) {lastName = ln;}

void Student::setNum(int num) {number = num;}

void Student::setEmail(string em) {email = em;}

void Student::setMajor(string m) {major = m;}

void Student::setYear(int year) {yearStanding = year;}

void Student::setCGPA(int cg) {cgpa = cg;}

void Student::setMGPA(int mg) {mgpa = mg;}

bool Student::canSetFirstName(string fn){
  string letters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm-";
  if(fn.find_first_not_of(letters) != std::npos){
    return false;
  }
  
  return true;

}

bool Student::canSetLastName(string ln){
  string letters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm-";
  if(ln.find_first_not_of(letters) != std::npos){
    return false;
  }
  
  return true;

}

bool Student::canSetStudentNumber(string num){
  string numbers = "1234567890";

  if(num.size() > 9){
    return false;
  }

  if(num.find_first_not_of(numbers) != std::npos){
    return false;
  }

  return true;

}

bool Student::canSetEmail(string e){

  string email = "@cmail.carleton.ca";

  if(e.find(email) == std::npos){
    return false;
  }

  if(e.find_first_of(" ")

  return true;

}

bool Student::canSetMajor(string m)
{
  string letters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm- ";
  if(m.find_first_not_of(letters) != string::npos){
    return false;
  }

  return true;

}

bool Student::canSetYear(string y){

  if(y.size() != 1){
    return false;
  }

  string numbers = "1234";
  
  if(y.find_first_not_of(numbers) != string::npos){
    return false;
  }

  return true;

}

bool Student::canSetCGPA(string c){

  if(c.size() == 0){
    return false;
  }

  string numbers = "1234567890.";
 
  if(c.find_first_not_of(numbers) != string::npos){
    return false;
  }

  double cumul = atof(c);

  if(cumul < 0.0 || cumul > 12.0){
    return false;
  }

  return true;

}

bool Student::canSetMGPA(string m){

  if(m.size() == 0){
    return false;
  }

  string numbers = "1234567890.";
 
  if(m.find_first_not_of(numbers) != string::npos){
    return false;
  }

  double major = atof(m);

  if(major < 0.0 || major > 12.0){
    return false;
  }

  return true;

}









  
