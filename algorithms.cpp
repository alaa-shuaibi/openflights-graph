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
    std::priority_queue<AirportID, 
    priority_queue.push(start);
    std::unordered_map<AirportID, bool> visited;
    AirportID curr = start;
    visited[start] = true;
    while (priority_queue.front() != end){
        for (AirportID v: g.getAdjacentAirports(curr)){
            if (visited.find(v) == visited.end()){
                paths_[v] = curr;
            }
            
        }
    }*/
    std::unordered_map<AirportID, AirportID> paths_;
    std::unordered_map<AirportID, bool> visited_;
    std::priority_queue<std::pair<AirportID, double>> distances_;
    double distance = 0;
    AirportID curr = start;
    while (distances_.top.first != end)
    {
        for (AirportID v: g.getAdjacentAirports(curr)){
            if (visited_.find(v) == visited_.end){
                distances_.push(std::make_pair<v, Graph::getEdge(curr, v));
                paths_[curr] = v;
            }
        }
        visited_[curr] = true;
    }

    double output = 0;
    for (auto elem: paths_){
        output += Graph::getEdge(elem.first, elem.second);
    }
    
}

void Algorithms::Landmark(Graph g, AirportID start, AirportID end, AirportID checkpoint) {}