#include <regex>
#include <string>
#include "mapman.hpp"
#include "branch.hpp"

bool games::branch::build(const std::string& line) {
    std::cout << "branch address " << this << std::endl;
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(.*?)(\\[)(.*?)(\\]:)"))) {
        auto search = games::mapman::branmap.find(match[1]);
        if (search != games::mapman::branmap.end()) {
            void*       backup_object = games::mapman::branmap[match[1]].object();
            std::string backup_string = games::mapman::branmap[match[1]].args();
            void*       backup_result = games::mapman::branmap[match[1]].result();
            games::mapman::branmap[match[1]].setObject(this);
            games::mapman::branmap[match[1]].setArgs(match[3]);
            games::mapman::branmap[match[1]].execute();
            games::mapman::branmap[match[1]].setObject(backup_object);
            games::mapman::branmap[match[1]].setArgs(backup_string);
            games::mapman::branmap[match[1]].setResult(backup_result);
        }
        else {
            std::cout << "[e] Fatal error while building branch " << line << std::endl;
            std::cout << "[e] Unknown identifier '" << match[1] << "'" << std::endl;
        }
    }
    else {
        std::cout << "[e] Fatal error while buiding branch " << line << std::endl;
    }

    return false;
}

void games::branch::execute() {
    for (unsigned int i = 0; i < evals.size(); i++) {
        if (evals[i].get()->evaluate()) {
            branches[i].get()->execute();
            return;
        }
    }
}

const std::shared_ptr <games::instrvector> games::branch::active_branch() const {
    return branches.back();
}

