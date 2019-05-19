#include "iterator.hpp"

std::string games::iteration::target() const {
    return vtarget;
}

void games::iteration::setTarget(const std::string& param) {
    vtarget = param;
}

void games::iteration::execute() {
    return;
}
