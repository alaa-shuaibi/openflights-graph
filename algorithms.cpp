#include "algorithms.h"

using namespace std;

bool Algorithms::extractDouble(string txt){
    istringstream iss(txt);
    double d;
    return iss >> d >> ws && iss.eof();
}

bool Algorithms::extractInt(string txt){
    istringstream iss(txt);
    int d;
    return iss >> d >> ws && iss.eof();
}

long double Algorithms::toRadians(const long double degree) 
{ 
    double pi = 2 * acos(0);
    long double one_deg = (pi) / 180; 
    return (one_deg * degree); 
} 
  
long double Algorithms::distance(long double lat1, long double long1,  
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

void Algorithms::calculateDistances(){
     double x = (double) rand() / RAND_MAX;
    double y = (double) rand() / RAND_MAX;
    for (unsigned long idx = 0; idx < coordinates.size(); idx++){
        distances_.push_back(distance(x, y, coordinates[idx].first, coordinates[idx].second));
    }
}

/*int **Algorithms::createGrid(const string & filename){
    string line;
    ifstream myfile (filename);
    if (myfile.is_open() == true){
    
    }

    for (int idx = 0; idx < Flights_Available.size(); idx++){
        
    }
    int **arr;
    return arr;
}

int **Algorithms::Dijkstra(){

}*/