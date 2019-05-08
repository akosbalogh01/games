#include <assert.h>
#include <regex>
#include <memory>
#include <iostream>
#include "scriptman.hpp"
#include "interfaces.hpp"

const std::shared_ptr <games::branch> games::scriptman::parse_branch(const std::string& line) {
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

