#include "logic.hpp"
#include "condition.hpp"

int f1() {return 30;}
int f2() {return 25;}

int main(const int argc, const char** argv) {
    system("chcp 65001");
    games::logic game(argv[1]);

    /*
    games::condition <int> lofasz(f1, 35);
    lofasz.bind(std::greater <int>());
    bool asd = lofasz.evaluate();
    */

    game.setRunning(true);
    while (game.isRunning()) {
        game.processInput();
        //game.nextMove();
        game.display();
    }

    return 0;
}
