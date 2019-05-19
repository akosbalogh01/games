#include <map>
#include <string>
#include "statfunc.hpp"
#include "instrvector.hpp"
#include "mapman.hpp"

typedef std::function <bool (void*, std::string, void*)> funtype;

std::map <std::string, games::instruction> games::mapman::funcmap;

void games::mapman::init_funcmap() {
    funcmap["DEFINE_VAR"]   = games::instruction(nullptr, funtype (games::statfunc::parsedefvar));
    funcmap["DEFINE_FUN"]   = games::instruction(nullptr, funtype (games::statfunc::parsedeffun));
    funcmap["WRITECONSOLE"] = games::instruction(nullptr, funtype (games::statfunc::writeconsole));
    funcmap["EXIT"]         = games::instruction(membmap["LOGIC"], funtype (games::statfunc::exit));

    funcmap["FOREACH"]      = games::instruction(nullptr, funtype (games::statfunc::iter::foreach));

    funcmap["CREATEPAWN"]   = games::instruction(membmap["PAWNMAN"], funtype (games::statfunc::createpawn));
    funcmap["SETPAWNPOS"]   = games::instruction(membmap["PAWNMAN"], funtype (games::statfunc::setpawnpos));
    funcmap["DEFINEMOVE"]   = games::instruction(membmap["PAWNMAN"], funtype (games::statfunc::moves::defmove));
    funcmap["ENABLEMOVE"]   = games::instruction(membmap["PAWNMAN"], funtype (games::statfunc::moves::dismove));
    funcmap["DISABLEMOVE"]  = games::instruction(membmap["PAWNMAN"], funtype (games::statfunc::moves::enamove));

    funcmap["CONST"]        = games::instruction(nullptr, funtype (games::statfunc::returnconst));
    funcmap["ASSIGN"]       = games::instruction(nullptr, funtype (games::statfunc::assignvalue));
    funcmap["VALUE"]        = games::instruction(nullptr, funtype (games::statfunc::value));

    funcmap["ADD"]          = games::instruction(nullptr, funtype (games::statfunc::math::add));
    funcmap["SUB"]          = games::instruction(nullptr, funtype (games::statfunc::math::sub));
    funcmap["INCREMENT"]    = games::instruction(nullptr, funtype (games::statfunc::math::increment));
    funcmap["DECREMENT"]    = games::instruction(nullptr, funtype (games::statfunc::math::decrement));
    funcmap["MULTIPLY"]     = games::instruction(nullptr, funtype (games::statfunc::math::multiply));
    funcmap["DIVIDE"]       = games::instruction(nullptr, funtype (games::statfunc::math::divide));
    funcmap["MODULO"]       = games::instruction(nullptr, funtype (games::statfunc::math::modulo));
}
