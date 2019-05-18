#ifndef GAMES_MOVE
#define GAMES_MOVE
#include <string>
#include <memory>
#include "vector2d.hpp"
#include "interfaces.hpp"

typedef std::shared_ptr <interfaces::executable> instr;
typedef std::shared_ptr <interfaces::conditional> cond;

namespace games {
    class move: public interfaces::executable, interfaces::conditional {
    private:
        bool         venabled;
        games::vec2d vmove;
        instr        vinstr;
        cond         vcond;

    public:
        move();
        move(const games::vec2d&);

        void setEnabled(bool);
        void setVect(const games::vec2d&);
        void buildCond(const std::string&);
        void buildInst(const std::string&);

        bool enabled() const;
        const games::vec2d& getVect() const;

        void execute();
        bool evaluate();
    };
};

#endif // GAMES_MOVE
