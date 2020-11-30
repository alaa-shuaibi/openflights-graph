#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "algorithms.h"

using namespace std;

bool extractDouble(string txt){
    istringstream iss(txt);
    double d;
    return iss >> d >> ws && iss.eof();
}

bool extractInt(string txt){
    istringstream iss(txt);
    int d;
    return iss >> d >> ws && iss.eof();
}

long double toRadians(const long double degree) 
{ 
    // cmath library in C++  
    // defines the constant 
    // M_PI as the value of 
    // pi accurate to 1e-30 
    double pi = 2 * acos(0);
    long double one_deg = (pi) / 180; 
    return (one_deg * degree); 
} 
  
long double distance(long double lat1, long double long1,  
                     long double lat2, long double long2) 
{ 
    // Convert the latitudes  
    // and longitudes 
    // from degree to radians. 
    lat1 = toRadians(lat1); 
    long1 = toRadians(long1); 
    lat2 = toRadians(lat2); 
    long2 = toRadians(long2); 
      
    // Haversine Formula 
    long double dlong = long2 - long1; 
    long double dlat = lat2 - lat1; 
  
    long double ans = pow(sin(dlat / 2), 2) +  
                          cos(lat1) * cos(lat2) *  
                          pow(sin(dlong / 2), 2); 
  
    ans = 2 * atan2(sqrt(ans), sqrt(1 - ans)); 
  
    // Radius of Earth in  
    // Kilometers, R = 6371 
    // Use R = 3956 for miles 
    long double R = 6371; 
      
    // Calculate the result 
    ans = ans * R; 
  
    return ans; 
} 

void Algorithms::insert(const string & filename){
    string txt;
    ifstream myfile(filename);
    int c = 1;
    string tmp;
    while (getline (myfile, txt, ',')){
        if (extractDouble(txt) == true && extractInt(txt) == false && c <= 2){
            if (c == 1){
                tmp = txt;
            } else{
                coordinates.push_back(make_pair(stod(tmp), stod(txt)));
            }
            c++;
        }
        if (c == 2){
            c = 0;
        }
    }
    myfile.close();
}

void calculateDistances(vector< pair<double, double> > coordinates_){
     double x = (double) rand() / RAND_MAX;
    double y = (double) rand() / RAND_MAX;
    for (int idx = 0; idx < coordinates_.size(); idx++){
        distances.push_back(distance(x, y, coordinates_[idx].first, coordinates_[idx].second));
    }
}

int **Algorithms::createGrid(const string & filename){
    /*string line;
    ifstream myfile (filename);
    if (myfile.is_open() == true){
        while (getline(myfile, line) == true){
            
        }
    }*/

    for (int idx = 0; idx < Flights_Available.size(); idx++){
        doub
    }
}

int **Algorithms::Dijkstra(){

}