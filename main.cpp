#include <iostream>
#include "Board.h"
#include "Player.h"
#include "NaivePlayer.h"

NaivePlayer players[2] = {NaivePlayer(RED), NaivePlayer(BLUE)};

int main() {

    std::cout << "Starting connect64!" << std::endl;
    Board board = Board();

    int turn = 0;
    bool run = true;
    while (run) {

        players[turn % NUM_PLAYERS].play(board);
        if (players[turn % NUM_PLAYERS].checkWin()) {
            run = false;
        }
        turn++;
    }

    board.print();
    return 0;

}