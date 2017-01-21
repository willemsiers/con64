//
// Created by willem on 21-1-17.
//

#include <iostream>
#include <vector>
#include "Board.h"

int Board::put(int x, int y, int mark) {
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
        updateFullBoard(mark, x, y, z);
    }
    return z;
}

void Board::updateFullBoard(int mark, int x, int y, int z) {
    fullBoard[x][y][z] = mark;
}

void Board::print() {
    for (int y = 3; y >= 0; --y) {
        for (int z = 3; z >= 0; --z) {
                for (int x = 0; x < 4; ++x) {
                std::cout << fullBoard[x][y][z];
            }
            std::cout << std::endl;
        }
        std::cout << (invalid ? "INVALID" : "====") << std::endl;
    }
}

int Board::getNonFullPositions(std::vector<std::pair<int, int>>& buffer){
    int count = 0;

    buffer.clear();
    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            if(fullBoard[x][y][3] == 0){
                buffer.push_back(std::make_pair(x,y));
                count++;
            }
        }
    }
}
