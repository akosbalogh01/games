#ifndef GAMES_LOGIC
#define GAMES_LOGIC
#include <vector>
#include <string>
#include <memory>
#include "interfaces.hpp"
#include "inifile.hpp"
#include "graphics.hpp"
#include "pawnman.hpp"
#include "mapman.hpp"
#include "initman.hpp"

namespace games {
    class logic {
        friend class games::mapman;
        private:
            unsigned int    logic_moves;
            bool            logic_running, logic_valid;
            ini::inifile    logic_inifile;
            std::string     logic_script_path;
            games::graphics logic_gfx;
            games::pawnman  logic_pawnman;
            games::initman  logic_initman;
            games::mapman   logic_mapman;

        public:
            logic(const logic&) = delete;
            logic(): logic_mapman(this) {
                logic_running = logic_valid = true;
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
