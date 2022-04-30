#include "InputParser.h"

InputParser::InputParser(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        this->tokens.emplace_back(std::string(argv[i]));
    }
}

std::string InputParser::getCmdOption(std::string option) const {
    std::vector<std::string>::const_iterator itr;
    itr = std::find(this->tokens.begin(), this->tokens.end(), option);
    if (itr != this->tokens.end() && ++itr != this->tokens.end()){
        return *itr;
    }

    return "";
}

bool InputParser::cmdOptionExists(std::string option) const {
    return std::find(this->tokens.begin(), this->tokens.end(), option)
            != this->tokens.end();
}
