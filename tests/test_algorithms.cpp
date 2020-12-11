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

    REQUIRE(path == "Path doesn't exist.");

    g.insertEdge(1, 2, 1);
    g.insertEdge(2, 3, 2);
    g.insertEdge(2, 4, 3);
    g.insertEdge(2, 5, 4);
    g.insertEdge(4, 6, 10);
    g.insertEdge(4, 7, 9);
    g.insertEdge(4, 8, 1);
    g.insertEdge(6, 9, 2);
    g.insertEdge(7, 10, 30);
    g.insertEdge(9, 10, 2);

    path = algo.Dijkstra(g, 1, 10);

    REQUIRE(path == "1->2->4->6->9->10");
}

TEST_CASE("Landmark returns the correct path for a simple example.") {
    Algorithms algo = Algorithms();
    
    std::vector<AirportID> airports;

    for (int i = 1; i <= 10; i++) {
        airports.push_back(i);
    }

    Graph g = Graph(airports);

    std::string path = algo.Landmark(g, 1, 10, 2);

    REQUIRE(path == "Path doesn't exist.");

    g.insertEdge(1, 2, 1);
    g.insertEdge(2, 3, 2);
    g.insertEdge(2, 4, 3);
    g.insertEdge(2, 5, 4);
    g.insertEdge(4, 6, 10);
    g.insertEdge(4, 7, 9);
    g.insertEdge(4, 8, 1);
    g.insertEdge(6, 9, 2);
    g.insertEdge(7, 10, 30);
    g.insertEdge(9, 10, 2);

    path = algo.Landmark(g, 1, 10, 7);

    REQUIRE(path == "1->2->4->7->10");
}