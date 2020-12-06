#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>

/**
 * Represents a collection of functions to read files. 
 * @author CS 225 Staff
 */
class readFromFile {
    public:
        /** 
        * Reads a file into a string
        * @param filename The file to read from 
        * @return a string containing filename's contents
        */
        std::string file_to_string(const std::string &s);

        /** 
        * Reads a file into a vector
        * @param filename The file to read from
        * @return a vector containing filename's contents
        */
        std::vector<std::string> file_to_vector(const std::string &s);
};