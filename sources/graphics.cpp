#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include "interfaces.hpp"
#include "graphics.hpp"
#include "tile.hpp"
#include "pawn.hpp"

void games::graphics::loadRenderVector(const std::string& filepath) {
    std::cout << "[i] Loading render vector from " << filepath << std::endl;
    std::ifstream   gfxtable(filepath);
    std::string     current_line;
    char            current_char;
    std::shared_ptr <interfaces::tile> new_field;
    std::shared_ptr <interfaces::tile> new_cosmetic;

    while (std::getline(gfxtable, current_line)) {
        while (current_line.size()) {
            current_char = current_line.front();

            switch (current_char) {
            case '#':
                new_field = std::make_shared <games::field> (' ');
                gfx_fieldvector.push_back(gfx_rendervector.size());
                gfx_rendervector.push_back(new_field);
                break;

            default:
                new_cosmetic = std::make_shared <games::cosmetic> (current_char);
                gfx_rendervector.push_back(new_cosmetic);
                break;
            }

            current_line.erase(current_line.begin());
        }

        new_cosmetic = std::make_shared <games::cosmetic> ('\n');
        gfx_rendervector.push_back(new_cosmetic);
    }
}

void games::graphics::loadCharacterVector(const std::string& filepath) {
    std::cout << "[i] Loading character vector from " << filepath << std::endl;
    std::ifstream   chartable(filepath);
    std::string     current_line;

    while (std::getline(chartable, current_line)) {
        gfx_charactervector.push_back(current_line.front());
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

char games::graphics::character(unsigned int index) const {
    return gfx_charactervector[index];
}
