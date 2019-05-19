#include <assert.h>
#include <regex>
#include <memory>
#include <iostream>
#include "scriptman.hpp"
#include "interfaces.hpp"

bool games::scriptman::parse_end(const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(END\\[)(.*?)(];)"))) {
        if (match[2].compare("IF") == 0) {
            if (games::stackman::branstack.size() == 0) {
                std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
                std::cout << "[e] Unbalanced instruction 'END[IF];'" << std::endl;
                assert(0);
            }
            else {
                std::cout << "[i] Ending branch" << std::endl;

                games::stackman::insvstack.pop_back();
                std::cout << "pushing branch to " << games::stackman::insvstack.back().get() << std::endl;
                games::stackman::insvstack.back().get()->add(games::stackman::branstack.back());
                games::stackman::branstack.pop_back();
                return true;
            }
        }
        else {
            auto search = games::mapman::funvmap.find(match[2]);
            if (search != games::mapman::funvmap.end()) {
                std::cout << "[i] Ending function '" << match[2] << "'" << std::endl;
                games::mapman::funvmap[match[2]] = *games::stackman::insvstack.back().get();
                games::stackman::insvstack.pop_back();
            }
            else {
                std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
                std::cout << "[e] Unknown label '" << match[2] << "'" << std::endl;
                assert(0);
            }
        }
    }

    return false;
}

