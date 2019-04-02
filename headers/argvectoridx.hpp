#ifndef GAMES_ARGVECTOR_INDEX
#define GAMES_ARGVECTOR_INDEX

namespace games {
    class argvindex {
    private:
        const unsigned int index;

    public:
        argvindex(unsigned int param): index(param) {}

        unsigned int data() {return index;}
    };
};

#endif
