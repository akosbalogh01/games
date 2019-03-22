#include <iostream>
#include "logic.hpp"
#include "graphics.hpp"

int main(const int argc, const char** argv) {
    games::logic    game(argv[1]);
    games::graphics gfx(argv[1]);


    while (game.isRunning()) {
        game.processInput();
        game.nextMove();
        gfx.display();
    }

    return 0;
}
