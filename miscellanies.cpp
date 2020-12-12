#include "miscellanies.h"

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

