#include <string>
#include <iostream>
#include <functional>
#include "instruction.hpp"

void games::instruction::execute() {

    if (target_(object_, args_, result_)) {
        std::cout << "[i] Execution successful." << std::endl;
    }
    else {
        std::cout << "[i] Execution failed." << std::endl;
    }

    return;
}

void games::instruction::setObject(void* param) {
    object_ = param;
}

void games::instruction::setArgs(const std::string& param) {
    args_ = param;
}

void games::instruction::bind(const std::function <bool (void*, std::string, void*)>& param) {
    target_ = param;
}

void* games::instruction::object() {
    return object_;
}

const std::string games::instruction::args() {
    return args_;
}

const std::function <bool (void*, std::string, void*)> games::instruction::get() {
    return target_;
}
