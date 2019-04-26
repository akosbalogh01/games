#include <regex>
#include "condition.hpp"

const std::string regpattern = "(CONDITION\\()((?:[A-Z][A-Z]+))(\\s+)(..)(\\s+)(.*?)(\\))";

template <class compare_type>
bool games::condition <compare_type>::build(const std::string& input) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex(regpattern))) {
        return true;
    }

    return false;
}
