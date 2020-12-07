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
    std::cout << "Welcome to a Graph-Based implementation of Traversal and Shortest Path\n Algorithms for the OpenFlights dataset\nType 1 for BFS (Bread First Search) 2 for Dijkstra's Algorithm or 3 for Landmark Path:" << std::endl;
    int input;
    std::cin >> input;
    
    if(input == 1){ //call BFS

    }
    else if(input == 2){ // call Dijkstra's

    }
    else if(input == 3){ //call Landmark path

    }
    else{
        std::cout << "Invalid Input. Rerun Program and Type 1, 2, or 3 and press Enter:" << std::endl;
        
    }
    return 0;
}
