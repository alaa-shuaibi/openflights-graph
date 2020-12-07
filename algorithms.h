#pragma once
#include "graph.h"

/**
 * Represents a collection of algorithms to run on a graph.
 */
class Algorithms {
    public:
        void BFS();

        void DFS();

        double Dijkstra(int starting_Airport, int ending_Airport);

        void Landmark();

    private:
};