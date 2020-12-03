#pragma once
#include "graph.h"

/**
 * Represents a collection of algorithms to run on a graph.
 */
class Algorithms {
    public:
        int **Dijkstra(); // sorts the graph based on the algorithm of Dijkstra

    private:
        std::vector<double> distances_;
         // size of array storing the flights available and the coordinates array
};