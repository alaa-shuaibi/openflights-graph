#include "algorithms.h"
#include <queue>

/**
 * @param g - the graphs based on OpenFlights dataset
 * @param start - the starting AirportID
 * 
 * Implements a Breadth First Search Traversal
 * 
 * */
void Algorithms::BFS(Graph g, AirportID start) {
    //no need to distinguish between CROSS and DISCOVERY edges
    queue<AirportID> q;
    //setLabel (V, VISITED)
    //q.push(v)

    //while !q.empty();
        //v = q.dequeue()
        //foreach (Vertex w: G.adjacent*v)
            //if getLabel(w) == UNEXPLORED
                //setLabel(w, VISITED)
                //setLabel(v, w, DISCOVERY)
                //q.enqueue(w);
            //elseif getLabel(v, w) == UNEXPLORED
                //setLabel(v, w, CROSS)


    //BFS(Graph g)
}

//BFS(Graph g){

//}

void Algorithms::DFS(Graph g, AirportID start) {}

void Algorithms::Dijkstra(Graph g, int start, int end) {}

void Algorithms::Landmark(Graph g, AirportID start, AirportID end, AirportID checkpoint) {}