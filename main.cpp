#include "OpenFlights.h"

int main() {
//these serve as userInputs. start, end, and checkPoint are used in traversals while input provides user options.
    int input, start, end, checkPoint;
    string fileAirports, fileRoutes;
    //if invalid input is provided twice, end program
    int toExit = 0;
    
    std::cout << "Welcome to a Graph-Based implementation of Depth-First Search(DFS), Breadth First Traversal (BFS), Dijkstra's Shortest Path, and Landmark Path Algorithms for the OpenFlights dataset\n\n";
    std::cout <<"Authors (listed alphabetically): Alaa Shuaibi (ashuai6), Chidambara Anagani (canaga2), Praneeth Mekapati (pm14), and Rahul Vasanth (rvasant2)\n";

//user input for filenames
    std::cout << "Input the name of your (properly formatted) Airports file:";
    std::cin >> fileAirports;
    std::cout << "Input the name of your (properly formatted) Routes file:";
    std::cin >> fileRoutes;
    //declare Openflights object with the files provided as input
    //if empty or invalid files the program crashes
    OpenFlights o = OpenFlights(fileAirports, fileRoutes);
    //take the graph that has already been constructed for use of Algorithms
    Graph g = o.getGraph();
    //to call algorithms and traversals
    Algorithms algo = Algorithms();

    do{
        std::cout << "g.getAllAirports().size() = " << g.getAllAirports().size() << std::endl;
        std:: cout << "\nType 0, 1, 2, 3, or 4 for the following:\n0 - DFS\n1 - BFS\n2 - Dijkstra's Algorithm\n3 - Landmark Path\n4 - Input new File\n";
    
        std::cin >> input;
        if(input == 0){ //call DFS
            //std::cout << "DFS call" << std::endl;
            auto airportVec = algo.DFS(g);
        }
        if(input == 1){ //call BFS
           //std::cout << "BFS call" << std::endl;
            auto airportVec = algo.BFS(g);
            //iterate through and print     
        }
        else if(input == 2){ // call Dijkstra's
            std::cout << "Input starting AirportID:";
            std::cin >> start;
            std::cout << "Input ending AirportID:";
            std::cin >> end;
             
            std::cout << "Dijkstra Path: " << o.pathToString(algo.Dijkstra(g, start, end)) << std::endl;
        }
        else if(input == 3){ //call Landmark path
            std::cout << "Input starting AirportID:";
            std::cin >> start;
            std::cout << "Input ending AirportID:";
            std::cin >> end;
            std::cout << "Input checkPoint AirportID:";
            std::cin >> checkPoint;

            std::cout << "Landmark Path: " << o.pathToString(algo.Landmark(g, start, end, checkPoint)) << std::endl;
        }
        else if(input == 4){//new files to be inputted
            std::cout << "Input new Airports file:";
            std::cin >> fileAirports;
            std::cout << "Input new Routes file:";
            std::cin >> fileRoutes;
            //make new graph based on new files
            o = OpenFlights(fileAirports, fileRoutes);
            g = o.getGraph();
        }
        else{//one chance for invalid input
            std::cout << "Invalid Input" << std::endl;
            toExit++;
        }
        
    }while(toExit < 2); //allow one invalid input

    return 0;
}
