#include "catch/catch.hpp"
#include "../graph.h"

TEST_CASE("A simple graph is created properly.") {
    std::vector<AirportID> airports;

    for (int i = 1; i <= 10; i++) {
        airports.push_back(i);
    }

    Graph g = Graph(airports);

    SECTION("A graph with no edges is created properly.") {
        std::vector<AirportID> vertices = g.getAllAirports();

        REQUIRE(vertices.size() == airports.size());

        for (size_t i = 0; i < airports.size(); i++) {
            REQUIRE(vertices[i] == airports[i]);
        }
    }

    SECTION("Edges are properly inserted.") {

        for (int start = 0; start < 11; start++) {
            g.insertEdge(start, start + 1, start + (start % 3));
        }

        std::vector<Edge> edges = g.getAllEdges();
        
        // Checks if only 9 edges were inserted since Airports 0 and 11 don't exist in the graph.
        REQUIRE(edges.size() == 9);
        
        // Checks getStart and getEnd.
        REQUIRE(g.getEdge(1, 2).getStart() == 1);
        REQUIRE(g.getEdge(2, 3).getEnd() == 3);

        // Checks getDistance.
        REQUIRE(g.getEdge(3, 4).getDistance() == 3.0);
        REQUIRE(g.getEdge(5, 6).getDistance() == 7.0);
    }
}