#include "RCourses.h"
using namespace std;

RCourses::RCourses(std::string s, CourseRelatedQueue **aq) : index(1), course(s), nBreaker(0), relatedCourse(s), courseIndex(1), cRHead(aq), cancel(false)
{
  labels[0] = "Term:";
  labels[1] = "Year:";
  labels[2] = "Final Grade:";
  labels[3] = "Cancel";
  labels[4] = "Accept";
  labels[5] = "Add";

  for(int i = 0; i < RCNUM_CHOI - 3; i++)
    textFields[i] = "";

}

RCourses::~RCourses()
{
  delete[] courseList;
}

////////////////////////////////////////////////////////////////////////////
//<summary> Creates the GUI... draws the labels and textfields  </summary>//
////////////////////////////////////////////////////////////////////////////
void RCourses::drawRCourses(int selection)
{
  char ccourse[RCMAX_BUF + 1];
  for(int i = 0; i < RCMAX_BUF; i++)
  {
    if(i < course.length())
      ccourse[i] = course[i];
    else
      ccourse[i] = 0;
  }
  ccourse[RCMAX_BUF] = 0;

  mvprintw(0, 0, "Why hello there, you are registering for: %s\n", ccourse);
  refresh();


  int x, lx, y, ly, i;
  char c[RCMAX_BUF + 1];
  
  mvprintw(3, 8, "Related Course: ");

  for(int j = 0; j < RCMAX_BUF; j++)
  {
    if(j < relatedCourse.length())
      c[j] = relatedCourse[j];
    else
      c[j] = 0;
  }

  if (selection == 0)
  {
    attron(A_REVERSE);
    mvprintw(3, 24, "%s", c);
    refresh();
    attroff(A_REVERSE);
  }
  else
  {
    mvprintw(3, 24, "%s", c);
    refresh();
  }
  

  x = 24;
  y = 6;
  ly = 6;

  for(i = 0; i < RCNUM_CHOI; i++) //Draw the labels for the text fields
  {
    for(int j = 0; j < RCMAX_BUF; j++)
    {
      if(j < labels[i].length())
        c[j] = labels[i][j];
      else
        c[j] = 0;
    }
    c[RCMAX_BUF] = 0;
    
    if(i > 2)
    {
      ly = LINES - 10;
      if(i == 3) { lx = COLS / 4; }
      else if (i == 4) { lx = COLS / 2; }
      else if (i == 5) { lx = 3 * COLS / 4; }
    }
    else
    {
      lx = 4;
    }

    if(selection > 3 && selection == i + 1)
    {
      if(selection == 4) { lx = COLS / 4; }
      else if(selection == 5) { lx = COLS / 2; }
      else if(selection == 6) { lx = 3 * COLS / 4; }
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

  for(i = 0; i < RCNUM_CHOI - 3; i++) //Draw the textFields
  {

    for(int j = 0; j < RCMAX_BUF; j++)
    {
      if (j < textFields[i].length())
        c[j] = textFields[i][j];
      else
        c[j] = 0;

    }
    c[RCMAX_BUF] = 0;

    if(selection == i+1)
    {
      attron(A_REVERSE);

      if(textFields[i].length() == 0)
        mvprintw(y, x, "          ");
      else
        mvprintw(y, x, "%s\n", c);

      refresh();
      attroff(A_REVERSE);
    }
    else
    {
      mvprintw(y, x, "%s\n", c);
      refresh();
    }

    c[0] = 0;
    
    ++y;
  }

  move(LINES - 2, 0);
}

////////////////////////////////////////////////////////////////////
//<summary> Draws the course selector view </summary>             //
////////////////////////////////////////////////////////////////////
int RCourses::drawCourseView(int selection)
{
  int x, y, i;
  char c[RCMAX_BUF + 1];

  mvprintw(1, 3, "Courses: \n");
  mvprintw(2, 3, "--------\n");

  x = 24;
  y = 4;

  for(i = 0; i < 24; i++) //Draw the labels for the text fields
  {
    if(i % 6 == 0) y = 4;
    
    for(int j = 0; j < RCMAX_BUF; j++)
    {
      if(j < courseList[i].length())
        c[j] = courseList[i][j];
      else
        c[j] = 0;
    }
    c[RCMAX_BUF] = 0;

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
int RCourses::handleInput(char c)
{

  switch(c)
    {
      case (char)KEY_UP: //FOR UP KEY
        if (index == 0)
          index = 0;
        else
          --index;
        break;

      case (char)KEY_LEFT: //FOR LEFT KEY
        if (index == 0)
          index = 0;
        else
          --index;
        break;

      case (char)KEY_RIGHT: //FOR RIGHT KEY
        if (index == RCNUM_CHOI)
          index = RCNUM_CHOI;
        else
          ++index;
        break;

      case (char)KEY_DOWN: //FOR DOWN KEY
        if(index == RCNUM_CHOI)
          index = RCNUM_CHOI;
        else
          ++index;
        break;

      case (char)KEY_F(2): //FOR F2 KEY, USER WOULD LIKE TO EXIT
        cancel = true;
        nBreaker = index + 1;
        break;

      case (char)KEY_F(3): //FOR F2 KEY, USER WOULD LIKE TO EXIT
        textFields[0] = "first";
        textFields[1] = "first";
        textFields[2] = "first";
        handleAccept();
        break;

      case (char)'\r':  //If ENTER KEY IS HIT
        printw("%d is the index when Enter was pressed\n", index);
        handleSelection(index);
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
int RCourses::handleSelection(int selection)
{
  if(index == 0) initCourseView(selection);
  if(index > 0 && index < 4)
  {
    char cInput[RCMAX_BUF], c[RCMAX_BUF + 1];
    
    for(int j = 0; j < RCMAX_BUF; j++)
    {
      if(j < labels[selection - 1].length()) {
        c[j] = labels[selection - 1][j];
      }
      else
        c[j] = 0;
    }
    c[RCMAX_BUF] = 0;
    
    mvprintw(LINES - 1, 0, "\n"); //Line clear
    mvprintw(LINES - 1, 0, "%s ", c);
    echo();
    getnstr(cInput, RCMAX_BUF);
    noecho();

    string sInput;
    sInput.assign(cInput);

    textFields[index - 1].assign(sInput);
  }
  else
  {
    if(index == 4) { cancel = true; return nBreaker = index; }
    if(index == 5) { handleAccept(); }
    if(index == 6) { handleAdd(); }
  }

  return 1;
}

////////////////////////////////////////////////////////////
//<summary> Resets the text fields and adds a node to the //
//          Queue of Course Related </summary>            //
////////////////////////////////////////////////////////////
int RCourses::handleAdd()
{
  /*Do */
  printw("DIS USA WANNA ADD");


  checkValid();
  if(newCR != 0)
  {
    if((*cRHead) == 0)
      (*cRHead) = new CourseRelatedQueue;
    
    (*cRHead) -> pushBack(newCR);
  }

  for(int i = 0; i < RCNUM_CHOI - 3; i++)
    textFields[i] = "";
  
  return 1;

}

////////////////////////////////////////////////////////////
//<summary> Calls error checking functions to make sure   //
//          that the textFields are valid.  </summary>    //
////////////////////////////////////////////////////////////
int RCourses::handleAccept()
{
  /*This is where we would do all the checking, have *
   *a boolean that would go false if one of the      *
   *input checkers returned false, set the data only *
   *if the boolean remains true.*/
  //But for now...
  mvprintw(LINES - 4, 0, "DIS USA AWNNA ACCEPT");

  checkValid();
  if(newCR != 0)
  {
    if((*cRHead) == 0)
      (*cRHead) = new CourseRelatedQueue;
    
    (*cRHead) -> pushBack(newCR);

    nBreaker = index;
  }

  return 1;
}

//////////////////////////////////////////////////////////////////////
//<summary> Checks to make sure every text field is valid </summary>//
//////////////////////////////////////////////////////////////////////
CourseRelated* RCourses::checkValid()
{
  //Would usually check every input, no time so just checking to see if the user has
  //filled something out

  bool canSet = true;
  bool testPassed = true;
  
  for(int i = 0; i < RCNUM_CHOI - 3; i++)
  {
    if(textFields[i].length() == 0) {
      testPassed = false;
      newCR = 0;
      mvprintw(LINES - 3, 0, "Some Fields are left blank");
    }
  }

  if(testPassed)
  {
    newCR = new CourseRelated(relatedCourse, textFields[0], textFields[1], textFields[2]);
    mvprintw(LINES - 2, 0, "Course Related has successfully been created!");
    return newCR;
  }
  else
  {
    mvprintw(LINES - 1, 0, "Course Related was not able to be created");
  }

  return 0;


}

////////////////////////////////////////////////////////////////////
//<summary> Draw the list of courses </summary>                   //
////////////////////////////////////////////////////////////////////
int RCourses::initCourseView(int prevIndex)
{
  clear();
  
  char c;
  int breaker = 0;

  index = 0;

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
bool RCourses::initRCourses()
{
  clear();

  load = new CourseLoader("courselist.txt");

  load -> loadCourses(&courseList);
  delete load;


  char c;

  relatedCourse = courseList[courseIndex];

  drawRCourses(index);

  while(1)
  {
    c = getch();
    
    handleInput(c); //Will deal with any input the user provides
    
    relatedCourse = courseList[courseIndex];

    drawRCourses(index); //Redraw the UI based on any changes made by the user

    if(nBreaker != 0)
      break;
  }
  
  noecho();
  if (cancel) return false;
  if (newCR != 0)
  return true;
  else return false;
}
