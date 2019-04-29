#ifndef GAMES_LOGIC
#define GAMES_LOGIC
#include <vector>
#include <map>
#include <string>
#include <memory>
#include "interfaces.hpp"
#include "inifile.hpp"
#include "graphics.hpp"
#include "pawnman.hpp"
#include "mapman.hpp"

typedef std::vector <std::shared_ptr <interfaces::triggerable>> cmdvector;
typedef std::shared_ptr <interfaces::callable> callable;

namespace games {
    class logic {
        private:
            unsigned int        logic_moves;
            bool                logic_running, logic_valid;
            cmdvector           logic_commands;
            ini::inifile        logic_inifile;
            std::string         logic_script_path;
            games::graphics     logic_gfx;
            games::pawnman      logic_pawnman;
            const games::mapman logic_mapman;

            void            pushDefaultCommands();
            void            loadFunctionMap();

        public:
            logic(): logic_mapman(this) {
                logic_running = logic_valid = false;
            }

            logic(const char* filepath): logic_mapman(this) {
                logic_running = logic_valid = false;
                loadConfig(filepath);
            }

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
