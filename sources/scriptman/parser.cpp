#include <regex>
#include <functional>
#include <map>
#include <string>
#include <iostream>
#include "instrvector.hpp"
#include "scriptman.hpp"

typedef std::function <void (std::string)> mapmod;
typedef enum lt {BRANCH, LEAF, ERR} line_type;
typedef enum lr {OK, REDEF, NODEF} leaf_ret;

std::map <std::string, mapmod> labmap;
std::map <std::string, unsigned int>        varmap;
std::map <std::string, games::instrvector>  funmap;

static inline void init_labmap();
static inline void init_varmap();
static inline void init_funmap();
static inline void add_varmap(const std::string&);
static inline void add_funmap(const std::string&);
static inline line_type type(const std::string&);
static inline leaf_ret leaf(const std::string&);

const games::instrvector games::scriptman::parser(const lexvec& input) {
    games::instrvector global;
    games::instrvector target;
    init_labmap();

    for (auto const& index: input) {
        switch (type(index)) {
        case BRANCH:
            std::cout << "[i] Parsing branch: " << index << std::endl;

            break;

        case LEAF:
            std::cout << "[i] Parsing leaf: " << index << std::endl;
            break;


        case ERR:
        default:
            std::cout << "[e] Fatal error: unparseable line " << index << std::endl;
            return games::instrvector();
        }
    }

    return target;
}


// Auxiliary static function implementations
static inline void add_varmap(const std::string& input) {
    varmap[input] = 0;
}

static inline void add_funmap(const std::string& input) {
    funmap[input] = games::instrvector();
}

void init_labmap() {
    labmap["DEFINE_VAR"] = mapmod(&add_varmap);
    labmap["DEFINE_FUN"] = mapmod(&add_funmap);
}

void init_funmap(const std::string&) {

}

void init_varmap(const std::string&) {

}

line_type type(const std::string& line) {
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\]:)"))) return BRANCH;
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\];)"))) return LEAF;
}

leaf_ret leaf(const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex())) {

    }
}









