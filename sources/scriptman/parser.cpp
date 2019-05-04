#include <map>
#include <regex>
#include <string>
#include <memory>
#include <iostream>
#include "mapman.hpp"
#include "scriptman.hpp"
#include "interfaces.hpp"
#include "instrvector.hpp"

typedef enum lt {BRANCH, LEAF, LABEL, END, ERR} line_type;
inline line_type type(const std::string&);
inline const std::shared_ptr <games::instrvector> parse_label(const std::string&);
inline const std::shared_ptr <games::instruction> parse_instr(void*, const std::string&);

const games::instrvector games::scriptman::parser(const lexvec& input) {
    games::instrvector target;
    std::vector <std::shared_ptr <games::instrvector>> context;

    for (auto const& index: input) {
        switch (type(index)) {
        case BRANCH: {
            std::cout << "[i] Parsing branch: " << index << std::endl;
            break;
        }

        case LEAF: {
            std::cout << "[i] Parsing leaf: " << index << std::endl;
            auto new_instr = parse_instr(games::mapman::membmap["PAWNMAN"], index);
            context.back().get()->add(new_instr);
            break;
        }

        case LABEL: {
            std::cout << "[i] Parsing label: " << index << std::endl;
            auto new_vector = parse_label(index);
            context.push_back(new_vector);
            break;
        }

        case END: {
            std::cout << "[i] Parsing block end: " << index << std::endl;
            target.add(context.back());
            context.pop_back();
            break;
        }

        case ERR:
        default:
            std::cout << "[e] Fatal error: unparsable line " << index << std::endl;
            return games::instrvector();
        }
    }

    std::cout << "target: " << target.size() << std::endl;

    return target;
}

line_type type(const std::string& line) {
    if (std::regex_match(line, std::regex("(END)(\\[)(.*?)(\\];)"))) return END;
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\]:)"))) return BRANCH;
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\];)"))) return LEAF;
    if (std::regex_match(line, std::regex("(.*?)(:)")))              return LABEL;
    return ERR;
}

const std::shared_ptr <games::instrvector> parse_label(const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(.*?)(:)"))) {
        auto result = std::make_shared <games::instrvector>();
        games::mapman::funvmap[match[1]] = *result.get();
        return result;
    }

    return nullptr;
}

const std::shared_ptr <games::instruction> parse_instr(void* object, const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(.*?)(\\[)(.*?)(\\];)"))) {
        auto new_instruction = std::make_shared <games::instruction>(object, games::mapman::funcmap[match[1]].get());
        new_instruction.get()->setArgs(line);
        return new_instruction;
    }

    return nullptr;
}








