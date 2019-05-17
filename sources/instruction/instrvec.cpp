#include "instrvector.hpp"

games::instrvector::instrvector() {

}

games::instrvector::instrvector(const games::instruction& param) {
    auto new_instr = std::make_shared <games::instruction> (param);
    data.push_back(new_instr);
}

games::instrvector::instrvector(const games::instrvector& param) {
    for (auto const& index: param.data) {
        this->data.push_back(index);
    }
}

void games::instrvector::add(const std::shared_ptr <interfaces::executable>& param) {
    data.push_back(param);
}

void games::instrvector::pop(unsigned int index) {
    data.erase(data.begin() + index);
}

unsigned int games::instrvector::size() {
    return data.size();
}

void games::instrvector::execute() {
    for (auto index: data) {
        index.get()->execute();
    }
}
