#include "iterator.hpp"

std::string games::iteration::args() {
    return vargs;
}

void games::iteration::setArgs(const std::string& param) {
    vargs = param;
}
