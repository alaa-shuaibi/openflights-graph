#include "graph.h"

Graph::Graph() {
    // Does nothing.
}

Graph::Graph(std::vector<AirportID> airports) {
    this->airports = airports;
    for (size_t i = 0; i < this->airports.size(); i++) {
        adjacency_list[this->airports[i]] = std::unordered_map<AirportID, Edge>();
    }
}

void Graph::insertAirport(AirportID airport) {
    if (adjacency_list.find(airport) == adjacency_list.end()) {
        airports.push_back(airport);
        adjacency_list[airport] = std::unordered_map<AirportID, Edge>();
    }
}

void Graph::insertEdge(AirportID start, AirportID end, long double distance) {
    // Checks if both airports exist in the graph.
    if (adjacency_list.find(start) == adjacency_list.end() || adjacency_list.find(end) == adjacency_list.end()) {   
        return;
    }

    Edge edge = Edge(start, end, distance);

    // Checks if edge already exists in graph.
    if (adjacency_list[start].find(end) == adjacency_list[start].end()) {
        adjacency_list[start][end] = edge;
    }
}

void Graph::insertEdge(AirportID start, AirportID end, long double distance, std::vector<int> airlines) {
    // Checks if both airports exist in the graph.
    if (adjacency_list.find(start) == adjacency_list.end() || adjacency_list.find(end) == adjacency_list.end()) {
        return;
    }

    Edge edge = Edge(start, end, distance, airlines);

    // Checks if edge already exists in graph.
    if (adjacency_list[start].find(end) == adjacency_list[start].end()) {
        adjacency_list[start][end] = edge;
    }
}

std::vector<AirportID> Graph::getAdjacentAirports(AirportID source) {
    std::vector<AirportID> adjAirports;
    
    if (adjacency_list.find(source) == adjacency_list.end()) {
        return adjAirports;
    }

    for (auto it : adjacency_list[source]) {
        adjAirports.push_back(it.first);
    }

    for (size_t i = 0; i < airports.size(); i++) {
        if (adjacency_list[airports[i]].find(source) != adjacency_list[airports[i]].end()) {
            adjAirports.push_back(airports[i]);
        }
    }

    return adjAirports;
}

std::vector<AirportID> Graph::getAdjacentAirports(AirportID source, bool sourceIsStart) {
    std::vector<AirportID> adjAirports;

    if (adjacency_list.find(source) == adjacency_list.end()) {
        return adjAirports;
    }

    if (sourceIsStart) {
        for (auto it : adjacency_list[source]) {
            adjAirports.push_back(it.first);
        }
    } else {
        for (size_t i = 0; i < airports.size(); i++) {
            if (adjacency_list[airports[i]].find(source) != adjacency_list[airports[i]].end()) {
                adjAirports.push_back(airports[i]);
            }
        }
    }

    return adjAirports;
}

std::vector<AirportID> Graph::getAllAirports() {
    return airports;
}

Edge Graph::getEdge(AirportID start, AirportID end) {
    if (adjacency_list[start].find(end) != adjacency_list[start].end()) {
        return adjacency_list[start][end];
    }

    return Edge();
}

std::vector<Edge> Graph::getAllEdges() {
    std::vector<Edge> edges;

    for (size_t i = 0; i < airports.size(); i++) {
        for (auto it : adjacency_list[airports[i]]) {
            edges.push_back(it.second);
        }
    }

    return edges;
}