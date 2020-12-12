#pragma once
#include "miscellanies.h"
#include "algorithms.h"
#include <algorithm>

using std::ifstream;

/**
 * Represents a series of functions to run on the OpenFlights dataset.
 */
class OpenFlights {
    public:
        /**
        * Constructor that also loads in the data by calling loadData.
        */
        OpenFlights(const string & airports_file, const string & routes_file);

        /**
         * @return The graph representing the data.
         */ 
        Graph getGraph();

        /**
         * @return The AirportID of the given airport.
         */
        AirportID getAirportID(string name);

        /**
         * @return The name of the given airport.
         */
        string getAirportName(AirportID);

        

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
         * Loads airports into graph and airportMap;
         */
        void loadAirports(const string & filename);

        /**
         * Loads edges into graph.
         */
        void loadRoutes(const string & filename);

        /**
         * A graph to load the aiports in.
         */
        Graph graph;

        /**
         * Maps an AirportID to the details of that airport.
         */
        std::unordered_map<AirportID, AirportData> airportMap;

        /**
         * Maps the name of an airport to its corresponding AirportID.
         */
        std::unordered_map<string, AirportID> nameToAirportID;
};