#pragma once
#include "edge.h"
#include <unordered_map>

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
         * Inserts an airline into the edge from start to end (if the edge exists).
         * 
         * If isBidirectional is true and there exists an edge from end to start,
         * then the airline will also be added to the edge from end to start.
         * 
         * WARNING: Doesn't check for duplicate airlines.
         */
        void insertAirline(AirportID start, AirportID end, int airlineID, bool isBidirectional);

        /**
         * A vector of Airports.
         */
        std::vector<AirportID> airports;

    private:
        /**
         * Adjaceny List for graph.
         */
        std::unordered_map<AirportID, std::unordered_map<AirportID, Edge>> adjacency_list;
};