//main function.
#include <iostream>
#include <cstdlib>
#include <string>
#include "Conn4_pls.h"
#include "conn4_Diagonal.h"

using namespace proj_Connect4Game;
int main(int argc, char** argv)
{
	char Input_object = '\0';
			//Conn4_pls *c4Plus_obj = new Conn4_pls();
			conn4_Diagonal c4Diag_obj;
bool endcond = true;
	//while(endcond){
Conn4_pls *c4Plus_obj = new Conn4_pls();

		cout <<endl<<"~~~~~~~~~~~~WELCOME TO THE CONNECT4 GAME~~~~~~~~~~~~~~~"<<endl;
		cout <<endl<<"this game has two modes::" << endl<< " 1) playing through plus object";
		cout<< "          2) playing through diagonal object type.";
	cout <<endl<<"Please, enter the Type of object ::"<<endl;
	cout <<endl<< "P -- Plus Object\nD -- Diagonal Object\nE ---exit  >>>>   ";
	cin >> Input_object;

  // condition for object to be diagonal or the plus typed object.

		switch(Input_object){
			case 'P':
			case 'p':
			//start

	  	c4Plus_obj->obj_type_set('P');
	  	c4Plus_obj->Game_start();
			break;
			//end

			case 'D':
			case 'd' :
			//start

			c4Diag_obj.obj_type_set('D');
			c4Diag_obj.Game_start();

			//end
			break;
			case 'E':
			case 'e':
			endcond = false;
			break;
			default:
			cerr << endl<< "The input object is not valid....!!!"<<endl<<endl;
			break;
		}

cout<<endl<<"Quiting game.";
	  return 0;
}
