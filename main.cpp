#include "OpenFlights.h"

int main() {
    // These serve as userInputs. start, end, and checkPoint are used in traversals while input provides user options.
    int input, start, end, checkPoint;
    string fileAirports, fileRoutes;

    // If invalid input is provided twice, end program
    int toExit = 0;
    
    std::cout << "Welcome to a Graph-Based implementation of Breadth First Traversal (BFS), Depth First Search (DFS), Dijkstra’s Algorithm, and Landmark Path for the OpenFlights dataset.\n\n";
    std::cout << "Authors (listed alphabetically): Alaa Shuaibi (ashuai6), Chidambara Anagani (canaga2), Praneeth Mekapati (pm14), and Rahul Vasanth (rvasant2)\n";
    std::cout << std::endl;

    //user input for filenames
    std::cout << "Input the name of your (properly formatted) Airports file: ";
    std::cin >> fileAirports;
    std::cout << "Input the name of your (properly formatted) Routes file: ";
    std::cin >> fileRoutes;
    std::cout << std::endl;

    // Initializes the Openflights object with the files provided as input.
    // If files are empty or invalid, the program crashes.
    OpenFlights o = OpenFlights(fileAirports, fileRoutes);

    // Stores the graph initialized by OpenFlights.
    Graph g = o.getGraph();

    // Initializes the Algorithms object that will be used to run algorithms on the graph.
    Algorithms algo = Algorithms();

    do {
        std:: cout << "\nType 0, 1, 2, 3, or 4 for the following:\n0 - BFS\n1 - DFS\n2 - Dijkstra's Algorithm\n3 - Landmark Path\n4 - Input New File\n";
        std::cout << std::endl;
        std::cin >> input;
        std::cout << std::endl;

        if (input == 0) { // Calls BFS Traversal
            // Can be commented out for long textfiles. 
            std::cout << "BFS Traversal: " << o.pathToString(algo.BFS(g)) << std::endl;
        } else if (input == 1) { // Calls DFS Traversal
            // Can be commented out for long textfiles.
            std::cout << "DFS Traversal: " << o.pathToString(algo.DFS(g)) << std::endl;
        } else if (input == 2) { // Calls Dijkstra's Algorithm
            std::cout << "Input Starting AirportID: ";
            std::cin >> start;
            std::cout << o.getAllAirportData(start) << std::endl;
            std::cout << std::endl;

            std::cout << "Input Ending AirportID: ";
            std::cin >> end;
            std::cout << o.getAllAirportData(end) << std::endl;
            std::cout << std::endl;
             
            std::cout << "Dijkstra's Path: " << o.pathToString(algo.Dijkstra(g, start, end)) << std::endl;
        } else if (input == 3) { // Calls Landmark Path
            std::cout << "Input Starting AirportID: ";
            std::cin >> start;
            std::cout << o.getAllAirportData(start) << std::endl;
            std::cout << std::endl;

            std::cout << "Input Ending AirportID: ";
            std::cin >> end;
            std::cout << o.getAllAirportData(end) << std::endl;
            std::cout << std::endl;

            std::cout << "Input CheckPoint AirportID: ";
            std::cin >> checkPoint;
            std::cout << o.getAllAirportData(checkPoint) << std::endl;
            std::cout << std::endl;

            std::cout << "Landmark Path: " << o.pathToString(algo.Landmark(g, start, end, checkPoint)) << std::endl;
        } else if (input == 4) { // Replaces current files with new files.
            std::cout << "Input New Airports file: ";
            std::cin >> fileAirports;
            std::cout << "Input New Routes file: ";
            std::cin >> fileRoutes;

            // Replaces the OpenFlights object and creates a new graph.
            o = OpenFlights(fileAirports, fileRoutes);
            g = o.getGraph();
        } else { // One chance for invalid input.
            std::cout << "Invalid Input." << std::endl;
            toExit++;
        }
        
    } while (toExit < 2); // Allows one invalid input.

    return 0;
}
