/*
 * test_graph.cpp
 *
 *  Created on: May 14, 2014
 *      Author: vietnguyen
 */

#include "graph.h"

int main(){
	graph g;
	int parent[10];
	g.read_graph(true);
	//g.twocolor();
	g.topo_sort();
}
