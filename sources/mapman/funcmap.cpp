#include <map>
#include <string>
#include "statfunc.hpp"
#include "instrvector.hpp"
#include "mapman.hpp"

typedef std::function <bool (void*, std::string, void*)> funtype;

std::map <std::string, games::instruction> games::mapman::funcmap;

void games::mapman::init_funcmap() {
    //games::logic* origin = (games::logic*) core;
    funcmap["DEFINE_VAR"] = games::instruction(nullptr, funtype (games::statfunc::parsedefvar));
    funcmap["DEFINE_FUN"] = games::instruction(nullptr, funtype (games::statfunc::parsedeffun));

    funcmap["CREATEPAWN"] = games::instruction(membmap["PAWNMAN"], funtype (games::statfunc::createpawn));
    funcmap["SETPAWNPOS"] = games::instruction(membmap["PAWNMAN"], funtype (games::statfunc::setpawnpos));

    funcmap["ADD"]        = games::instruction(nullptr, funtype (games::statfunc::math::add));
    funcmap["SUB"]        = games::instruction(nullptr, funtype (games::statfunc::math::sub));
    funcmap["INCREMENT"]  = games::instruction(nullptr, funtype (games::statfunc::math::increment));
    funcmap["DECREMENT"]  = games::instruction(nullptr, funtype (games::statfunc::math::decrement));
    funcmap["MULTIPLY"]   = games::instruction(nullptr, funtype (games::statfunc::math::multiply));
    funcmap["DIVIDE"]     = games::instruction(nullptr, funtype (games::statfunc::math::divide));
    funcmap["MODULO"]     = games::instruction(nullptr, funtype (games::statfunc::math::modulo));
}
