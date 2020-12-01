#pragma once
#include "miscellanies.h"
#include <tuple>

typedef std::pair<long double, long double> Coords;
typedef std::tuple<int, Coords, std::string> Airport;

/**
* Represents an Edge between a starting airport and ending airport.
*/
class Edge {
    public:
        Edge(Airport start, Airport end, long double distance);

        Edge(Airport start, Airport end, long double distance, std::vector<int> airlines);

        /**
        * The starting airport.
        */
        Airport start;

        /**
        * The destination airport.
        */
        Airport end;

        /**
        * The distance between start and end.
        */
        long double distance;

        /**
        * A list of airlines that travel from start to end.
        */
        std::vector<int> airlines;

    private:                
};