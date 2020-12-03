#pragma once
#include "miscellanies.h"
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
        * Constructor that also loads in the data by calling loadData.
        */
        OpenFlights(const string & filename);

        /**
         * Loads data into airportMap and graph;
         */
        void loadData(const string & filename);

        /**
         * Loads edges into graph. 
         * If includeAirlines is true, airlines will also be loaded into edges.
         */
        void loadEdges(bool includeAirlines);

        /**
         * Given a starting airport, returns the nearest airport 
         * that can be traveled to to arrive at the given city. 
         * 
         * If no such airport is found, return -1.
         */
        int cityFinder(AirportID start, string country);

        /**
         * Given a starting airport, returns the nearest airport 
         * that can be traveled to to arrive at the given country. 
         * 
         * If no such airport is found, return -1.
         */
        int countryFinder(AirportID start, string country);

        /**
         * @return The number of airports the given airport can travel to and from.
         */
        size_t airportNetworkSize(AirportID airport);

        /**
         * Stores data for a specific airport.
         */
        struct AirportData {
            string name;
            string city;
            string country;
            long double latitude;
            long double longitude;
        };
        

    private:
        /**
         * Maps an AirportID to the details of that airport.
         */
        std::map<AirportID, AirportData> airportMap;

        /**
         * A graph to load the aiports in.
         */
        Graph graph;
};