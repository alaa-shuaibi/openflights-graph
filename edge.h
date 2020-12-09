#pragma once
#include <vector>
#include <iostream>

typedef int AirportID;

/**
 * Represents an Edge between a starting airport and ending airport. 
 * 
 * @note This class was heavily inspired by the graph class in lab_ml.
 */
class Edge {
    public:
        /**
         * Creates a default edge.
         */
        Edge();

        /**
         * Creates an edge from start to end with the given distance.
         */
        Edge(AirportID start, AirportID end, long double distance);

        /**
         * Creates an edge from start to end with the given distance and vector of airlines.
         */
        Edge(AirportID start, AirportID end, long double distance, std::vector<int> airlines);

        /**
         * @return Starting AirportID
         */
        AirportID getStart();

        /**
         * @return Ending AirportID
         */
        AirportID getEnd();

        /**
         * @return Distance between two airports
         */
        long double getDistance();

        /**
         * @return Vector of airlines that travel from start to end
         */
        std::vector<int> getAirlines();

    private:
        /**
        * The starting airport.
        */
        AirportID start;

        /**
        * The ending airport.
        */
        AirportID end;

        /**
        * The distance between start and end.
        */
        long double distance;

        /**
        * A list of airlines that travel from start to end.
        */
        std::vector<int> airlines;
};