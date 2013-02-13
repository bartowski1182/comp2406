#include "Form.h"
using namespace std;

MainScreen::MainScreen(std::string s) : index(1), nBreaker(0)
{
  labels[0] = "Main Menu";
  labels[1] = "Select Role: ";
  labels[2] = "Student";
  labels[3] = "Administrator";
  labels[4] = "Exit";

}

Form::~Form()
{
}

int MainScreen::getIndex() const { return index; }

////////////////////////////////////////////////////////////////////////////
//<summary> Creates the GUI... draws the labels and textfields  </summary>//
////////////////////////////////////////////////////////////////////////////
void Form::drawForm(int selection)
{
  int x, lx, y, ly, i;
  char *c;

  x = 24;
  y = 4;
  ly = 4;
  lx = 2;




  for(i = 0; i < 5; i++) //Draw the labels for the text fields
  {
    Util::stringToChar(labels[i], &c);
    
    
    mvprintw(ly, lx, "%s", c);
    refresh();
    

    ++ly;

    delete[] c;
  }



  move(LINES - 2, 0);
}
////////////////////////////////////////////////////////////////////
//<summary> Deal with any character the user might input</summary>//
////////////////////////////////////////////////////////////////////
int Form::handleInput(char c)
{

  switch(c)
    {
      case (char)KEY_UP: //FOR UP KEY
        if (getIndex() == 1)
          index = 1;
        else
          --index;
        break;

      case (char)KEY_LEFT: //FOR LEFT KEY
        if (getIndex() == 1)
          index = 1;
        else
          --index;
        break;

      case (char)KEY_RIGHT: //FOR RIGHT KEY
        if (getIndex() == NUM_CHOI)
          index = NUM_CHOI;
        else
          ++index;
        break;

      case (char)KEY_DOWN: //FOR DOWN KEY
        if(getIndex() == NUM_CHOI)
          index = NUM_CHOI;
        else
          ++index;
        break;

      case (char)KEY_F(2): //FOR F2 KEY, USER WOULD LIKE TO EXIT
        nBreaker = getIndex();
        break;

      case (char)'\r':  //If ENTER KEY IS HIT
        printw("%d is the index when Enter was pressed\n", getIndex());
        handleSelection(c);
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
int Form::handleSelection(char c)
{
  
  else
  {
    if(getIndex() == 9) { 
		return nBreaker = getIndex(); 
	}
    if(getIndex() == 10) { 
		printw("DIS USA AWNNA ACCEPT"); 
		printw("Data correct");
		}
	
	}
    printw("   Index is %d", getIndex());
    
    
  }
}

////////////////////////////////////////////////////////////
//<summary> Creates the form                    </summary>//
////////////////////////////////////////////////////////////  
void Form::initForm()
{

  char c;

  drawForm(getIndex());

  while(1)
  {
    c = getch();
    
    handleInput(c); //Will deal with any input the user provides
    
    drawForm(getIndex()); //Redraw the UI based on any changes made by the user

    if(nBreaker != 0)
      break;
  }
  
  noecho();
  mvprintw(LINES - 2, 0, "Program over, press any key\n");
  refresh();
  getch();
}
