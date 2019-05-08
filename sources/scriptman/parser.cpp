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
inline const std::shared_ptr <games::instrvector> parse_label(const std::string&);
inline const std::shared_ptr <games::branch>      parse_branch(const std::string&);
inline const std::shared_ptr <games::instruction> parse_instr(void*, const std::string&);
inline void parse_end(const std::string&);

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
        auto search = games::mapman::funcmap.find(match[1]);
        if (search != games::mapman::funcmap.end()) {
            auto new_instruction = std::make_shared <games::instruction>(games::mapman::funcmap[match[1]]);
            if (new_instruction.get()->object() == nullptr) new_instruction.get()->setObject(object);
            new_instruction.get()->setArgs(line);
            return new_instruction;
        }
        else {
            std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
            std::cout << "[e] Unknown instruction '" << match[1] << "'" << std::endl;
            assert(0);
        }
    }

    return nullptr;
}

const std::shared_ptr <games::branch> parse_branch(const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(.*?)(\\[)(.*?)(\\]:)"))) {
        auto search = games::mapman::branmap.find(match[1]);
        if (search != games::mapman::branmap.end()) {
            auto new_branch = std::make_shared <games::branch>();
            new_branch.get()->build(line);
            return new_branch;
        }
        else {
            std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
            std::cout << "[e] Unknown branch instruction '" << match[1] << "'" << std::endl;
            assert(0);
        }
    }

    return nullptr;
}

void parse_end(const std::string& line) {
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
                games::stackman::branstack.pop_back();
                games::stackman::insvstack.pop_back();
            }
        }
        else {
            auto search = games::mapman::funvmap.find(match[2]);
            if (search != games::mapman::funvmap.end()) {
                std::cout << "[i] Ending function " << match[2] << "'" << std::endl;

            }
            else {
                std::cout << "[e] Fatal error: unparsable line " << line << std::endl;
                std::cout << "[e] Unknown label '" << match[2] << "'" << std::endl;
                assert(0);
            }
        }
    }
}









