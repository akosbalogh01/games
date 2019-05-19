#ifndef GAMES_PAWN
#define GAMES_PAWN
#include <iostream>
#include <string>
#include <vector>
#include "move.hpp"
#include "vector2d.hpp"

// TODO: add condition vector to pawn moves
// TODO: add post-process instructionvector to pawn moves

namespace games {
    class pawn {
    private:
        const unsigned int          pawn_id;
        games::vec2d                pawn_pos;
        std::vector <games::move>   pawn_moveset;
        char                        pawn_char;
        unsigned int                pawn_type;
        unsigned int                owner_id;

    public:
        // Constructors
        pawn(unsigned int id): pawn_id(id), pawn_pos(0, 0) {
            std::cout << "[i] Pawn[" << id << "] initialised." << std::endl;
        }

        // Member functions
        const unsigned int id() const {return pawn_id;}
        const char character() const {return pawn_char;}
        const unsigned int getType() const {return pawn_type;}
        const games::vec2d& getPos() const {return pawn_pos;}

        bool move(const games::vec2d&);
        void setMoveEnabled(unsigned int, const bool);
        void pushMove(const games::vec2d&);
        void popMove(const int);
        void setOwnerID(const unsigned int);
        void setCharacter(const char);
        void setPos(const games::vec2d&);
        unsigned int pos1D() const;
        void setType(const unsigned int);

        void enableMoves();
        void enableMove(unsigned int);
        void enableMove(const games::vec2d&);

        void disableMoves();
        void disableMove(unsigned int);
        void disableMove(const games::vec2d&);
    };
};

#endif // GAMES_PAWN
