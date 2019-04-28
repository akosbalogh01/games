#ifndef GAMES_CALLABLE
#define GAMES_CALLABLE
#include <functional>
#include "interfaces.hpp"

namespace games {
    template <class ret_type, class arg_type>
    class call1arg: public interfaces::callable {
        private:
            std::string c_key;
            std::function <ret_type (arg_type)> target;

        public:
            call1arg (const std::function <ret_type (arg_type)>& param): target(param) {}

            void bind(const std::function <ret_type (arg_type)>& param) {target = param;}
            void bind(const std::string& param) {c_key = param;}

            const std::function <ret_type (arg_type)>& get() {return target;}
            const std::string key() {return c_key;}
    };

    template <class ret_type, class arg1_type, class arg2_type>
    class call2arg: public interfaces::callable {
        private:
            std::string c_key;
            std::function <ret_type (arg1_type, arg2_type)> target;

        public:
            call2arg (const std::function <ret_type (arg1_type, arg2_type)>& param): target(param) {}

            void bind(const std::function <ret_type (arg1_type, arg2_type)>& param) {target = param;}
            void bind(const std::string& param) {c_key = param;}

            const std::function <ret_type (arg1_type, arg2_type)>& get() {return target;}
            const std::string key() {return c_key;}
    };

    template <class ret_type, class arg1_type, class arg2_type, class arg3_type>
    class call3arg: public interfaces::callable {
        private:
            std::string c_key;
            std::function <ret_type (arg1_type, arg2_type, arg3_type)> target;

        public:
            call3arg (const std::function <ret_type (arg1_type, arg2_type, arg3_type)>& param): target(param) {}

            void bind(const std::function <ret_type (arg1_type, arg2_type, arg3_type)>& param) {target = param;}
            void bind(const std::string& param) {c_key = param;}

            const std::function <ret_type (arg1_type, arg2_type, arg3_type)>& get() {return target;}
            const std::string key() {return c_key;}
    };
};

#endif
