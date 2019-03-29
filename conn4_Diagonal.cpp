#include <iostream>
#include <cstdlib>
#include <string>
#include "conn4_Diagonal.h"
#include "Conn4_abstrct.h"
#define MAXVAL 7
//standards used in this code later.
using std::cout;
using std::endl;

namespace proj_Connect4Game
{

  // empty parameter constructor.
  conn4_Diagonal::conn4_Diagonal():Conn4_abstrct(){}

  //this constructor calls base class constructor for object creation with some parameters.
  conn4_Diagonal::conn4_Diagonal(int wdth_, int Hght_, char Slct_Game_n)
  :Conn4_abstrct(wdth_,Hght_,Slct_Game_n)
  {
  }

  //for player 1
  /*this is the condition for winning the game. Only when connected diagonally.*/
  void conn4_Diagonal::win_plr1()
  {
    //traversing through out the dashboard of the game.
    for(int ii=0; ii<hght_curr_get(); ++ii)
    {
        for(int jj=0; jj<wdth_curr_get(); ++jj)
        {
            if(game_borad_Pntr[ii][jj].state_chamber_get() == 1)
            {
              // travelling from left side to the right following the diagonal path.
                  if(ii  < hght_curr_get()- 3 && jj<wdth_curr_get()-3)
                  {
                      if(game_borad_Pntr[ii+1][jj+1].state_chamber_get() == 1 && game_borad_Pntr[ii+2][jj+2].state_chamber_get() == 1 && game_borad_Pntr[ii+3][jj+3].state_chamber_get() == 1)
                      {
                       isGame_Win=true;
                       game_borad_Pntr[ii][jj].state_chamber_set(MAXVAL -1);
                       game_borad_Pntr[ii+1][jj+1].state_chamber_set(MAXVAL -1);
                       game_borad_Pntr[ii+2][jj+2].state_chamber_set(MAXVAL -1);
                       game_borad_Pntr[ii+3][jj+3].state_chamber_set(MAXVAL -1);
                       curnt_board_display();

                       cout <<endl<<"!!!!The Game is Over .." << endl;
                       cout <<"Winner is  --> Player 1 (X)"<<endl;
                       cout << "hope you enjoyed the Game."<<endl;
                       cout<< "Tnank you for your time..."<<endl;


                      }
                  }

                  // travelling from the right side towards the left side following diagonal path.
                  if(ii  < hght_curr_get()- 3 && jj - 3 >= 0 )
                  {
                    if(game_borad_Pntr[ii+1][jj-1].state_chamber_get() == 1 && game_borad_Pntr[ii+2][jj-2].state_chamber_get() == 1 && game_borad_Pntr[ii+3][jj-3].state_chamber_get() == 1)
                    {
                       isGame_Win=true;
                       game_borad_Pntr[ii][jj].state_chamber_set(MAXVAL -1);
                       game_borad_Pntr[ii+1][jj-1].state_chamber_set(MAXVAL -1);
                       game_borad_Pntr[ii+2][jj-2].state_chamber_set(MAXVAL -1);
                       game_borad_Pntr[ii+3][jj-3].state_chamber_set(MAXVAL -1);
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
  // Only accept diagonally connected components of the game.
  void conn4_Diagonal::plr2_comp_win()
  {
      for(int ii=0; ii<hght_curr_get(); ++ii)
      {
        for(int jj=0; jj<wdth_curr_get(); ++jj)
        {
            if(game_borad_Pntr[ii][jj].state_chamber_get() == 2)
            {
               // travelling from left towards the right side of the game following diagonal path.
                    if(ii  < hght_curr_get()- 3 && jj<wdth_curr_get()-3)
                    {
                       if(game_borad_Pntr[ii+1][jj+1].state_chamber_get() == 2 && game_borad_Pntr[ii+2][jj+2].state_chamber_get() == 2 && game_borad_Pntr[ii+3][jj+3].state_chamber_get() == 2)
                      {
                          isGame_Win2=true;
                          game_borad_Pntr[ii][jj].state_chamber_set(MAXVAL);
                          game_borad_Pntr[ii+1][jj+1].state_chamber_set(MAXVAL);
                          game_borad_Pntr[ii+2][jj+2].state_chamber_set(MAXVAL);
                          game_borad_Pntr[ii+3][jj+3].state_chamber_set(MAXVAL);
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
                  // moving from right towards the left side diagonally.
                  if(ii  < hght_curr_get()- 3 && jj - 3 >= 0  )
                  {
                    if(game_borad_Pntr[ii+1][jj-1].state_chamber_get() == 2 && game_borad_Pntr[ii+2][jj-2].state_chamber_get() == 2 && game_borad_Pntr[ii+3][jj-3].state_chamber_get() == 2)
                    {
                         isGame_Win2=true;
                         game_borad_Pntr[ii][jj].state_chamber_set(MAXVAL);
                         game_borad_Pntr[ii+1][jj-1].state_chamber_set(MAXVAL);
                         game_borad_Pntr[ii+2][jj-2].state_chamber_set(MAXVAL);
                         game_borad_Pntr[ii+3][jj-3].state_chamber_set(MAXVAL);
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
