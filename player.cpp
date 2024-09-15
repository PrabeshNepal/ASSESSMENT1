
/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/




#include "Player.h"
#include "TicTacToe.h"
#include "NBTicTacToe.h"



//bool Player::getXMove(char player, int& x, int& y) {//What does & mean?
//
//	if (grid[currentBoard.x][currentBoard.y].noOfMoves >= 81)
//		return false;
//
//	int row, col;
//
//
//	do {
//
//		cin >> row >> col;
//		cout << endl;
//	} while (!nb.isTheMoveValid(row - 1, col - 1));
//	x = row - 1;
//	y = col - 1;
//
//	// select each bock in assiging coordinates base on the input eg
//	/*
//	_______ here X is 0,0 -> in other grids X may be 0,3 or 0,6 etc
//	|X|*|*|
//	-------
//	|*|*|*|
//	-------
//	|*|*|*|
//	-------
//	*/
//	// gets the sub board. eg if i playe 1,2 which is (0,1 for the calculation) it will be 0/3 = 0 and 1/3 = 0 so the coordinate will be [0,0] or sub grid [1,1] (basically the same)
//	//  another example if i play 5,9 (4,8) then it will be 4/3 = 1 and 8/3= 2 hence [1,2] or [2,3] whcih is the middle right most subgrid.
//
//	currentBoard.x = x % 3; // gets which grid was played eg 0%3 = 0 hence x = 0 or 8%3 = 2 hence x = 2
//	currentBoard.y = y % 3;
//
//
//
//
//
//	//currentBoard.x = x;
//	//currentBoard.y = y;
//	// WARNING :::: CurrentBoard is in indexing begining from 0.
//	cout << "Current Grid: [" << currentBoard.x + 1 << "," << currentBoard.y + 1 << "]" << endl;
//
//	return true;
//}
//bool Player::getOMove(char player, int& x, int& y) {//What does & mean?
//
//	if (grid[currentBoard.x][currentBoard.y].noOfMoves >= 81)
//		return false;
//
//	int row, col;
//	do {
//		// rand num between (0,1,2) + 1 = (1,2,3).
//		// rand() % 3 = (0,1,2) if you do +1 it will be (1,2,3) hence row = (rand() % 3) + 1; chooses a random number 1,2 or 3.
//
//		if (currentBoard.x == 0 && currentBoard.y == 0) {
//			row = (rand() % 3) + 1;
//			col = (rand() % 3) + 1;
//		}
//		else if (currentBoard.x == 0 && currentBoard.y == 1) {
//			row = (rand() % 3) + 1;
//			col = (rand() % 3) + 4;
//		}
//		else if (currentBoard.x == 0 && currentBoard.y == 2) {
//			row = (rand() % 3) + 1;
//			col = (rand() % 3) + 7;
//		}
//		else if (currentBoard.x == 1 && currentBoard.y == 0) {
//			row = (rand() % 3) + 4;
//			col = (rand() % 3) + 1;
//		}
//		else if (currentBoard.x == 1 && currentBoard.y == 1) {
//			row = (rand() % 3) + 4;
//			col = (rand() % 3) + 4;
//		}
//		else if (currentBoard.x == 1 && currentBoard.y == 2) {
//			row = (rand() % 3) + 4;
//			col = (rand() % 3) + 7;
//		}
//		else if (currentBoard.x == 2 && currentBoard.y == 0) {
//			row = (rand() % 3) + 7;
//			col = (rand() % 3) + 1;
//		}
//		else if (currentBoard.x == 2 && currentBoard.y == 1) {
//			row = (rand() % 3) + 7;
//			col = (rand() % 3) + 4;
//		}
//		else if (currentBoard.x == 2 && currentBoard.y == 2) {
//			row = (rand() % 3) + 7;
//			col = (rand() % 3) + 7;
//		}
//
//
//
//
//
//		cout << endl;
//	} while (!nb.isTheMoveValid(row - 1, col - 1));
//	x = row - 1;
//	y = col - 1;
//	currentBoard.x = x % 3; // gets which grid was played eg 0%3 = 0 hence x = 0 or 8%3 = 2 hence x = 2
//	currentBoard.y = y % 3;
//	// WARNING :::: CurrentBoard is in indexing begining from 0.
//	cout << "Current Grid: [" << currentBoard.x + 1 << "," << currentBoard.y + 1 << "]" << endl;
//
//
//	return true;
//}
//
