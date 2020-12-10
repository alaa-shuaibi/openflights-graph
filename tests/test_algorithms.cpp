#include "catch/catch.hpp"
#include "../algorithms.h"

/*
TEST_CASE("BFS works on a simple graph.") {
    SECTION("BFS traverses through the entire component containing start in the correct order.") {}

    SECTION("BFS traverses through the entire graph in the correct order.") {}
}

TEST_CASE("DFS works on a simple graph.") {
    SECTION("DFS traverses through the entire component containing start in the correct order.") {}

    SECTION("DFS traverses through the entire graph in the correct order.") {}
}*/

TEST_CASE("Dijkstra returns the correct path for a simple example.") {
    Algorithms algo = Algorithms();
    
    std::vector<AirportID> airports;

    for (int i = 1; i <= 10; i++) {
        airports.push_back(i);
    }

    Graph g = Graph(airports);

    std::string path = algo.Dijkstra(g, 1, 10);

    REQUIRE(path == "");
}
/*
TEST_CASE("Landmark returns the correct path for a simple example.") {
    Algorithms algo = Algorithms();
    
    std::vector<AirportID> airports;

    for (int i = 1; i <= 10; i++) {
        airports.push_back(i);
    }

    Graph g = Graph(airports);
    std::string path;
    
    path = algo.Landmark(g, 1, 10);

    REQUIRE(path == "");
}*/