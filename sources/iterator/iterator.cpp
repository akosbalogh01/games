#include "iterator.hpp"

void games::iteration::execute() {
    vinstr.get()->execute();
}


void games::iteration::bind(const std::shared_ptr <games::instrvector>& param) {
    vinstr = param;
}

const std::shared_ptr <games::instrvector>& games::iteration::get() const {
    return vinstr;
}
