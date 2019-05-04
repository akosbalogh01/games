#include "instrvector.hpp"

games::instrvector::instrvector() {

}

games::instrvector::instrvector(const games::instruction param) {
    std::shared_ptr <games::instruction> new_instr = std::make_shared <games::instruction> (param);
    data.push_back(new_instr);
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
