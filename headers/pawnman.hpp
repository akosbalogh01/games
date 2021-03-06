#ifndef GAMES_PAWNMAN
#define GAMES_PAWNMAN
#include <vector>
#include <memory>
#include <string>
#include "pawn.hpp"
#include "vector2d.hpp"

typedef std::vector <std::shared_ptr <games::pawn>> pawnvec;
typedef std::shared_ptr <games::pawn> pPawn;
typedef std::shared_ptr <std::vector <char>> charvec;
typedef unsigned int uint;

namespace games {
    class pawnman {
        private:
            pawnvec pawn_vector;
            charvec pawn_charmap;

        public:
            static uint pawn_index;

            bool    createPawn(uint, uint);
            bool    setPawnPos(const uint, const games::vec2d&);
            void    setCharmap(const charvec&);
            char    getChar(const uint) const;
            uint    getPawnType(uint);
            int     getPawnIndex(const games::vec2d&);
            int     getPawnOwner(uint);

            void    defineMove(uint, const games::vec2d&);
            void    enableMoves(uint);
            void    enableMove(uint, uint);
            void    enableMove(uint, const games::vec2d&);

            void    disableMoves(uint);
            void    disableMove(uint, uint);
            void    disableMove(uint, const games::vec2d&);
            bool    movePawn(uint, const games::vec2d&);

            const pawnvec& get();
    };
};

#endif
