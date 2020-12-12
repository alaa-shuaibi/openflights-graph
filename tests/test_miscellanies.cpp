#include "catch/catch.hpp"
#include "../miscellanies.h"
#include <sstream>
#include <fstream>

TEST_CASE("Airport Data is properly retrieved.") {
    std::ifstream myfile("tinyAirport.txt");
    string txt;
    std::getline(myfile, txt);
    int ID = Miscellanies::getIndex(txt);
    string name_ = Miscellanies::airport_name(txt);
    string city_ = Miscellanies::airport_city(txt);
    string country_ = Miscellanies::airport_country(txt);
    long double lat = Miscellanies::airport_latitude(txt);
    long double longi = Miscellanies::airport_longitude(txt);

    REQUIRE(ID == 4049);
    REQUIRE(name_ == "\"University of Illinois Willard Airport\"");
    REQUIRE(city_ == "\"Champaign\"");
    REQUIRE(country_ == "\"United States\"");
    REQUIRE(lat == 40.03919983);
    REQUIRE(longi == -88.27809906);
}

TEST_CASE("Distances are calculated correctly.") {
    long double lat_1 = -6.0985;
    long double lat_2 = -4.8674;
    long double longi_1 = 45.923;
    long double longi_2 = 143.38679;

    long double ans = Miscellanies::distance(lat_1,longi_1,lat_2,longi_2);
    
    REQUIRE(std::floor(ans) == std::floor(10771.37));
}