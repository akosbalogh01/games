#include <assert.h>
#include <regex>
#include <memory>
#include <iostream>
#include "scriptman.hpp"
#include "interfaces.hpp"

const std::shared_ptr <games::instrvector> games::scriptman::parse_label(const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(.*?)(:)"))) {
        if (games::stackman::branstack.size() != 0) {
            if (games::stackman::insvstack.size() != 1) {
                auto search1 = games::mapman::funcmap.find(match[1]);
                auto search2 = games::mapman::funvmap.find(match[1]);
                if ((search1 == games::mapman::funcmap.end()) && (search2 == games::mapman::funvmap.end())) {
                    auto result = std::make_shared <games::instrvector>();
                    games::mapman::funvmap[match[1]] = *result.get();
                    return result;
                }
                else {
                    std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
                    std::cout << "[e] Redefinition of label '" << match[1] << "'" << std::endl;
                }
            }
            else {
                std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
                std::cout << "[e] Invalid or ambiguous target vector" << std::endl;
            }
        }
        else {
            std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
            std::cout << "[e] Branch stack not empty, missing END?" << std::endl;
        }
    }

    assert(0);
    return nullptr;
}

