#include "mapman.hpp"
#include "statfunc.hpp"

typedef std::function <bool (void*, std::string, void*)> funtype;

std::map <std::string, games::instruction> games::mapman::branmap;

void games::mapman::init_branmap() {
    branmap["IF"]     = games::instruction(nullptr, funtype (games::statfunc::branch::bif));
    branmap["ELSEIF"] = games::instruction(nullptr, funtype (games::statfunc::branch::belif));
    branmap["ELSE"]   = games::instruction(nullptr, funtype (games::statfunc::branch::belse));

    branmap["TRUE"]   = games::instruction(nullptr, funtype (games::statfunc::branch::btrue));
    branmap["FALSE"]  = games::instruction(nullptr, funtype (games::statfunc::branch::bfalse));

    branmap["CONDITION"]    = games::instruction(nullptr, funtype (games::statfunc::branch::bcond));
    branmap["CONDITIONSET"] = games::instruction(nullptr, funtype (games::statfunc::branch::bconv));
    branmap["FOREACH"]      = games::instruction(nullptr, funtype (games::statfunc::branch::foreach));
}
