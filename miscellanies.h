#pragma once
#include "readFromFile.h"
#include <stdlib.h>
#include <typeinfo>
#include <utility>
#include <math.h>

using std::string;
using std::vector;
using std::stringstream;
using std::istringstream;
using std::ws;

/**
 * Represents a collection of miscellaneous functions that will be used 
 * for our final project.
 */
class Miscellanies {
    public:
        static long double toRadians(const long double degree);
        static long double distance(long double lat1, long double long1, long double lat2, long double long2);
        static bool extractDouble(string txt);
        static bool extractInt(string txt);

        // below functions are helpers for working with airports.txt
        static int getIndex(string line);
        static string airport_name(string line);
        static string airport_city(string line);
        static string airport_country(string line);
        static long double airport_latitude(string line);
        static long double airport_longitude(string line);

        //below functions are helpers for working with routes.txt
        static int getAirlineID(string line);
        static int sourceAirportID(string line);
        static int destAirportID(string line);
        static int numStops(string line);

        //below functions are helpers for working with airlines.txt
        static int AirlineIdentifier(string line);
        static string AirlineName(string line);
        static string AirlineCountry(string line);
};