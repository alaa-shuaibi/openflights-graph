# Source: Final Project Demo GitHub (with some adjustments)
EXENAME = finalproject
#this matches the object files 
#OBJS = main.o Good.o Receipt.o
OBJS = main.o algorithms.o graph.o edge.o readFromFile.o OpenFlights.o
CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement Makefile rule:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu")
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp OpenFlights.h
	$(CXX) $(CXXFLAGS) main.cpp

OpenFlights.o: OpenFlights.cpp OpenFlights.h
	$(CXX) $(CXXFLAGS) OpenFlights.cpp

algorithms.o: algorithms.cpp algorithms.h
	$(CXX) $(CXXFLAGS) algorithms.cpp

graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) graph.cpp

edge.o: edge.cpp edge.h
	$(CXX) $(CXXFLAGS) edge.cpp

miscellanies.o: miscellanies.cpp miscellanies.h
	$(CXX) $(CXXFLAGS) miscellanies.cpp

readFromFile.o: readFromFile.cpp readFromFile.h
	$(CXX) $(CXXFLAGS) readFromFile.cpp

testmiscellanies: output_msg tests/catch/catchmain.cpp tests/test_miscellanies.cpp
	$(LD) tests/catch/catchmain.cpp tests/test_miscellanies.cpp $(LDFLAGS) -o test

testgraph: output_msg tests/catch/catchmain.cpp tests/test_graph.cpp
	$(LD) tests/catch/catchmain.cpp tests/test_graph.cpp $(LDFLAGS) -o testgraph

testalgorithms: output_msg tests/catch/catchmain.cpp tests/test_algorithms.cpp
	$(LD) tests/catch/catchmain.cpp tests/test_algorithms.cpp $(LDFLAGS) -o testalgorithms

testopenflights: output_msg tests/catch/catchmain.cpp tests/test_openflights.cpp
	$(LD) tests/catch/catchmain.cpp tests/test_openflights.cpp $(LDFLAGS) -o testopenflights

test: output_msg tests/catch/catchmain.cpp tests/test_miscellanies.cpp tests/test_graph.cpp tests/test_algorithms.cpp tests/test_OpenFlights.cpp  
	$(LD) tests/catch/catchmain.cpp tests/test_miscellanies.cpp tests/test_graph.cpp tests/test_algorithms.cpp tests/test_OpenFlights.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test