#ifndef GAMES_LOGIC
#define GAMES_LOGIC

#include <vector>
#include <string>
#include <memory>
#include "interfaces.hpp"
#include "inifile.hpp"
#include "graphics.hpp"
#include "pawn.hpp"

typedef std::vector <std::shared_ptr <interfaces::triggerable>> cmdvector;

namespace games {
    class logic {
        private:
            unsigned int    logic_moves;
            bool            logic_running, logic_valid;
            void            pushDefaultCommands();
            cmdvector       logic_commands;
            std::shared_ptr <ini::inifile> logic_inifile;
            std::string     logic_script_path;
            games::graphics logic_gfx;
            std::vector     <std::shared_ptr <games::pawn>> logic_pawns;

        public:
            logic();
            logic(const char*);

            void                loadConfig(const std::string&);
            void                processInput();
            void                nextMove();
            void                display();
            void                loadPawns(const std::string&);
            std::shared_ptr <games::pawn> createPawn(const std::string&, const unsigned int);

            void                setRunning(const bool);

            unsigned int        moves() const;
            const bool          isRunning() const;
    };
};

#endif // GAMES_LOGIC
