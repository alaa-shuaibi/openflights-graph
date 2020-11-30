#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

class readFromFile{
    public:
        std::string file_to_string(const std::string &s);
        std::vector<std::string> file_to_vector(const std::string &s);
};