#pragma once
#include "edge.h"
#include <unordered_map>
#include <algorithm>

/**
 * Represents a directed graph used to load the OpenFlights dataset. 
 * 
 * A vertex stores a single int that represents the ID of an airport. 
 * 
 * An edge between two vertices indicates one can travel from 
 * the starting airport to the destination airport. 
 * Each edge contains the distance between the two airports as well 
 * as a vector of airlines that travel between those two airports in 
 * the direction of the edge. 
 * 
 * @note This class was heavily inspired by the graph class in lab_ml.
 */
class Graph {
    public:
        /**
         * Creates an empty graph.
         */
        Graph();

        /**
         * Creates a graph with the given airports.
         */
        Graph(std::vector<AirportID> airports);

        /**
         * Inserts a new airport into the graph.
         */
        void insertAirport(AirportID airport);

        /**
         * Inserts an edge from start to end with the given distance.
         */
        void insertEdge(AirportID start, AirportID end, long double distance);
        
        /**
         * Inserts an edge from start to end with the given distance and vector of airlines.
         */
        void insertEdge(AirportID start, AirportID end, long double distance, std::vector<int> airlines);
        
        /**
         * @return A vector of all airports that share an edge with the given airport.
         */
        std::vector<AirportID> getAdjacentAirports(AirportID source);

        /**
         * @return If sourceIsStart is true, returns all airports that have an edge
         * that starts at the source. Otherwise, returns all airports that have an edge
         * that ends at the source.
         */
        std::vector<AirportID> getAdjacentAirports(AirportID source, bool sourceIsStart);

        /**
         * @return A vector of all airports in the graph.
         */
        std::vector<AirportID> getAllAirports();

        /**
         * @return An edge from start to end.
         * If no edge exists between start and end, returns a default edge.
         */
        Edge getEdge(AirportID start, AirportID end);

        /**
         * @return A vector of all edges in the graph.
         */
        std::vector<Edge> getAllEdges();

    private:
        /**
         * The adjaceny list for the graph.
         */
        std::unordered_map<AirportID, std::unordered_map<AirportID, Edge>> adjacency_list;

        /**
         * A vector of all airports in the graph.
         */
        std::vector<AirportID> airports;
};