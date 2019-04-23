#ifndef GAMES_PAWN
#define GAMES_PAWN
#include <iostream>
#include <string>
#include <vector>
#include "vector2d.hpp"

namespace games {
    class pawn {
    private:
        const unsigned int          pawn_id;
        std::vector <games::vec2d>  pawn_moveset;
        char                        pawn_char;
        unsigned int                owner_id;

    public:
        // Constructors
        pawn(unsigned int id): pawn_id(id) {std::cout << "[i] Pawn[" << id << "] initialised." << std::endl;}

        // Member functions
        const unsigned int id() const {return pawn_id;}

        bool valid_move(const games::vec2d&);
        void pushMove(const games::vec2d&);
        void popMove(const int);
        void setOwnerID(const unsigned int);
        void setCharacter(const char);
    };
};

#endif // GAMES_PAWN
