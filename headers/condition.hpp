#ifndef GAMES_CONDITION
#define GAMES_CONDITION
#include <functional>
#include "interfaces.hpp"

namespace games {
    template <class compare_type>
    class condition: public interfaces::conditional {
        private:
            compare_type  ca1, ca2;
            std::function <compare_type ()> arg1;
            std::function <compare_type ()> arg2;
            std::function <bool (compare_type, compare_type)> comparation;

        public:
            condition(const std::function <compare_type ()>& a1, const std::function <compare_type ()>& a2): arg1(a1), arg2(a2) {
                ca1 = ca2 = 0;
            }

            condition(const std::function <compare_type ()>& a1, const compare_type a2):arg1(a1) {
                ca1 = 0;
                ca2 = a2;
            }

            bool evaluate() {
                if (arg1) {ca1 = arg1();}
                if (arg2) {ca2 = arg2();}
                return comparation(ca1, ca2);
            }

            void bind(const std::function <bool (compare_type, compare_type)>& param) {comparation = param;}

    };
};

#endif // GAMES_CONDITION
