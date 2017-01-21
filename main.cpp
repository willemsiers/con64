#include <iostream>
#include "Board.h"

int main() {
    std::cout << "Starting connect64!" << std::endl;
    Board *board = new Board();

    int turn = 0;

    bool run = true;
    for (int x = 0; x < 4 && run; ++x) {
        for (int y = 0; y < 4 && run; ++y) {
            board->put(x, y, board->players[turn++ % NUM_PLAYERS]);

            if (board->checkWin()) {
                run = false;
            }
        }
    }

    board->print();
    delete board;
    return 0;
}