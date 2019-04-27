#ifndef GAMES_LOGIC
#define GAMES_LOGIC
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <functional>
#include "interfaces.hpp"
#include "inifile.hpp"
#include "graphics.hpp"
#include "pawnman.hpp"

typedef std::vector <std::shared_ptr <interfaces::triggerable>> cmdvector;

namespace games {
    class logic {
        private:
            unsigned int    logic_moves;
            bool            logic_running, logic_valid;
            cmdvector       logic_commands;
            ini::inifile    logic_inifile;
            std::string     logic_script_path;
            games::graphics logic_gfx;
            games::pawnman  logic_pawnman;

            void            pushDefaultCommands();
            void            loadConditionMap();

        public:
            logic();
            logic(const char*);

            static std::map <std::string, std::function <unsigned int (unsigned int)>> logic_condmap;

            void                loadConfig(const std::string&);
            void                processInput();
            void                nextMove();
            void                display();

            void                setRunning(const bool);

            unsigned int        moves() const;
            const bool          isRunning() const;
    };
};

#endif // GAMES_LOGIC
