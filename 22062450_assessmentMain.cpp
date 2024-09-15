
/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/





/*
 * TicTacToeAPP.cpp
 *
 *  Created on: 5 Aug 2023
 *      Author: 2002345
 */
#include <iostream>
#include <iomanip>
#include <string>

#include <cstdlib>

using namespace std;

#include "NBTicTacToe.h"

/*
Resources Used:
    - For generating random Numbers between two numbers eg: rand() % 3 generates a random number 0,1 or 2 
	https://stackoverflow.com/questions/55786909/how-do-i-generate-random-numbers-in-a-range

	- Text Book


*/


int main() {
	//checking if division returns int or floating value
	// 
	//this is the game object and provides the initial arguments (0,0) for that object 
	//it is used in the constructor int NBtictactoe where it sets currentboard both to 0
	NBTicTacToe game(0, 0); 
	
	game.play();

	return 0;

}
