//
// Created by willem on 21-1-17.
//

#ifndef CON64_PLAYER_H
#define CON64_PLAYER_H

class Player {

private:
    int board_p[4][4][4];

public:

    Player(int mark);

    void updatePBoard(int x, int y, int z);

    int mark;

    void print();

    bool checkWin();
};


#endif //CON64_PLAYER_H
