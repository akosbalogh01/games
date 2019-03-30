#ifndef GAMES_LOGIC
#define GAMES_LOGIC

#include <vector>
#include <string>
#include "interfaces.hpp"
#include "inifile.hpp"

namespace games {
    class logic {
        private:
            unsigned int    logic_moves;
            bool            logic_running;
            std::vector <interfaces::triggerable> logic_commands;
            std::string     logic_inputstring;

        protected:
            ini::inifile    logic_inifile;
            std::string     logic_script_path;

        public:
            explicit logic(const char* fp): logic_inifile(fp) {
                std::cout << "Game Logic constructor with config " << fp << std::endl;
                logic_script_path   = fp;
                logic_moves         = 0;
                logic_running       = false;
            }

            virtual void        display() const {};
            void                processInput();
            void                nextMove();

            void                setRunning(const bool);

            unsigned int        moves() const;
            const bool          isRunning() const;
    };
};

#endif // GAMES_LOGIC
