# canaga2-ashuai6-rvasant2-pm14
Final Project

Warning: Use of EWS Machine recommended

Summary: This program is responsible for implementing traversal algorithms on the openflights dataset. https://openflights.org/data.html

Goals: Find the shortest paths between two cities or countries through air travel. Traveling paths include Djikstra, Landmark, and BFS to get to other places in the world.

Steps:

1. Type make
2. Type ./finalproject

3. Type filename1 for airports default option: airports.txt
                                other options: tinyAirport.txt

4. Type filename2 for routes default option: routes.txt
                                other options: tinyRoute.txt
    *Feel free to include other files but of the same type and have to be within the same format as the options listed above.
    *Make sure the files are within the same folder.

5. Pick an options for traversals:
    1. BFS
    2. Djikstra
    3. Landmark
    4. Change the File

6. Input any char besides 1, 2, 3, or 4 to exit out of the program twice when it's the first time 
    otherwise do it once

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
                          

