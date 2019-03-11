#ifndef GAMES_PAWN
#define GAMES_PAWN
#include <string>
#include <vector>
#include "vector2d.hpp"

namespace games {
    class pawn {
    private:
        const unsigned int          pawn_id;
        std::string                 pawn_name;
        bool                        pawn_flag;
        std::vector <games::vec2d>  pawn_moveset;

    public:
        // Constructors
        pawn(unsigned int id): pawn_id(id) {std::cout << "[LOG] Pawn[" << id << "] initialised." << std::endl;}

        // Member functions
        const unsigned int id() const {return pawn_id;}
        const std::string& name() const {return pawn_name;}

        void move(const games::vec2d&);
        void pushMove(const games::vec2d&);
        void popMove(const int);

    };
};

#endif // GAMES_PAWN
