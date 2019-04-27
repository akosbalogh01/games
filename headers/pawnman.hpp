#ifndef GAMES_PAWNMAN
#define GAMES_PAWNMAN
#include <vector>
#include <memory>
#include <string>
#include "pawn.hpp"

typedef std::vector <std::shared_ptr <games::pawn>> pawnvec;
typedef std::shared_ptr <games::pawn> pPawn;
typedef std::shared_ptr <std::vector <char>> charvec;

namespace games {
    class pawnman {
        private:
            pawnvec pawn_vector;
            charvec pawn_charmap;

        public:
            pPawn   createPawn(const std::string&, const unsigned int);
            void    loadPawns(const std::string&);
            void    initPawns(const std::string&);


            void    setPawnPos(const unsigned int, const games::vec2d&);
            void    setCharmap(const charvec&);
            char    getChar(const unsigned int) const;

            const pawnvec& get();
            //void    setPawnType()

            //getPawnPos
            unsigned int getPawnType(unsigned int);
    };
};

#endif
