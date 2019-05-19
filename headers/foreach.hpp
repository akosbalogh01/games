#ifndef GAMES_FOREACH
#define GAMES_FOREACH
#include <memory>
#include "iterator.hpp"
#include "instrvector.hpp"

namespace games {
    class foreach: public games::iteration {
    private:
        std::string viter;
        std::shared_ptr <games::instrvector> vinstr;

    public:
        foreach(const std::string& p1, const std::string& p2): iteration(p1), viter(p2) {}

        void execute();

        void setIterator(const std::string&);
        std::string iter() const;

        void setTarget(const std::string&);
        std::string target() const;

        void bind(const std::shared_ptr <games::instrvector>&);
        const std::shared_ptr <games::instrvector>& get() const;
    };
};

#endif // GAMES_FOREACH
