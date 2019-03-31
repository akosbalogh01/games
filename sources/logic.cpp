#include <iostream>
#include <string>
#include "logic.hpp"

games::logic::logic() {
    logic_running = logic_valid = false;
}

games::logic::logic(const char* filepath) {
    logic_running = logic_valid = false;
    loadConfig(filepath);
}

void games::logic::loadConfig(const std::string& filepath) {
    if (logic_valid) return;
    logic_inifile = std::make_shared <ini::inifile>(filepath);
    std::cout << "Loading Game Logic from " << filepath << std::endl;
    logic_script_path = filepath;
    logic_moves = 0;
    logic_valid = logic_running = true;

    pushDefaultCommands();
}

void games::logic::setRunning(const bool param) {
    logic_running = param;
}

unsigned int games::logic::moves() const {
    return logic_moves;
}

const bool games::logic::isRunning() const {
    return logic_running;
}
