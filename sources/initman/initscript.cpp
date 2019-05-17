#include <regex>
#include <memory>
#include <fstream>
#include <iostream>
#include "scriptman.hpp"
#include "initman.hpp"
#include "mapman.hpp"
#include "instruction.hpp"

bool games::initman::loadInitScript(const std::string& filepath) {
    std::cout << "[i] Generating init script from " << filepath << ':' << std::endl;

    vinitscript = games::scriptman::lexer(filepath);
    vinstvector = games::scriptman::parser(vinitscript);
    games::mapman::funvmap["INIT"] = vinstvector;

    return true;
}
