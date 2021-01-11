#include "OpenFlights.h"

int main() {
    // Variables for user input.
    int input, start, end, checkPoint;
    string fileAirports, fileRoutes;

    // Variable to keep track of invalid inputs.
    int toExit = 0;
    
    std::cout << "OpenFlights Graph - CS 225 Final Project\n\n";
    std::cout << "Authors: Alaa Shuaibi, Chidambara Anagani, Praneeth Mekapati, and Rahul Vasanth\n";
    std::cout << std::endl;

    std::cout << "Input the name of your (properly formatted) Airports file: ";
    std::cin >> fileAirports;
    std::cout << "Input the name of your (properly formatted) Routes file: ";
    std::cin >> fileRoutes;
    std::cout << std::endl;

    // Initializes required objects.
    OpenFlights o = OpenFlights(fileAirports, fileRoutes);
    Graph g = o.getGraph();
    Algorithms algo = Algorithms();

    do {
        std:: cout << "\nType 0, 1, 2, 3, or 4 for the following:\n0 - BFS\n1 - DFS\n2 - Dijkstra's Algorithm\n3 - Landmark Path\n4 - Input New File\n";
        std::cout << std::endl;
        std::cin >> input;
        std::cout << std::endl;

        if (input == 0) { // Calls BFS
            // Can be commented out for long textfiles. 
            std::cout << "BFS Traversal: " << o.pathToString(algo.BFS(g)) << std::endl;
        } else if (input == 1) { // Calls DFS
            // Can be commented out for long textfiles.
            std::cout << "DFS Traversal: " << o.pathToString(algo.DFS(g)) << std::endl;
        } else if (input == 2) { // Calls Dijkstra
            std::cout << "Input Starting AirportID: ";
            std::cin >> start;
            std::cout << o.getAllAirportData(start) << std::endl;
            std::cout << std::endl;

            std::cout << "Input Ending AirportID: ";
            std::cin >> end;
            std::cout << o.getAllAirportData(end) << std::endl;
            std::cout << std::endl;
             
            std::cout << "Dijkstra's Path: " << o.pathToString(algo.Dijkstra(g, start, end)) << std::endl;
        } else if (input == 3) { // Calls Landmark
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
        } else { // Allows one chance for invalid input.
            std::cout << "Invalid Input." << std::endl;
            toExit++;
        }
        
    } while (toExit < 2);

    return 0;
}