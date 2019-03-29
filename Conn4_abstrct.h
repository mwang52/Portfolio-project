

/*This is the header file for the class Conn4_abstrct.cpp file*/

#ifndef CONN4ABSTRCT_H
#define CONN4ABSTRCT_H

#include <string>
#include "Chamber.h"

using namespace std;

namespace proj_Connect4Game
{

    class Conn4_abstrct {
            
        public:
            //no argument constructor.
            Conn4_abstrct();
	    //constructor to initialize 3 parameters on object creation.
            Conn4_abstrct(int wdth_curnt_n,int hght_curnt_n,char sel_game_n);
	    //make sure to invode actual object destructor.
            virtual ~Conn4_abstrct();

            // getter methods, for accessing private object member use Accessor Functions
            int  wdth_curr_get()  const;  // give in output, the width at current position
            int  hght_curr_get() const;  // give in output, the height at current position
            char sel_Game_get() const;  // Provide selection of game to be either vs player or computer
            char obj_type_get()    const;  // execute to give object of type P-D
        
            // setter methods or Mutators.
            void wdth_curr_set(int wdth_curnt_n);
            void hght_curr_set(int hght_curnt_n);
            void sel_Game_set(char sel_Game_nn);   // input selection set either P or C
            void obj_type_set(char obj_type_nn);   // Setin object having the form of P,D               
          
            void load(string  fle_inpt_nam); // start new game.
            void curr_game_save(string fle_name_out, char* inpt_users, int& inpt_users_nmbr); //for storing current state of game.    
            void play();                    // function for computer play.
            void play(char& ChamberPosition);  // for user play turn. Need position of Chamber as parameter.
            void Game_start();                
            // it works as we take input from the user as a board size then ask for either user or computer to play.
     	    
//fuctions for the minimax use.
	    int algorithm_func(int depth);	//function for calling the minimax algorithm and find the best move.
	    int mini_MaxAlgorithm(Chamber **board, int depth, int turn); //minimax algorithm that finds the best move.
	    int heuristic(Chamber **s);    	//function that estimates the heuristic
	    int endgame(Chamber **s,int player);	//function for the game to be ended in minimax
	    void remove_board_val(Chamber **board, int col_val);	//remove the value of the chamber at the move.
	    int place_value(Chamber **board, int col_val, int player);	//update the value of the the new chamber on board


	    //protected scope variables.
        protected: 
            // used as the data collection for this game
            int  wdth_curnt;   //used as the width for the game.
            int  hght_curnt;  // variable for height of the game.
            char selct_game;  // game mode, either be against P(Player) or C(Computer)
            char obt_type;     // used as the Type of the object as either P (Plus), D (Diagonal).
            Chamber **game_borad_Pntr;    // overall board used to play the game..
            
            // Static members           
            static int arrngmnt;
            static int alive_ChamberAll;	//used in check condition for the game board either full or not.
	    static bool isGame_Win, isGame_Win2;		//check for the win condition
           // static int aliveChamberPlr1;   
           // static int aliveChamberPlr2;	
            static int aliveChamber_file;	//used along with along alive_ChamberAll as counter variable.
            

            // function declared as virtual because they are expected to be redefined.
            virtual void win_plr1() = 0;                 //win case for the player1
            virtual void plr2_comp_win() = 0;       //win case for the player2

            void data_get();                                //getting all the data of the board.
            void board_starter();                           // initialize the board at startup
            void curnt_board_display() const;           // function used as the display of board on console
            void mov_comptr_optml();       	  // used as a move for the computer
            
   	    void board_resz(int rowNumber, int columnNumber); // board resizing function
            void brd_resz_RoCl(string gameFile,int& rowNumber,int& columnNumber);//board resizing function and give row and column.
            string distinguish(string userInput, int& index); //user input Parse in order to load and saving the current game command   
            bool board_stps(int yPosition);   // putting board steps.

	    int  letter_posi(char& inputData);    // conversion method form characters to position of the board
            void board_StpRange() const;            // restrict the user for range value.
            bool game_terminate();               // when game is ended return true.
            bool isAliveUse1Chambers(Chamber Chamber); 
            bool isAliveUse2Chambers(Chamber Chamber);
            static int rec_ordr() {return arrngmnt;} 
    };

}

#endif

