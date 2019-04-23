#include <iostream>
#include "logic.hpp"
#include "graphics.hpp"

int main(const int argc, const char** argv) {
    system("chcp 65001");
    games::logic    game(argv[1]);

    game.setRunning(true);
    while (game.isRunning()) {
        game.processInput();
        //game.nextMove();
        game.display();
    }

    return 0;
}
