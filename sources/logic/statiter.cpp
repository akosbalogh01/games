#include <regex>
#include <memory>
#include <iostream>
#include "mapman.hpp"
#include "stackman.hpp"
#include "statfunc.hpp"
#include "interfaces.hpp"
#include "foreach.hpp"

bool games::statfunc::iter::foreach(void* unused1, const std::string& input, void* unused2) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(FOREACH\\[)(.*?)(,\\s+)(.*?)(\\]:)"))) {
        auto search1 = games::mapman::vectmap.find(match[2]);
        auto search2 = games::mapman::varimap.find(match[4]);
        if (search1 != games::mapman::vectmap.end()) {
            if (search2 != games::mapman::varimap.end()) {
                std::shared_ptr <interfaces::executable> new_foreach = std::make_shared <games::foreach> (match[2], match[4]);
                games::stackman::insvstack.back().get()->add(new_foreach);

                std::shared_ptr <games::instrvector> new_vector = std::make_shared <games::instrvector> ();
                (dynamic_cast <games::foreach*> (new_foreach.get()))->bind(new_vector);
                games::stackman::insvstack.push_back(new_vector);
                return true;
            }
            else {
                std::cout << "[e] Unparsable line " << input << std::endl;
                std::cout << "[e] Unknown iteration variable '" << match[4] << "'" << std::endl;
            }
        }
        else {
            std::cout << "[e] Unparsable line " << input << std::endl;
            std::cout << "[e] Unknown target vector '" << match[2] << "'" << std::endl;
        }
    }
    else {
        std::cout << "[e] Failed to create for each iterator from line " << input << std::endl;
    }

    return false;
}
