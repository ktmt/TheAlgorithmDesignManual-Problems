/*
 * test_graph.cpp
 *
 *  Created on: May 14, 2014
 *      Author: vietnguyen
 */

#include "graph.h"

int main(){
	graph g;
	g.read_graph_weight(false);
	g.prim(1);
	g.kruskal();
	g.dijkstra(1);
}
