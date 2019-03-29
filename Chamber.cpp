
/*This class usees the Chamber.h header file functions*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Chamber.h"

using namespace std;

namespace proj_Connect4Game
{
  //evaluating our first constructor having no parameters
  Chamber::Chamber()
  {
    //initializing the data values to empty.
    pos_row  =  0;
    state_chamber = 0;
    pos_chamber = ' ';
  }

  // chamber position assigning in constructor.
  Chamber::Chamber(const char& chamber_PosNew)
  {
    //assign new position to this value of chamber position
    pos_chamber = chamber_PosNew;
    //initializing rows and chamber state to zero.
    pos_row = 0;
    state_chamber = 0;
  }

  // assign row position in the below constructor.
  Chamber::Chamber(const int& Horiz_PosNew)
  {
    //make empty declaration to both chamber position and state chamber.
    pos_chamber = ' ';
    //assign new value to horizontal Position.
    pos_row = Horiz_PosNew;
    state_chamber = 0;
  }

  // assigning chamber and row position in constructor below
  Chamber::Chamber(const char& chamber_PosNew, const int& Horiz_PosNew)
  {
    pos_chamber = chamber_PosNew;
    pos_row  =  Horiz_PosNew;
    //zero declaration of chamber state.
    state_chamber = 0;
  }

  // assigning all three values, the new values through constructor.
  Chamber::Chamber(const int& State_Chamber_N,const char& chamber_PosNew, const int& Horiz_PosNew)
  {
    state_chamber = State_Chamber_N;
    pos_chamber = chamber_PosNew;
    pos_row =  Horiz_PosNew;
  }

  // function for chamber position value.
  void Chamber::Pos_Chamber_set(const char& chamber_PosNew)
  {
    // condition for chamber position
    // If user enter some invalid then warn him/her and exit.
    if(chamber_PosNew > 'Z')
    {
        cout << "Invalid postion of chamber is entered.. " << endl;
        exit(1);
    }
    else {
        //store entered position to the variable.
        pos_chamber = chamber_PosNew;
    }
  }

  // Function for fow postion.
  void Chamber::Pos_row_set(const int& Horiz_PosNew)
  {
    // condition for illegal number.
    if(Horiz_PosNew < 0)
    {
        cout << "Invalid Row Position " << endl;
        exit(1);
    }
    else
    //assigning the new postion
        pos_row = Horiz_PosNew;
  }

//function for setting chamber state.
  void Chamber::state_chamber_set(const int& State_Chamber_N)
  {
    state_chamber = State_Chamber_N;
  }

  // function for getting chamber state
  int  Chamber::state_chamber_get() const
  {
    //return integer valued state of the chamber.
    return state_chamber;
  }

  // function for setting chamber position aswell as that of row.
  void Chamber::Pos_Set_whole(const char& chamber_PosNew,const int& Horiz_PosNew)
  {
    //assigning new variables to these given.
    pos_chamber =  chamber_PosNew;
    pos_row  =  Horiz_PosNew;
  }

  // function that gets Chamber Position value.
  char  Chamber::Pos_chamber_get() const
  {
    return pos_chamber;
  }

  // function for position of row value
  int Chamber::Pos_row_get() const
  {
    return pos_row;
  }

} // proj_Connect4Game
