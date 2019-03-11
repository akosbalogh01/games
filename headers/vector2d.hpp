#ifndef GAMES_VEC2D
#define GAMES_VEC2D

namespace games {
    class vec2d {
    private:
        int coord_x;
        int coord_y;

    public:
        vec2d(int x, int y): coord_x(x), coord_y(y) {}

        const int x() {return coord_x;}
        const int y() {return coord_y;}

        void setX(int x) {coord_x = x;}
        void setY(int y) {coord_y = y;}
    };
};

#endif // GAMES_VEC2D
