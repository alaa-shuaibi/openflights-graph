#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

class readFromFile{
    public:
        std::string file_to_string(std::string) const;
        std::vector<std::string> file_to_vector(std::string) const;
};