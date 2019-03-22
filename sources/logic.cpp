#include <string>
#include "logic.hpp"

/*games::logic::logic(const char* filepath) {
    logic_script_path = filepath;

}
*/
void games::logic::setRunning(const bool param) {
    logic_running = param;
}

unsigned int games::logic::moves() const {
    return logic_moves;
}

const bool games::logic::isRunning() const {
    return logic_running;
}
