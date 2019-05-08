#include <assert.h>
#include <map>
#include <regex>
#include <string>
#include <memory>
#include <iostream>
#include "mapman.hpp"
#include "stackman.hpp"
#include "branch.hpp"
#include "scriptman.hpp"
#include "interfaces.hpp"
#include "instrvector.hpp"

const std::shared_ptr <games::instruction> parse_instr(void* object, const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(.*?)(\\[)(.*?)(\\];)"))) {
        if (games::stackman::insvstack.size() == 0) {
            auto search1 = games::mapman::funcmap.find(match[1]);
            auto search2 = games::mapman::funvmap.find(match[1]);
            if (search1 != games::mapman::funcmap.end()) {
                auto new_instruction = std::make_shared <games::instruction>(games::mapman::funcmap[match[1]]);
                if (new_instruction.get()->object() == nullptr) new_instruction.get()->setObject(object);
                new_instruction.get()->setArgs(line);
                return new_instruction;
            }
            else if (search2 != games::mapman::funvmap.end()) {
                // TODO: define instruction to call instr vector
                //auto new_instrvect = std::make_shared <games::instrvector>(games::mapman::funvmap[match[1]]);
                //new_instrvect.get()-> anything to be set?
                //return new_instrvect;
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
    return nullptr;
}
