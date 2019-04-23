#ifndef GAMES_TILE
#define GAMES_TILE

#include <iostream>
#include "interfaces.hpp"

namespace games {
    class cosmetic: public interfaces::tile {
    private:
        char data;
    public:
        cosmetic(char param): data(param) {}
        void render() const {std::cout << data;}

        void setData(char param) {data = param;}
    };

    class field: public interfaces::tile {
    private:
        bool valid;
        char current_data;
        char default_data;

    public:
        field(char param): default_data(param) {}

        void render() const {std::cout << (current_data == default_data ? default_data : current_data);}

        void setDefault(char param) {default_data = param;}
        void setCurrent(char param) {current_data = param;}
        void reset() {current_data = default_data;}
    };
};

#endif // GAMES_TILE
