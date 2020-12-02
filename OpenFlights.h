#pragma once
#include "traversal.h"
#include "algorithms.h"
#include <tuple>

typedef long double Coords;
typedef std::tuple<std::string, std::string, Coords> airport_details;

/**
 * Represents a series of functions to run on the OpenFlights dataset.
 */
class OpenFlights {
    public:
        /**
        * Defualt Constructor.
        */ 
        OpenFlights();

    private:
        /**
         * Maps an AirportID to the details of that airport.
         */
        std::map<AirportID, airport_details> airportData;

        /**
         * A graph to load the dataset.
         */
        Graph g;
};