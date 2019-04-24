#ifndef GAMES_GRAPHICS
#define GAMES_GRAPHICS

#include <vector>
#include <string>
#include <memory>
#include "tile.hpp"
#include "pawn.hpp"

typedef std::vector <unsigned int>                          vec_field;
typedef std::vector <std::shared_ptr <interfaces::tile>>    vec_render;
typedef std::vector <std::shared_ptr <games::pawn>>         vec_pawn;
typedef std::shared_ptr <std::vector <char>>                vec_char;

namespace games {
    class graphics {
        private:
            vec_field   gfx_fieldvector;
            vec_render  gfx_rendervector;
            vec_char    gfx_charactervector;

        public:
            void    loadRenderVector(const std::string&);
            void    loadCharacterVector(const std::string&);
            void    render() const;
            void    update(const vec_pawn&);
            void    reset();
            const   vec_char& charmap() const;
    };
};

#endif // GAMES_GRAPHICS
