#include <functional>
#include <map>
#include <string>
#include "logic.hpp"
#include "pawn.hpp"

std::map <std::string, std::function <unsigned int (unsigned int)>> games::logic::logic_condmap;

void games::logic::loadConditionMap() {
    logic_condmap["PAWNTYPE"] = std::bind(&games::pawnman::getPawnType, &logic_pawnman, std::placeholders::_1);
}
