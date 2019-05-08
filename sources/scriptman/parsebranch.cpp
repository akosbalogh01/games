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

const std::shared_ptr <games::branch> parse_branch(const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(.*?)(\\[)(.*?)(\\]:)"))) {
        auto search = games::mapman::branmap.find(match[1]);
        if (search != games::mapman::branmap.end()) {
            auto new_branch = std::make_shared <games::branch>();
            new_branch.get()->build(line);
            return new_branch;
        }
        else {
            std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
            std::cout << "[e] Unknown branch instruction '" << match[1] << "'" << std::endl;
            assert(0);
        }
    }

    return nullptr;
}

