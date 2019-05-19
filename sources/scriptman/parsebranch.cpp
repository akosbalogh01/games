#include <assert.h>
#include <regex>
#include <memory>
#include <iostream>
#include "scriptman.hpp"
#include "interfaces.hpp"

bool games::scriptman::parse_branch(const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(.*?)(\\[)(.*?)(\\]:)"))) {
        auto search = games::mapman::branmap.find(match[1]);
        if (search != games::mapman::branmap.end()) {
            if (match[1].compare("IF") == 0) {
                auto new_branch = std::make_shared <games::branch>();
                games::stackman::branstack.push_back(new_branch);
                new_branch.get()->build(line);
                //games::stackman::insvstack.push_back(new_branch.get()->active_branch());
                return true;
            }
            else if (match[1].compare("FOREACH") == 0) {

            }
            else if (match[1].compare("WHILE") == 0) {

            }
            else {
                //games::stackman::insvstack.pop_back();
                games::stackman::branstack.back().get()->build(line);
                //games::stackman::insvstack.push_back(new_branch.get()->active_branch());
                return true;
            }

        }
        else {
            std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
            std::cout << "[e] Unknown branch instruction '" << match[1] << "'" << std::endl;
        }
    }

    assert(0);
    return false;
}

