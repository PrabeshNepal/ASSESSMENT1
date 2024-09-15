#include "NBTicTacToe.h"



/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the
code has been written/produced for me by another person or copied
from any other source.
I hold a copy of this assignment that I can produce if the original
is lost or damaged.
**************************/
#include "TicTacToe.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;




bool NBTicTacToe::isTheMoveValid(int x, int y) {//Add your code to complete the program
	int correctX = 0;
	int correctY = 0;
	if (grids[x][y] == 0) //Add your code here)
	{
		if (currentBoard.x == 0 && x <= 3) {
			correctX = 1;
		}
		else if (currentBoard.x == 1 && x <= 6 && x >= 3) {
			correctX = 1;
		}
		else if (currentBoard.x == 2 && x >= 7 && x <= 9) {
			correctX = 1;
		}

		if (currentBoard.y == 0 && y >= 1 && y <= 3) {
			correctY = 1;
		}
		else if (currentBoard.y == 1 && y >= 4 && y <= 6) {
			correctY = 1;
		}
		else if (currentBoard.y == 2 && y >= 7 && y <= 9) {
			correctY = 1;
		}

		//cout << "Current Move: " << x+1 << " " << y+1 << endl;
		if (correctX == 1 && correctY == 1) {
			return true;
		}

	}
	else
	{
		cout << "INVALID MOVE TRY AGAIN (x = (1,9) , y = (1,9))" << endl;
		return false;
	}

}
// checks the gamestatus on every board
int NBTicTacToe::gameStatusCheck() {

	// Check specific grid out of the 9
	for (int blockRow = 0; blockRow < 3; blockRow++) {
		for (int blockCol = 0; blockCol < 3; blockCol++) {

			// Iterate over rows 
			// the != 0 is checking weter there is a payer symbol -1 or 1 there, skips if row has empty value.
			for (int row = 0; row < 3; row++) {                     //                grid[x][y]            ==                     grid[x][y+1]            &&                    grid[x][y+1]            == grid[x][y+2] if true then a winner is returned                         
				if (grids[blockRow * 3 + row][blockCol * 3] != 0 && grids[blockRow * 3 + row][blockCol * 3] == grids[blockRow * 3 + row][blockCol * 3 + 1] && grids[blockRow * 3 + row][blockCol * 3 + 1] == grids[blockRow * 3 + row][blockCol * 3 + 2]) {
					return grids[blockRow * 3 + row][blockCol * 3];
				}
			}

			// Iterate over columns 
			for (int col = 0; col < 3; col++) {
				if (grids[blockRow * 3][blockCol * 3 + col] != 0 &&
					grids[blockRow * 3][blockCol * 3 + col] == grids[blockRow * 3 + 1][blockCol * 3 + col] &&
					grids[blockRow * 3 + 1][blockCol * 3 + col] == grids[blockRow * 3 + 2][blockCol * 3 + col]) {
					return grids[blockRow * 3][blockCol * 3 + col];
				}
			}

			// Check diagonal
			if (grids[blockRow * 3][blockCol * 3] != 0 &&
				grids[blockRow * 3][blockCol * 3] == grids[blockRow * 3 + 1][blockCol * 3 + 1] &&
				grids[blockRow * 3 + 1][blockCol * 3 + 1] == grids[blockRow * 3 + 2][blockCol * 3 + 2]) {
				return grids[blockRow * 3][blockCol * 3];
			}

			if (grids[blockRow * 3][blockCol * 3 + 2] != 0 &&
				grids[blockRow * 3][blockCol * 3 + 2] == grids[blockRow * 3 + 1][blockCol * 3 + 1] &&
				grids[blockRow * 3 + 1][blockCol * 3 + 1] == grids[blockRow * 3 + 2][blockCol * 3]) {
				return grids[blockRow * 3][blockCol * 3 + 2];
			}
		}
	}

	if (grid[currentBoard.x][currentBoard.y].noOfMoves >= 81)
		return 2;  // Draw

	return 0;  // Game continues
}
void NBTicTacToe::addMoves(int x, int y, int player)
{
	// adds move to the inputed x and y parameter on a 9x9 grid x and y are 0 indexed
	grids[x][y] = player;
}
void NBTicTacToe::displayBoards() {

	// Top bit for 0th index row .

	if (currentBoard.x == 0 && currentBoard.y == 0) {
		cout << " * * * * * *     - - - - - -     - - - - - -\n";
	}
	else if (currentBoard.x == 0 && currentBoard.y == 1) {
		cout << " - - - - - -     * * * * * *     - - - - - -\n";
	}
	else if (currentBoard.x == 0 && currentBoard.y == 2) {
		cout << " - - - - - -     - - - - - -     * * * * * *\n";
	}
	else
		cout << " - - - - - -     - - - - - -     - - - - - -\n";


	for (int i = 0; i < 9; i++)
	{
		// Top bit for 1th index row .
		if (i == 3)
		{
			if (currentBoard.x == 1 && currentBoard.y == 0 && i == 3)
			{
				cout << " * * * * * *     - - - - - -     - - - - - -\n";
			}
			else if (currentBoard.x == 1 && currentBoard.y == 1 && i == 3)
			{
				cout << " - - - - - -     * * * * * *     - - - - - -\n";
			}
			else if (currentBoard.x == 1 && currentBoard.y == 2 && i == 3)
			{
				cout << " - - - - - -     - - - - - -     * * * * * *\n";
			}
			else
				cout << " - - - - - -     - - - - - -     - - - - - -\n";
		}
		// Top bit for 2th index row .
		if (i == 6)
		{
			if (currentBoard.x == 2 && currentBoard.y == 0)
			{
				cout << " * * * * * *     - - - - - -     - - - - - -\n";
			}
			else if (currentBoard.x == 2 && currentBoard.y == 1)
			{
				cout << " - - - - - -     * * * * * *     - - - - - -\n";
			}
			else if (currentBoard.x == 2 && currentBoard.y == 2)
			{
				cout << " - - - - - -     - - - - - -     * * * * * *\n";
			}
			else
				cout << " - - - - - -     - - - - - -     - - - - - -\n";
		}

		for (int j = 0; j < 9; j++)
		{
			if (j == 0)
			{
				if (currentBoard.y == 0)
				{
					if (currentBoard.x == 0)
					{
						if (i == 0 || i == 1 || i == 2)
						{
							cout << "*";
						}
						else
							cout << "|";
					}
					else if (currentBoard.x == 1)
					{
						if (i == 3 || i == 4 || i == 5)
						{
							cout << "*";
						}
						else
							cout << "|";
					}
					else if (currentBoard.x == 2)
					{
						if (i == 6 || i == 7 || i == 8)
						{
							cout << "*";
						}
						else
							cout << "|";
					}
					else
						cout << "|";
				}
				else
					cout << "|";
			}

			// add j == 6 for the last one this is the left wall for the 1,2 index boards.
			if (j == 3)
			{
				if (currentBoard.x == 0) {
					if (i == 0 || i == 1 || i == 2) {
						if (currentBoard.y == 1)
						{
							cout << "   *";
						}
						else
							cout << "   |";
					}
					else
						cout << "   |";

				}
				if (currentBoard.x == 1) {
					if (i == 3 || i == 4 || i == 5) {
						if (currentBoard.y == 1)
						{
							cout << "   *";
						}
						else
							cout << "   |";
					}
					else
						cout << "   |";

				}
				if (currentBoard.x == 2) {
					if (i == 6 || i == 7 || i == 8) {
						if (currentBoard.y == 1)
						{
							cout << "   *";
						}
						else
							cout << "   |";
					}
					else
						cout << "   |";

				}
			}
			else if (j == 6)
			{  // Here we figured out where i when changed puts the symbol it puts it on the y axis of which ever split its on in this case on split on 6.
				if (currentBoard.x == 0) {
					if (i == 0 || i == 1 || i == 2) {
						if (currentBoard.y == 2) {
							cout << "   *";
						}
						else
							cout << "   |";
					}
					else
						cout << "   |";

				}
				if (currentBoard.x == 1) {
					if (i == 3 || i == 4 || i == 5) {
						if (currentBoard.y == 2) {
							cout << "   *";
						}
						else
							cout << "   |";
					}
					else
						cout << "   |";

				}
				if (currentBoard.x == 2) {
					if (i == 6 || i == 7 || i == 8) {
						if (currentBoard.y == 2) {
							cout << "   *";
						}
						else
							cout << "   |";
					}
					else
						cout << "   |";

				}
			}


			cout << " ";
			char symbol;

			if (grids[i][j] == 1)
				symbol = 'X';
			else if (grids[i][j] == -1)
				symbol = 'O';
			else
				symbol = '_';

			cout << symbol;

			if (i == 0 || i == 1 || i == 2)
			{
				if (currentBoard.x == 0 && currentBoard.y == 0)
				{
					if (j == 2)
					{
						cout << " *";
					}
					else
						cout << " |";
				}
				else if (currentBoard.x == 0 && currentBoard.y == 1)
				{
					if (j == 5)
					{
						cout << " *";
					}
					else
						cout << " |";
				}
				else if (currentBoard.x == 0 && currentBoard.y == 2)
				{
					if (j == 8)
					{
						cout << " *";
					}
					else
						cout << " |";
				}
				else
					cout << " |";

			}

			else if (i == 3 || i == 4 || i == 5)
			{
				if (currentBoard.x == 1 && currentBoard.y == 0)
				{
					if (j == 2)
					{
						cout << " *";
					}
					else
						cout << " |";
				}
				else if (currentBoard.x == 1 && currentBoard.y == 1)
				{
					if (j == 5)
					{
						cout << " *";
					}
					else
						cout << " |";
				}
				else if (currentBoard.x == 1 && currentBoard.y == 2)
				{
					if (j == 8)
					{
						cout << " *";
					}
					else
						cout << " |";
				}
				else
					cout << " |";
			}
			else if (i == 6 || i == 7 || i == 8)
			{
				if (currentBoard.x == 2 && currentBoard.y == 0)
				{
					if (j == 2)
					{
						cout << " *";
					}
					else
						cout << " |";
				}
				else if (currentBoard.x == 2 && currentBoard.y == 1)
				{
					if (j == 5)
					{
						cout << " *";
					}
					else
						cout << " |";
				}
				else if (currentBoard.x == 2 && currentBoard.y == 2)
				{
					if (j == 8)
					{
						cout << " *";
					}
					else
						cout << " |";
				}
				else
					cout << " |";
			}
			else
				cout << " |";
		}


		//cout << " |";
		cout << endl;

		if (currentBoard.y == 0)
		{
			if (i == 2)
			{
				if (currentBoard.x == 0)
				{
					cout << " * * * * * *     - - - - - -     - - - - - -";
				}
				else
					cout << " - - - - - -     - - - - - -     - - - - - -";

			}


			else if (i == 5)
			{
				if (currentBoard.x == 1)
				{
					cout << " * * * * * *     - - - - - -     - - - - - -";
				}
				else
					cout << " - - - - - -     - - - - - -     - - - - - -";
			}


			else if (i == 8)
			{
				if (currentBoard.x == 2)
				{
					cout << " * * * * * *     - - - - - -     - - - - - -";
				}
				else
					cout << " - - - - - -     - - - - - -     - - - - - -";
			}
		}
		//////////////////////////////////////////////////////////////////////////////////
		else if (currentBoard.y == 1)
		{
			if (i == 2)
			{
				if (currentBoard.x == 0)
				{
					cout << " - - - - - -     * * * * * *     - - - - - -";
				}
				else
					cout << " - - - - - -     - - - - - -     - - - - - -";

			}


			else if (i == 5)
			{
				if (currentBoard.x == 1)
				{
					cout << " - - - - - -     * * * * * *     - - - - - -";
				}
				else
					cout << " - - - - - -     - - - - - -     - - - - - -";
			}


			else if (i == 8)
			{
				if (currentBoard.x == 2)
				{
					cout << " - - - - - -     * * * * * *     - - - - - -";
				}
				else
					cout << " - - - - - -     - - - - - -     - - - - - -";
			}
		}
		//////////////////////////////////////////////////////////////////////////////
		else if (currentBoard.y == 2)
		{
			if (i == 2)
			{
				if (currentBoard.x == 0)
				{
					cout << " - - - - - -     - - - - - -     * * * * * *";
				}
				else
					cout << " - - - - - -     - - - - - -     - - - - - -";

			}


			else if (i == 5)
			{
				if (currentBoard.x == 1)
				{
					cout << " - - - - - -     - - - - - -     * * * * * *";
				}
				else
					cout << " - - - - - -     - - - - - -     - - - - - -";
			}


			else if (i == 8)
			{
				if (currentBoard.x == 2)
				{
					cout << " - - - - - -     - - - - - -     * * * * * *";
				}
				else
					cout << " - - - - - -     - - - - - -     - - - - - -";
			}
		}
		else
			cout << " - - - - - -     - - - - - -     - - - - - -";






		cout << endl;
		if (i == 2 || i == 5)
		{
			cout << endl;
		}
		// 9 loop ends here:
	}
	//cout << " - - -   - - -   - - - \n";
}


bool NBTicTacToe::getXMove(char player, int& x, int& y) {//What does & mean?

	if (grid[currentBoard.x][currentBoard.y].noOfMoves >= 81)
		return false;

	int row, col;
	do {
		cin >> row >> col;
		cout << endl;
	} while (!isTheMoveValid(row - 1, col - 1));
	x = row - 1;
	y = col - 1;

	// select each bock in assiging coordinates base on the input eg
	/*
	_______ here X is 0,0 -> in other grids X may be 0,3 or 0,6 etc
	|X|*|*|
	-------
	|*|*|*|
	-------
	|*|*|*|
	-------
	*/
	// gets the sub board. eg if i playe 1,2 which is (0,1 for the calculation) it will be 0/3 = 0 and 1/3 = 0 so the coordinate will be [0,0] or sub grid [1,1] (basically the same)
	//  another example if i play 5,9 (4,8) then it will be 4/3 = 1 and 8/3= 2 hence [1,2] or [2,3] whcih is the middle right most subgrid.

	currentBoard.x = x % 3; // gets which grid was played eg 0%3 = 0 hence x = 0 or 8%3 = 2 hence x = 2
	currentBoard.y = y % 3;





	//currentBoard.x = x;
	//currentBoard.y = y;
	// WARNING :::: CurrentBoard is in indexing begining from 0.
	cout << "Current Grid: [" << currentBoard.x + 1 << "," << currentBoard.y + 1 << "]" << endl;

	return true;
}
bool NBTicTacToe::getOMove(char player, int& x, int& y) {//What does & mean?

	if (grid[currentBoard.x][currentBoard.y].noOfMoves >= 81)
		return false;

	int row, col;
	do {
		// rand num between (0,1,2) + 1 = (1,2,3).
		// rand() % 3 = (0,1,2) if you do +1 it will be (1,2,3) hence row = (rand() % 3) + 1; chooses a random number 1,2 or 3.

		if (currentBoard.x == 0 && currentBoard.y == 0) {
			row = (rand() % 3) + 1;
			col = (rand() % 3) + 1;
		}
		else if (currentBoard.x == 0 && currentBoard.y == 1) {
			row = (rand() % 3) + 1;
			col = (rand() % 3) + 4;
		}
		else if (currentBoard.x == 0 && currentBoard.y == 2) {
			row = (rand() % 3) + 1;
			col = (rand() % 3) + 7;
		}
		else if (currentBoard.x == 1 && currentBoard.y == 0) {
			row = (rand() % 3) + 4;
			col = (rand() % 3) + 1;
		}
		else if (currentBoard.x == 1 && currentBoard.y == 1) {
			row = (rand() % 3) + 4;
			col = (rand() % 3) + 4;
		}
		else if (currentBoard.x == 1 && currentBoard.y == 2) {
			row = (rand() % 3) + 4;
			col = (rand() % 3) + 7;
		}
		else if (currentBoard.x == 2 && currentBoard.y == 0) {
			row = (rand() % 3) + 7;
			col = (rand() % 3) + 1;
		}
		else if (currentBoard.x == 2 && currentBoard.y == 1) {
			row = (rand() % 3) + 7;
			col = (rand() % 3) + 4;
		}
		else if (currentBoard.x == 2 && currentBoard.y == 2) {
			row = (rand() % 3) + 7;
			col = (rand() % 3) + 7;
		}





		cout << endl;
	} while (!isTheMoveValid(row - 1, col - 1));
	x = row - 1;
	y = col - 1;
	currentBoard.x = x % 3; // gets which grid was played eg 0%3 = 0 hence x = 0 or 8%3 = 2 hence x = 2
	currentBoard.y = y % 3;
	// WARNING :::: CurrentBoard is in indexing begining from 0.
	cout << "Current Grid: [" << currentBoard.x + 1 << "," << currentBoard.y + 1 << "]" << endl;


	return true;
}


int NBTicTacToe::play() {//What is the counterpart of this function in the original code

	int player = 1;

	//grid[currentBoard.x][currentBoard.y].displayBoard();
	displayBoards();
	int done = 0;
	while (done == 0) {
		char playerSymbol = (player == 1) ? 'X' : 'O';
		cout << "Player " << playerSymbol << " enter move: ";
		int x, y;

		if (player == 1) {
			cout << "valid moves in grid: [" << currentBoard.x + 1 << "," << currentBoard.y + 1 << "]" << endl;
			getXMove(playerSymbol, x, y);
		}
		else
		{
			cout << "valid moves in grid: [" << currentBoard.x + 1 << "," << currentBoard.y + 1 << "]" << endl;
			getOMove(playerSymbol, x, y);
		}



		//grid[currentBoard.x][currentBoard.y].addMove(x, y, player);
		addMoves(x, y, player);
		grid[currentBoard.x][currentBoard.y].noOfMoves++;
		//grid[currentBoard.x][currentBoard.y].displayBoard();
		displayBoards();

		done = gameStatusCheck();
		if (done == 1) {
			cout << "Player X wins!" << endl;
			return 1;
		}
		else if (done == -1) {
			cout << "Player O wins!" << endl;
			return -1;
		}
		else if (done == 2) {
			cout << "Draw game!" << endl;
			return 0;
		}

		if (player == 1)
			player = -1;
		else
			player = 1;
	}

	return 0;
}
