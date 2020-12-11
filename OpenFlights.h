#pragma once
#include "miscellanies.h"
#include "algorithms.h"
#include <map>

using std::ifstream;

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
        OpenFlights(const string & airports_file, const string & routes_file);

        /**
        * Constructor that also loads in the data by calling loadData.
        */
        OpenFlights(const string & airports_file, const string & routes_file, const string & airlines_file);

        /**
         * Loads data into airportMap and graph;
         */
        void loadData(const string & filename);

        void loadRoutes(const string & filename);

        void loadAirlines(const string & filename);

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
        int cityFinder(AirportID start, string city);

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

        struct Airline {
            string Airline_name;
            string Airline_country;
        };

        struct Route {
            long int AirlineID;
            long int ending_AirportID;
            long int num_stops;
            long double distance;
        };
        

    private:
        /**
         * Maps an AirportID to the details of that airport.
         */
        std::map<AirportID, AirportData> airportMap;

        std::map<AirportID, Route> routes_;

        std::map<AirportID, Airline> airlines_;

        /**
         * A graph to load the aiports in.
         */
        Graph graph;
};