#include <map>
#include <regex>
#include <string>
#include <iostream>
#include "scriptman.hpp"
#include "instrvector.hpp"

typedef enum lt {BRANCH, LEAF, LABEL, ERR} line_type;
static inline line_type type(const std::string&);

const games::instrvector games::scriptman::parser(const lexvec& input) {
    games::instrvector target;

    for (auto const& index: input) {
        switch (type(index)) {
        case BRANCH:
            std::cout << "[i] Parsing branch: " << index << std::endl;
            break;

        case LEAF:
            std::cout << "[i] Parsing leaf: " << index << std::endl;
            break;

        case LABEL:
            std::cout << "[i] Parsing label: " << index << std::endl;
            break;

        case ERR:
        default:
            std::cout << "[e] Fatal error: unparseable line " << index << std::endl;
            return games::instrvector();
        }
    }

    return target;
}

line_type type(const std::string& line) {
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\]:)"))) return BRANCH;
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\];)"))) return LEAF;
    if (std::regex_match(line, std::regex("(.*?)(:)")))              return LABEL;
    return ERR;
}










