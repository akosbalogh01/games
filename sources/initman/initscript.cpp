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
    games::scriptman::parser(vinitscript);

    return true;
}

bool games::initman::loadMainScript(const std::string& filepath) {
    std::cout << "[i] Generating main script from " << filepath << ':' << std::endl;

    vmainscript = games::scriptman::lexer(filepath);
    games::scriptman::parser(vmainscript);

    return true;
}
