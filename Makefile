CXX = g++
CXXFLAGS = -g

main: graph.o main.cpp # list dependencies
	$(CXX) $(CXXFLAGS) -o main graph.o main.cpp

graph: graph.h
	$(CXX) $(CXXFLAGS) -c graph.cpp

clean:
	rm -Rf main *.o *.dSYM
