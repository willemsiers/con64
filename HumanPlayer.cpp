//
// Created by willem on 21-1-17.
//

#include <iostream>
#include "HumanPlayer.h"
#include "Board.h"

HumanPlayer::HumanPlayer(int mark) : Player(mark) {

}

void HumanPlayer::play(Board &board) {

    int inputX, inputY;
    std::cout << "x" << mark << ":";
    std::cin >> inputX;
    std::cout << "y" << mark << ":";
    std::cin >> inputY;

    Player::play(board, inputX, inputY);

}
