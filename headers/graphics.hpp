#ifndef GAMES_GRAPHICS
#define GAMES_GRAPHICS

#include <vector>
#include <string>
#include "logic.hpp"
#include "inifile.hpp"

namespace games {
    class graphics {
        private:
            std::vector <char>  gfx_rendervector;

        public:

            void loadRenderVector(const std::string&);

    };
};

#endif // GAMES_GRAPHICS
