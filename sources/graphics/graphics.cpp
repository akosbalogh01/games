#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include "interfaces.hpp"
#include "graphics.hpp"
#include "tile.hpp"
#include "pawn.hpp"

void games::graphics::loadCharacterVector(const std::string& filepath) {
    std::cout << "[i] Loading character vector from " << filepath << std::endl;
    std::ifstream   chartable(filepath);
    std::string     current_line;
    gfx_charactervector = std::make_shared <std::vector <char>> ();

    while (std::getline(chartable, current_line)) {
        gfx_charactervector.get()->push_back(current_line.front());
    }
}

void games::graphics::update(const std::vector <std::shared_ptr <games::pawn>>& pawns) {
    for (unsigned int i = 0; i < pawns.size(); i++) {
        std::cout << "Pawn[" << i << "] of type " << pawns[i].get()->character() << " at " << pawns[i].get()->pos1D() << std::endl;
        dynamic_cast <games::field*> (gfx_rendervector[gfx_fieldvector[pawns[i].get()->pos1D()]].get())->setCurrent(pawns[i].get()->character());
    }
}

void games::graphics::render() const {
    for (auto index: gfx_rendervector) {
        index->render();
    }
}

void games::graphics::reset() {
    for (unsigned int i = 0; i < gfx_fieldvector.size(); i++) {
        dynamic_cast <games::field*> (gfx_rendervector[gfx_fieldvector[i]].get())->reset();
    }
}

const vec_char& games::graphics::charmap() const {
    return gfx_charactervector;
}
