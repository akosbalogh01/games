#include <map>
#include <string>
#include "mapman.hpp"
#include "command.hpp"
#include "instruction.hpp"
#include "statfunc.hpp"

typedef std::function <bool (void*, std::string, void*)> funtype;

std::map <std::string, games::command> games::mapman::cmdmap;

void games::mapman::init_cmdmap() {
    cmdmap["exit"] = games::command(games::instruction(membmap["LOGIC"], funtype (games::statfunc::exit)));
    cmdmap["exit"].addPattern("(exit)");
    cmdmap["exit"].addPattern("(quit)");
}
