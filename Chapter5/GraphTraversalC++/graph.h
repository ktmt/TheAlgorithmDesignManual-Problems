/*
 * graph.h
 *
 * Reference: Chapter 5: Graph Traversal - The Algorithm Design Manual
 *  Created on: May 14, 2014
 *      Author: vietnguyen
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#define MAXV 	1000		/* maximum number of vertices */

#define UNCOLORED 	-1
#define WHITE 		0
#define BLACK		1

class edgenode{
public:
	int y;			/* adjacency info */
	int weight;		/* edge weight, if any */
	edgenode *next;	/* next edge in list */

};

class graph {
private:
	edgenode *edges[MAXV+1]; 	/* adjacency info */
	int degree[MAXV+1];			/* outdegree of each vertex */
	int nvertices;				/* number of vertices in graph */
	int nedges;					/* number of edges in graph */
	bool directed;				/* is the graph directed? */

	/* For BFS */
	bool processed[MAXV+1];		/* which vertices have been processed */
	bool discovered[MAXV+1];	/* which vertices have been found */
	int parent[MAXV+1];			/* discovery relation */

	/* For two color */
	int color[MAXV+1];
	bool bipartite;

public:
	graph();
	virtual ~graph();
	void init_graph(bool directed);
	void insert_edge(int x, int y, bool directed);
	void read_graph(bool directed);
	void print_graph();

	/* For BFS */
	void init_search();
	void bfs(int start);
	void process_vertex_early(int v);
	void process_vertex_late(int v);
	void process_edge(int v, int y);
	void find_path(int start, int end, int parent[]);	/* application of BFS to find path from one vertex to another */

	/* Two color */
	void twocolor();
	int complement(int color);
};


#endif /* GRAPH_H_ */
