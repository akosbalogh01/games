#include <iostream>
#include <regex>
#include <string>
#include <memory>
#include <vector>
#include "interfaces.hpp"
#include "logic.hpp"
#include "conditionvector.hpp"

typedef enum {EQ, LS, LE, GR, GE, NA} relation;
inline relation deduce_relation(const std::string&);

bool games::condvector::build(const std::string& input) {
    std::vector <std::string> condstrings;
    std::smatch match;
    std::cout << "[i] Building condition vector from " << input << std::endl;
    if (std::regex_match(input, match, std::regex("(.*?)(CONDITIONSET\\[)(.*?)(\\].*?)"))) {
        std::istringstream sstream(match[3]);
        std::string new_token;

        while (std::getline(sstream, new_token, ',')) {
            if (new_token.front() == ' ') new_token.erase(new_token.begin());
            std::cout << "[i] condition: " << new_token << std::endl;
            condstrings.push_back(new_token);
        }

        for (const auto& index: condstrings) {
            if (std::regex_match(index, match, std::regex("(CONDITION\\()((?:[A-Z][A-Z]+))(\\s+)(..)(\\s+)(.*?)(\\))"))) {
                auto search = games::logic::logic_funcmap.find(match[2]);
                if (search != games::logic::logic_funcmap.end()) {

                    return true;
                }
                else {
                    std::cout << "[e] Error building condition from line " << index << std::endl;
                    std::cout << "[e] Unkown key '" << match[2] << "'" << std::endl;
                }
            }
            else {
                std::cout << "[e] Unmatched regular expression to build condition " << index << std::endl;
            }
        }
    }
    else {
        std::cout << "[e] Unmatched regular expression to build conditionvector." << std::endl;
    }

    return false;
}

inline relation deduce_relation(const std::string& input) {
    if (input.size() != 2) return NA;
    if (input.compare("==") == 0) return EQ;
    if (input.compare(">=") == 0) return GE;
    if (input.compare("<=") == 0) return LE;

    return NA;
}






