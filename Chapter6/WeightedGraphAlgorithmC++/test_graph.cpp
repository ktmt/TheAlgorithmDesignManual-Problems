/*
 * test_graph.cpp
 *
 *  Created on: May 14, 2014
 *      Author: vietnguyen
 */

#include "graph.h"
#include "graph_adjacency_matrix.h"

int main(){
	/*
	graph g;
	g.read_graph_weight(false);
	g.prim(1);
	g.kruskal();
	g.dijkstra(1);
    */
	adjacency_matrix g2;
	g2.init_graph();
	g2.read_graph();
	g2.floyd();
	int x, y;
	cin >> x >> y;
	cout << "Shortest path: " << g2.shortest_path(x,y) << "\n";

}
