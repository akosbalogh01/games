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

    logic_gfx.loadRenderVector(logic_inifile.value("Graphics", "table"));
    logic_gfx.loadCharacterVector(logic_inifile.value("Graphics", "charmap"));
    logic_pawnman.setCharmap(logic_gfx.charmap());
    //logic_pawnman.loadPawns(logic_inifile.value("Game", "pawns"));
    //logic_pawnman.initPawns(logic_inifile.value("Game", "initscript"));

    //logic_pawnman.initMoves(logic_inifile.get()->value("Game", "movescript"));
    logic_initman.loadInitScript(logic_inifile.value("Game", "initscript"));
    //logic_mapman.funvmap["INIT"].execute();
    logic_initman.init();
}
