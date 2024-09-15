#ifndef NBTICTACTOE_H_
#define NBTICTACTOE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

#include "Coordinate.h"
#include "TicTacToe.h"
#include "Player.h"

// Forward declaration of Player class if needed
// class Player; // Uncomment if `Player` is needed in this file

class NBTicTacToe {
public:
    // initilizer
    NBTicTacToe(int x, int y)
        : currentBoard{ x, y } // Initialize currentBoard using initializer list
    {   // selects random grid to start game on
        if (grid[x][y].noOfMoves == 0) {
            int initialX = (rand() % 3) + 1;
            int initialY = (rand() % 3) + 1;
            currentBoard.x = initialX - 1;
            currentBoard.y = initialY - 1;
            // Initialize the grids to zero
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    grids[i][j] = 0;
                }
            }
        }
        else {
            // Coordinates were already set
            currentBoard.x = x;
            currentBoard.y = y;
        }
    }

    int play();
    bool getXMove(char player, int&, int&);
    bool getOMove(char player, int&, int&);
    void displayBoards();
    void addMoves(int, int, int);
    bool isTheMoveValid(int x, int y);
    int gameStatusCheck();

private:
    // objects and grids
    Coordinate currentBoard;
    TicTacToe grid[9][9];
    int grids[9][9];
    //Player p;
    
};

#endif /* NBTICTACTOE_H_ */
