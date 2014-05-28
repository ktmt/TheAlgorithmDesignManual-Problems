/*
 * networkflow.h
 *
 *  Created on: May 27, 2014
 *      Author: vietnguyen
 */

#ifndef NETWORKFLOW_H_
#define NETWORKFLOW_H_

#define MAXV 	1000		/* maximum number of vertices */

class flowedgenode{
public:
	int v;			/* neighboring vertex */
	int capacity; 	/* capacity of edge */
	int flow;		/* flow through edge */
	int residual;	/* residual capacity of edge */
	struct flowedgenode *next; 	/*next edge in list */
};

class flow_graph{
	flowedgenode *edges[MAXV+1]; 	/* adjacency info */
	int degree[MAXV+1];			/* outdegree of each vertex */
	int nvertices;				/* number of vertices in graph */
	int nedges;					/* number of edges in graph */
	bool directed;				/* is the graph directed? */

	/* For BFS */
	bool processed[MAXV+1];		/* which vertices have been processed */
	bool discovered[MAXV+1];	/* which vertices have been found */
	int parent[MAXV+1];			/* discovery relation */

public:

	int maxflow;				/* maxflow */

	flow_graph();
	virtual ~flow_graph();
	void init_graph(bool directed);
	void insert_edge_weight(int x, int y, int weight, bool directed);
	void read_graph_weight(bool directed);
	void print_graph();

	/* For BFS */
	void init_search();
	void bfs(int start);
	void process_vertex_early(int v);
	void process_vertex_late(int v);
	void process_edge(int v, int y);
	void find_path(int start, int end, int parent[]);	/* application of BFS to find path from one vertex to another */

	/* For network flow */
	void netflow(int source, int sink);
	bool valid_edge(flowedgenode *e);
	int path_volume(int start, int end, int parents[]);
	flowedgenode *find_edge(int x, int y);
	void augment_path(int start, int end, int parents[], int volume);
	void add_residual_edges();
};

#endif /* NETWORKFLOW_H_ */
