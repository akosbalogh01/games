#include <regex>
#include <memory>
#include <iostream>
#include "logic.hpp"
#include "mapman.hpp"
#include "statfunc.hpp"
#include "instrvector.hpp"

bool games::statfunc::parsedefvar(void* unused, const std::string& key, void* unused2) {
    games::mapman::varimap[key] = 0;
    return true;
}

bool games::statfunc::parsedeffun(void* unused, const std::string& key, void* unused2) {
    games::mapman::funvmap[key] = games::instrvector();
    return true;
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
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(EXIT\\[)(.*?)(\\];)"))) {
        games::logic* target = (games::logic*) object;
        std::cout << "[i] Exiting application." << std::endl;
        target->setRunning(false);
        return true;
    }

    return false;
}
