#include "edge.h"
#include <algorithm>

Edge::Edge() {
    start = -1;
    end = -1;
    distance = 0;
}

Edge::Edge(AirportID start, AirportID end, long double distance) {
    this->start = start;
    this->end = end;
    this->distance = distance;
}

Edge::Edge(AirportID start, AirportID end, long double distance, std::vector<int> airlines) {
    this->start = start;
    this->end = end;
    this->distance = distance;
    this->airlines = airlines;
    std::sort(airlines.begin(), airlines.end());
}

AirportID Edge::getStart() {
    return start;
}

AirportID Edge::getEnd() {
    return end;
}

/**
 * This function returns, using the distance formula the distance 
 * between the  airports (derived from longitude and latitude)
 * @return type double 
 * */
long double Edge::getDistance() {
    return distance;
}


std::vector<int> Edge::getAirlines() {
    return airlines;
}