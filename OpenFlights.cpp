#include "OpenFlights.h"

OpenFlights::OpenFlights(const string & airports_file, const string & routes_file) {
    loadAirports(airports_file);
    loadRoutes(routes_file);
}

Graph OpenFlights::getGraph() {
    return graph;
}

AirportID OpenFlights::getAirportID(string name) {
    std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c){return std::tolower(c);});

    if (nameToAirportID.find(name) != nameToAirportID.end()) {
        return nameToAirportID[name];
    }

    return -1;
}

string OpenFlights::getAirportName(AirportID airportID) {
    if (airportMap.find(airportID) != airportMap.end()) {
        return airportMap[airportID].name;
    }

    return "NULL";
}

string OpenFlights::getAirportLocation(AirportID airportID) {
    if (airportMap.find(airportID) != airportMap.end()) {
        return airportMap[airportID].city + ", " + airportMap[airportID].country;
    }

    return "NULL";
}

string OpenFlights::getAirportCoords(AirportID airportID) {
    if (airportMap.find(airportID) != airportMap.end()) {
        return "(" + std::to_string(airportMap[airportID].latitude) + ", " + std::to_string(airportMap[airportID].latitude) + ")";
    }

    return "NULL";
}

string OpenFlights::getAllAirportData(AirportID airportID) {
    if (airportMap.find(airportID) != airportMap.end()) {
        return getAirportName(airportID) + " | " + getAirportLocation(airportID) + " | " + getAirportCoords(airportID);
    }

    return "NULL";
}

string OpenFlights::pathToString(std::vector<AirportID> path) {
    if (path.empty()) {
        return "Path doesn't exist.";
    } else if (path.size() == 1) {
        return "You have arrived at your destination!";
    }

    string ret = airportMap[path[0]].name;

    for (size_t i = 1; i < path.size(); i++) {
        ret += " -> " + airportMap[path[i]].name;
    }

    return ret;
}

void OpenFlights::loadAirports(const string & filename){
    string txt;
    ifstream myfile(filename);
    std::vector<AirportID> airports;

    while(getline(myfile,txt)) {
        AirportID ID = Miscellanies::getIndex(txt);
        string name = Miscellanies::airport_name(txt);
        string city = Miscellanies::airport_city(txt);
        string country = Miscellanies::airport_country(txt);
        long double latitude = Miscellanies::airport_latitude(txt);
        long double longitude = Miscellanies::airport_longitude(txt);

        airports.push_back(ID);
        AirportData point = {name, city, country, latitude, longitude};
        airportMap.insert({ID, point});
        std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c){return std::tolower(c);});
        nameToAirportID[name] = ID;
    }

    graph = Graph(airports);
    
    myfile.close();
}

void OpenFlights::loadRoutes(const string & filename){
    string txt;
    ifstream myfile(filename);

    while(getline(myfile,txt)) {
        AirportID start = Miscellanies::sourceAirportID(txt);
        AirportID end = Miscellanies::destAirportID(txt);

        if (start == -1 || end == -1) {
            continue;
        }

        long double distance = Miscellanies::distance(airportMap[start].latitude, airportMap[start].longitude, airportMap[end].latitude, airportMap[end].longitude);

        graph.insertEdge(start, end, distance);
    }

    myfile.close();
}