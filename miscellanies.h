#pragma once
#include "readFromFile.h"
#include <stdlib.h>
#include <typeinfo>
#include <utility>
#include <math.h>

using std::string;
using std::vector;
using std::stringstream;
using std::istringstream;
using std::ws;

/**
 * Represents a collection of miscellaneous functions that will be used
 * for our final project.
 */
class Miscellanies {
    public:
        //void insert(const string & filename); // gets the string of available flights into the vector
        void calculateDistances();
        long double toRadians(const long double degree);
        long double distance(long double lat1, long double long1, long double lat2, long double long2);
        int **createGrid(const string & filename); // creates a graph of locations
        bool extractDouble(string txt);
        bool extractInt(string txt);
        int getIndex(string line);
        string airport_name(string line);
        string airport_city(string line);
        string airport_country(string line);
        long double airport_latitude(string line);
        long double airport_longitude(string line);

    private:
        vector<double> distances_;
        // size of array storing the flights available and the coordinates array
};