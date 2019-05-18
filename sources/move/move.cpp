#include "move.hpp"

games::move::move() {
    venabled = false;
    vmove = games::vec2d(0, 0);
}

games::move::move(const games::vec2d& param) {
    venabled = true;
    vmove = param;
}

void games::move::setEnabled(bool param) {
    venabled = param;
}

void games::move::setVect(const games::vec2d& param) {
    vmove = param;
}

bool games::move::enabled() const {
    return venabled;
}

const games::vec2d& games::move::getVect() const {
    return vmove;
}

void games::move::execute() {
    vinstr.get()->execute();
}

bool games::move::evaluate() {
    return vcond.get()->evaluate();
}

void games::move::buildCond(const std::string& input) {
    //vcond.get()->build(input);
}

void games::move::buildInst(const std::string& input) {
    //vinstr.get()->build(input);
}
