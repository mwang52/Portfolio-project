#ifndef CONN4_PLS_H
#define	CONN4_PLS_H

#include "Conn4_abstrct.h"

namespace proj_Connect4Game
{
    
    class Conn4_pls: public Conn4_abstrct 
    {
        
        public:
           //Constructors
           Conn4_pls();
           Conn4_pls(int wdth_, int Hght_, char Slct_Game_n);
        protected:
           virtual void win_plr1();                 // User 1 winning state
           virtual void plr2_comp_win();       // User 2 and Computer winning state 
        
    };
  
}

#endif
