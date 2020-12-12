#include "catch/catch.hpp"
#include "../miscellanies.h"
#include <sstream>
#include <fstream>

TEST_CASE("We get the basic airport information that is important") {
    Miscellanies ms = Miscellanies();
    std::ifstream myfile("airports.txt");
    int ID;
    string name_;
    string city_;
    string country_;
    long double lat;
    long double longi;
    string txt;
    int cnt = 0;
    while (std::getline(myfile, txt) && cnt < 10){
        ID = ms.getIndex(txt);
        name_ = ms.airport_name(txt);
        city_ = ms.airport_city(txt);
        country_ = ms.airport_country(txt);
        lat = ms.airport_latitude(txt);
        longi = ms.airport_longitude(txt);
        //std::cout << ID << " " << name_ << " " << city_ << " " << country_ << " " << lat << " " << longi << " " << std::endl;
        cnt++;
    }
}

TEST_CASE("Calculate distances through lat & long") {
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
            //std::cout << cnt << " " << lat_1 << " " << longi_1 << " " << std::endl;
        }
        if (cnt == idx_2){
            lat_2 = ms.airport_latitude(txt);
            longi_2 = ms.airport_longitude(txt);
            //std::cout << cnt << " " << lat_2 << " " << longi_2 << " " << std::endl;
        }
        cnt++;
    }
    //std::cout << ms.distance(lat_1, longi_1, lat_2, longi_2) << std::endl;
}