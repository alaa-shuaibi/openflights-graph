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
        
    }
    AirportData point = {Airport_Name, city, country, latitude, longitude};
    airportMap.insert({ID, point});
    
    myfile.close();
}

void OpenFlights::loadEdges(bool includeAirlines){
    if (includeAirlines == true){
        std::map<AirportID, AirportData> iter;
        for (iter = airportMap.begin(); iter != airportMap.end(); ++iter){
            graph.insertEdge()
        }
    }else{
        graph.insertEdge()
    }
}

OpenFlights::OpenFlights(const string & filename) {
    loadData(filename);
}

int OpenFlights::cityFinder(AirportID start, string country){

}