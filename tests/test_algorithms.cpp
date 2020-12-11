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

TEST_CASE("Dijkstra returns the correct path for a more complex example.") {
    Algorithms algo = Algorithms();
    
    std::vector<AirportID> airports;

    for (int i = 1; i <= 10; i++) {
        airports.push_back(i);
    }

    Graph g = Graph(airports);

    g.insertEdge(1, 2, 20);
    g.insertEdge(1, 4, 80);
    g.insertEdge(1, 7, 90);
    g.insertEdge(2, 6, 10);
    g.insertEdge(3, 6, 50);
    g.insertEdge(3, 8, 20);
    g.insertEdge(4, 7, 20);
    g.insertEdge(5, 2, 50);
    g.insertEdge(5, 7, 30);
    g.insertEdge(6, 3, 10);
    g.insertEdge(6, 4, 40);
    g.insertEdge(7, 1, 20);

    std::string path = algo.Dijkstra(g, 1, 3);

    std::string path2 = algo.Dijkstra(g, 8, 4);

     REQUIRE(path == "1->2->6->3");

     REQUIRE(path2 == "Path doesn't exist.");

}

TEST_CASE("Dijkstra returns the correct path for another complex example.") {
    Algorithms algo = Algorithms();
    
    std::vector<AirportID> airports;

    for (int i = 0; i <= 10; i++) {
        airports.push_back(i);
    }

    Graph g = Graph(airports);
    g.insertEdge(4, 5, .35);
    g.insertEdge(5, 4, .35);
    g.insertEdge(4, 7, .37);
    g.insertEdge(5, 7, .28);
    g.insertEdge(7, 5, .28);
    g.insertEdge(5, 1, .32);
    g.insertEdge(0, 4, .38);
    g.insertEdge(0, 2, .26);
    g.insertEdge(7, 3, .39);
    g.insertEdge(1, 3, .29);
    g.insertEdge(2, 7, .34);
    g.insertEdge(6, 2, .40);
    g.insertEdge(3, 6, .52);
    g.insertEdge(6, 0, .58);
    g.insertEdge(6, 4, .93);

    std::string path = algo.Dijkstra(g, 0, 6);
    std::cout << algo.Dijkstra(g, 5, 6) << std::endl;
    REQUIRE(path == "0->2->7->3->6");
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