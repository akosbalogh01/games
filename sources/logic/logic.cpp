#include <string>
#include "logic.hpp"

/*
games::logic::logic() {
    logic_running = logic_valid = false;
}

games::logic::logic(const char* filepath) {
    logic_running = logic_valid = false;
    loadConfig(filepath);
}
*/

void games::logic::setRunning(const bool param) {
    logic_running = param;
}

unsigned int games::logic::moves() const {
    return logic_moves;
}

const bool games::logic::isRunning() const {
    return logic_running;
}

void games::logic::display() {
    logic_gfx.update(logic_pawnman.get());
    logic_gfx.render();
    logic_gfx.reset();
}

void games::logic::processInput() {
    std::string input;
    std::cout << std::endl << std::endl << ">> ";
    std::getline(std::cin, input);

    logic_cmdman.process(input);
}










































