#include <assert.h>
#include <regex>
#include <memory>
#include <iostream>
#include "scriptman.hpp"
#include "interfaces.hpp"

const std::shared_ptr <interfaces::executable> games::scriptman::parse_end(const std::string& line) {
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
                if (games::stackman::branstack.size() == 1) {
                    auto temp = games::stackman::branstack.back();
                    games::stackman::insvstack.pop_back();
                    games::stackman::branstack.pop_back();
                    return temp;
                }
                else {
                    auto temp = games::stackman::branstack.back();
                    games::stackman::insvstack.back().get()->add(temp);
                    games::stackman::branstack.pop_back();
                    return nullptr;
                }
            }
        }
        else {
            auto search = games::mapman::funvmap.find(match[2]);
            if (search != games::mapman::funvmap.end()) {
                std::cout << "[i] Ending function '" << match[2] << "'" << std::endl;

            }
            else {
                std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
                std::cout << "[e] Unknown label '" << match[2] << "'" << std::endl;
                assert(0);
            }
        }
    }

    return nullptr;
}

