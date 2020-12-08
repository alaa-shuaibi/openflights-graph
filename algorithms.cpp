#include "algorithms.h"
#include <queue>
#include <map>

/**
 * @param g - the graphs based on OpenFlights dataset
 * @param start - the starting AirportID
 * 
 * Implements a Breadth First Search Traversal
 * 
 * */
void Algorithms::BFS(Graph g, AirportID start) {
    //no need to distinguish between CROSS and DISCOVERY edges
    std::map<AirportID, bool> m;
    m[start] = true;

    std::queue<AirportID> q;

    //setLabel (V, VISITED)
    q.push(start);
    

    AirportID temp;
    
    while(!q.empty()){
        temp = q.front();
        //foreach (Vertex w: G.adjacent*v)
        for(AirportID it: g.getAdjacentAirports(temp)){
            //if getLabel(w) == UNEXPLORED
            if(m.find(it) == m.end()){//if true m[it] has not been assigned
                //setLabel(w, VISITED)
                m[it] = true;
                //setLabel(v, w, DISCOVERY)

                //q.enqueue(w);
                q.push(it);
            }
            
            //elseif getLabel(v, w) == UNEXPLORED
                //setLabel(v, w, CROSS)
        }
        q.pop();

    }
    //BFS(Graph g)
}

//BFS(Graph g){

//}

void Algorithms::DFS(Graph g, AirportID start) {}

void Algorithms::Dijkstra(Graph g, int start, int end) {}

void Algorithms::Landmark(Graph g, AirportID start, AirportID end, AirportID checkpoint) {}