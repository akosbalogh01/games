#include <regex>
#include <fstream>
#include <iostream>
#include "scriptman.hpp"
#include "initman.hpp"
#include "mapman.hpp"
#include "instruction.hpp"

/*
SETPAWNPOS[];
CREATEPAWN[];
*/

bool games::initman::loadInitScript(const std::string& filepath) {
    std::cout << "[i] Generating init script from " << filepath << ':' << std::endl;
    games::mapman::funcmap["INIT"] = games::instrvector();
    vinitscript = games::scriptman::lexer(filepath);
    vinstvector = games::scriptman::parser(vinitscript);
    games::mapman::funcmap["INIT"].add(vinstvector);
    return true;
}

/*
std::cout << "[i] Generating init script from " << filepath << ':' << std::endl;
    std::ifstream initscript(filepath);
    std::string   current_line;
    std::smatch   match;

    while (std::getline(initscript, current_line)) {
        if (current_line.front() == '#') continue;
        else {
            if (std::regex_match(current_line, match, std::regex("(.*?)(\\[)(.*?)"))) {
                std::cout << current_line << std::endl;
                std::shared_ptr <games::instruction> new_instruction = std::make_shared <games::instruction> (games::mapman::membmap["PAWNMAN"], games::mapman::funcmap[match[1]].get());
                new_instruction.get()->setArgs(current_line);
                vinstvector.add(new_instruction);
            }
        }
    }

    return true;
*/
