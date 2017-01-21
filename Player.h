//
// Created by willem on 21-1-17.
//

#ifndef CON64_PLAYER_H
#define CON64_PLAYER_H

#include "Board.h"

class Board;

class Player {

private:
    int board_p[4][4][4];

public:

    Player(int mark);

    void updatePBoard(int x, int y, int z);

    virtual void play(Board &board, int x, int y); //TODO: virtual?

    int mark;

    void print();

    bool checkWin();

};


#endif //CON64_PLAYER_H
