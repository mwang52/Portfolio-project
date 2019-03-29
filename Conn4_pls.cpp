//function for the plus object handling.
#include <iostream>
#include <cstdlib>
#include <string>
#include "Conn4_pls.h"
#include "Conn4_abstrct.h"
#define MAXVAL 7
using std::cout;
using std::endl;

namespace proj_Connect4Game
{
   // constructor with empty parameter.
  Conn4_pls::Conn4_pls():Conn4_abstrct(){ }

  //this constructor calls base class constructor for object creation with some parameters.
  Conn4_pls::Conn4_pls(int wdth_, int Hght_, char Slct_Game_n)
  :Conn4_abstrct(wdth_,Hght_,Slct_Game_n){}

  //for player 1
  /*this is the condition for winning the game. Only when connected horizontally or vertically.*/
  void Conn4_pls::win_plr1()
  {
    //traversing through out the dashboard.
    for(int ii=0; ii<hght_curr_get(); ++ii)
    {
        for(int jj=0; jj<wdth_curr_get(); ++jj)
        {
          //condition for  moving from top to bottom
            if(game_borad_Pntr[ii][jj].state_chamber_get() == 1)
            {
              // traverse from top to bottom moving in horizontal direction.
              if(ii+3<hght_curr_get())
              {
                 if(game_borad_Pntr[ii+1][jj].state_chamber_get() == 1 && game_borad_Pntr[ii+2][jj].state_chamber_get() == 1 && game_borad_Pntr[ii+3][jj].state_chamber_get() == 1)
                 {
                    isGame_Win=true;
                    game_borad_Pntr[ii][jj].state_chamber_set(MAXVAL -1 );
                    game_borad_Pntr[ii+1][jj].state_chamber_set(MAXVAL -1 );
                    game_borad_Pntr[ii+2][jj].state_chamber_set(MAXVAL -1 );
                    game_borad_Pntr[ii+3][jj].state_chamber_set(MAXVAL -1 );
                    //display the dashboard of the game.
                    curnt_board_display();
                    cout <<endl<<"!!!!The Game is Over .." << endl;
                    cout <<"The Winner is --> Player 1 (X)"<<endl;
                    cout << "hope you enjoyed the Game."<<endl;
                    cout<< "Tnank you for your time..."<<endl;
                  }
              }
              // traverse from left to the right in vertical direction.
              if(jj + 3 <wdth_curr_get())
              {
                if(game_borad_Pntr[ii][jj+1].state_chamber_get() == 1 && game_borad_Pntr[ii][jj+2].state_chamber_get() == 1 && game_borad_Pntr[ii][jj+3].state_chamber_get() == 1)
                {
                   isGame_Win=true;
                   game_borad_Pntr[ii][jj].state_chamber_set(MAXVAL -1 );
                   game_borad_Pntr[ii][jj+1].state_chamber_set(MAXVAL -1 );
                   game_borad_Pntr[ii][jj+2].state_chamber_set(MAXVAL -1 );
                   game_borad_Pntr[ii][jj+3].state_chamber_set(MAXVAL -1 );
                   curnt_board_display();
                   cout <<endl<<"!!!!The Game is Over .." << endl;
                   cout <<"Winner is  --> Player 1 (X)"<<endl;
                   cout << "hope you enjoyed the Game."<<endl;
                   cout<< "Tnank you for your time..."<<endl;
                }
              }
            }
        }
    }
  }

  // winning states for the computer/user2 are shown below.
  // Only accept horizontally or vertically connected cells as the goal of the game.
  void Conn4_pls::plr2_comp_win()
  {
      for(int ii=0; ii<hght_curr_get(); ++ii)
      {
        for(int jj=0; jj<wdth_curr_get(); ++jj)
        {
          if(game_borad_Pntr[ii][jj].state_chamber_get() == 2)
          {
            // sliding from top to bottom in the horizontal direction.
            //condition for the horizontal direction.
            if(ii+3<hght_curr_get())
            {
              if(game_borad_Pntr[ii+1][jj].state_chamber_get() == 2 && game_borad_Pntr[ii+2][jj].state_chamber_get() == 2 && game_borad_Pntr[ii+3][jj].state_chamber_get() == 2)
              {
                isGame_Win2=true;
                game_borad_Pntr[ii][jj].state_chamber_set(MAXVAL);
                game_borad_Pntr[ii+1][jj].state_chamber_set(MAXVAL);
                game_borad_Pntr[ii+2][jj].state_chamber_set(MAXVAL);
                game_borad_Pntr[ii+3][jj].state_chamber_set(MAXVAL);
                curnt_board_display();

                switch(sel_Game_get()){
                  case 'P':
                          cout <<endl<<"!!!!The Game is Over .." << endl;
                          cout <<"Winner is  --> Player 2 (O)"<<endl;
                          cout << "hope you enjoyed the Game."<<endl;
                          cout<< "Tnank you for your time..."<<endl;
                  break;
                  case 'C':
                          cout <<endl<<"!!!!The Game is Over .." << endl;
                          cout <<"Winner is  --> Computer (O)"<<endl;
                          cout << "hope you enjoyed the Game."<<endl;
                          cout<< "Tnank you for your time..."<<endl;
                  break;
                  default:
                  break;
                }//end switch
              }
            }

            // traversing from the left side towards the right side by moving in the vertical direction.
            if(jj+ 3 < wdth_curr_get())
            {
             if(game_borad_Pntr[ii][jj+1].state_chamber_get() == 2 && game_borad_Pntr[ii][jj+2].state_chamber_get() == 2 && game_borad_Pntr[ii][jj+3].state_chamber_get() == 2)
             {
                isGame_Win2=true;
                game_borad_Pntr[ii][jj].state_chamber_set(MAXVAL);
                game_borad_Pntr[ii][jj+1].state_chamber_set(MAXVAL);
                game_borad_Pntr[ii][jj+2].state_chamber_set(MAXVAL);
                game_borad_Pntr[ii][jj+3].state_chamber_set(MAXVAL);
                curnt_board_display();

                switch(sel_Game_get()){
                  case 'P':
                          cout <<endl<<"!!!!The Game is Over .." << endl;
                          cout <<"Winner is  --> Player 2 (O)"<<endl;
                          cout << "hope you enjoyed the Game."<<endl;
                          cout<< "Tnank you for your time..."<<endl;
                  break;
                  case 'C':
                          cout <<endl<<"!!!!The Game is Over .." << endl;
                          cout <<"Winner is  --> Computer (O)"<<endl;
                          cout << "hope you enjoyed the Game."<<endl;
                          cout<< "Tnank you for your time..."<<endl;
                  break;
                  default:
                  break;
                }//end switch
             }
            }
          }
        }
      }
  }

}//proj_Connect4Game
