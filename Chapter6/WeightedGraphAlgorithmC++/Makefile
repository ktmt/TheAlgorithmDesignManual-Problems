all: test_graph.out
	
graph.o: graph.cpp
	g++ -c graph.cpp

graph_adjacency_matrix.o: graph_adjacency_matrix.cpp
	g++ -c graph_adjacency_matrix.cpp 
	
set_union_custom.o: set_union_custom.cpp
	g++ -c set_union_custom.cpp

test_graph.out: test_graph.cpp graph.o set_union_custom.o graph_adjacency_matrix.o
	g++ graph.o set_union_custom.o graph_adjacency_matrix.o test_graph.cpp -o test_graph.out
	
clean:
	rm *.o *.out