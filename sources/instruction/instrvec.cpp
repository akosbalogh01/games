#include "instrvector.hpp"

void games::instrvector::add(const std::shared_ptr <games::instruction>& param) {
    data.push_back(param);
}

void games::instrvector::pop(unsigned int index) {
    data.erase(data.begin() + index);
}

void games::instrvector::execute() {
    for (auto index: data) {
        index.get()->execute();
    }
}
