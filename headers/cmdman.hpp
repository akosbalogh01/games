#ifndef GAMES_COMMANDMAN
#define GAMES_COMMANDMAN
#include <map>
#include "command.hpp"

namespace games {
    class cmdman {
    private:
        void init_cmdmap();

    public:
        static std::map <std::string, games::command> cmdmap;

        cmdman() {
            init_cmdmap();
        }

        bool addcmd(const std::string&);
        void process(const std::string&);
    };
};

#endif // GAMES_COMMANDMAN

//DEFINE_CMD[REGEXSET[REGEX[trigger1], REGEX[trigger2]], ];
