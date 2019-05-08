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

typedef enum lt {BRANCH, LEAF, LABEL, END, ERR} line_type;
inline line_type type(const std::string&);

const games::instrvector games::scriptman::parser(const lexvec& input) {
    std::shared_ptr <games::instrvector> target_vector = std::make_shared <games::instrvector>();
    games::stackman::insvstack.push_back(target_vector);

    for (auto const& index: input) {
        switch (type(index)) {
        case BRANCH: {
            std::cout << "[i] Parsing branch: " << index << std::endl;
            std::shared_ptr <games::branch> new_branch = parse_branch(index);
            games::stackman::branstack.push_back(new_branch);
            target_vector.get()->add(new_branch);
            break;
        }

        case LEAF: {
            std::cout << "[i] Parsing leaf: " << index << std::endl;
            auto new_instr = parse_instr(nullptr, index);
            games::stackman::insvstack.back().get()->add(new_instr);
            break;
        }

        case LABEL: {
            std::cout << "[i] Parsing label: " << index << std::endl;
            auto new_vector = parse_label(index);
            games::stackman::insvstack.push_back(new_vector);
            target_vector.get()->add(new_vector);
            break;
        }

        case END: {
            std::cout << "[i] Parsing block end: " << index << std::endl;
            parse_end(index);
            break;
        }

        case ERR:
        default:
            std::cout << "[e] Fatal error: unparsable line " << index << std::endl;
            assert(0);
            return games::instrvector();
        }
    }

    std::cout << "target: " << target_vector.get()->size() << std::endl;

    return *target_vector.get();
}

line_type type(const std::string& line) {
    if (std::regex_match(line, std::regex("(END)(\\[)(.*?)(\\];)"))) return END;
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\];)"))) return LEAF;
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\]:)"))) return BRANCH;
    if (std::regex_match(line, std::regex("(.*?)(:)")))              return LABEL;
    return ERR;
}
