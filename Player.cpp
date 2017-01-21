//
// Created by willem on 21-1-17.
//

#include <iostream>
#include "Board.h"

void Player::updatePBoard(int x, int y, int z) {
    board_p[x][y][z] = mark;
}

void Player::print() {
    for (int x = 0; x < 4; ++x) {
        for (int z = 3; z >= 0; --z) {
            for (int y = 0; y < 4; ++y) {
                std::cout << board_p[x][y][z];
            }
            std::cout << std::endl;
        }
        std::cout << "PPPP (" << mark << ")" << std::endl;
    }
}

Player::Player(int m) {
    mark = m;
}

bool Player::checkWin() {
    bool result = false;
    bool f2b = false;
    bool l2r = false;
    bool vert = false;

    for (int z = 0; z < 4; ++z) {
        //per level
        for (int x = 0; x < 4; ++x) {
            //per x

            //front to back
            if (   board_p[x][0][z]
                && board_p[x][1][z]
                && board_p[x][2][z]
                && board_p[x][3][z]) {
                f2b = true;
            }
        }

        for (int y = 0; y < 4; ++y) {
            //per y

            //left to right
            if (   board_p[0][y][z]
                && board_p[1][y][z]
                && board_p[2][y][z]
                && board_p[3][y][z]) {
                l2r = true;
            }
        }
    }

    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            //per column

            //down to up
            if (   board_p[x][y][0]
                && board_p[x][y][1]
                && board_p[x][y][2]
                && board_p[x][y][3]) {
                vert = true;
            }
        }
    }

    result = f2b || l2r || vert;
    std::cout << "l2r: " << l2r << ", f2b: " << f2b << ", vert: " << vert << std::endl;
    return result;
}
