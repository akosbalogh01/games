#include <map>
#include <string>
#include <functional>
#include "mapman.hpp"
#include "statfunc.hpp"
#include "instruction.hpp"


typedef std::function <bool (void*, std::string, void*)> funtype;

std::map <std::string, games::instruction> games::mapman::itermap;

void games::mapman::init_itermap() {
    itermap["FOREACH"]  = games::instruction(nullptr, funtype (games::statfunc::iter::foreach));
    itermap["WHILE"]    = games::instruction(nullptr, funtype (games::statfunc::iter::whileloop));
    // TODO: itermap["FOR"]
    // TODO: itermap["DOWHILE"]
}
