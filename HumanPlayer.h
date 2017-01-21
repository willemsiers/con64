//
// Created by willem on 21-1-17.
//

#ifndef CON64_HUMANPLAYER_H
#define CON64_HUMANPLAYER_H


#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(int mark);

    void play(Board &board);

private:

};


#endif //CON64_HUMANPLAYER_H
