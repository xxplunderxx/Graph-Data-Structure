#compiler variables for this file
# Macros
CXX = g++
CXXFLAGS = -std=c++11 -Wall
# Rule to link object code files to create executable file
simplegraph: simplegraph.o graph.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rules to compile source code file to object code
simplegraph.o: simplegraph.cc
	$(CXX) $(CXXFLAGS) -c -o $@    $<

graph.o: graph.cc graph.h
	$(CXX) $(CXXFLAGS) -c -o $@    $<

.PHONY: clean
clean:
	rm simplegraph *.o 

