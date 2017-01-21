//
// Created by willem on 21-1-17.
//

#ifndef CON64_BOARD_H
#define CON64_BOARD_H

#include "Player.h"

#define NUM_PLAYERS 2
#define RED 7
#define BLUE 4

class Board {

private:
    int fullBoard[4][4][4];
    bool invalid = false;

public:
    Board();

    void print();

    void updateFullBoard(int x, int y, int z, int mark);

    void put(int x, int y, Player &p);

    Player players[2] = {Player(RED), Player(BLUE)};

    bool checkWin();
};


#endif //CON64_BOARD_H
