#include "miscellanies.h"

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
  
long double Miscellanies::distance(long double lat1, long double long1,  
                     long double lat2, long double long2) 
{
    lat1 = toRadians(lat1); 
    long1 = toRadians(long1); 
    lat2 = toRadians(lat2); 
    long2 = toRadians(long2); 
      
  
    long double ans = pow(sin((lat2 - lat1) / 2), 2) +  
                          cos(lat1) * cos(lat2) *  
                          pow(sin((long2 - long1) / 2), 2); 
  
    ans = 2 * atan2(sqrt(ans), sqrt(1 - ans)); 
  
    long double R = 6371; 
      
    ans = ans * R; 
  
    return ans; 
}

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