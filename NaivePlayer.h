//
// Created by willem on 21-1-17.
//

#ifndef CON64_NAIVEPLAYER_H
#define CON64_NAIVEPLAYER_H

#include <vector>

#include "Player.h"

class NaivePlayer : public Player {
public:
    NaivePlayer(int mark);

    void play(Board &board);
};


#endif //CON64_NAIVEPLAYER_H
