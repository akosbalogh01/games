#include <regex>
#include <iostream>
#include <functional>
#include "condition.hpp"
#include "mapman.hpp"

std::function <bool (int, int)> relation(const std::string& input) {
    if (input.compare("!=") == 0) return std::not_equal_to <int> ();
    if (input.compare("==") == 0) return std::equal_to <int> ();
    if (input.compare(">=") == 0) return std::greater_equal <int> ();
    if (input.compare("<=") == 0) return std::less_equal <int> ();

    return std::equal_to <int> ();
}

games::condition::condition(const std::string& line) {
    std::cout << "[i] Building condition " << line << std::endl;
    std::smatch match;

    if (std::regex_match(line, match, std::regex("(.*?)(\\[)(.*?)(\\])(\\s+)(..)(\\s+)(\\d+)"))) {
        auto search = games::mapman::funcmap.find(match[1]);
        if (search != games::mapman::funcmap.end()) {
            cond_comp   = relation(match[6]);
            cond_instr2 = games::mapman::funcmap["CONST"];
            cond_instr2.setArgs(match[8]);

            cond_instr1 = games::mapman::funcmap[match[1]];
            cond_instr1.setArgs(match[3]);
        }
        else {
            std::cout << "[e] Error building condition " << line << std::endl;
            std::cout << "[e] Invalid label '" << match[1] << "'" << std::endl;
        }
    }
    else if (std::regex_match(line, match, std::regex("(.*?)(\\s+)(..)(\\s+)(\\d+)"))) {
        auto search = games::mapman::varimap.find(match[1]);
        if (search != games::mapman::varimap.end()) {
            cond_comp   = relation(match[3]);
            cond_instr1 = games::mapman::funcmap["VALUE"];
            cond_instr1.setArgs(match[1]);

            cond_instr2 = games::mapman::funcmap["CONST"];
            cond_instr2.setArgs(match[5]);
        }
        else {
            std::cout << "[e] Error building condition " << line << std::endl;
            std::cout << "[e] Unknown variable '" << match[1] << "'" << std::endl;
        }
    }
    else {
        std::cout << "[e] Error building condition " << line << std::endl;
    }
}


bool games::condition::evaluate() {
    int* backup_res1 = (int*) cond_instr1.result();
    int* backup_res2 = (int*) cond_instr1.result();

    int* res1 = new int;
    int* res2 = new int;

    cond_instr1.setResult(res1);
    cond_instr2.setResult(res2);

    cond_instr1.execute();
    cond_instr2.execute();

    cond_instr1.setResult(backup_res1);
    cond_instr2.setResult(backup_res2);

    bool result = cond_comp(*res1, *res2);
    delete res1;
    delete res2;

    return result;
}
