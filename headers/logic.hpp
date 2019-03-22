#ifndef GAMES_LOGIC
#define GAMES_LOGIC

#include <string>
#include "inifile.hpp"

namespace games {
    class logic {
        protected:
            ini::inifile    logic_inifile;
            std::string     logic_script_path;
            unsigned int    logic_moves;
            bool            logic_running;

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
