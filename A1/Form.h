#ifndef FORM_H
#define FORM_H

#include <curses.h>
#include <iostream>
#include <string>

#define NUM_CHOI 10
#define MAX_BUF 20

class Form
{
 public:
  //In constructor, take in a CourseQueue pointer
  Form(std::string = "SCIENCE");
  ~Form();

  //GETTERS
  int getIndex() const;
  std::string getCourse() const;

  void initForm();

 private:
  //Member Functions
  void drawForm(int);
  int handleInput(char);
  int handleSelection(char);
  int handleAccept();
  int update();

  //Data Members
  int index;
  int nBreaker;
  std::string course;
  std::string labels[NUM_CHOI];
  std::string textFields[NUM_CHOI - 2];

};

#endif
