#include <iostream>
#include <regex>
#include "condition.hpp"
#include "logic.hpp"

const std::string regpattern = "(CONDITION\\()((?:[A-Z][A-Z]+))(\\s+)(..)(\\s+)(.*?)(\\))";

template <class compare_type>
bool games::condition <compare_type>::build(const std::string& input) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex(regpattern))) {
        auto search = games::logic::logic_funcmap.find(match[2]);
        if (search != games::logic::logic_funcmap.end()) {

            return true;
        }
        else {
            std::cout << "[e] Error building condition from line: " << input << std::endl;
            std::cout << "[e] Unknown key '" << match[2] << "'" << std::endl;
        }
    }
    else {
        std::cout << "[e] Unmatched regular expression to build " << input << std::endl;
    }

    return false;
}
