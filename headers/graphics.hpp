#ifndef GAMES_GRAPHICS
#define GAMES_GRAPHICS

#include <vector>
#include <string>
#include "logic.hpp"

namespace games {
    class graphics: games::logic {
        private:
            std::vector <char>  graphics_elements;
            unsigned int        graphics_elements_num;
            std::string         graphics_elements_filepath;


        public:
            explicit graphics(const char* config_filepath): logic(config_filepath) {
                graphics_elements_filepath = games::logic::logic_inifile.value("Graphics", "gfxdatabase");
                graphics_elements_num = std::stoi(games::logic::logic_inifile.value("Graphics", "elementnum"));
                std::cout << "Game Graphics constructor with config " << config_filepath << " from " << graphics_elements_filepath << " for " << graphics_elements_num << " elements" << std::endl;
                graphics_elements.clear();
                graphics_elements.resize(graphics_elements_num);
                loadGraphicsElements(graphics_elements_filepath);
            }

            void display() const;

            void loadGraphicsElements(const std::string&);
            void setGraphicsElement(unsigned int, char);


            ~graphics();
    };
};

#endif // GAMES_GRAPHICS
