#pragma once

#include <string>
#include <vector>

class InputParser {
public:
    InputParser(int argc, char **argv);
    std::string getCmdOption(std::string option) const;
    bool cmdOptionExists(std::string option) const;
private:
    std::vector<std::string> tokens;
};