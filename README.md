# OpenFlights Graph - CS 225 Final Project

### Authors: Alaa Shuaibi, Chidambara Anagani, Praneeth Mekapati, and Rahul Vasanth

**Summary**: This program loads in data from https://openflights.org/data.html into a graph that supports BFS, DFS, Dijkstra, and Landmark algorithms.

**Requirements**: This program was designed to run on the EWS machines at UIUC. To run this program on your own machine, refer to https://courses.engr.illinois.edu/cs225/fa2020/resources/own-machine/ for instructions. Keep in mind, these instructions are written for UIUC students taking CS 225 so feel free to find other guides meant for a broader audience.

**How to use this program**:

1. Change your current working directory to the location of this program and then enter `$ make && ./main` in terminal to begin.

2. Next, the terminal will prompt you to enter two text files. The first text file should contain the data for all airports you're interested in while the second text file should contain the data for all routes you're interested in. For information on how data in both text files should be formatted, check out the "Airport" section and "Route" section on https://openflights.org/data.html. Note: If you're interested in using the data provided by OpenFlights, use the airports.txt and routes.txt files that are located inside of this repository.

3. You should now be able to run various algorithms on the data you entered.
    * Enter 0 to run BFS.
        - BFS outputs the traversal of the entire graph using the BFS algorithm.
        
    * Enter 1 to run DFS.
        - DFS outputs the traversal of the entire graph using the DFS algorithm.
        
    * Enter 2 to run Dijkstra.
        - Dijkstra takes in two input, a starting airport and an ending airport.
        - Outputs the shortest path between the startign airport and ending airport.
        
    * Enter 3 to run Landmark.
        - Landmark takes in three input: a starting airport, an ending airport, and a checkpoint airport.
        - Outputs the shortest path between the starting airport and ending airport through the checkpoint airport.
        
    * Enter 4 to change the input files.
    
    * Enter any other character twice to exit the program.
