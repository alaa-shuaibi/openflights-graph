#include "OpenFlights.h"


OpenFlights::OpenFlights() {
    // Does nothing yet for now.
}

OpenFlights::OpenFlights(const string & airports_file, const string & routes_file) {
    loadData(airports_file);
    loadRoutes(routes_file);
    loadEdges(false);
}

OpenFlights::OpenFlights(const string & airports_file, const string & routes_file, const string & airlines_file) {
    loadData(airports_file);
    loadRoutes(routes_file);
    loadAirlines(airlines_file);
    loadEdges(true);
}

void OpenFlights::loadData(const string & filename){
    string txt;
    ifstream myfile(filename);
    int ID;
    string Airport_Name;
    string city;
    string country;
    long double latitude;
    long double longitude;
    while(getline(myfile,txt)){
        ID = Miscellanies::getIndex(txt);
        Airport_Name = Miscellanies::airport_name(txt);
        city = Miscellanies::airport_city(txt);
        country = Miscellanies::airport_country(txt);
        latitude = Miscellanies::airport_latitude(txt);
        longitude = Miscellanies::airport_longitude(txt);
        AirportData point = {Airport_Name, city, country, latitude, longitude};
        airportMap.insert({ID, point});
    }
    
    myfile.close();
}

/*void OpenFlights::loadAirlines(const string & filename){
    string txt;
    ifstream myfile(filename);

    int ID;
    string airlineName;
    string country;
    while (getline(myfile, txt)){
        ID = Miscellanies::AirlineIdentifier(txt);
        airlineName = Miscellanies::AirlineName(txt);
        country = Miscellanies::AirlineCountry(txt);
        Airline point = {airlineName, country};
        airlines_.insert({ID, point});
    }
}*/

void OpenFlights::loadRoutes(const string & filename){
    string txt;
    ifstream myfile(filename);
    int starting_ID;
    long int AirlineID;
    long int ending_AirportID;
    long int num_stops;
    long double distance_;
    while(getline(myfile,txt)){
        starting_ID = Miscellanies::sourceAirportID(txt);
        AirlineID = Miscellanies::getAirlineID(txt);
        ending_AirportID = Miscellanies::destAirportID(txt);
        num_stops = Miscellanies::numStops(txt);
        if (starting_ID == -1 || AirlineID == -1 || ending_AirportID == -1 || num_stops == -1){
            break;
        }
        distance_ = Miscellanies::distance(airportMap[starting_ID].latitude, airportMap[starting_ID].longitude, airportMap[ending_AirportID].latitude, airportMap[ending_AirportID].longitude);
        Route point = {AirlineID, ending_AirportID, num_stops, distance_};
        routes_.insert({starting_ID, point});
    }
    myfile.close();

}

void OpenFlights::loadEdges(bool includeAirlines){
    if (includeAirlines == true){
        for (auto elem: routes_){
            vector<int> airlineIDs;
            graph.insertEdge(elem.first, elem.second.ending_AirportID, elem.second.distance);
        }
    }else{
        for (auto elem: routes_){
            graph.insertEdge(elem.first, elem.second.ending_AirportID, elem.second.distance);
        }
    }
}

int OpenFlights::cityFinder(AirportID start, string city){
    for (auto elem: routes_){
        if (city == airportMap[elem.second.ending_AirportID].city && start == elem.first){
            return elem.second.ending_AirportID;
        }
    }
    return -1;
}

int OpenFlights::countryFinder(AirportID start, string country){
     for (auto elem: routes_){
        if (country == airportMap[elem.second.ending_AirportID].country && start == elem.first){
            return elem.second.ending_AirportID;
        }
    }
    return -1;
}

size_t OpenFlights::airportNetworkSize(AirportID airport){
    vector<AirportID> destinations;
    for (auto elem: routes_){
        if (elem.first == airport){
            destinations.push_back(elem.second.ending_AirportID);
        }
    }
    return destinations.size();
}