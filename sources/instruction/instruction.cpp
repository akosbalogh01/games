#include <string>
#include <functional>
#include "instruction.hpp"

void games::instruction::execute() {
    return;
}

void games::instruction::setObject(void* param) {
    object_ = param;
}

void games::instruction::setArgs(const std::string& param) {
    args_ = param;
}

void games::instruction::bind(const std::function <bool (void*, std::string)>& param) {
    target_ = param;
}

void* games::instruction::object() {
    return object_;
}

const std::string games::instruction::args() {
    return args_;
}

const std::function <bool (void*, std::string)> games::instruction::get() {
    return target_;
}
