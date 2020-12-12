#include "OpenFlights.h"

OpenFlights::OpenFlights(const string & airports_file, const string & routes_file) {
    loadAirports(airports_file);
    loadRoutes(routes_file);
}

Graph OpenFlights::getGraph() {
    return graph;
}

AirportID OpenFlights::getAirportID(string name) {
    if (nameToAirportID.find(name) != nameToAirportID.end()) {
        return nameToAirportID[name];
    }

    return -1;
}

void OpenFlights::loadAirports(const string & filename){
    string txt;
    ifstream myfile(filename);
    std::vector<AirportID> airports;

    while(getline(myfile,txt)){
        AirportID ID = Miscellanies::getIndex(txt);
        string name = Miscellanies::airport_name(txt);
        string city = Miscellanies::airport_city(txt);
        string country = Miscellanies::airport_country(txt);
        long double latitude = Miscellanies::airport_latitude(txt);
        long double longitude = Miscellanies::airport_longitude(txt);

        airports.push_back(ID);
        AirportData point = {name, city, country, latitude, longitude};
        airportMap.insert({ID, point});
        nameToAirportID[name] = ID;
    }

    graph = Graph(airports);
    
    myfile.close();
}

void OpenFlights::loadRoutes(const string & filename){
    string txt;
    ifstream myfile(filename);

    while(getline(myfile,txt)){
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