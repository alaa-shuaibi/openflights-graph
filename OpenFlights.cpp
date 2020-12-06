#include "OpenFlights.h"

OpenFlights::OpenFlights() {
    // Does nothing yet for now.
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
    while(getLine(myfile,txt)){
        ID = getIndex(txt);
        Airport_Name = airport_name(txt);
        city = airport_city(txt);
        country = airport_country(txt);
        latitude = airport_latitude(txt);
        longitude = airport_longitude(txt);
        AirportData point = {Airport_Name, city, country, latitude, longitude};
        airportMap.insert({ID, point});
        
    }
    
    myfile.close();
}

void OpenFlights::loadAirlines(const string & filename){
    string txt;
    ifstream myfile(filename);

    int ID;
    string airlineName;
    string country;
    while (getLine(myfile, txt)){
        ID = AirlineIdentifier(txt);
        airlineName = AirlineName(txt);
        country = AirlineCountry(txt);
        Airline point = {ID, airlineName, country};
        airlines_.insert({ID, point});
    }
}

void OpenFlights::loadRoutes(const string & filename){
    string txt;
    ifstream myfile(filename);

    int starting_ID;
    long int AirlineID;
    long int ending_AirportID;
    long int num_stops;
    long double distance_;
    while(getLine(myfile,txt)){
        starting_ID = sourceAirportID(txt);
        AirlineID = getAirlineID(txt);
        ending_AirportID = destAirportID(txt);
        num_stops = numstops(txt);
        distance_ = distance(airportMap[starting_ID].second.latitude, airportMap[starting_ID].second.longitude, airportMap[ending_AirportID].second.latitude, airportMap[ending_AirportID].second.longitude);
        Route point = {AirlineID, ending_AirportID, num_stops, distance_};
        routes_.insert({starting_ID, point});
    }


}

void OpenFlights::loadEdges(bool includeAirlines){
    if (includeAirlines == true){
        std::map<AirportID, Route> iter;
        for (iter = airportMap.begin(); iter != airportMap.end(); ++iter){
            vector<int> airlineIDs;

            for (iter2 = ++iter; iter2 != airportMap.end(); ++iter2){
                
            }
        }
    }else{
        std::map<AirportID, Route> iter;
        for (iter = airportMap.begin(); iter != airportMap.end(); ++iter){
            graph.insertEdge(iter.first, iter.second.ending_AirportID, iter.second.distance);
        }
    }
}

int OpenFlights::cityFinder(AirportID start, string city){
    std::map<AirportID, Route> iter;
    for (iter = routes_.begin(); iter != routes_.end(); ++iter){
        if (iter.first == start && city == airportMap[iter.second.ending_AirportID].city){
            return iter.second.ending_AirportID;
        }
    }
    return -1;
}

int OpenFlights::countryFinder(AirportID start, string country){
     std::map<AirportID, Route> iter;
    for (iter = routes_.begin(); iter != routes_.end(); ++iter){
        if (iter.first == start && country == airportMap[iter.second.ending_AirportID].country){
            return iter.second.ending_AirportID;
        }
    }
    return -1;
}

OpenFlights::OpenFlights(const string & filename) {
    loadData(filename);
    loadRoutes(filename);
}

int OpenFlights::cityFinder(AirportID start, string country){

}