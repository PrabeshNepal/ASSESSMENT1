#pragma once
#ifndef TICTACTOE_H_
#define TICTACTOE_H_
class TicTacToe {
private:
	int board[8][8];

public:
	int noOfMoves;
	TicTacToe();
	bool isValidMove(int, int);
	//bool getXMove(int&, int&);
	//bool getOMove(int&, int&);
	void addMove(int, int, int);
	int gameStatus();
	//int play();
	void displayBoard();
};

#endif /* TICTACTOE_H_ */
