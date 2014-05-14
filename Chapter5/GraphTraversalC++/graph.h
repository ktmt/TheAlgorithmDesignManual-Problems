/*
 * graph.h
 *
 *  Created on: May 14, 2014
 *      Author: vietnguyen
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#define MAXV 	1000		/* maximum number of vertices */

class graph {
private:
	edgenode *edge[MAXV+1]; 	/* adjacency info */
	int degree[MAXV+1];			/* outdegree of each vertex */
	int nvertices;				/* number of vertices in graph */
	int nedges;					/* number of edges in graph */
	bool directed;				/* is the graph directed? */
public:
	graph();
	virtual ~graph();
	void init_graph(bool directed);
	void insert_edge(int x, int y, bool directed);
	void read_graph(bool directed);
	void print_graph();
};

class edgenode{
	int y;			/* adjacency info */
	int weight;		/* edge weight, if any */
	edgenode *next;	/* next edge in list */

};

#endif /* GRAPH_H_ */
