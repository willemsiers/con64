//
// Created by willem on 21-1-17.
//

#ifndef CON64_BOARD_H
#define CON64_BOARD_H

#define NUM_PLAYERS 2
#define RED 7
#define BLUE 4

class Board {

private:

    int fullBoard[4][4][4];
    bool invalid = false;

public:

    void print();

    void updateFullBoard(int x, int y, int z, int mark);

    /** Returns z **/
    int put(int x, int y, int mark);

};


#endif //CON64_BOARD_H
