#include <string>
#include <iostream>
#include <functional>
#include "instruction.hpp"

games::instruction::instruction(const games::instruction& p2) {
    this->vobject = p2.vobject;
    this->vtarget = p2.vtarget;
    this->vargs   = p2.vargs;
    this->vresult = p2.vresult;
}

void games::instruction::execute() {
    if (vtarget(vobject, vargs, vresult)) {
        std::cout << "[i] Execution successful." << std::endl;
    }
    else {
        std::cout << "[i] Execution failed." << std::endl;
    }
}

void games::instruction::setObject(void* param) {
    vobject = param;
}

void games::instruction::setArgs(const std::string& param) {
    vargs = param;
}

void games::instruction::bind(const std::function <bool (void*, std::string, void*)>& param) {
    vtarget = param;
}

void* games::instruction::object() {
    return vobject;
}

const std::string games::instruction::args() {
    return vargs;
}

const std::function <bool (void*, std::string, void*)> games::instruction::get() {
    return vtarget;
}
