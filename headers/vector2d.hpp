#ifndef GAMES_VEC2D
#define GAMES_VEC2D

namespace games {
    class vec2d {
    private:
        int coord_x;
        int coord_y;

    public:
        vec2d(int x, int y): coord_x(x), coord_y(y) {}

        const int x() const {return coord_x;}
        const int y() const {return coord_y;}

        void setX(int x) {coord_x = x;}
        void setY(int y) {coord_y = y;}
    };
/*
    bool operator==(const vec2d& p1, const vec2d& p2) {
        return (p1.x() == p2.x() && p1.y() == p2.y());
    }
*/
};

#endif // GAMES_VEC2D
