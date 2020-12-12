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

std::vector<AirportID> Algorithms::Dijkstra(Graph g, AirportID start, AirportID end) {    
    std::vector<AirportID> path;

    if (start == end) {
        path.push_back(start);
        return path;
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
        return path;
    }

    // Loads path into vector.
    path.push_back(end);
    curr = end;
    while (curr != start) {
        path.push_back(previous[curr]);
        curr = previous[curr];
    }
    std::reverse(path.begin(), path.end());

    return path;
}

std::vector<AirportID> Algorithms::Landmark(Graph g, AirportID start, AirportID end, AirportID checkpoint) {
    if (start == checkpoint || end == checkpoint) {
        return Dijkstra(g, start, end);
    }

    std::vector<AirportID> path1 = Dijkstra(g, start, checkpoint);
    
    if (path1.empty()) {
        return path1;
    }
    std::vector<AirportID> path2 = Dijkstra(g, checkpoint, end);

    if (path2.empty()) {
        return path2;
    }

    for (size_t i = 1; i < path2.size(); i++) {
        path1.push_back(path2[i]);
    }

    return path1;
}


