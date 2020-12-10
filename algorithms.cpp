#include "algorithms.h"
#include <queue>
#include <stack>
#define INFINITY 1000000007
#include <iostream>

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

std::string Algorithms::Dijkstra(Graph g, AirportID start, AirportID end) {
    std::unordered_map<AirportID, bool> visited_; //makes sure the current vertex is visited
    std::priority_queue<std::pair<double, AirportID>, std::vector<std::pair<double, AirportID>>, std::greater<std::pair<double, AirportID>>> important_destinations;
    //pushes in the distances from current airport to the airports that have paths from the current and later sorts them out
    std::unordered_map<AirportID, AirportID> path; 
    std::unordered_map<AirportID, double> curr_dist; //updates the distance traveled from each vertex 
    //std::vector<AirportID> adjacents_;
    AirportID curr = start;
    important_destinations.push(std::make_pair<0, start>);
    curr_dist[start] = 0;

    std::vector<AirportID> airports_ = g.getAllAirports();
    for (unsigned long int idx = 0; idx < airports_.size(); idx++){
        if (airports_[idx] != start){
            curr_dist[idx] = INFINITY;
        }
        else{
            curr_dist[idx] = 0;
        }
    }
    while (important_destinations.empty() == false){
        curr = important_destinations.top().second;
        important_destinations.pop();
        for (AirportID v: g.getAdjacentAirports(curr, true)){
            if (visited_.find(v) == visited_.end() || (g.getEdge(curr, v).getDistance() + curr_dist[curr] < curr_dist[v])){
                curr_dist[v] = g.getEdge(curr, v).getDistance() + curr_dist[curr];
            }
            important_destinations.push(std::make_pair<curr_dist[v], v>);
            //backtracking: 
        }
        visited_[curr] = true;
        path[curr] = important_destinations.top().second;
        //curr_dist[curr] += g.getEdge(curr, important_destinations.top.second).getDistance();
        //curr = important_destinations.top.second;
        curr_dist[curr] = important_destinations.top().first;
    }
    return "";
}

std::string Algorithms::Landmark(Graph g, AirportID start, AirportID end, AirportID checkpoint) {
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
    
    /** 
     * map<airportID, long double> tentative distances
     * map<airportID, true> visited
     * priority_queue<airportID> q
     * 
     * q.push(start, 0)
     * while (q is not empty)     
     *  curr = q.top
     *  q.pop
     *  visited[curr] == true
     *  if (curr == end) {
     * 
     *  }
     *     for (v : curr.getAdj())
     *        if (v isn't visited && (v.getTD > currTD + getDist(curr, v)))
     *           q.push(v, currTD + getDist(curr, v))
     *      
     * 
     */
    return "";
}


