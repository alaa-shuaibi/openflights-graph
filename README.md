# canaga2-ashuai6-rvasant2-pm14

Final Project

Summary: This program implements graph-based traversal algorithms on the OpenFlights airport and routes datasets in C++. https://openflights.org/data.html

Goals: Find the shortest flight routes between two airports. Traveling paths include Djikstra, Landmark, and Breadth-First Search (BFS) to help users travel to  other places in the world.

Warning: Use of EWS Machine recommended. Make sure to scroll up to see output as the program continually takes user input to run different algorithms, traversals, or read new files.

Steps:

0. Load files into your working directory.
    1. If you want to test with your own files, make sure the files are included in the same folder.
    
1. Type make
    1. if you get an error mentioning llvm/6.0.1
        type "module load llvm/6.0.1"

2. Type ./main

3. First, the program takes user input in Terminal for two files:
    1. AirportFile: This serves as the nodes for the graph.
        1. airports.txt has the entire dataset of 14110 airports
        2. tinyAirport.txt contains three airports.
        3. Feel free to include your own file provided it is in the same format (see below).
    2. RoutesFile: This serves as the edges for the graph, mapping the routes from one airport to another
        1. routes.txt has the entire routes dataset with 67663 routes
        2. tinyRoute.txt contains routes between the three airports in tinyAirport.txt
        3. Feel free to include other files but of the same type and have to be within the same format as the options listed above and ideally be mapped between the AirportsFile you provide.
  
4. Next, the program takes an integer from 0 - 4 from user input to implement BFS, Dijkstra, Landmark Path, or DFS.
    0. DFS
        1. main runs DFS which is a vector of AirportIDs. This is not put in string form, due to large files producing immense outputs.
    1. BFS
        1. main runs BFS which returns a vector of AirportIDs but prints nothing to console.        
    2. Djikstra
        1. Input starting AirportID and ending AirportID
            1. The traversals also take user input in the form of integer AirportIDs. This also applies to Landmark Path. 
            
            AirportIDs correspond to Airports in the airports.txt file.
            
            [To text specific airports of your choosing, find AirportIDs for airports of your choice from the airports.txt file and select the first integer(not to be confused by line of code) on the line with the airport of your choosing. For example, 3830 corresponds to "Chicago O'Hare International Airport"]
        2. Output is displayed as string in terminal, mapping the path from the starting AirportID to the ending AirportID. For ease of access, instead of AirportIDs we output the name of each airport and the route from the starting Airport to the ending Airport.          
    3. Landmark
        1. Input starting AirportID, ending AirportID, and checkPoint AirportID
            1. The checkPoint AirportID is an airport that the user inputs. The Landmark Path Algorithm includes this airport on the way to finding the shortest path using Dijkstra's Algorithm.
        2. Similar to Dijkstra, output is displayed as a string in terminal listing the path by naming each Airport's full name.
    4. Change the input files
        1. AirportFile as first input
        2. RoutesFile as second input
    5. Input of any character besides 0, 1, 2, 3, or 4
        1. The first time the program loops back to the initial state
        2. The second time the program closes. An alternative is to press Escape or other commands to exit terminal
    6. The program loops continually provided that the user types 0 through 4, so feel free to implement each algorithm and read in new files.

Airport Format: 

{3469,"San Francisco International Airport","San Francisco","United States","SFO","KSFO",37.61,-122.37,13,-8,"A","America/Los_Angeles","airport","OurAirports"}

*For more clarification look at openflights.org/data.html

ID: 3469

AirportName: San Francisco International Airport

City: San Francisco

Country: United States

Latitude: 37.61899948120117

Longitude: -122.375

Route Format: {AA,24,SFO,3469,ORD,3830,,0,738}

*For more clarification look at openflights.org/data.html

Airline Name = AA (American Airlines) 

SA = starting airport - 3469

EA = ending airport - 3830
                          

