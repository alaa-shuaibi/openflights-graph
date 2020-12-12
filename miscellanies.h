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

/**
 * Represents a collection of miscellaneous functions that will be used 
 * for our final project.
 */
class Miscellanies {
    public:
        /**
         * This helper function below takes in a variable (degree) which is either a longitude or latitude value
         * and converts it to radians before returning it
        */
        static long double toRadians(const long double degree);

        /**
         * The function below takes two sets of longitude and latitude parameters
         * and calculates and returns the distance between those points.
        */
        static long double distance(long double lat1, long double long1, long double lat2, long double long2);

        /**
         * This function takes in a single line from airports.txt and returns the unique airport identifier
        */
        static int getIndex(string line);
        
        /**
         * This function takes in a single line from airports.txt and returns the name of the airport
        */
        static string airport_name(string line);
        
        /**
         * This function takes in a single line from airports.txt and returns the city in which the airport is located in.
        */
        static string airport_city(string line);
        
        /**
         * This function takes in a single line from airports.txt and returns the country in which the airport is located in.
        */
        static string airport_country(string line);

        /**
         * This function takes in a single line from airports.txt and returns the latitude of airport coordinates.
        */
        static long double airport_latitude(string line);

        /**
         * This function takes in a single line from airports.txt and returns the longitude of airport coordinates.
        */
        static long double airport_longitude(string line);

        /**
         * This function takes in a single line from routes.txt and returns the unique identifier
         * of the source aiport.
        */
        static int sourceAirportID(string line);

        /**
         * This function takes in a single line from routes.txt and returns the unique identifier
         * of the destination aiport.
        */
        static int destAirportID(string line);
};