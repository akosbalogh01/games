#ifndef GAMES_CONDITION
#define GAMES_CONDITION
#include <functional>
#include "interfaces.hpp"

namespace games {
    template <class compare_type>
    class condition: public interfaces::conditional {
        private:
            std::function <compare_type ()> arg1;
            std::function <compare_type ()> arg2;
            std::function <bool (compare_type, compare_type)> comparation;

        public:
            condition(const std::function <compare_type ()>& a1, const std::function <compare_type ()>& a2): arg1(a1), arg2(a2) {}

            bool evaluate() const {return comparation(arg1(), arg2());}

            void bind(const std::function <bool (compare_type, compare_type)>& param) {comparation = param;}

    };
};

#endif // GAMES_CONDITION
