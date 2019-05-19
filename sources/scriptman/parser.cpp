#include <assert.h>
#include <map>
#include <regex>
#include <string>
#include <memory>
#include <iostream>
#include "mapman.hpp"
#include "stackman.hpp"
#include "branch.hpp"
#include "scriptman.hpp"
#include "interfaces.hpp"
#include "instrvector.hpp"

void print_insvstack() {
    for (unsigned int i = 0; i < games::stackman::insvstack.size(); i++) {
        std::cout << "[" << i << "] " << games::stackman::insvstack[i].get() << std::endl;
    }
}

typedef enum lt {BRANCH, LEAF, LABEL, END, ERR} line_type;
inline line_type type(const std::string&);

void games::scriptman::parser(const lexvec& input) {
    for (auto const& index: input) {
        switch (type(index)) {
        case BRANCH: {
            print_insvstack();
            std::cout << "[i] Parsing branch: " << index << std::endl;
            parse_branch(index);
            print_insvstack();
            break;
        }

        case LEAF: {
            print_insvstack();
            std::cout << "[i] Parsing leaf (" << games::stackman::insvstack.back().get() << "): " << index << std::endl;
            parse_instr(nullptr, index);
            print_insvstack();
            break;
        }

        case LABEL: {
            print_insvstack();
            std::cout << "[i] Parsing label: " << index << std::endl;
            parse_label(index);
            print_insvstack();
            break;
        }

        case END: {
            print_insvstack();
            std::cout << "[i] Parsing block end: " << index << std::endl;
            parse_end(index);
            print_insvstack();
            break;
        }

        case ERR:
        default:
            std::cout << "[e] Fatal error: unparsable line " << index << std::endl;
            assert(0);
        }
    }
}

line_type type(const std::string& line) {
    if (std::regex_match(line, std::regex("(END)(\\[)(.*?)(\\];)"))) return END;
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\];)"))) return LEAF;
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\]:)"))) return BRANCH;
    if (std::regex_match(line, std::regex("(.*?)(:)")))              return LABEL;
    return ERR;
}
