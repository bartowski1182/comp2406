#include "PendingOneCourse.h"

using namespace std;

PendingOneCourse::PendingOneCourse(ApplicationQueue **aq) : index(1), nBreaker(0), courseIndex(1), startViewApp(1),
                                                            endViewApp(15), currViewApp(1), applications(aq), arraySize(0)
{

  //WELCOME TO ADMIN MENU
  //PRESS 1 TO VIEW AN APPLICATION
  //PRESS 2 TO ASSIGN A SUCCESSFUL APPLICANT

  labels[0] = "/\\";
  labels[1] = "\\/";
  labels[2] = "Back";

}

PendingOneCourse::~PendingOneCourse()
{
  delete[] courseList;
}


////////////////////////////////////////////////////////////////////////////
//<summary> Creates the GUI... draws the labels and textfields  </summary>//
////////////////////////////////////////////////////////////////////////////
void PendingOneCourse::drawPendOCourse(int selection)
{
  clear();

  int lx, ly, i;
  char c[100];

  
  for(int j = 0; j < 45; j++)
  {
    if(j < course.length())
      c[j] = course[j];
    else
      c[j] = 0;
  }
  c[46] = 0;

  
  mvprintw(2, 2, "Summary for %s Course", c);
  mvprintw(3, 2, "-----------------------");

  ly = 10;
  lx = COLS/ 2 - 18;

  for(i = 0; i < 3; i++) //Draw the options for the Student Menu
  {
    for(int j = 0; j < 45; j++)
    {
      if(j < labels[i].length())
        c[j] = labels[i][j];
      else
        c[j] = 0;
    }
    c[46] = 0;
    
    if (i == 0) { ly = 5; lx = COLS - 5; }
    if (i == 1) { ly = LINES - 5; lx = COLS - 5; }
    if (i == 2) { ly = LINES - 2; lx = 10; }
    
    if(selection == i + 1)
    {
      attron(A_REVERSE);
      mvprintw(ly, lx, "%s", c);
      refresh();
      attroff(A_REVERSE);
    }
    else
    {
      mvprintw(ly, lx, "%s", c);
      refresh();
    }

    ++ly;
  }

  ///////////////////////////////////////////////////////////////
  //For actual pending applications summaries
  mvprintw(currViewApp + 4, 6, "THIS IS A SENTENCE");
  mvprintw(LINES - 1, 0, "currViewApp is %d", currViewApp);
  if (applications != 0) {
    for(int i = 0; i < arraySize; i++)
    {
      if (appArray[i] -> getCourse() == course)
      {

        //mvprintw(currViewApp + 5, 6, );
      }
    }
  }

  move(LINES - 2, 0);
}

////////////////////////////////////////////////////////////////////
//<summary> Draws the course selector view </summary>             //
////////////////////////////////////////////////////////////////////
int PendingOneCourse::drawCourseView(int selection)
{
  int x, y, i;
  char c[12];

  mvprintw(1, 3, "Courses: \n");
  mvprintw(2, 3, "--------\n");

  x = 24;
  y = 4;

  for(i = 0; i < 24; i++) //Draw the labels for the text fields
  {
    if(i % 6 == 0) y = 4;
    
    for(int j = 0; j < 12; j++)
    {
      if(j < courseList[i].length())
        c[j] = courseList[i][j];
      else
        c[j] = 0;
    }
    c[12] = 0;

    if(i + 1 < 7) x = 4;
    else if(i + 1 < 13) x = 18;
    else if(i + 1 < 19) x = 32;
    else x = 46;

    if(selection == i + 1)
    {
      attron(A_REVERSE);
      mvprintw(y, x, "%s", c);
      refresh();
      attroff(A_REVERSE);
    }
    else
    {
      mvprintw(y, x, "%s", c);
      refresh();
    }

    ++y;
  }

  move(LINES - 2, 0);
}


////////////////////////////////////////////////////////////////////
//<summary> Deal with any character the user might input</summary>//
////////////////////////////////////////////////////////////////////
int PendingOneCourse::handleInput(char c)
{
  
  switch(c)
    {
      case (char)KEY_UP: //FOR UP KEY
        if (index == 1)
          index = 1;
        else
          --index;
        break;

      case (char)KEY_LEFT: //FOR LEFT KEY
        if (index == 1)
          index = 1;
        else
          --index;
        break;

      case (char)KEY_RIGHT: //FOR RIGHT KEY
        if (index == 3)
          index = 3;
        else
          ++index;
        break;

      case (char)KEY_DOWN: //FOR DOWN KEY
        if(index == 3)
          index = 3;
        else
          ++index;
        break;

      case (char)KEY_F(2): //FOR F2 KEY, USER WOULD LIKE TO EXIT
        nBreaker = index + 1;
        break;

      case (char)'\r':
        handleSelection(index);
        printw("Enter was presssed\n");
        break;

      default:
        printw("%c was entered\n", c);
        break;
    }

  return c;

}

///////////////////////////////////////////////////////////
//<summary> Figures out what to do based on index's      //
//          value  </summary>                            //
///////////////////////////////////////////////////////////
int PendingOneCourse::handleSelection(int selection)
{

  switch(selection)
  {
    case 1: //up arrow
      if (currViewApp != startViewApp) {
        currViewApp --;
      }
      break;

    case 2: //down arrow
      if (currViewApp != endViewApp) {
        currViewApp ++;
      }
      break;
 
    case 3:
      nBreaker = selection;
      break;
   
    case (char)KEY_F(2):
      nBreaker = 50;
      break;

    default:
      break;
  }

  return 1;
}


////////////////////////////////////////////////////////////////////
//<summary> Draw the list of courses </summary>                   //
////////////////////////////////////////////////////////////////////
int PendingOneCourse::initCourseView()
{
  clear();
  
  char c;
  int breaker = 0;

  drawCourseView(courseIndex);

  while(1)
  {
    c = getch();

    switch(c)
    {
      case (char)KEY_UP: //FOR UP KEY
        if (courseIndex == 1)
          courseIndex = 1;
        else
          --courseIndex;
        break;

      case (char)KEY_LEFT: //FOR LEFT KEY
        if (courseIndex == 1)
          courseIndex = 1;
        else
          if(courseIndex - 6 < 1)
            courseIndex = 1;
          else
            courseIndex = courseIndex - 6;
        break;

      case (char)KEY_RIGHT: //FOR RIGHT KEY
        if (courseIndex == 24)
          courseIndex = 24;
        else
          if(courseIndex + 6 > 24)
            courseIndex = 24;
          else
            courseIndex = courseIndex + 6;
        break;

      case (char)KEY_DOWN: //FOR DOWN KEY
        if(courseIndex == 24)
          courseIndex = 24;
        else
          ++courseIndex;
        break;

      case (char)'\r':
        course = courseList[courseIndex - 1];
        breaker = courseIndex;
        break;

      default:
        break;
    }

    
    drawCourseView(courseIndex);

    if(breaker != 0)
      break;
  }
  
  --courseIndex;
  clear();
  return 0;
}


////////////////////////////////////////////////////////////
//<summary> Creates the form                    </summary>//
////////////////////////////////////////////////////////////  
void PendingOneCourse::initPendOCourse()
{
  clear();

  load = new CourseLoader("courselist.txt");
  load -> loadCourses(&courseList);
  delete load;

  mvprintw(LINES - 2, 0, "Before I'm doing the array thing %d\n", index);
  getch();
  
  if (*applications != 0)
    arraySize = (*applications) -> setQueueIntoArray(&appArray);

  mvprintw(LINES - 3, 0, "After the array thing %d\n", arraySize);
  getch();

  char c;

  initCourseView();

  mvprintw(LINES - 2, 0, "Index is currently %d\n", index);
  getch();

  drawPendOCourse(index);

  while(1)
  {
    c = getch();
    
    handleInput(c); //Will deal with any input the user provides

    drawPendOCourse(index); //Redraw the UI based on any changes made by the user

    if(nBreaker != 0)
      break;
  }
  
  noecho();
}
