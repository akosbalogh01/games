#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include "vector2d.hpp"
#include "logic.hpp"
#include "pawn.hpp"

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
    std::cout << "[i] Loading game logic from " << filepath << std::endl;
    logic_script_path = filepath;
    logic_moves = 0;
    logic_valid = logic_running = true;

    pushDefaultCommands();
    logic_gfx.loadRenderVector(logic_inifile.get()->value("Graphics", "table"));
    logic_gfx.loadCharacterVector(logic_inifile.get()->value("Graphics", "charmap"));
    loadPawns(logic_inifile.get()->value("Game", "pawns"));
}

std::shared_ptr <games::pawn> games::logic::createPawn(const std::string& current_line, unsigned int current_index) {
    std::smatch match;
    if (std::regex_match(current_line, match, std::regex("(CREATEPAWN\\[)(\\d+)(,\\s+)(\\d+)(\\];)"))) {
        std::shared_ptr <games::pawn> new_pawn = std::make_shared <games::pawn> (current_index);
        new_pawn.get()->setOwnerID(std::stoi(match[2]));
        new_pawn.get()->setCharacter(logic_gfx.character(std::stoi(match[4])));
        return new_pawn;
    }

    return nullptr;
}

void games::logic::loadPawns(const std::string& filepath) {
    std::cout << "[i] Loading initial pawns from " << filepath << std::endl;
    unsigned int    new_pawn_index = 0;
    std::ifstream   pawncreate(filepath);
    std::string     current_line;
    std::shared_ptr <games::pawn> new_pawn;

    while(std::getline(pawncreate, current_line)) {
        if (new_pawn = createPawn(current_line, new_pawn_index)) {
            logic_pawns.push_back(new_pawn);
            new_pawn_index++;
        }
    }
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

void games::logic::display() {
    logic_gfx.render();
}











































