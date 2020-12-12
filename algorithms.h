#pragma once
#include "graph.h"
#include <iostream>

/**
 * Represents a collection of algorithms to run on a graph.
 */
class Algorithms {
    public:
        /**
         * Traverses through the entire graph using the BFS algorithm.
         * 
         * @return A vector of all visited airports in the order they were visited.
         */
        std::vector<AirportID> BFS(Graph g);

        /**
         * Traverses through the entire connected component that start is located in using the BFS algorithm.
         * 
         * @param visited Used by BFS(Graph g) to keep track of visited airports. 
         * @param path Used by BFS(Graph g) generate a path of airports in the order they were visited.
         * @return A vector of all visited airports in the order they were visited. 
         * If path is passed in with at least 1 element, it will be adjusted to contain the newly visited airports and then returned.
         */
        std::vector<AirportID> BFS(Graph g, AirportID start, std::unordered_map<AirportID, bool> & visited, std::vector<AirportID> path);

        /**
         * Traverses through the entire graph using the DFS algorithm.
         * 
         * @return A vector of all visited airports in the order they were visited.
         */
        std::vector<AirportID> DFS(Graph g);

        /**
         * Traverses through the entire connected component that start is located in using the DFS algorithm.
         * 
         * @param visited Used by DFS(Graph g) to keep track of visited airports. 
         * @param path Used by DFS(Graph g) generate a path of airports in the order they were visited.
         * @return A vector of all visited airports in the order they were visited. 
         * If path is passed in with at least 1 element, it will be adjusted to contain the newly visited airports and then returned.
         */
        std::vector<AirportID> DFS(Graph g, AirportID start, std::unordered_map<AirportID, bool> & visited, std::vector<AirportID> path);

        /**
         * Given two airports start and end, finds the shortest path from start to end.
         * @return A vector representing the shortest path.
         */
        std::vector<AirportID> Dijkstra(Graph g, AirportID start, AirportID end);

        /**
         * Given two airports start and end, finds the shortest path from start to end through 
         * a checkpoint airport.
         * @return A vector representing the shortest path.
         */ 
        std::vector<AirportID> Landmark(Graph g, AirportID start, AirportID end, AirportID checkpoint);
};