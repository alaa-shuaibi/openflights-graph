#include "graph.h";

Graph::Graph() {
    // Does nothing.
}

Graph::Graph(std::vector<AirportID> airports) {
    this->airports = airports;
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

void Graph::insertAirline(AirportID start, AirportID end, int airlineID, bool isBidirectional) {
    // Checks if both airports exists and if there exists an edge between them.
    if (adjacency_list.find(start) == adjacency_list.end() || adjacency_list.find(end) == adjacency_list.end()) {
        return;
    } else if (adjacency_list[start].find(end) == adjacency_list[start].end()) {
        return;
    }

    // Retrieve current edge data
    Edge old_edge = adjacency_list[start][end];
    long double distance = old_edge.getDistance();
    std::vector<int> airlines = old_edge.getAirlines();

    // Checks if airline is already in edge.
    for (size_t i = 0; i < airlines.size(); i++) {
        if (airlines[i] == airlineID) {
            return;
        }
    }

    // Replace current edge with new edge
    airlines.push_back(airlineID);
    Edge new_edge = Edge(start, end, distance, airlines);
    adjacency_list[start][end] = new_edge;

    // Adds airline to edge in opposite direction if conditions are met.
    if (isBidirectional && adjacency_list[end].find(start) != adjacency_list[end].end()) {
        // Retrieve current edge data
        old_edge = adjacency_list[end][start];
        distance = old_edge.getDistance();
        airlines = old_edge.getAirlines();

        // Checks if airline is already in edge.
        for (size_t i = 0; i < airlines.size(); i++) {
            if (airlines[i] == airlineID) {
                return;
            }
        }

        // Replace current edge with new edge
        airlines.push_back(airlineID);
        new_edge = Edge(start, end, distance, airlines);
        adjacency_list[end][start] = new_edge;
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
            if (adjacency_list[i].find(source) != adjacency_list[i].end()) {
                adjAirports.push_back(i);
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
        for (auto it : adjacency_list[i]) {
            edges.push_back(it.second);
        }
    }

    return edges;
}