#ifndef GAMES_VEC2D
#define GAMES_VEC2D

namespace games {
    class vec2d {
    private:
        int coord_x;
        int coord_y;

    public:
        vec2d(): coord_x(0), coord_y(0) {}
        vec2d(const vec2d& param): coord_x(param.coord_x), coord_y(param.coord_y) {}
        vec2d(int x, int y): coord_x(x), coord_y(y) {}

        const int x() const {return coord_x;}
        const int y() const {return coord_y;}

        void setX(int x) {coord_x = x;}
        void setY(int y) {coord_y = y;}

        bool operator==(const vec2d& p) const {
            return (this->coord_x == p.coord_x) && (this->coord_y == p.coord_y);
        }
    };
};

#endif // GAMES_VEC2D
