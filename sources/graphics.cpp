#include <iostream>
#include <fstream>
#include <string>
#include "graphics.hpp"
/*
void games::graphics::loadGraphicsElements(const std::string& filepath) {
    std::ifstream   data(filepath);
    std::string     line;
    unsigned int i = 0;
    char temp;
    while (i < graphics_elements_num) {
        std::getline(data, line);
        temp = line.back();
        setGraphicsElement(i, temp);
        i++;
        std::cout << temp << std::endl;
    }
}

void games::graphics::setGraphicsElement(unsigned int index, char element) {
    if (index < graphics_elements.size()) graphics_elements.assign(index, element);
}

games::graphics::~graphics() {
    unsigned int i = 0;
    std::cout << "Deconstructing Graphics elements vector:" << std::endl;

    while (i < graphics_elements_num) {
        std::cout << '[' << i << "]:" << graphics_elements[i] << std::endl;
        i++;
    }

    graphics_elements.clear();
}
*/
