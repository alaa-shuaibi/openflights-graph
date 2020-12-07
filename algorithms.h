#pragma once
#include "graph.h"

/**
 * Represents a collection of algorithms to run on a graph.
 */
class Algorithms {
    public:
        void BFS(Graph g, AirportID start);

        void DFS(Graph g, AirportID start);

        double Dijkstra(Graph g, int starting_Airport, int ending_Airport);

        void Landmark(Graph g, AirportID start, AirportID end, AirportID checkpoint);

    private:
};