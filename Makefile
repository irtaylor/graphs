CXX = g++
CXXFLAGS = -g

# TODO: figure out best way to list dependencies

main: graph.o weighted_graph.o main.cpp # list dependencies
	$(CXX) $(CXXFLAGS) -o main graph.o weighted_graph.o main.cpp

graph: graph.hpp
	$(CXX) $(CXXFLAGS) -c graph.cpp

weighted_graph: weighted_graph.hpp
	$(CXX) $(CXXFLAGS) -c weighted_graph.cpp

clean:
	rm -Rf main *.o *.dSYM
