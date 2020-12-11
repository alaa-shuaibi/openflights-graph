#include "catch/catch.hpp"
#include "../OpenFlights.h"

TEST_CASE("We make sure we can find some routes of some airport IDs") {

    OpenFlights ms = OpenFlights();
    std::ifstream myfile("airports.txt");
    ms.loadData("airports.txt");
    ms.loadRoutes("routes.txt");
    Miscellanies a = Miscellanies();
    int cnt = 0;
    string txt;
    int ID = 246;
    std::cout<<ms.airportNetworkSize(ID)<<std::endl; 
    

}

/*TEST_CASE("Calculate distances through lat & long") {
    Miscellanies ms = Miscellanies();
    std::ifstream myfile("airports.txt");
    int idx_1 = (std::rand() % 10) + 1;
    int idx_2 = (std::rand() % 20) + 1;
    long double lat_1;
    long double lat_2;
    long double longi_1;
    long double longi_2;
    string txt;
    int cnt = 1;
    while (std::getline(myfile, txt) && cnt <= 20){
        if (cnt == idx_1){
            lat_1 = ms.airport_latitude(txt);
            longi_1 = ms.airport_longitude(txt);
            std::cout << cnt << " " << lat_1 << " " << longi_1 << " " << std::endl;
        }
        if (cnt == idx_2){
            lat_2 = ms.airport_latitude(txt);
            longi_2 = ms.airport_longitude(txt);
            std::cout << cnt << " " << lat_2 << " " << longi_2 << " " << std::endl;
        }
        cnt++;
    }
    std::cout << ms.distance(lat_1, longi_1, lat_2, longi_2);
}*/