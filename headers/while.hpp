#ifndef GAMES_WHILE
#define GAMES_WHILE
#include <memory>
#include "iterator.hpp"
#include "instrvector.hpp"

namespace games {
    class whileloop: public games::iteration {
    private:
        std::shared_ptr <interfaces::conditional> vcond;

    public:
        whileloop() {}

        void execute();
        bool build(const std::string&);

        void bind(const std::shared_ptr <games::instrvector>&);
        const std::shared_ptr <games::instrvector>& get() const;
    };
};

#endif // GAMES_WHILE
