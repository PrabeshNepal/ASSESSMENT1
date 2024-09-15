


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

TicTacToe::TicTacToe() {//How to call this function?
	for (int row = 0; row < 9; row++)
		for (int col = 0; col < 9; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}
void TicTacToe::displayBoard() {//Where to get the board data?
	cout << "   1    2    3" << endl << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1;
		for (int j = 0; j < 3; j++) {
			char playerSymbol = ' ';
			if (board[i][j] == 1)
				playerSymbol = 'X';
			else if (board[i][j] == -1)
				playerSymbol = 'O';
			cout << setw(3) << playerSymbol;
			if (j != 2)
				cout << " |";
		}
		cout << endl;
		if (i != 2)
			cout << " ____|____|____" << endl << "     |    |    " << endl;
	}
	cout << endl;
}
bool TicTacToe::isValidMove(int x, int y) {//Add your code to complete the program
	if (board[x][y] != -1 || board[x][y] != 1) //Add your code here)
		return true;
	else
		return false;
}
void TicTacToe::addMove(int x, int y, int player) {//What is this function for?
	board[x][y] = player;
}

// WARNING:::::::::::::::::::: This is not used to get gamestatus in program. That function is in NBtictactoe class as gameStatusCheck.
int TicTacToe::gameStatus() {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
	}

	// Check columns for a win
	for (int i = 0; i < 3; i++) {
		if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}

	// Check diagonals for a win
	if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[0][0];
	if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[0][2];

	if (noOfMoves >= 9)
		return 2;  // Draw

	return 0;  // Game continues
}

