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

                // Push airport to queue.
                q.push(v);
            }
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

                // Push airport to stack.
                s.push(v);
            }
        }
    }

    return path;
}

std::string Algorithms::Dijkstra(Graph g, AirportID start, AirportID end) {    
    if (start == end) {
        return "You have arrived at your destination!";
    }

    std::priority_queue<std::pair<double, AirportID>, std::vector<std::pair<double, AirportID>>, std::greater<std::pair<double, AirportID>>> q;
    std::unordered_map<AirportID, bool> visited_; // Marks airports as visited.
    std::unordered_map<AirportID, double> curr_dist; // Maps each airport to its distance from start.
    std::unordered_map<AirportID, AirportID> previous; // Keeps track of the current shortest path.

    AirportID curr;
    q.push(std::make_pair(0, start));
    curr_dist[start] = 0;

    while (!q.empty()) {
        curr = q.top().second;
        visited_[curr] = true;
        q.pop();

        // Checks if current airport is the end.
        if (curr == end) {
            break;
        }

        for (AirportID v: g.getAdjacentAirports(curr, true)) {
            if (visited_.find(v) != visited_.end()) {
                continue;
            }

            long double newDistance = g.getEdge(curr, v).getDistance() + curr_dist[curr];
            
            if (curr_dist.find(v) == curr_dist.end() || newDistance < curr_dist[v]) {
                curr_dist[v] = newDistance;
                previous[v] = curr;
                q.push(std::make_pair(curr_dist[v], v));
            }
        }
    }

    // Checks if end was found.
    if (previous.find(end) == previous.end()) {
        return "Path doesn't exist.";
    }

    // Loads path into string.
    std::string path = std::to_string(end);
    curr = end;
    while (curr != start) {
        path = std::to_string(previous[curr]) + "->" + path;
        curr = previous[curr];
    }

    return path;
}

std::string Algorithms::Landmark(Graph g, AirportID start, AirportID end, AirportID checkpoint) {
    if (start == checkpoint || end == checkpoint) {
        return Dijkstra(g, start, end);
    }

    std::string path1 = Dijkstra(g, start, checkpoint);
    
    if (path1 == "Path doesn't exist.") {
        return path1;
    }
    std::string path2 = Dijkstra(g, checkpoint, end);

    if (path2 == "Path doesn't exist.") {
        return path2;
    }

    int cpStringSize = std::to_string(checkpoint).size();

    return path1 + "->" + path2.substr(cpStringSize + 2);
}


