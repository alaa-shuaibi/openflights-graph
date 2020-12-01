#pragma once
#include "traversal.h"
#include "algorithms.h"

/**
 * Represents a series of functions to run on the OpenFlights dataset.
 */
class OpenFlights {
    public:
        OpenFlights();

    private:
        /**
         * A vector of Airports.
         * The index of an Airport represents the OpenFlights ID of that airport.
         */
        const std::vector<Airport> airports;
};