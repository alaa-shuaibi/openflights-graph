#include "catch/catch.hpp"
#include "../miscellanies.h"
#include <sstream>
#include <fstream>

TEST_CASE("We get the basic airport information that is important") {
    //Miscellanies ms = Miscellanies();
    std::ifstream myfile("tinyAirport.txt");
    int ID;
    string name_;
    string city_;
    string country_;
    long double lat;
    long double longi;
    string txt;
    std::getline(myfile, txt);
    ID = Miscellanies::getIndex(txt);
    name_ = Miscellanies::airport_name(txt);
    city_ = Miscellanies::airport_city(txt);
    country_ = Miscellanies::airport_country(txt);
    lat = Miscellanies::airport_latitude(txt);
    longi = Miscellanies::airport_longitude(txt);


    REQUIRE(ID == 4049);
    REQUIRE(name_ == "\"University of Illinois Willard Airport\"");
    REQUIRE(city_ == "\"Champaign\"");
    REQUIRE(country_ == "\"United States\"");
    REQUIRE(lat == 40.03919983);
    REQUIRE(longi == -88.27809906);
}

TEST_CASE("Calculate distances through lat & long") {
    
    long double lat_1 = -6.0985;
    long double lat_2 = -4.8674;
    long double longi_1 = 45.923;
    long double longi_2 = 143.38679;

    long double ans = Miscellanies::distance(lat_1,longi_1,lat_2,longi_2);
    
    REQUIRE(std::floor(ans) == std::floor(10771.37));
    
}