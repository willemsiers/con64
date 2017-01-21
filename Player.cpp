//
// Created by willem on 21-1-17.
//

#include <iostream>
#include "Player.h"

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
    bool f2b = false;   //front to back
    bool l2r = false;   //left to right
    bool vert = false;  //vertical columns

    bool l2rd = false;  //left to right diagonal
    bool r2ld = false;  //right to left diagonal

    bool f2bd = false;  //front to back diagonal
    bool b2fd = false;  //back to front diagonal

    bool l2rt = false;  //left to right topview diagonal
    bool r2lt = false;  //right to left topview diagonal

    bool dd1 = false;   //diagonal diagonal 1
    bool dd2 = false;   //diagonal diagonal 2
    bool dd3 = false;   //diagonal diagonal 3
    bool dd4 = false;   //diagonal diagonal 4

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

    //lateral diagonals
    for (int y = 0; y < 4; ++y) {

        //left to right diagonal
        if (board_p[0][y][0]
            && board_p[1][y][1]
            && board_p[2][y][2]
            && board_p[3][y][3]) {
            l2rd = true;
        }

        //right to left diagonal
        if (board_p[3][y][0]
            && board_p[2][y][1]
            && board_p[1][y][2]
            && board_p[0][y][3]) {
            r2ld = true;
        }
    }

    //forwards backwards diagonals
    for (int x = 0; x < 4; ++x) {

        //front to back diagonal
        if (   board_p[x][0][0]
            && board_p[x][1][1]
            && board_p[x][2][2]
            && board_p[x][3][3]) {
            f2bd = true;
        }

        //back to front diagonal
        if (      board_p[x][0][3]
               && board_p[x][1][2]
               && board_p[x][2][1]
               && board_p[x][3][0]) {
            b2fd = true;
        }
    }

    //top-view diagonals
    for (int z = 0; z < 4; ++z) {

        //left to right (top-view)
        if (      board_p[0][0][z]
               && board_p[1][1][z]
               && board_p[2][2][z]
               && board_p[3][3][z]) {
            l2rt = true;
        }

        //right to left (top-view)
        if (         board_p[3][0][z]
                  && board_p[2][1][z]
                  && board_p[1][2][z]
                  && board_p[0][3][z]) {
            r2lt = true;
        }
    }

    //diagonal diagonals
    dd1 = board_p[0][0][0] && board_p[1][1][1] && board_p[2][2][2] && board_p[3][3][3];
    dd2 = board_p[0][0][3] && board_p[1][1][2] && board_p[2][2][1] && board_p[3][3][0];
    dd3 = board_p[0][3][0] && board_p[1][2][1] && board_p[2][1][2] && board_p[3][0][3];
    dd4 = board_p[3][0][0] && board_p[2][1][1] && board_p[1][2][2] && board_p[0][3][3];

    result = f2b || l2r || vert || l2rd || r2ld || f2bd || b2fd || l2rt || r2lt || dd1 || dd2 || dd3 || dd4;
    std::cout << "f2b="<<f2b<<" l2r="<<l2r<<" vert="<<vert<<" l2rd="<<l2rd<<" r2ld="<<r2ld<<" f2bd="<<f2bd<<" b2fd="<<b2fd<<" l2rt="<<l2rt<<" r2lt="<<r2lt<<" dd1="<<dd1<<" dd2="<<dd2<<" dd3="<<dd3<<" dd4="<<dd4<<std::endl;

    return result;
}

void Player::play(Board &board, int x, int y) {
    int z = board.put(x, y, this->mark);
    updatePBoard(x, y, z);
}
