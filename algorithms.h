#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <typeinfo>
#include <utility>
#include <math.h>
using namespace std;

class Algorithms {

    public:
        void insert(const string & filename); // gets the string of available flights into the vector
        void calculateDistances();
        long double toRadians(const long double degree);
        long double distance(long double lat1, long double long1, long double lat2, long double long2);
        int **createGrid(const string & filename); // creates a graph of locations
        int **Dijkstra(); // sorts the graph based on the algorithm of Dijkstra
        bool extractDouble(string txt);
        bool extractInt(string txt);


    private:
        vector< pair<double, double> > coordinates;
        vector<double> distances_;
         // size of array storing the flights available and the coordinates array
};