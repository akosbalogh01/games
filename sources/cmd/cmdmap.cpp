#include <map>
#include <string>
#include "cmdman.hpp"
#include "mapman.hpp"
#include "statfunc.hpp"
#include "instruction.hpp"

typedef std::function <bool (void*, std::string, void*)> funtype;

std::map <std::string, games::command> games::cmdman::cmdmap;

void games::cmdman::init_cmdmap() {
    cmdmap["exit"] = games::command(games::instruction(games::mapman::membmap["LOGIC"], funtype (games::statfunc::exit)));
    cmdmap["exit"].addPattern("(exit)");
    cmdmap["exit"].addPattern("(quit)");

    cmdmap["move"] = games::command(games::instruction(games::mapman::membmap["PAWNMAN"], funtype (games::statfunc::movepawn)));
    cmdmap["move"].addPattern("(move)(\\s+\\[\\d+,\\s+\\d+\\]\\s+\\[\\d+,\\s+\\d+\\])");
    //cmdmap["move"].addPattern("(move)(\\s+\\[\\d+,\\s+\\d+\\]\\s+)(to)(\\s+\\[\\d+,\\s+\\d+\\])");

}
