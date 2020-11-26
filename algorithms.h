#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Algorithms {

    public:
        void insert(const string & filename); // gets the string of available flights into the vector
        int **createGrid(const string & filename); // creates a graph of locations
        int **Dijkstra(); // sorts the graph based on the algorithm of Dijkstra


    private:
        vector<string> Flights_Available;
        vector<double> coordinates_; // 
        int size_; // size of array storing the flights available and the coordinates array
        double longitude; // current location longitude
        double lattitude; // current location lattitude
};