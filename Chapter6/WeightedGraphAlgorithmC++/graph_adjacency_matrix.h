/*
 * graph_adjacency_matrix.h
 *
 *  Created on: May 26, 2014
 *      Author: vietnguyen
 */

#ifndef GRAPH_ADJACENCY_MATRIX_H_
#define GRAPH_ADJACENCY_MATRIX_H_
#include <iostream>
#include <limits>

#define MAXV 1000
#define MAXINT 1000000
class adjacency_matrix{
	int weight[MAXV+1][MAXV+1];		/* adjacency/weight info */
	int nvertices;					/* number of vertices in graph */
public:
	void floyd();
	void init_graph();
	void read_graph();
	int shortest_path(int i, int j);
};

#endif /* GRAPH_ADJACENCY_MATRIX_H_ */
