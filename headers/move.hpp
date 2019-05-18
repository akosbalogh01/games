#ifndef GAMES_MOVE
#define GAMES_MOVE
#include "vector2d.hpp"

namespace games {
    class move {
    private:
        bool venabled;
        games::vec2d vmove;

    public:
        move();
        move(const games::vec2d&);

        void setEnabled(bool);
        void setVect(const games::vec2d&);

        bool enabled() const;
        const games::vec2d& getVect() const;
    };
};

#endif // GAMES_MOVE
