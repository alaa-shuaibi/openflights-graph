#include "catch/catch.hpp"
#include "../OpenFlights.h"

TEST_CASE("testing test") {
    SECTION("check if y = 3") {
        int y = 3;
        REQUIRE(y == 3);
    }
    SECTION("finally check if x = 1") {
        int x = 2;
        REQUIRE(x == 1);
    }
}