#include "Form.h"
using namespace std;

Form::Form(ApplicationQueue **aq) : index(1), nBreaker(0), cont(false), course("Spanish"), which_menu(-1), stuType(0),
                                    page1_1(0), page1_2(0), page2(0), page3(0), page4(0), applications(aq), 
                                    cRQueue(0), tACQueue(0), wEQueue(0), newApp(0), newStu(0)
{

}

Form::~Form()
{
}

////////////////////////////////////////////////////////////
//<summary> Update the screen based on what's supposed    //
//          to be drawn </summary>                        //
////////////////////////////////////////////////////////////
int Form::update()
{

  bool quit = false;


  int n = index;
  int reset = -1;
  std::string firstName;

  switch(n)
  {
    case 1:
      //draw the gen info page

      
      while(which_menu < 0)
      {
        clear();
        mvprintw(10, 10, "What type of user are you?\n");
        mvprintw(11, 10, "G: Graduate Student\n");
        mvprintw(12, 10, "U: Undergraduate Student\n");


        char c = getch();
        
        switch (c){
          case (char)'u':
            which_menu = 1;
            quit = true;
            break;
          case (char)'U':
            which_menu = 1;
            quit = true;
            break;
          case (char)'G':
            which_menu = 2;
            quit = true;
            break;
          case (char)'g':
            which_menu = 2;
            quit = true;
            break;
          case (char)KEY_F(2):
            quit = true;
            break;
          default:
            break;
        }

        if(quit)
          break;
      }
      

      if(which_menu == 1) {
        page1_1 = new USGenInfo(&course, &newStu, &stuType);
        cont = page1_1 -> initGenInfo();
        delete page1_1;
      }
      else if(which_menu == 2) {
        page1_2 = new GGenInfo(&course, &newStu, &stuType);
        cont = page1_2 -> initGenInfo();
        delete page1_2;
      }
      else nBreaker = index;

      if (cont) ++index;
      else nBreaker = index;
      
      break;
    case 2:
      //draw the related courses page

      page2 = new RCourses(course, &cRQueue);
      cont = page2 -> initRCourses();
      delete page2;

      if (cont) ++index;
      else nBreaker = index;

      break;
    case 3:
      //draw the ta courses page

      page3 = new TCourses(course, &tACQueue);
      cont = page3 -> initTCourses();
      delete page3;

      if (cont) ++index;
      else nBreaker = index;

      break;
    case 4:
      //draw the relevant work exp page
      
      page4 = new RWExp(course, &wEQueue);
      reset = page4 -> initRWExp();
      delete page4;

      if(reset > 0) {cont = true; ++index;}
      else if(reset == 0) {cont = false; ++index;}
      else if(reset < 0) cont = false;

      if(!cont && index <= 4) {nBreaker = index; notValid(); }
      
      break;
    case 5:
      if(cont) {index = 1; allValid();}
      else if(!cont) {nBreaker = index; allValid();}
      
      break;

    default:
      break;
  }

}

////////////////////////////////////////////////////////////
//<summary> All is valid, allocate memory and store into  //
//          new application and add it to Queue </summary>//
////////////////////////////////////////////////////////////
int Form::allValid()
{
  //Add the valid application to the Queue
  //GOING TO NEED AN INT WHICH WILL TELL WHAT TYPE OF STUDENT
  newApp = new Application(course, "pending", newStu, stuType, cRQueue, tACQueue, wEQueue);

  if((*applications) == 0)
    (*applications) = new ApplicationQueue;

  (*applications) -> pushBack(newApp);

  return 0;
}

////////////////////////////////////////////////////////////
//<summary> User wanted to cancel, deallocate all memory  //
//                                          </summary>    //
////////////////////////////////////////////////////////////
int Form::notValid()
{
  //For now, nothing, add deallocation later
  nBreaker = index;

  delete newStu;

  if (cRQueue != 0)
  while(!(cRQueue -> empty()))
  {
    cRQueue -> popFront();
  }

  if (tACQueue != 0)
  while(!(tACQueue -> empty()))
  {
    tACQueue -> popFront();
  }

  if (wEQueue != 0)
  while(!(wEQueue -> empty()))
  {
    wEQueue -> popFront();
  }

  

}

////////////////////////////////////////////////////////////
//<summary> Creates the form                    </summary>//
////////////////////////////////////////////////////////////  
void Form::initForm()
{
  clear();

  while(1)
  { 
    update();

    if(nBreaker != 0)
      break;
  }
  
  noecho();
  clear();
  mvprintw(2, 0, "Returning to student Menu, press any key\n");
  refresh();
  getch();
}
