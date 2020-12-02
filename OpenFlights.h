#pragma once
#include "traversal.h"
#include "algorithms.h"
#include <tuple>

/**
 * Represents a series of functions to run on the OpenFlights dataset.
 */
class OpenFlights {
    public:
        /**
        * Defualt Constructor.
        */ 
        OpenFlights();

        /**
         * Stores data for a specific airport.
         */
        struct AirportData {
            std::string name;
            std::string city;
            std::string country;
            std::pair<long double, long double> coords;
        };
        

    private:
        /**
         * Maps an AirportID to the details of that airport.
         */
        std::map<AirportID, AirportData> airportMap;

        /**
         * A graph to load the dataset.
         */
        Graph g;
};