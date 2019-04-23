#include <iostream>
#include "logic.hpp"

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