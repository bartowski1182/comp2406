#include "GenInfo.h"
using namespace std;

GenInfo::GenInfo(std::string* s, Student** stu) : index(1), course(s), nBreaker(0), newStu(stu), courseList(0), courseIndex(1), cancel(false)
{

  labels[0] = "First Name:";
  labels[1] = "Last Name:";
  labels[2] = "Student Number:";
  labels[3] = "Email:";
  labels[4] = "Major:";
  labels[5] = "Year Standing:";
  labels[6] = "CGPA:";
  labels[7] = "Major GPA:";
  labels[8] = "Cancel";
  labels[9] = "Accept";


  if((*newStu) != 0){
    mvprintw(LINES - 2, 0, "newStu is not zero!\n");
    
    textFields[0] = (*newStu) -> getFirstName();
    textFields[1] = (*newStu) -> getLastName();
    textFields[2] = (*newStu) -> getNum();
    textFields[3] = (*newStu) -> getEmail();
    textFields[4] = ((UndergradStudent*)(*newStu)) -> getMajor();
    textFields[5] = ((UndergradStudent*)(*newStu)) -> getYear();
    textFields[6] = ((UndergradStudent*)(*newStu)) -> getCGPA();
    textFields[7] = ((UndergradStudent*)(*newStu)) -> getMGPA();
  }
  else if ((*newStu) == 0)
  {

    for(int i = 0; i < 8; i++)
      textFields[i] = "";
  }
}

GenInfo::~GenInfo()
{
  delete[] courseList;
}

////////////////////////////////////////////////////////////////////////////
//<summary> Creates the GUI... draws the labels and textfields  </summary>//
////////////////////////////////////////////////////////////////////////////
void GenInfo::drawGenInfo(int selection)
{
  int x, lx, y, ly, i;
  char c[GIMAX_BUF + 1];


  char ccourse[GIMAX_BUF + 1];
  for(int i = 0; i < GIMAX_BUF; i++)
  {
    if(i < course -> length())
      ccourse[i] = (*course)[i];
    else
      ccourse[i] = 0;
  }
  ccourse[GIMAX_BUF] = 0;

  mvprintw(0, 0, "Why hello there, you are registering for: ");
  refresh();


  if (selection == 0)
  {
    attron(A_REVERSE);
    printw("%s\n", ccourse);
    refresh();
    attroff(A_REVERSE);
  }
  else
  {
    printw("%s\n", ccourse);
    refresh();
  }


  x = 24;
  y = 4;
  ly = 4;

  for(i = 0; i < GINUM_CHOI; i++) //Draw the labels for the text fields
  {
    for(int j = 0; j < GIMAX_BUF; j++)
    {
      if(j < labels[i].length())
        c[j] = labels[i][j];
      else
        c[j] = 0;
    }
    c[GIMAX_BUF] = 0;
    
    if(i > 7)
    {
      ly = LINES - 10;
      if(i == 8) { lx = COLS / 3; }
      else if (i == 9) { lx = 2 * COLS / 3; }
    }
    else
    {
      lx = 4;
    }

    if(selection > 8 && selection == i + 1)
    {
      if(selection == 9) { lx = COLS / 3; }
      else if(selection == 10) { lx = 2 * COLS / 3; }
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

  for(i = 0; i < GINUM_CHOI - 2; i++) //Draw the textFields
  {
    
    for(int j = 0; j < GIMAX_BUF; j++)
    {
      if(j < textFields[i].length()) {
        c[j] = textFields[i][j];
      }
      else
        c[j] = 0;
    }
    c[GIMAX_BUF] = 0;

    move (LINES - 3, 0);
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
      //mvprintw(y, x + 20, "Size: %d", textFields[i].length());
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
int GenInfo::drawCourseView(int selection)
{
  int x, y, i;
  char c[GIMAX_BUF + 1];

  mvprintw(1, 3, "Courses: \n");
  mvprintw(2, 3, "--------\n");

  x = 24;
  y = 4;

  for(i = 0; i < 24; i++) //Draw the labels for the text fields
  {
    if(i % 6 == 0) y = 4;
    
    for(int j = 0; j < GIMAX_BUF; j++)
    {
      if(j < courseList[i].length())
        c[j] = courseList[i][j];
      else
        c[j] = 0;
    }
    c[GIMAX_BUF] = 0;

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
int GenInfo::handleInput(char c)
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
        if (index == GINUM_CHOI)
          index = GINUM_CHOI;
        else
          ++index;
        break;

      case (char)KEY_DOWN: //FOR DOWN KEY
        if(index == GINUM_CHOI)
          index = GINUM_CHOI;
        else
          ++index;
        break;

      case (char)KEY_F(2): //FOR F2 KEY, USER WOULD LIKE TO EXIT
        cancel = true;
        nBreaker = index + 1;
        break;

      case (char)KEY_F(3): //FOR F3 KEY, SHORTCUT FOR DEBUG
        textFields[0] = "Yugo";
        textFields[1] = "Yugo";
        textFields[2] = "Yugo";
        textFields[3] = "Yugo";
        textFields[4] = "Yugo";
        textFields[5] = "Yugo";
        textFields[6] = "Yugo";
        textFields[7] = "Yugo";
        handleAccept();
        nBreaker = index;
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
int GenInfo::handleSelection(int selection)
{
  if(index == 0)
  {
    initCourseView(selection);
  }
  else if(index > 0 && index < 9)
  {
    char cInput[GIMAX_BUF], c[GIMAX_BUF + 1];
    
    for(int j = 0; j < GIMAX_BUF; j++)
    {
      if(j < labels[selection - 1].length()) {
        c[j] = labels[selection - 1][j];
      }
      else
        c[j] = 0;
    }
    c[GIMAX_BUF] = 0;
    
    mvprintw(LINES - 1, 0, "\n"); //Line clear
    mvprintw(LINES - 1, 0, "%s ", c);
    echo();
    getnstr(cInput, GIMAX_BUF);
    noecho();

    string sInput;
    sInput.assign(cInput);
    textFields[index - 1].assign(sInput);
  }
  else
  {
    if(index == 9) { cancel = true; return nBreaker = index; }
    if(index == 10) {  handleAccept(); }
  }

  return 1;
}

////////////////////////////////////////////////////////////
//<summary> Calls error checking functions to make sure   //
//          that the textFields are valid.  </summary>    //
////////////////////////////////////////////////////////////
int GenInfo::handleAccept()
{
  /*This is where we would do all the checking, have *
   *a boolean that would go false if one of the      *
   *input checkers returned false, set the data only *
   *if the boolean remains true.*/
  //But for now...

  bool canSet = true;
  bool testPassed = true;

  //CHECKING DOESN'T WORK RIGHT NOW
  /*
  mvprintw(LINES - 4, 0, "Size of textFields is %d", textFields[0].length());

  canSet = Student::canSetFirstName("Yugo");
  if (!canSet) testPassed = false; mvprintw(LINES - 2, 0, "First Name is invalid\n"); return -1;
  
  canSet = Student::canSetLastName(textFields[1]);
  if (!canSet) testPassed = false; mvprintw(LINES - 2, 0, "Last Name is invalid\n"); return -1;
 
  canSet = Student::canSetStudentNumber(textFields[2]);
  if (!canSet) testPassed = false; mvprintw(LINES - 2, 0, "Student # is invalid\n"); return -1;

  canSet = Student::canSetEmail(textFields[3]);
  if (!canSet) testPassed = false; mvprintw(LINES - 2, 0, "Email is invalid\n"); return -1;
  
  canSet = Student::canSetMajor(textFields[4]);
  if (!canSet) testPassed = false; mvprintw(LINES - 2, 0, "Major is invalid\n"); return -1;

  canSet = Student::canSetYear(textFields[5]);
  if (!canSet) testPassed = false; mvprintw(LINES - 2, 0, "Year Standing is invalid\n"); return -1;

  canSet = Student::canSetCGPA(textFields[6]);
  if (!canSet) testPassed = false; mvprintw(LINES - 2, 0, "CGPA is invalid\n"); return -1;

  canSet = Student::canSetMGPA(textFields[7]);
  if (!canSet) testPassed = false; mvprintw(LINES - 2, 0, "MGPA is invalid\n"); return -1;
  */
  
  for(int i = 0; i < GINUM_CHOI - 2; i++)
  {
    if(textFields[i].length() == 0) {
      testPassed = false;
      mvprintw(LINES - 3, 0, "Some Fields are left blank");
    }
  }

  if(testPassed)
  {
    *newStu = new UndergradStudent(textFields[0], textFields[1], textFields[2], textFields[3],
                                   textFields[4], textFields[5], textFields[6], textFields[7]);
    mvprintw(LINES - 2, 0, "Student has successfully been created!");
    nBreaker = index;
    return 1;
  }
  else
  {
    mvprintw(LINES - 1, 0, "Student was not able to be created");
  }

  return -1;
}


////////////////////////////////////////////////////////////////////
//<summary> Draw the list of courses </summary>                   //
////////////////////////////////////////////////////////////////////
int GenInfo::initCourseView(int prevIndex)
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
bool GenInfo::initGenInfo()
{
  clear();

  load = new CourseLoader("courselist.txt");

  load -> loadCourses(&courseList);
  delete load;

  char c;

  *course = courseList[courseIndex];

  drawGenInfo(index);

  while(1)
  {
    c = getch();
    
    handleInput(c); //Will deal with any input the user provides

    *course = courseList[courseIndex];
    
    drawGenInfo(index); //Redraw the UI based on any changes made by the user

    if(nBreaker != 0)
      break;
  }
  
  noecho();
  if (cancel) return false;
  if (newStu != 0)
    return true;
  else return false;
}
