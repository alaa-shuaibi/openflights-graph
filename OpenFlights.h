#pragma once
#include "traversal.h"
#include "algorithms.h"

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
         * Given a starting airport, returns the nearest airport
         * that can be traveled to to arrive at the given city.
         * 
         * If no such airport is found, return -1.
         */
        int cityFinder(AirportID start, std::string country);

        /**
         * Given a starting airport, returns the nearest airport
         * that can be traveled to to arrive at the given country.
         * 
         * If no such airport is found, return -1.
         */
        int countryFinder(AirportID start, std::string country);

        /**
         * @return The number of airports the given airport can travel to and from.
         */
        size_t airportNetworkSize(AirportID airport);

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