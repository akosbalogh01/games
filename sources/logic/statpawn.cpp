#include <regex>
#include <iostream>
#include "statfunc.hpp"
#include "vector2d.hpp"
#include "stackman.hpp"
#include "mapman.hpp"
#include "pawnman.hpp"

inline games::vec2d* buildvec(const std::string input) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(VEC2D\\[)([-]?\\d+)(,\\s+)([-]?\\d+)(\\])"))) {
        return new games::vec2d(std::stoi(match[2]), std::stoi(match[4]));;
    }
    else {
        std::cout << "[e] Failed to create 2D vector from " << input << std::endl;
    }

    return NULL;
}

bool games::statfunc::moves::defmove(void* object, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(DEFINEMOVE\\[)(\\d+)(,\\s+)(.?*)(\\];)"))) {
        if (games::vec2d* new_vector = buildvec(match[4])) {
            games::pawnman* target = (games::pawnman*) object;
            target->defineMove(std::stoi(match[2]), *new_vector);
            std::cout << "[i] Defined move " << match[4] << " on pawn[" << match[2] << "]" << std::endl;
            return true;
        }
        else {
            std::cout << "[e] Failed to define vector from " << input << std::endl;
        }
    }
    else if (std::regex_match(input, match, std::regex("(DEFINEMOVE\\[)((?:[a-z][a-z0-9_]*))(,\\s+)(.?*)(\\];)"))) {
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            if (games::vec2d* new_vector = buildvec(match[4])) {
                games::pawnman* target = (games::pawnman*) object;
                unsigned int id = games::mapman::varimap[match[2]];
                target->defineMove(id, *new_vector);
                std::cout << "[i] Defined move " << match[4] << " on pawn[" << match[2] << "]" << std::endl;
                return true;
            }
            else {
                std::cout << "[e] Failed to define vector from " << input << std::endl;
            }
        }
        else {
            std::cout << "[e] Failed to define move from " << input << std::endl;
            std::cout << "[e] Unknown identifier '" << match[2] << "'" << std::endl;
        }
    }
    else {
        std::cout << "[e] Failed to define move from " << input << std::endl;
    }

    return false;
}

bool games::statfunc::moves::dismove(void* object, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(DISABLEMOVE\\[)(\\d+)(,\\s+)(\\d+)(\\];)"))) {
        games::pawnman* target = (games::pawnman*) object;
        target->disableMove(std::stoi(match[2]), std::stoi(match[4]));
        std::cout << "[i] Disabled move[" << match[4] << "] on pawn[" << match[2] << "]" << std::endl;
    }
    else {
        std::cout << "[e] Failed to disable move from " << input << std::endl;
    }

    return false;
}

bool games::statfunc::moves::dismoves(void* object, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(DISABLEMOVES\\[)(\\d+)(\\];)"))) {
        games::pawnman* target = (games::pawnman*) object;
        target->disableMoves(std::stoi(match[2]));
        std::cout << "[i] Disabled moves of pawn[" << match[2] << "]" << std::endl;
        return true;
    }
    else if (std::regex_match(input, match, std::regex("(DISABLEMOVES\\[)(.?*)(\\];)"))) {
        games::pawnman* target = (games::pawnman*) object;
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            unsigned int id = games::mapman::varimap[match[2]];
            target->disableMoves(id);
            std::cout << "[i] Disabled moves of pawn[" << id << "]" << std::endl;
            return true;
        }
        else {
            std::cout << "[e] Failed to disable moves from " << input << std::endl;
            std::cout << "[e] Unknown identifier '" << match[2] << "'" << std::endl;
        }
    }
    else {
        std::cout << "[e] Failed to disable moves from " << input << std::endl;
    }

    return false;
}

bool games::statfunc::moves::enamove(void* object, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(ENABLEMOVE\\[)(\\d+)(,\\s+)(\\d+)(\\];)"))) {
        games::pawnman* target = (games::pawnman*) object;
        target->enableMove(std::stoi(match[2]), std::stoi(match[4]));
        std::cout << "[i] Enabled move[" << match[4] << "] of pawn[" << match[2] << "]" << std::endl;
    }
    else {
        std::cout << "[e] Failed to enable move from " << input << std::endl;
    }

    return false;
}

bool games::statfunc::moves::enamoves(void* object, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(ENABLEMOVES\\[)(\\d+)(\\];)"))) {
        games::pawnman* target = (games::pawnman*) object;
        target->enableMoves(std::stoi(match[2]));
        std::cout << "[i] Enabled moves of pawn[" << match[2] << "]" << std::endl;
        return true;
    }
    else if (std::regex_match(input, match, std::regex("(ENABLEMOVES\\[)(.?*)(\\];)"))) {
        games::pawnman* target = (games::pawnman*) object;
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            unsigned int id = games::mapman::varimap[match[2]];
            target->enableMoves(id);
            std::cout << "[i] Enabled moves of pawn[" << id << "]" << std::endl;
            return true;
        }
        else {
            std::cout << "[e] Failed to enable moves from " << input << std::endl;
            std::cout << "[e] Unknown identifier '" << match[2] << "'" << std::endl;
        }
    }
    else {
        std::cout << "[e] Failed to enable moves from " << input << std::endl;
    }

    return false;
}

bool games::statfunc::movepawn(void* object, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(move)(\\s+\\[)([-]?\\d+)(,\\s+)([-]?\\d+)(\\]\\s+\\[)([-]?\\d+)(,\\s+)([-]?\\d+)(\\])"))) {
        games::pawnman* target = (games::pawnman*) object;
        games::vec2d from(std::stoi(match[3]), std::stoi(match[5]));
        games::vec2d offs(std::stoi(match[7]), std::stoi(match[9]));

        int id = target->getPawnIndex(from);
        if (id != -1) {
            if (target->movePawn(id, offs)) {
                std::cout << "[i] Done" << std::endl;
                return true;
            }
            else {
                std::cout << "[e] Invalid move" << std::endl;
            }
        }
        else {
            std::cout << "[e] No pawn found at " << from.x() << ";" << from.y() << std::endl;
        }
    }
    else {
        std::cout << "[e] Invalid syntax, use" << std::endl;
        std::cout << "[e] (move)(\\s+\\[)(\\d+)(,\\s+)(\\d+)(\\]\\s+\\[)(\\d+)(,\\s+)(\\d+)(\\])" << std::endl;
    }

    return false;
}

// TODO: pawntype nested function call as argument
bool games::statfunc::pawn::type(void* object, const std::string& input, void* result) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(\\d+)"))) {
        games::pawnman* target = (games::pawnman*) object;
        int type = target->getPawnType(std::stoi(match[1]));
        if (type != -1) {
            //games::stackman::resstack.push_back(type);
            std::cout << "[i] Pawn[" << match[1] << "] is of type " << type << std::endl;
            *(int*) result = type;
            return true;
        }
        else {
            std::cout << "[e] Pawn[" << match[1] << "] does not exist" << std::endl;
        }
    }
    else if (std::regex_match(input, match, std::regex("(.?*)"))) {
        games::pawnman* target = (games::pawnman*) object;
        auto search = games::mapman::varimap.find(match[1]);
        if (search != games::mapman::varimap.end()) {
            unsigned int id = games::mapman::varimap[match[1]];
            int type = target->getPawnType(id);
            if (type != -1) {
                //games::stackman::resstack.push_back(type);
                std::cout << "[i] Pawn[" << match[1] << " == " << id << "] is of type " << type << std::endl;
                *(int*) result = type;
                return true;
            }
            else {
                std::cout << "[e] Pawn[" << match[1] << " == " << id << "] does not exist" << std::endl;
            }
        }
        else {
            std::cout << "[e] Error executing line " << input << std::endl;
            std::cout << "[e] Unknown identifier '" << match[1] << std::endl;
        }
    }
    else {
        std::cout << "[e] Error finding pawn type from " << input << std::endl;
    }

    return false;
}

bool games::statfunc::pawn::owner(void* object, const std::string& input, void* result) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(\\d+)"))) {
        games::pawnman* target = (games::pawnman*) object;
        int owner = target->getPawnOwner(std::stoi(match[1]));
        if (owner != -1) {
            std::cout << "[i] Pawn[" << match[1] << "] is owned by " << owner << std::endl;
            *(int*) result = owner;
            return true;
        }
        else {
            std::cout << "[e] Pawn[" << match[1] <<  "] does not exist" << std::endl;
        }
    }
    else if (std::regex_match(input, match, std::regex("(.?*)"))) {
        games::pawnman* target = (games::pawnman*) object;
        auto search = games::mapman::varimap.find(match[1]);
        if (search != games::mapman::varimap.end()) {
            unsigned int id = games::mapman::varimap[match[1]];
            int owner = target->getPawnOwner(id);
            if (owner != -1) {
                //games::stackman::resstack.push_back(type);
                std::cout << "[i] Pawn[" << match[1] << " == " << id << "] is owned by "  << owner << std::endl;
                *(int*) result = owner;
                return true;
            }
            else {
                std::cout << "[e] Pawn[" << match[1] << " == " << id << "] does not exist" << std::endl;
            }
        }
        else {
            std::cout << "[e] Error executing line " << input << std::endl;
            std::cout << "[e] Unknown identifier '" << match[1] << std::endl;
        }
    }
    else {
        std::cout << "[e] Error findinf pawn owner from " << input << std::endl;
    }

    return false;
}












