#include <map>
#include <string>
#include "statfunc.hpp"
#include "instruction.hpp"
#include "mapman.hpp"
#include "logic.hpp"

std::map <std::string, games::instruction> games::mapman::funcmap;

void games::mapman::init_funcmap() {
    games::logic* origin = (games::logic*) core;

    funcmap["CREATEPAWN"] = games::instruction(membmap["PAWNMAN"], std::function <bool (void*, std::string)> (games::statfunc::createpawn));
}

/*
    std::function <void (const std::string)> echofun = &writeConsole;
    std::shared_ptr <interfaces::callable> echo = std::make_shared <games::call1arg <void, std::string>> (echofun);
    (dynamic_cast <games::call1arg <void, std::string>*> (echo.get()))->bind("WRITECONSOLE");
    logic_funcmap["WRITECONSOLE"] = echo;

    std::function <unsigned int (games::pawnman*, unsigned int)> pawntypefun = &games::pawnman::getPawnType;
    std::shared_ptr <interfaces::callable> pawntype = std::make_shared <games::call2arg <unsigned int, games::pawnman*, unsigned int>> (pawntypefun);
    (dynamic_cast <games::call2arg <unsigned int, games::pawnman*, unsigned int>*> (pawntype.get()))->bind("PAWNTYPE");
    logic_funcmap["PAWNTYPE"] = pawntype;

    std::function <pPawn (games::pawnman*, std::string, unsigned int)> pawncreatefun = &games::pawnman::createPawn;
    std::shared_ptr <interfaces::callable> createpawn = std::make_shared <games::call3arg <pPawn, games::pawnman*, std::string, unsigned int>> (pawncreatefun);
    (dynamic_cast <games::call3arg <pPawn, games::pawnman*, std::string, unsigned int>*> (createpawn.get()))->bind("CREATEPAWN");
    logic_funcmap["CREATEPAWN"] = createpawn;

    std::function <void (games::pawnman*, unsigned int, games::vec2d)> pawnposfun = &games::pawnman::setPawnPos;
    std::shared_ptr <interfaces::callable> setpawnpos = std::make_shared <games::call3arg <void, games::pawnman*, unsigned int, games::vec2d>> (pawnposfun);
    (dynamic_cast <games::call3arg <void, games::pawnman*, unsigned int, games::vec2d>*> (setpawnpos.get()))->bind("SETPAWNPOS");
    logic_funcmap["SETPAWNPOS"] = setpawnpos;
*/
