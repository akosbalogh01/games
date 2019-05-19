#include <iostream>
#include "logic.hpp"
#include "instrvector.hpp"

void games::logic::loadConfig(const std::string& filepath) {
    if (logic_valid) return;
    logic_inifile.load(filepath);
    std::cout << "[i] Loading game logic from " << filepath << std::endl;
    logic_script_path = filepath;
    logic_moves = 0;
    logic_valid = logic_running = true;

    games::mapman::varimap["test1"] = 5;
    games::mapman::varimap["test2"] = 10;

    logic_gfx.loadRenderVector(logic_inifile.value("Graphics", "table"));
    logic_gfx.loadCharacterVector(logic_inifile.value("Graphics", "charmap"));
    logic_pawnman.setCharmap(logic_gfx.charmap());

    logic_initman.loadInitScript(logic_inifile.value("Game", "initscript"));
    logic_initman.init();

    logic_initman.loadMainScript(logic_inifile.value("Game", "logiscript"));
}
