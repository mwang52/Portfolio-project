//this is the abstract class for the game created
//libraries support
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
//including the header files of the othe classes.
#include "Conn4_abstrct.h"
#include "Chamber.h"

using namespace std;

//same project directory as for the other source files
namespace proj_Connect4Game
{
     //initializing static members to the no value at the beginning.
    int Conn4_abstrct::alive_ChamberAll=0;
    int Conn4_abstrct::aliveChamber_file=0;
    int Conn4_abstrct::arrngmnt=0;
    bool Conn4_abstrct::isGame_Win=false;
    bool Conn4_abstrct::isGame_Win2=false;
    bool closeVariable = false;

    // empty argument constructor
    Conn4_abstrct::Conn4_abstrct():wdth_curnt(30),hght_curnt(30)
    {
        game_borad_Pntr = new Chamber*[hght_curr_get()]; // number of rows
        for(int ii=0; ii<hght_curr_get(); ++ii)
            game_borad_Pntr[ii] = new Chamber[wdth_curr_get()];   // number of columns
    }

    Conn4_abstrct::Conn4_abstrct(int wdth_curnt_n, int hght_curnt_n,char sel_game_n)
    :wdth_curnt(wdth_curnt_n),hght_curnt(hght_curnt_n),selct_game(sel_game_n)
    {

        game_borad_Pntr = new Chamber*[hght_curr_get()]; // number of rows
        for(int ii=0; ii<hght_curr_get(); ++ii)
            game_borad_Pntr[ii] = new Chamber[wdth_curr_get()];  //number of columns
    }
    //virtual constructor definition
    Conn4_abstrct::~Conn4_abstrct()
    {
       for(int ii=0; ii<hght_curr_get(); ++ii)
          delete [] game_borad_Pntr[ii];

        delete [] game_borad_Pntr;
        //making null pointer address to board pointer
        game_borad_Pntr = NULL;
    }

    // at start initialize the dashboard of the game
    void Conn4_abstrct::board_starter()
    {
      //traversing through out the board.
        for(int ii=0; ii<hght_curr_get(); ++ii)
        {
            for(int jj=0; jj<wdth_curr_get(); ++jj)
            {
              //update to the current value.
               game_borad_Pntr[ii][jj].state_chamber_set(5);
            }
        }
    }
    // setting the width_value_d for out current game.
    void Conn4_abstrct::wdth_curr_set(int wdth_curnt_n)
    {
        if(wdth_curnt_n < 4 || wdth_curnt_n>30 )
        {
                cerr <<endl << "~~~Board Width is not valid....!!" << endl;
                cout<<endl<<"entering again";
                exit(1);
                //data_get();
                //closeVariable = true;
        }
        else
        {
          //update to the current value.
                wdth_curnt = wdth_curnt_n;
        }
    }
    // set height_value_d of the game at current time.
    void Conn4_abstrct::hght_curr_set(int hght_curnt_n)
    {
        if(hght_curnt_n < 4)
        {
            cerr << endl << "~~~~Board Height of the game is not valid......!!" << endl;
            exit(1);
        }
        else
        {
          //update to the current value.
            hght_curnt = hght_curnt_n;
        }
    }

    // setting the object type value in the code.
    void Conn4_abstrct::obj_type_set(char obj_type_nn)
    {
      //when object is of type Player or Computer
       if(obj_type_nn =='P' || obj_type_nn == 'D' )
       {
         //update to the current value.
           obt_type = obj_type_nn;
       }else{
           cerr << endl << "~~~Object should be of type:: P or D " << endl;
           exit(1);
       }
    }

    // setting method for selecting the current game.
    void Conn4_abstrct::sel_Game_set(char sel_Game_nn)
    {
      //when object is of type Player or Computer
       if(sel_Game_nn == 'P' || sel_Game_nn == 'C')
       {
         //updating the values.
           selct_game= sel_Game_nn;
       }
       else
       {
           cerr << endl << "Game should always be P or C " << endl;
           exit(1);
       }
     }

     //getter method for current object of the game.
    char Conn4_abstrct::obj_type_get() const
    {
        return obt_type;
    }

    // getter for game selection method
    char Conn4_abstrct::sel_Game_get() const
    {
        return selct_game;
    }

    // Getter method for dashboard width_value_d
    int Conn4_abstrct::wdth_curr_get() const
    {
        return wdth_curnt;
    }

    // height_value_d getter method for the current game dashboard
    //where height_value_d is the col_val number.
    int Conn4_abstrct::hght_curr_get() const
    {
        return hght_curnt;
    }


  // loading the command_vari value.
  void Conn4_abstrct::load(string  fle_inpt_nam)
  {
    int  check_flg=1;
    ifstream get_fileIn;
    //open the file of having some name.
    get_fileIn.open(fle_inpt_nam,ios::in | ios::binary);
    //check the failure of file opening.
    if(get_fileIn.fail())
    {
      //prompt the error
      cerr << "failed to open the input file...!!" << endl;
      exit(1);
    }

    // Read object type P or D from the saved file
    //reading for the values P or D object types from file.
      char Character_nxt;

      //looping until flag = 1.
      //check for the object type and set the character.
      while(check_flg==1){
            get_fileIn.get(Character_nxt);
            if(Character_nxt == 'P' || Character_nxt == 'D'){
                    obj_type_set(Character_nxt);
                    //closing loop value.
                    check_flg=0;
            }
      }


      // check for the width_value_d and height_value_d from the file and read these values.
      int width_brd=0,hght_brd=0;
      //
      get_fileIn >> width_brd >> hght_brd;

      //game chambers/cells counter.
      aliveChamber_file=0;

      /*setting the width_value_d and height_value_d for the new board and resizing it and initialize it.*/
      hght_curr_set(hght_brd);
      wdth_curr_set(width_brd);
      //uses parametes width_value_d and height_value_d.
      board_resz(wdth_curr_get(),hght_curr_get());
      board_starter();

      // array for the character input for the user.
      char * charArray =
      new char [wdth_curr_get()*hght_curr_get()];
      //condition temporary variable.
      check_flg=1;
      //loop till the user input character is matched.
      while(check_flg==1){
        //get character value from the file.
          get_fileIn.get(Character_nxt);

          //when the character player is founded then set that. to the game.
          if(Character_nxt == 'P' || Character_nxt == 'C'){
                sel_Game_set(Character_nxt);
                  check_flg=0;
          }
      }

      /*for loading the command_vari read input of the user to save in array.*/

      int ii=0,NumInput_available=0;
      char char_name = 'A';

      //loop till the end of file character comes.
      while(!get_fileIn.eof())
      {
        Character_nxt = get_fileIn.get();
        // condition for the character present in the file.
        if(Character_nxt != '\n' && Character_nxt !='\0' && Character_nxt >='A' && Character_nxt<='Z')
        {
          //set array character in the character array.
          if(Character_nxt >='A' && Character_nxt<(wdth_curr_get()+'A'))
          {
            charArray[ii] = Character_nxt;
            ++ii;
            ++NumInput_available;
            ++aliveChamber_file;
          }
        }
      }

      int temperoryOrdr=arrngmnt;
     // Place the remaining charactere to game dashboard
      if(NumInput_available != 0)
      {
        for(int ii=0; ii<NumInput_available; ++ii)
        {
          if(ii%2==0)
          {
            arrngmnt = 0;
            board_stps(letter_posi(charArray[ii]));
          }
          else
          {
            arrngmnt = 1;
            board_stps(letter_posi(charArray[ii]));
          }
         }
      }

      arrngmnt = temperoryOrdr;
      //closing the file value.
      get_fileIn.close();
  }

  // Creating dashboard for the file input.
  void Conn4_abstrct::board_resz(int row_no, int col_no)
  {
    //number of rows to be set.
      game_borad_Pntr = new Chamber*[hght_curr_get()];

      for(int ii=0; ii<hght_curr_get(); ++ii)
          game_borad_Pntr[ii] = new Chamber[wdth_curr_get()];   // setting the col_val.
  }

  // Conversion of character input file --> integer value.
  int Conn4_abstrct::letter_posi(char& inputData)
  {
      char char_name = 'A';
      int  v_Integer=0;

      for(v_Integer=0,char_name='A'; char_name<='Z'; ++char_name,++v_Integer)
              if(char_name == inputData)
                      return v_Integer;
  }

  /*at the mid of the game need to display the dashboard values.
  i-e, for player 1 (X) =1 etc...
  */
  void  Conn4_abstrct::curnt_board_display() const
  {

    char char_dboard = 'A';

    cout << endl;

    for(int ii = 0; ii<wdth_curr_get(); ii++){
          cout << " ";
          cout <<static_cast<char>(char_dboard + ii) << " " ;}
          cout << "\n";

      int jj=0;

      for(int ii=0; ii<hght_curr_get(); ++ii)
      {
          if(jj==wdth_curr_get())
                  cout << endl;

              for(jj=0; jj<wdth_curr_get(); ++jj){

                // taking in mind that every integer number represents the game character.
                switch(game_borad_Pntr[ii][jj].state_chamber_get()){
                  case 1:
                  cout << " " << "X" << " ";
                  break;
                  case 2:
                  cout << " " << "O" << " ";
                  break;
                  case 3:
                  cout << " " << "O" << " ";
                  break;
                  case 4:
                  cout << " " << " " << " ";
                  break;
                  case 5:
                  cout << " " << "." << " ";
                  break;
                  case 6:
                  cout << " " << "x" << " ";
                  break;
                  case 7:
                  cout << " " << "o" << " ";
                  break;
                  default:
                  cout << " " << " " << " ";
                  break;
                }
                  }

    }
    cout << endl;
  }

  // Ask the user for the data necessary for the game.
  void Conn4_abstrct::board_StpRange() const
  {
    //assigning the initial character as A.
      char char_dboard = 'A';
      for(int ii = 0; ii<wdth_curr_get(); ii++)
         cout << static_cast<char>(char_dboard + ii) << "." ;
  }

  // using parse string for loading or saving commands.
  string Conn4_abstrct:: distinguish(string inpt_User, int& index_val)
  {

    int ii=0,char_posi_first = index_val;
    string char_tokn = "";
      ii = char_posi_first;
      int size_inpt = inpt_User.length();
      while(ii<=size_inpt){
        //token input char_val conditions
        if (inpt_User[ii] == ' ' || inpt_User[ii] == '\0' || inpt_User[ii] == '\t') {
            //store the token in the char_tokn variable.
              char_tokn = inpt_User.substr(char_posi_first, ii - index_val);
              index_val = ii;
              break;
          }
          ++ii;
      }

      while(index_val <= size_inpt && (char_tokn == " " || char_tokn == "\0" || char_tokn == "\t")) {
          index_val++;
          return distinguish(inpt_User, index_val);
      }

      return char_tokn;

  }

  // boolean function for checking that if the chamber is still free.
  bool Conn4_abstrct::isAliveUse1Chambers(Chamber chamber_obj)
  {
   // when player one is equal to 1.
   //loop throughout the board.
      for(int ii=0;ii<hght_curr_get(); ++ii)
      {
          for(int jj=0; jj<wdth_curr_get(); ++jj )
          //check when the value of the chamber is 1 then return true.
          if(game_borad_Pntr[ii][jj].state_chamber_get() == 1 && chamber_obj.state_chamber_get() == 1)
          {
              return true;
          }
      }
      return false;
  }
  // function for the chamber object to be alive/true
  bool Conn4_abstrct::isAliveUse2Chambers(Chamber chamber_obj)
  {
      // check whether player2 is equal to 2.
      for(int ii=0;ii<hght_curr_get(); ++ii)
      {
          for(int jj=0; jj<wdth_curr_get(); ++jj )

          if(game_borad_Pntr[ii][jj].state_chamber_get() == 2 && chamber_obj.state_chamber_get() == 2)
          {
              return true;
          }
      }
      return false;
  }

  // Introduce the character sleep here.
  //where the following values represents.
  // User1(X)=>1,User2(O)=>2,Computer(O)=>3,Empty( )=>4,Asteriks(*)=>5
  // Little Player1(x)=6
  // Little Player2(o)=7
  bool Conn4_abstrct::board_stps(int positon_for_Y)
  {

    bool state_inpt = true;

      for(int ii=hght_curr_get()-1; ii>=0; --ii)
      {
        //when chamber/cell value is asterik, then store the character of game.
          if(game_borad_Pntr[ii][positon_for_Y].state_chamber_get() == 5)
          {
            // player 1 steps of board paramaters set the game board

            if(arrngmnt==0)
            {
               game_borad_Pntr[ii][positon_for_Y].Pos_Chamber_set(positon_for_Y+'A');
               game_borad_Pntr[ii][positon_for_Y].Pos_row_set(ii);
               game_borad_Pntr[ii][positon_for_Y].state_chamber_set(1);
               //increment in the chamber alive variable.
               ++alive_ChamberAll;
               state_inpt = true;
               break;
            }
            else
            {
               // Computer or player 2  steps of board parameters to be set.
               game_borad_Pntr[ii][positon_for_Y].Pos_Chamber_set(positon_for_Y+'A');
               game_borad_Pntr[ii][positon_for_Y].Pos_row_set(ii);
               game_borad_Pntr[ii][positon_for_Y].state_chamber_set(2);
               ++alive_ChamberAll;
               state_inpt = true;
               break;
            }

         }

         //dashboard position traversal, if it does not exist return invalid.
        else if(game_borad_Pntr[ii][positon_for_Y].state_chamber_get() == 4 ||
                      (game_borad_Pntr[0][positon_for_Y].state_chamber_get() == 1 || game_borad_Pntr[0][positon_for_Y].state_chamber_get() == 2))
          {
            cerr << endl<< endl << ">>> step_var is Invalid. Column is already full..!!!"<<endl<<endl;
            state_inpt = false;
            break;
          }

      }

      return state_inpt;
  }

  // Computer move for the character smarter
  // Inserted character would be from left side to the right.
  void Conn4_abstrct::mov_comptr_optml()
  {
    //make flag false initially.
    bool check_flg = false;
    char step_com_character='A';

    //calling the mini_MaxAlgorithm algorithm value.
    int jj= algorithm_func(5);
    check_flg = true;
    ++alive_ChamberAll;
    cout << endl;
    cout << "Computer (O) MOVE: ";
    cout << static_cast<char>(step_com_character + (jj-1));
    cout << endl ;
  }

  // function for the many user play function.
  void Conn4_abstrct::play(char& pos_chamber)
  {
    //initial variables declaration with only function scope.
    char char_name = 'A';
    int  v_Integer=0;

    // data input condition
    // in case of failure repeat the step_var input.
    if(pos_chamber >'A'+(wdth_curr_get()-1) || !(pos_chamber>='A' && pos_chamber<='Z'))
    {
      char character_repeat='\0';
      while(1){
          cerr << endl << ">> Step is invalid.. due to wrong input character." << endl;
          cout << endl << "Re-Input MOVE: ";
          cin >> character_repeat;
          if(character_repeat<'A'+wdth_curr_get() && (character_repeat>='A' && character_repeat<='Z') ){
              pos_chamber = character_repeat;
              break;
          }
      }
    }

    // data input condition
    // in case of failure repeat the step_var input.
   if(isAliveUse1Chambers(Chamber(pos_chamber,0))|| isAliveUse2Chambers(Chamber(pos_chamber,0)))
   {
      char character_repeat='\0';
      //loop infinite times until the correct col_val is founded
      while(1){
          cerr << endl << ">> step_var is not valid because Column is full...!" << endl;
          cout << endl << "Re-Input MOVE: ";
          cin >> character_repeat;
          //condition for the loop break.
          if(!isAliveUse1Chambers(Chamber(character_repeat,0)) && !isAliveUse2Chambers(Chamber(character_repeat,0))){
              pos_chamber = character_repeat;
              break;
          }
      }
   }
    /*
    *condition to check that whether the chamber is not alive. then place step_var.
    * Re-input when the chamber is live.
    */
    if(!isAliveUse1Chambers(Chamber(pos_chamber,0)) && !isAliveUse2Chambers(Chamber(pos_chamber,0)))
    {
      // Player 1 state
        if (arrngmnt==0)
        {
              for(v_Integer=0,char_name='A'; char_name<='Z'; ++char_name, ++v_Integer)
              {
                  if(char_name == pos_chamber)
                  {
                    // failure of player1 step_var.
                    if(board_stps(v_Integer) == false)
                    {
                        while(1)
                        {
                          cout << "Re-Input MOVE: ";
                          char step_rept;
                          cin >> step_rept;

                          // Success step_var for player 1.
                          if((board_stps(letter_posi(step_rept))) == true)
                          {
                            arrngmnt=0;
                            break;
                          }
                        }
                    }
                    //display the dashboard.
                    curnt_board_display();
                    //check for the winning condition for player 1
                    win_plr1();
                    arrngmnt=1;
                    //in case of the game_terminate true then board is filled completely.
                    if(game_terminate())
                         cout<<endl<<endl<<"Board Filled !"<<endl<<endl;
                    return ;
                  }
              }
        }

        // state of player 2
        if(arrngmnt==1 && sel_Game_get()=='P') {
            for(v_Integer=0,char_name='A'; char_name<='Z'; ++char_name, ++v_Integer)
              {
                  if(char_name == pos_chamber)
                  {
                    arrngmnt=1;

                    // step_var for player 2 is failed.
                    if(board_stps(v_Integer) == false)
                    {
                          while(1)
                          {
                            cout << "Re-Input MOVE: ";
                            char step_rept;
                            cin >> step_rept;

                            // Success case for the step_var for player 2.
                            if((board_stps(letter_posi(step_rept))) == true)
                            {
                              arrngmnt=0;
                              break;
                            }
                          }

                    }
                    //display the board.
                    curnt_board_display();
                    //check for the winning condition for the player2
                    plr2_comp_win();
                    arrngmnt=0;
                    //in case of the dashboard complety filled.
                    if(game_terminate())
                         cout<<endl<<endl<<"Board Filled !"<<endl<<endl;
                    return ;
                  }
              }
        }
    }
  }

  /*steps for the computer in multiple mode Gameplay.*/
  //In case of failure it would use smart step_var using mini_MaxAlgorithm algorithm.
  void Conn4_abstrct::play()
  {
    //computer random step_var generator.
    int steps_for_computer= (rand() % wdth_curr_get());
    arrngmnt=1;
    //when step_var on the board does not exist. call optimal step_var function.
    if(board_stps(steps_for_computer) == false)
    {
      //call for smarter star function.
      mov_comptr_optml();
      arrngmnt=0;
      //display board at this instance.
      curnt_board_display();
      //condition for the winning of the player 2.
      plr2_comp_win();

    }
    else
    {
      arrngmnt=0;
      cout << endl << "Computer Step : " << static_cast<char>(steps_for_computer+'A');
      cout << endl << endl;
      curnt_board_display();
      plr2_comp_win();
    }
  }
  // saving steps to the file.
  void Conn4_abstrct::curr_game_save(string fle_name_out, char* inpt_users, int& inpt_users_nmbr)
  {
      //ofstream object declaration for the file.
      ofstream file_out_var;
      //opening the current file.
      file_out_var.open(fle_name_out);
      //in case of the failure display the file opening failure message.
      if(file_out_var.fail()) {
              cerr << "failed to open the output file...!!" << endl;
              exit(1);
      }

      //file parameters for write to file
      file_out_var  << obj_type_get();
      cout << endl;
      file_out_var  << wdth_curr_get();
      cout << endl;
      file_out_var  << hght_curr_get();
      cout << endl;
      //check for the game to play against.
      if(sel_Game_get()=='P')
              file_out_var <<'P'<<endl;
      else
              file_out_var <<'C'<< endl;

      // given file to write the input.
      for(int ii=0; ii<inpt_users_nmbr; ++ii)
        file_out_var << inpt_users[ii]<<endl;
        //closing parameters for the file.
      file_out_var.close();

      cout << endl << "> >Game status is written to ";
      cout<< fle_name_out << " file." <<endl<<endl;
  }

  //perfom computation on row_val and the col_val for the given file input
  void Conn4_abstrct::brd_resz_RoCl(string file_game, int& row_no, int& col_no)
  {
    //declaration of the function variables.
    int char_val=0;
    ifstream get_fileIn;
    get_fileIn.open(file_game);

    //condition for the failure of the file.
    if(get_fileIn.fail()) {
      cerr << "Input file opening failed" << endl;
      exit(1);
   }

    char char_next;
    int row_val=0;
    int col_val =0;

    //loop until the end of file is founded.

    while(!get_fileIn.eof())
    {
      // maximum column value calculation.
      if(char_next != '\n' && get_fileIn.peek() != get_fileIn.eof())
      {
        //increment the character variable.
        ++char_val;
      }
      if(char_val > col_no)
      //update.
        col_val = char_val;

      // row number calculation.
      if(char_next == '\n'){
        //variable updates
        char_val=0;
        ++row_val;
      }
      //update
      char_next = get_fileIn.get();
    }
    //update rows and columns.
    row_no = row_val;
    col_no = col_val;

    // sut up of the parameter of the game at current time.
    hght_curr_set(row_no);               // for rows values.
    wdth_curr_set(col_no);            // for columns values.
    //closing the file.
    get_fileIn.close();
  }


// funciton to get the game data from the user.
void Conn4_abstrct::data_get()
{
    char computer_player_value='\0';
    int width_value_d=0,height_value_d=0;

    cout << endl << "Enter Width of Board ::: ";
    cin >> width_value_d;
    //update width value
    wdth_curr_set(width_value_d);
    //if(closeVariable)
    //  return;
    cout << endl << "Enter Height of Board ::: ";
    cin >> height_value_d;
    //update height value
    hght_curr_set(height_value_d);

    cout <<endl << "Player(P) | Computer(C): ";
    cin >> computer_player_value;
    //update value for game selection
    sel_Game_set(computer_player_value);

}

  //for players and computer the function of Single step_var
  void Conn4_abstrct::Game_start()
  {

      int position_lst=0;
      char input_choice;

      string step_var="",command_vari="";
      string order_alphbt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

      // Get board width_value_d,height_value_d and selection of game.
      data_get();

    //  if( closeVariable){
        //cout<<endl<<"wrong input"<<endl<<"~~~~~entering again~~~~~~~"<<endl;
  //      return;
  //    }

      cin.ignore(1000, '\n');
      cout<<endl;
      //start value of the board.
      board_starter();

      // take keyboard input values.
      char *inpt_users = new char [hght_curr_get()*wdth_curr_get()];
      int  val_count =0;
      //loop till the game is won.
      while(isGame_Win==false && isGame_Win2==false)
      {
          cout << endl;
          curnt_board_display();
          cout << endl << ">> To load new game type 'LOAD fileName'command" << endl;
          cout << ">> To save the game type 'SAVE fileName' command" << endl;
          cout << "> game continuation use positions such as ";
          //board step range function call.
          board_StpRange();

          if(arrngmnt==0)
            cout << endl << endl << "Player 1 (X) MOVE : ";
          else
            cout << endl << endl << "Player 2 (O) MOVE : ";
            //take input value.
          getline(cin,step_var);
          //condition for length to be zero
           if(step_var.length() == 0)
           {
            cerr << endl<< "Player Input Size = 0 . Exit the game !"<<endl;
            exit (EXIT_SUCCESS);
           }

          string file_out="";
          position_lst=0;
          command_vari = distinguish(step_var,position_lst);

          // saving the variable command.
          if(command_vari == "SAVE")
          {
            file_out = distinguish(step_var,position_lst);
            curr_game_save(file_out,inpt_users,val_count);
          }

          //Load command_vari
          if(command_vari == "LOAD")
          {
            string newInputFile = distinguish(step_var,position_lst);
            load(newInputFile);
            alive_ChamberAll = aliveChamber_file;
          }

          // state variable for the player.
          else
          {
                //traverse through the whole set of alphabet.
                for(int ii=0; ii<26; ++ii)
                {
                  //condition for the alphabet to the variable given.
                   if(order_alphbt[ii] == command_vari[0])
                   {
                      if(ii<wdth_curr_get())
                      {
                        // Using Player 1
                          if(arrngmnt==0)
                          {
                              inpt_users[val_count] = command_vari[0];   //find player moves
                              ++val_count;

                              if(board_stps(ii) == false) {        // in case of board step failure, repeat step.
                                arrngmnt=0;
                                break;
                              }
                              // winning state for the player 1.
                              win_plr1();
                              if(sel_Game_get()=='P')
                              {
                                  arrngmnt=1;  // Player 2
                              }

                              //random steps would be taken by the computer.
                              if(sel_Game_get()=='C' && isGame_Win==false)
                              {

                                  int steps_for_computer= (rand() % wdth_curr_get()); //MINIMAX HERE

                                  cout << endl<<steps_for_computer <<endl;
                                  arrngmnt=1;
                                  // game moves collection.
                                  inpt_users[val_count] = static_cast<char>(steps_for_computer+'A');
                                  ++val_count;

                                  //In case the move is not smart, then make it smarter move using mini_MaxAlgorithm.
                                  if(board_stps(steps_for_computer) == false)
                                  {

                                    mov_comptr_optml();
                                    arrngmnt=0;
                                    plr2_comp_win(); // winning state checker for player2
                                    break;
                                  }
                                  cout << endl << "Computer MOVE (O) : " << static_cast<char>(steps_for_computer+'A') << endl << endl;
                                  arrngmnt=0;
                              // winning state checker for player2
                                  plr2_comp_win();
                                  break;
                              }

                           break;
                          }
                          // check winning state of the user step and collect steps.
                          else if(arrngmnt == 1 && sel_Game_get() !='C')
                          {
                            inpt_users[val_count] = command_vari[0];
                            ++val_count;
                            // repeat steps when board steps are failed.
                            if(board_stps(ii) == false){
                              arrngmnt=1;
                              break;
                            }
                           arrngmnt=0;
                           //checking winning state for player 2
                           plr2_comp_win();
                           break;
                          }
                      }
                      // show invalid command message, if the board step is out to game biard.
                      else
                      {
                        if(ii > wdth_curr_get()-1 && command_vari !="SAVE" && command_vari !="LOAD")
                        {
                            cerr << endl << ">Invalid Step !!, may be due to wrong character or command." << endl << endl;
                        }
                      }
                   }
              }
          }
              // when there is no winning state then terminate the game.
                if(game_terminate() && isGame_Win==false && isGame_Win2==false)
                {
                  //display the current board of the game.
                   curnt_board_display();
                   cout<<endl<<"Board is completely Filled.Start Again !!!"<<endl<<endl;
                   return ;
                }

          } // ending the loop while.
  }

  // return false, in case the dashboard of the game is not full.
  bool Conn4_abstrct::game_terminate()
  {
    if(alive_ChamberAll < wdth_curr_get()*hght_curr_get())
        return false;
    else
        return true;
  }

int Conn4_abstrct::place_value(Chamber **board, int col_val, int player) {

    int ii;
    for(ii = 0; ii < hght_curnt; ii++) {
        if(board[ii][col_val].state_chamber_get() == 0) {
            board[ii][col_val].state_chamber_set(player);
            return ii+1;
        }
    }
}


void Conn4_abstrct::remove_board_val(Chamber **board, int col_val) {
    int ii;
    for (ii=hght_curnt-1; ii>=0; ii--){
        if (board[ii][col_val].state_chamber_get() != 0) {
            board[ii][col_val].state_chamber_set(0);
	return;
        }
    }
return;
}


int Conn4_abstrct::algorithm_func(int depth){

  int col_val, move;
  int n, value_ini = -10000-1;
Chamber **board = game_borad_Pntr;

  for(col_val=0; col_val < wdth_curnt-1; col_val++)
      if(board[hght_curnt-1][col_val].state_chamber_get()==5) {
          place_value(board, col_val, 2);
          n = mini_MaxAlgorithm(board, depth, 1);
          if ( -n > value_ini ) {
              value_ini = -n;
              move = col_val;
          }
          remove_board_val(board, col_val);
      }

  return move;
}

//0=no, 1=player, 2=computer,

int Conn4_abstrct::endgame(Chamber **s,int player) {
    int ii, jj;

    //checking for the horizontals
    for(ii=0; ii<hght_curnt; ii++)
        for(jj=0; jj<=wdth_curnt-4; jj++){
            if(s[ii][jj].state_chamber_get()== player && s[ii][jj+1].state_chamber_get()== player && s[ii][jj+2].state_chamber_get()== player && s[ii][jj+3].state_chamber_get()== player)
                return player;
        }

    //checking for the verticals
    for(ii=0; ii<=hght_curnt-4; ii++)
        for(jj=0; jj<7; jj++){
            if(s[ii][jj].state_chamber_get()== player && s[ii+1][jj].state_chamber_get()== player && s[ii+2][jj].state_chamber_get()== player && s[ii+3][jj].state_chamber_get()== player )
                return player;
        }

    //checking for the main diagonals (\)
    for(ii=hght_curnt-1; ii>=4-1; ii--)
        for(jj=0; jj<=wdth_curnt-4; jj++){
            if(s[ii][jj].state_chamber_get()== player && s[ii-1][jj+1].state_chamber_get()== player && s[ii-2][jj+2].state_chamber_get()== player && s[ii-3][jj+3].state_chamber_get()== player)
                return player;
        }

    //checking for the diagonals (/)
    for(ii=0; ii<=hght_curnt-4; ii++)
        for(jj=0; jj<=wdth_curnt-4; jj++){
            if(s[ii][jj].state_chamber_get()== player && s[ii+1][jj+1].state_chamber_get()== player && s[ii+2][jj+2].state_chamber_get()== player && s[ii+3][jj+3].state_chamber_get()== player)
                return player;
        }


    //check if stalement
    for(ii=0; ii<wdth_curnt; ii++)
        if(s[hght_curnt-1][ii].state_chamber_get()==0)
            return 0; //game is still not complete one in the last row is remaining.

    return 3; //board is filled
}


int Conn4_abstrct::heuristic(Chamber **s) {
    int result = 0;
    int ii, jj;

    //check in the horizontal direction
    for(ii=0; ii<hght_curnt; ii++)
        for(jj=0; jj<=wdth_curnt-4; jj++){
            if(s[ii][jj].state_chamber_get()!= 2 && s[ii][jj+1].state_chamber_get()!= 2 && s[ii][jj+2].state_chamber_get()!= 2 && s[ii][jj+3].state_chamber_get()!= 2)
                result++;
            if(s[ii][jj].state_chamber_get()!= 1 && s[ii][jj+1].state_chamber_get()!= 1 && s[ii][jj+2].state_chamber_get()!= 1 && s[ii][jj+3].state_chamber_get()!= 1)
                result--;
        }

    //check verticals
    for(ii=0; ii<=hght_curnt-4; ii++)
        for(jj=0; jj<wdth_curnt; jj++){
            if(s[ii][jj].state_chamber_get()!= 2 && s[ii+1][jj].state_chamber_get()!= 2 && s[ii+2][jj].state_chamber_get()!= 2 && s[ii+3][jj].state_chamber_get()!= 2 )
                result++;
            if(s[ii][jj].state_chamber_get()!= 1 && s[ii+1][jj].state_chamber_get()!= 1 && s[ii+2][jj].state_chamber_get()!= 1 && s[ii+3][jj].state_chamber_get()!= 1 )
                result--;
        }

    return result;
}

int Conn4_abstrct::mini_MaxAlgorithm(Chamber **board, int depth, int turn /*1 or 2*/) {
    int e;
    int col_val, best;
    int n;
    int player;

    if((e=endgame(board, player))) {
        if(e==3)
            return 0;
        if(e==turn)
            return 10000;
        else
            return -10000;
    }

    if(depth==0)
        return ((turn==1) ? heuristic(board) : -heuristic(board));


    best = -10000;
    for(col_val=0; col_val < wdth_curnt; col_val++)

      //check every moveement of the game.
        if(board[hght_curnt-1][col_val].state_chamber_get()==5) {
          //check that column variable is not empty
            place_value(board, col_val, turn);
            //recursive call to the minimax algorithm.
            n = mini_MaxAlgorithm(board, depth-1, 3-turn);
            if(turn==1) {
                if ( -n > best ) best = -n;
            } else {
                if ( -n > best ) best = -n;
            }
            remove_board_val(board, col_val);
        }

    return best;
}
}//proj_Connect4Game
