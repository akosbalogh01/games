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
        games::vec2d                pawn_pos;
        std::vector <games::vec2d>  pawn_moveset;
        char                        pawn_char;
        unsigned int                pawn_type;
        unsigned int                owner_id;

    public:
        // Constructors
        pawn(unsigned int id): pawn_id(id), pawn_pos(0, 0) {std::cout << "[i] Pawn[" << id << "] initialised." << std::endl;}

        // Member functions
        const unsigned int id() const {return pawn_id;}
        const char character() const {return pawn_char;}
        const unsigned int getType() {return pawn_type;}

        bool valid_move(const games::vec2d&);
        void pushMove(const games::vec2d&);
        void popMove(const int);
        void setOwnerID(const unsigned int);
        void setCharacter(const char);
        void setPos(const games::vec2d&);
        unsigned int pos1D() const;
        void setType(const unsigned int);
    };
};

#endif // GAMES_PAWN
