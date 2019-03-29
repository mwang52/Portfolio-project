
#ifndef CHAMBER_H

#define	CHAMBER_H

namespace proj_Connect4Game 
{
    //this is the chamber class used for the defining the position of the board of the game.
    class Chamber {

        public:
            //Constructors to Chamber Class
            Chamber();
            Chamber(const char& chamber_PosNew);
           
	    //new chamber state, chamber position and row position constructor
            Chamber(const int& State_Chamber_N,const char& chamber_PosNew,const int& Horiz_PosNew);
	    //Horizontal Row position for the chamber.	    
	    Chamber(const int& Horiz_PosNew);
            Chamber(const char& chamber_PosNew,const int& Horiz_PosNew);
       
            //These are the given Mutator Functions -  used as setters
            void  Pos_Set_whole(const char& chamber_PosNew,const int& Horiz_PosNew);
            void  state_chamber_set(const int& State_Chamber_N);
	    void  Pos_Chamber_set(const char& chamber_PosNew);
            void  Pos_row_set(const int& Horiz_PosNew);

            //These are the accessor Functions - used as Getters
            char  Pos_chamber_get() const;
            int   Pos_row_get() const;
            int   state_chamber_get() const;
            
        protected:
            char pos_chamber;	//position of the Chamber
            int  pos_row;	//position for the row
            int  state_chamber; 	//state of the chamber used.
           

    };

} 

#endif

