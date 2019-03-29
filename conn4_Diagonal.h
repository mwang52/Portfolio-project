//HEADER FILE FOR CONN4_DIAGONAL.

#ifndef conn4_Diagonal_H
#define	conn4_Diagonal_H
#include "Conn4_abstrct.h"

namespace proj_Connect4Game
{
    class conn4_Diagonal: public Conn4_abstrct 
    {
        public:
           /*Constructors are declared below*/
           conn4_Diagonal();
	   conn4_Diagonal(int slct_Game_n);	
           conn4_Diagonal(int wdth_, int Hght_, char Slct_Game_n);
        private:
           virtual void win_plr1();                 // this stage shows winning state for first player
           virtual void plr2_comp_win();       	    // this shows plr 2 and Computer win state   
    };     
}
#endif
