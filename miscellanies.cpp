#include "miscellanies.h"
#include <iostream>
#include <typeinfo>


 bool Miscellanies::extractDouble(string txt){
    istringstream iss(txt);
    double d;
    return iss >> d >> ws && iss.eof();
}

 bool Miscellanies::extractInt(string txt){
    istringstream iss(txt);
    int d;
    return iss >> d >> ws && iss.eof();
}

 long double Miscellanies::toRadians(const long double degree) 
{ 
    double pi = 2 * acos(0);
    long double one_deg = (pi) / 180; 
    return (one_deg * degree); 
} 
  
long double Miscellanies::distance(long double latitude0, long double longitude0,  
                     long double latitude1, long double longitude1) 
{
    latitude0 = toRadians(latitude0); 
    longitude0 = toRadians(longitude0); 
    latitude1 = toRadians(latitude1); 
    longitude1 = toRadians(longitude1); 
      
  
    long double ans = pow(sin((latitude1 - latitude0) / 2), 2) +  cos(latitude0) * cos(latitude1) *  pow(sin((longitude1 - longitude0) / 2), 2); 
  
    ans = 2 * atan2(sqrt(ans), sqrt(1 - ans)); 
  
    long double R = 6371; 
  
    return (ans * R); 
}

// The below functions are for airports.txt
int Miscellanies::getIndex(string line) 
{ 
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    return stoi(data[0]);
} 

 string Miscellanies::airport_name(string line) 
{ 
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    return data[1];
} 

 string Miscellanies::airport_city(string line) 
{ 
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    return data[2];
}

 string Miscellanies::airport_country(string line) 
{ 
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    return data[3];
} 

 long double Miscellanies::airport_latitude(string line) 
{ 
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    double ans;
    stringstream(data[6]) >> ans;
    return ans;
}

 long double Miscellanies::airport_longitude(string line) 
{ 
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    double ans;
    stringstream(data[7]) >> ans;
    return ans;
} 

// The below helper functions are for working with airlines.txt

 int Miscellanies::AirlineIdentifier(string line){
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }

    
    return stoi(data[0]);
}

 string Miscellanies::AirlineName(string line){
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    return data[1];
}

 string Miscellanies::AirlineCountry(string line){
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    return data[6];
}

// Functions below are helpers for working with routes.txt
 int Miscellanies::getAirlineID(string line){
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    string output = data[1];
    for (unsigned long i = 0; i < output.size(); i++){
        if (isdigit(output[i]) == false){
            return -1;
        }
    }
    return stoi(data[1]);
}

 int Miscellanies::sourceAirportID(string line){
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    string output = data[3];
    for (unsigned long i = 0; i < output.size(); i++){
        if (isdigit(output[i]) == false){
            return -1;
        }
    }
    return stoi(data[3]);
}

 int Miscellanies::destAirportID(string line){
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
    string output = data[5];
    for (unsigned long i = 0; i < output.size(); i++){
        if (isdigit(output[i]) == false){
            return -1;
        }
    }
    return stoi(data[5]);
}

 int Miscellanies::numStops(string line){
    vector<string> data;
    stringstream ss(line);
    while(ss.good()){
        string substring;
        getline(ss,substring,',');
        data.push_back(substring);
    }
   string output = data[7];
    for (unsigned long i = 0; i < output.size(); i++){
        if (isdigit(output[i]) == false){
            return -1;
        }
    }
    return stoi(data[7]);
}


// Might not need this anymore since we're using a struct in OpenFlights
/*void Miscellanies::insert(const string & filename){
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
        airport_map.insert(ID,make_tuple(Airport_Name,city_,country,latitude,longitude));
    }
    
    myfile.close();
}*/

/*void Miscellanies::calculateDistances(){
    double x = (double) rand() / RAND_MAX;
    double y = (double) rand() / RAND_MAX;
    for (unsigned long idx = 0; idx < coordinates.size(); idx++){
        distances_.push_back(distance(x, y, coordinates[idx].first, coordinates[idx].second));
    }
}*/

/*int **Miscellanies::createGrid(const string & filename){
    string line;
    ifstream myfile (filename);
    if (myfile.is_open() == true){
    
    }

    for (int idx = 0; idx < Flights_Available.size(); idx++){
        
    }
    int **arr;
    return arr;
}*/