#include "OpenFlights.h"

int main() {
    /**
    * type module load llvm/6.0.1
    * type make 
    * type ./finalproject
    * 
    * modify main as you see fit. 
    */
/*
    std::cout << "Rahul's test output message indicates MakeFile is working!" << std::endl;

    //make the fileReader constructor so that the file_to_vector function can be called
    readFromFile *fileReader = new readFromFile(); 

    //setup vector to see what readFromFile is doing, all data coming from airports.txt
    std::vector<std::string> testRFF = fileReader->file_to_vector("airports.txt");

    //it looks like it's stopping in chunks instead of each line. But some spaces are included, others aren't
    std::cout << "vector contents:" << testRFF[0] << testRFF[1] << testRFF[2] << testRFF[3] << std::endl;

    //same output but added a space between each index. This is the proper full line in the airports.txt file
    std::cout << "vector contents:" << testRFF[0] << " " <<  testRFF[1] << " " << testRFF[2] << " " << testRFF[3] << std::endl;

    //the size of the vector is 26832. About 3.48 indexes for each line of the airports.txt file
    std::cout << "size = : " << testRFF.size() << std::endl;
*/  
    int input, start, end, checkPoint;
    string fileAirports, fileRoutes;
    //if invalid input is provided twice, end program
    int toExit = 0;
    
    std::cout << "Welcome to a Graph-Based implementation of Breadth First Traversal (BFS), Dijkstra's Shortest Path, and Landmark Path Algorithms for the OpenFlights dataset\n\n";
    std::cout <<"Authors (listed alphabetically): Alaa Shuaibi (ashuai6), Chidambara Anagani (canaga2), Praneeth Mekapati (pm14), and Rahul Vasanth (rvasant2)\n";

    Algorithms algo = Algorithms();

    std::cout << "Input the name of your (properly formatted) Airports file:";
    std::cin >> fileAirports;
    std::cout << "Input the name of your (properly formatted) Routes file:";
    std::cin >> fileRoutes;
    
    // this can be repeated for routes/airlines/airports if necessary
    //hardcoded in for now.

    //Load File First
    //OpenFlights o= OpenFlights("airports.txt", "routes.txt");
    OpenFlights o = OpenFlights(fileAirports, fileRoutes);
    Graph g = o.getGraph();
    //o.loadEdges(false);
    
    //o.loadRoutes("routes.txt");


    
    //If Valid, Construct Graph

    do{
        std::cout << "g.getAllAirports().size() = " << g.getAllAirports().size() << std::endl;
        std:: cout << "\nType 1, 2, 3, or 4 for the following:\n1 - BFS\n2 - Dijkstra's Algorithm\n3 - Landmark Path\n4 - Input new File\n";
    
        std::cin >> input;

        if(input == 1){ //call BFS
            std::cout << "BFS call" << std::endl;
            auto airportVec = algo.BFS(g);
            //iterate through and print
            
        }
        else if(input == 2){ // call Dijkstra's
            std::cout << "Input starting AirportID:";
            std::cin >> start;
            std::cout << "Input ending AirportID:";
            std::cin >> end;
            //comment out this line when graph is loaded and uncomment next line
            //std::cout << "Dijkstra Path: algo.Dijkstra(g, " << start << ", " << end << ") = "  << std::endl;
        
            std::cout << "Dijkstra Path: " << algo.Dijkstra(g, start, end) << std::endl;
        }
        else if(input == 3){ //call Landmark path
            std::cout << "Input starting AirportID:";
            std::cin >> start;
            std::cout << "Input ending AirportID:";
            std::cin >> end;
            std::cout << "Input checkPoint AirportID:";
            std::cin >> checkPoint;
            //comment out this line when graph is loaded and uncomment next line      
            //std::cout << "Landmark Path: algo.Landmark(g, " << start << ", " << end << ", " << checkPoint << ") = "  << std::endl;

            std::cout << "Landmark Path: " << algo.Landmark(g, start, end, checkPoint) << std::endl;
        }
        else if(input == 4){
            std::cout << "Input new Airports file:";
            std::cin >> fileAirports;
            std::cout << "Input new Routes file:";
            std::cin >> fileRoutes;

            o = OpenFlights(fileAirports, fileRoutes);
            g = o.getGraph();
            //load files and make new graph, same code as above loop
        }
        else{
            std::cout << "Invalid Input" << std::endl;
            toExit++;
        }

    }while(toExit < 2); //allow one invalid input

    return 0;
}
