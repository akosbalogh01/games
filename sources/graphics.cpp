#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include "interfaces.hpp"
#include "graphics.hpp"
#include "tile.hpp"

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

void games::graphics::render() const {
    for (auto index: gfx_rendervector) {
        index->render();
    }
}

char games::graphics::character(unsigned int index) const {
    return gfx_charactervector[index];
}
