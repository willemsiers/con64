//
// Created by willem on 21-1-17.
//

#include <iostream>
#include "Board.h"

Board::Board() {
}

void Board::put(int x, int y, Player &p) {
    int z = 0;

    while (z < 4) {
        if (fullBoard[x][y][z] == 0) {
            break;
        }
        z++;
    }

    if (z > 3) {
        std::cout << "invalid mark or move";
        invalid = true;
    } else {
        p.updatePBoard(x, y, z);
        updateFullBoard(p.mark, x, y, z);
    }
}

void Board::updateFullBoard(int mark, int x, int y, int z) {
    fullBoard[x][y][z] = mark;
}

void Board::print() {
    for (int x = 0; x < 4; ++x) {
        for (int z = 3; z >= 0; --z) {
            for (int y = 0; y < 4; ++y) {
                std::cout << fullBoard[x][y][z];
            }
            std::cout << std::endl;
        }
        std::cout << (invalid ? "INVALID" : "====") << std::endl;
    }
}

bool Board::checkWin() {
    bool result = false;
    result = result || players[0].checkWin();
    result = result || players[1].checkWin();
    return result;
}
