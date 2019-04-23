#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "logic.hpp"

void games::logic::loadPawns(const std::string& filepath) {
    std::cout << "[i] Loading initial pawns from " << filepath << std::endl;
    unsigned int    new_pawn_index = 0;
    std::ifstream   pawncreate(filepath);
    std::string     current_line;
    std::shared_ptr <games::pawn> new_pawn;

    while(std::getline(pawncreate, current_line)) {
        if (new_pawn = createPawn(current_line, new_pawn_index)) {
            logic_pawns.push_back(new_pawn);
            new_pawn_index++;
        }
    }
}