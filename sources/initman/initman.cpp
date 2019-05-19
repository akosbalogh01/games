#include "initman.hpp"
#include "mapman.hpp"

void games::initman::init() {
    games::mapman::funvmap["INIT"].execute();
}

void games::initman::main() {
    games::mapman::funvmap["MAIN"].execute();
}
