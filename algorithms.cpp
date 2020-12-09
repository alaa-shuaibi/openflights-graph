#include "algorithms.h"
#include <queue>
#include <stack>

std::vector<AirportID> Algorithms::BFS(Graph g) {
    std::vector<AirportID> path;
    std::unordered_map<AirportID, bool> visited;

    for (AirportID v : g.getAllAirports()) {
        path = BFS(g, v, visited, path);
    }

    return path;
}

std::vector<AirportID> Algorithms::BFS(Graph g, AirportID start, std::unordered_map<AirportID, bool> & visited, std::vector<AirportID> path) {
    if (visited.find(start) != visited.end()) {
        return path;
    }

    // No need to label edges yet.
    std::queue<AirportID> q;
    visited[start] = true;
    q.push(start);
    
    while(!q.empty()){
        AirportID curr = q.front();
        q.pop();
        path.push_back(curr);
        for(AirportID v: g.getAdjacentAirports(curr)){
            // Check if airport is visited.
            if(visited.find(v) == visited.end()){
                // Set airport to visited.
                visited[v] = true;

                // Label edge as discovery edge.

                // Push airport to queue.
                q.push(v);
            }
            // else if (edge == UNEXPLORED)
                // Label edge as cross edge.
        }
    }

    return path;
}

std::vector<AirportID> Algorithms::DFS(Graph g) {
    std::vector<AirportID> path;
    std::unordered_map<AirportID, bool> visited;

    for (AirportID v : g.getAllAirports()) {
        path = DFS(g, v, visited, path);
    }

    return path;
}

std::vector<AirportID> Algorithms::DFS(Graph g, AirportID start, std::unordered_map<AirportID, bool> & visited, std::vector<AirportID> path) {
    if (visited.find(start) != visited.end()) {
        return path;
    }
    
    // No need to label edges yet.
    std::stack<AirportID> s;
    visited[start] = true;
    s.push(start);
    
    while(!s.empty()){
        AirportID curr = s.top();
        s.pop();
        path.push_back(curr);
        for(AirportID v: g.getAdjacentAirports(curr)){
            // Check if airport is visited.
            if(visited.find(v) == visited.end()){
                // Set airport to visited.
                visited[v] = true;

                // Label edge as discovery edge.

                // Push airport to stack.
                s.push(v);
            }
            // else if (edge == UNEXPLORED)
                // Label edge as back edge.
        }
    }

    return path;
}

void Algorithms::Dijkstra(Graph g, AirportID start, AirportID end) {
    /*std::unordered_map<AirportID, AirportID> paths_;
    std::unordered_map<AirportID, bool> visited_;
    std::unordered_map<AirportID, double> values_;  
    std::priority_queue<std::pair<AirportID, double>> distances_;
    double distance = 0;
    AirportID curr = start;
    values_[curr] = 0;
    while (distances_.top.first != end)
    {
        for (AirportID v: g.getAdjacentAirports(curr)){
            if (visited_.find(v) == false && ){
                distances_.push(std::make_pair<v, Graph::getEdge(curr, v));
                paths_[curr] = v;
            }
        }
        visited_[curr] = true;
    }

    double output = 0;
    for (auto elem: paths_){
        output += Graph::getEdge(elem.first, elem.second);
    }*/

    std::unordered_map<AirportID, bool> visited_;
    std::priority_queue<std::pair<AirportID, double>> important_destinations;
    std::unordered_map<AirportID, AirportID> path;
    std::vector<AirportID> adjacents_;
    double path_distance = 0;
    important_destinations.push(std::make_pair<start, 0>);
    while (important_destinations.empty() == false){
        AirportID curr = important_destinations.top();
        important_destinations.pop();
        for (AirportID v: g.getAdjacentAirports(curr)){
            if (visited_.find(v) == false && (g.getEdge(curr, v) > path_distance + g.getEdge(curr, v).getDistance())){
                important_destinations.push(std::make_pair<v, g.getEdge(curr, v).getDistance()>);
            }
        }
        visited_[curr] = true;
        path[curr] = important_destinations.top.first;
        path_distance += g.getEdge(curr, important_destinations.top.first).getDistance();
        curr = important_destinations.top.first;
    }
    
}

void Algorithms::Landmark(Graph g, AirportID start, AirportID end, AirportID checkpoint) {
    
}


