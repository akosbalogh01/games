#ifndef GAMES_FUNCTION
#define GAMES_FUNCTION
#include <functional>
#include <string>

namespace games {
    template <class ret_type>
    class function {
    private:
        void* object_;
        std::function <ret_type (void*, std::string)> target_;
        std::string args_;

    public:
        function() {}
        function(void* p1, const std::function <ret_type (void*, std::string)>& p2): object_(p1), target_(p2) {}

        void setObject(void* param) {object_ = param;}
        void setArgs(const std::string& param) {args_ = param;}
        void bind(const std::function <ret_type (void*, std::string)>& param) {target_ = param;}

        void* object() {return object_;}
        const std::string args() {return args_;}
        const std::function <ret_type (void*, std::string)> get() {return target_;}
    };
};

#endif
