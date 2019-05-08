#include "condvec.hpp"

bool games::condvec::evaluate() {
    if (vec.size() == 0) return true;
    else {
        for (const auto index: vec) {
            if (index.get()->evaluate() == false) return false;
        }
    }

    return true;
}
