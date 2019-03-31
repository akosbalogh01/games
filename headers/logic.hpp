#ifndef GAMES_LOGIC
#define GAMES_LOGIC

#include <vector>
#include <string>
#include <memory>
#include "interfaces.hpp"
#include "inifile.hpp"

namespace games {
    class logic {
        private:
            unsigned int    logic_moves;
            bool            logic_running, logic_valid;
            void            pushDefaultCommands();
            std::vector <std::shared_ptr <interfaces::triggerable>> logic_commands;
            std::shared_ptr <ini::inifile> logic_inifile;
            std::string     logic_script_path;

        public:
            logic();
            logic(const char*);

            void                loadConfig(const std::string&);
            void                processInput();
            void                nextMove();

            void                setRunning(const bool);

            unsigned int        moves() const;
            const bool          isRunning() const;
    };
};

#endif // GAMES_LOGIC
