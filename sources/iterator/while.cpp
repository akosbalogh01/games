#include <regex>
#include <iostream>
#include "mapman.hpp"
#include "while.hpp"
#include "condition.hpp"

void games::whileloop::execute() {
    while (vcond.get()->evaluate()) {
        vinstr.get()->execute();
    }
}

bool games::whileloop::build(const std::string& line) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(CONDITION\\[)(.*?)(\\])"))) {
        auto new_cond = std::make_shared <games::condition> (match[2]);
        vcond = new_cond;
        return true;
    }
    else {
        std::cout << "[e] Error building condition from " << line << std::endl;
        std::cout << "[e] Unknown identifier '" << match[1] << "'" << std::endl;
    }

    return false;
}

void games::whileloop::bind(const std::shared_ptr <games::instrvector>& param) {
    vinstr = param;
}

const std::shared_ptr <games::instrvector>& games::whileloop::get() const {
    return vinstr;
}

