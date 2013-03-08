#include"PendingChoose.h"
using namespace std;

PendingChoose::PendingChoose() : index(1), nBreaker(0)
{

  //WELCOME TO ADMIN MENU
  //PRESS 1 TO VIEW AN APPLICATION
  //PRESS 2 TO ASSIGN A SUCCESSFUL APPLICANT

  labels[0] = "One Course";
  labels[1] = "Multiple Courses";

}

PendingChoose::~PendingChoose()
{

}


////////////////////////////////////////////////////////////////////////////
//<summary> Creates the GUI... draws the labels and textfields  </summary>//
////////////////////////////////////////////////////////////////////////////
void PendingChoose::drawPendChoose(int selection)
{
  clear();
  
  mvprintw(5, 20, "Would you like to see Pending Applications for...");

  int lx, ly, i;
  char c[46];

  ly = 10;
  lx = COLS/ 2 - 18;

  for(i = 0; i < 2; i++) //Draw the options for the Student Menu
  {
    for(int j = 0; j < 45; j++)
    {
      if(j < labels[i].length())
        c[j] = labels[i][j];
      else
        c[j] = 0;
    }
    c[46] = 0;

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
int PendingChoose::handleInput(char c)
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
        if (index == 2)
          index = 2;
        else
          ++index;
        break;

      case (char)KEY_DOWN: //FOR DOWN KEY
        if(index == 2)
          index = 2;
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
int PendingChoose::handleSelection(int selection)
{

  switch(selection)
  {
    case 1: //
      nBreaker = selection;
      break;

    case 2:
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

////////////////////////////////////////////////////////////
//<summary> Creates the form                    </summary>//
////////////////////////////////////////////////////////////  
int PendingChoose::initPendChoose()
{
  clear();

  char c;

  drawPendChoose(index);

  while(1)
  {
    c = getch();
    
    handleInput(c); //Will deal with any input the user provides

    drawPendChoose(index); //Redraw the UI based on any changes made by the user

    if(nBreaker != 0)
      break;
  }
  
  noecho();

  return nBreaker;
}
