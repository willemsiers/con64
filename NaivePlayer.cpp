//
// Created by willem on 21-1-17.
//

#include <cstdlib>
#include <ctime>
#include "NaivePlayer.h"

NaivePlayer::NaivePlayer(int mark) : Player(mark) {
    std::srand(551155); //std::time(0)
}

void NaivePlayer::play(Board &board) {
    std::vector<std::pair<int,int>> free = std::vector<std::pair<int,int>>(16);
    int count = board.getNonFullPositions(free);
    int choiceNo = std::rand() % count;
    const std::pair<int,int> choice = (std::pair<int, int> &&) free[choiceNo];
    Player::play(board, choice.first, choice.second);
}
