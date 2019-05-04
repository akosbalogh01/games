#include <regex>
#include <iostream>
#include "statfunc.hpp"
#include "mapman.hpp"

bool games::statfunc::math::add(void* unused, const std::string& input, void* result) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(ADD\\[)(.*?)(,\\s+)(\\d+)(\\];)"))) {
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            games::mapman::varimap[match[2]] += std::stoi(match[4]);
            return true;
        }
        else {
            std::cout << "[e] Error adding from line: " << input << std::endl;
            std::cout << "[e] Undefined variable '" << match[2] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::math::sub(void* unused, const std::string& input, void* result) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(SUB\\[)(.*?)(,\\s+)(\\d+)(\\];)"))) {
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            games::mapman::varimap[match[2]] -= std::stoi(match[4]);
            return true;
        }
        else {
            std::cout << "[e] Error subtracting from line: " << input << std::endl;
            std::cout << "[e] Undefined variable '" << match[2] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::math::increment(void* unused, const std::string& input, void* result) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(INCREMENT\\[)(.*?)(\\];)"))) {
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            games::mapman::varimap[match[2]]++;
            return true;
        }
        else {
            std::cout << "[e] Error incrementing from line: " << input << std::endl;
            std::cout << "[e] Undefined variable '" << match[2] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::math::decrement(void* unused, const std::string& input, void* result) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(DECREMENT\\[)(.*?)(\\];)"))) {
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            games::mapman::varimap[match[2]]--;
            return true;
        }
        else {
            std::cout << "[e] Error decrementing from line: " << input << std::endl;
            std::cout << "[e] Undefined variable '" << match[2] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::math::multiply(void* unused, const std::string& input, void* result) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(MULTIPLY\\[)(.*?)(,\\s+)(\\d+)(\\];)"))) {
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            games::mapman::varimap[match[2]] = games::mapman::varimap[match[2]] * std::stoi(match[4]);
            return true;
        }
        else {
            std::cout << "[e] Error computing multiplication from line: " << input << std::endl;
            std::cout << "[e] Undefined variable '" << match[2] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::math::divide(void* unused, const std::string& input, void* result) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(DIVIDE\\[)(.*?)(,\\s+)(\\d+)(\\];)"))) {
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            games::mapman::varimap[match[2]] = games::mapman::varimap[match[2]] / std::stoi(match[4]);
            return true;
        }
        else {
            std::cout << "[e] Error computing division from line: " << input << std::endl;
            std::cout << "[e] Undefined variable '" << match[2] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::math::modulo(void* unused, const std::string& input, void* result) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(MODULO\\[)(.*?)(,\\s+)(\\d+)(\\];)"))) {
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            games::mapman::varimap[match[2]] = games::mapman::varimap[match[2]] % std::stoi(match[4]);
            return true;
        }
        else {
            std::cout << "[e] Error computing modulo from line: " << input << std::endl;
            std::cout << "[e] Undefined variable '" << match[2] << "'" << std::endl;
        }
    }

    return false;
}
