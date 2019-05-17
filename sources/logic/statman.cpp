#include <regex>
#include <memory>
#include <iostream>
#include "logic.hpp"
#include "mapman.hpp"
#include "statfunc.hpp"
#include "instrvector.hpp"

bool games::statfunc::parsedefvar(void* unused, const std::string& key, void* unused2) {
    std::smatch match;
    if (std::regex_match(key, match, std::regex("(DEFINE_VAR\\[)(.*?)(\\];)"))) {
        auto search = games::mapman::varimap.find(match[2]);
        if (search == games::mapman::varimap.end()) {
            games::mapman::varimap[match[2]] = 0;
            games::mapman::varimap.size();
            return true;
        }
        else {
            std::cout << "[e] Redefinition of variable '" << match[2] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::parsedeffun(void* unused, const std::string& key, void* unused2) {
    std::smatch match;
    if (std::regex_match(key, match, std::regex("(DEFINE_FUN\\[)(.*?)(\\];)"))) {
        auto search = games::mapman::funvmap.find(match[2]);
        if (search == games::mapman::funvmap.end()) {
            games::mapman::funvmap[match[2]] = games::instrvector();
            return true;
        }
        else {
            std::cout << "[e] Redefinition of function '" << match[2] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::writeconsole(void* unused, const std::string& input, void* unused2) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(WRITECONSOLE\\[\")(.*?)(\"\\];)"))) {
        std::cout << "[i] " << match[2] << std::endl;
        return true;
    }

    return false;
}

bool games::statfunc::exit(void* object, const std::string& input, void* unused2) {
    if (std::regex_match(input, std::regex("(EXIT\\[)(.*?)(\\];)")) || \
        std::regex_match(input, std::regex("(exit)")) || \
        std::regex_match(input, std::regex("(quit)")))
    {
        games::logic* target = (games::logic*) object;
        std::cout << "[i] Exiting application." << std::endl;
        target->setRunning(false);
        return true;
    }

    return false;
}
