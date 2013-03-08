#include"CutaesStudentMenu.h"
using namespace std;

CutaesStudentMenu::CutaesStudentMenu(ApplicationQueue **aq) : index(1), nBreaker(0), form(0)
{
  applications = aq;

  labels[0] = "Create an Application";
  labels[1] = "Edit an Application";
  labels[2] = "Back to Main Menu";

}

CutaesStudentMenu::~CutaesStudentMenu()
{

}


////////////////////////////////////////////////////////////////////////////
//<summary> Creates the GUI... draws the labels and textfields  </summary>//
////////////////////////////////////////////////////////////////////////////
void CutaesStudentMenu::drawStudentMenu(int selection)
{
  clear();

  
  mvprintw(5, 20, "----------------------------------------");
  mvprintw(6, 20, "--------      Student Menu     ---------");
  mvprintw(7, 20, "----------------------------------------");

  int lx, ly, i;
  char c[31];

  ly = 10;
  lx = COLS/ 2 - 12;

  for(i = 0; i < 3; i++) //Draw the options for the Student Menu
  {
    for(int j = 0; j < 30; j++)
    {
      if(j < labels[i].length())
        c[j] = labels[i][j];
      else
        c[j] = 0;
    }
    c[31] = 0;

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

  move(LINES - 2, 0);
}


////////////////////////////////////////////////////////////////////
//<summary> Deal with any character the user might input</summary>//
////////////////////////////////////////////////////////////////////
int CutaesStudentMenu::handleInput(char c)
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
int CutaesStudentMenu::handleSelection(int selection)
{

  switch(selection)
  {
    case 1: //Create an Application
      
      form = new Form(applications);
      form -> initForm();
      delete form;

      break;

    case 2:
      break;

    case 3:
      nBreaker = index  + 1;
      break;

    default:
      break;
  }

  return 1;
}

////////////////////////////////////////////////////////////
//<summary> Creates the form                    </summary>//
////////////////////////////////////////////////////////////  
int CutaesStudentMenu::initStudentMenu()
{
  clear();

  char c;

  drawStudentMenu(index);

  while(1)
  {
    c = getch();
    
    handleInput(c); //Will deal with any input the user provides

    drawStudentMenu(index); //Redraw the UI based on any changes made by the user

    if(nBreaker != 0)
      break;
  }
  
  noecho();
}
