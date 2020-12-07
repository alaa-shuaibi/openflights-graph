#pragma once
#include "graph.h"

/**
 * Represents a collection of algorithms to run on a graph.
 */
class Algorithms {
    public:
        void BFS(Graph g, AirportID start);

        void DFS(Graph g, AirportID start);

        void Dijkstra(Graph g, int start, int end);

        void Landmark(Graph g, AirportID start, AirportID end, AirportID checkpoint);

    private:
};