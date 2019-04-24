#ifndef GAMES_LOGIC
#define GAMES_LOGIC
#include <vector>
#include <string>
#include <memory>
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
            void            pushDefaultCommands();
            cmdvector       logic_commands;
            std::shared_ptr <ini::inifile> logic_inifile;
            std::string     logic_script_path;
            games::graphics logic_gfx;
            games::pawnman  logic_pawnman;
            //std::vector     <std::shared_ptr <games::pawn>> logic_pawns;
            //to do: create pawnmanager class to relocate the public methods of games::logic

        public:
            logic();
            logic(const char*);

            void                loadConfig(const std::string&);
            void                processInput();
            void                nextMove();
            void                display();

            //these methods below will be moved
            //void                loadPawns(const std::string&);
            //void                initPawns(const std::string&);
            //void                setPawnPos(const unsigned int, const games::vec2d&);
            //std::shared_ptr <games::pawn> createPawn(const std::string&, const unsigned int);


            void                setRunning(const bool);

            unsigned int        moves() const;
            const bool          isRunning() const;
    };
};

#endif // GAMES_LOGIC
