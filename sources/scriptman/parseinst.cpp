#include <assert.h>
#include <regex>
#include <memory>
#include <iostream>
#include "scriptman.hpp"
#include "stackman.hpp"
#include "interfaces.hpp"

bool games::scriptman::parse_instr(void* object, const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(.*?)(\\[)(.*?)(\\];)"))) {
        if (games::stackman::insvstack.size() != 0) {
            auto search1 = games::mapman::funcmap.find(match[1]);
            auto search2 = games::mapman::funvmap.find(match[1]);
            if (search1 != games::mapman::funcmap.end()) {
                auto new_instruction = std::make_shared <games::instruction>(games::mapman::funcmap[match[1]]);
                if (new_instruction.get()->object() == nullptr) new_instruction.get()->setObject(object);
                new_instruction.get()->setArgs(line);
                games::stackman::insvstack.back().get()->add(new_instruction);
                return true;
            }
            else if (search2 != games::mapman::funvmap.end()) {
                // TODO: define instruction to call instr vector - is this even working? apparently it does, dunno how :DD
                std::shared_ptr <interfaces::executable> new_funccall = std::make_shared <games::instrvector>(games::mapman::funvmap[match[1]]);
                games::stackman::insvstack.back().get()->add(new_funccall);
                return true;
            }
            else {
                std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
                std::cout << "[e] Unknown instruction '" << match[1] << "'" << std::endl;
            }
        }
        else {
            std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
            std::cout << "[e] Invalid instruction vector target" << std::endl;
        }
    }

    assert(0);
    return false;
}
