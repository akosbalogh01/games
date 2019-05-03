#include <fstream>
#include "scriptman.hpp"

static inline std::string remove_comments(std::string);
static inline std::string remove_forwards(std::string);
static inline std::string remove_trailing(std::string);

const lexvec games::scriptman::lexer(const std::string& filepath) {
    lexvec       target;
    std::string  current_line;
    std::fstream input(filepath);

    while (std::getline(input, current_line)) {
        current_line = remove_comments(current_line);
        current_line = remove_forwards(current_line);
        current_line = remove_trailing(current_line);

        if (current_line.size() == 0) continue;
        target.push_back(current_line);
    }

    return target;
}

static inline std::string remove_comments(std::string input) {
    unsigned int pos = input.find('#');

    if (pos != std::string::npos) {
        input = input.substr(0, pos);
    }

    return input;
}

static inline std::string remove_forwards(std::string input) {
    while ((input.front() == ' ') || (input.front() == '\t')) {
        input.erase(input.begin());
    }

    return input;
}

static inline std::string remove_trailing(std::string input) {
    while ((input.back() == ' ') || (input.back() == '\t')) {
        input.erase(input.end() - 1);
    }

    return input;
}
