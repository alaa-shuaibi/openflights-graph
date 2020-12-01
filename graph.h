#pragma once
#include "edge.h"

/**
 * Represents a directed graph used to load the OpenFlights dataset.
 * 
 * A vertex is a tuple that represents an airport.
 * vertex.first is the AirportID, vertex.second are the coordinates,
 * and vertex.third is a string containing the city and the country.
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
        Graph(std::vector<Airport> airports);

        /**
         * Inserts a new airport.
         */
        void insertAirport(Airport airport);

        /**
         * Inserts an edge from start to end with the given distance.
         */
        void insertEdge(Airport start, Airport end, long double distance);
        
        /**
         * Inserts an edge from start to end with the given distance and vector of airlines.
         */
        void insertEdge(Airport start, Airport end, long double distance, std::vector<int> airlines);

    private:
        /**
         * A vector of Airports.
         */
        std::vector<Airport> airports;
};