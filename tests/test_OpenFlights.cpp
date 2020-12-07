#include "catch/catch.hpp"
#include "../OpenFlights.h"

TEST_CASE("Example 4") {
    SECTION("Check if x is equal to 3.") {
        int x = 3;
        REQUIRE(x == 3);
    }
    
    SECTION("Check if y is equal to 1.") {
        int y = 2;
        REQUIRE(y == 1);
    }
}