/*
 * graph.cpp
 *
 *  Created on: May 14, 2014
 *      Author: vietnguyen
 */

#include "graph.h"
#include <iostream>
#include <queue>
#include <limits>

using namespace std;

graph::graph() {
	// TODO Auto-generated constructor stub

}

graph::~graph() {
	// TODO Auto-generated destructor stub
}

void graph::init_graph (bool isDirected){
	nvertices = 0;
	nedges = 0;
	directed = isDirected;

	for(int i = 1; i<= MAXV; i++){
		degree[i] = 0;
	}
	for(int i = 1; i <= MAXV; i++){
		edges[i] = NULL;
	}
}

void graph::insert_edge(int x, int y, bool directed){
	edgenode *p;		/* temporary pointer */
	p = (edgenode *)malloc(sizeof(edgenode));

	p->weight = 0;
	p->y = y;
	p->next = edges[x];

	edges[x] = p;	/* insert at head of list */
	degree[x] ++;

	if(directed == false){
		insert_edge(y, x, true);
	}
	else{
		nedges ++;
	}
}

void graph::insert_edge_weight(int x, int y, int weight, bool directed){
	edgenode *p;		/* temporary pointer */
	p = (edgenode *)malloc(sizeof(edgenode));

	p->weight = weight;
	p->y = y;
	p->next = edges[x];

	edges[x] = p;	/* insert at head of list */
	degree[x] ++;

	if(directed == false){
		insert_edge(y, x, true);
	}
	else{
		nedges ++;
	}
}

void graph::read_graph(bool directed){
	int x,y;
	int m; 		/* number of edges */
	init_graph(directed);
	cin >> nvertices >> m;
	for (int i = 1; i<=m; i++){
		cin >> x >> y;
		insert_edge(x,y, directed);
	}
}

void graph::read_graph_weight(bool directed){
	int x,y, weight;
	int m; 		/* number of edges */
	init_graph(directed);
	cin >> nvertices >> m;
	for (int i = 1; i<=m; i++){
		cin >> x >> y >> weight;
		insert_edge_weight(x,y,weight,directed);
	}
}

void graph::print_graph(){
	edgenode *p;
	for(int i = 1; i<= nvertices; i++){
		cout << i <<  ": ";
		p = edges[i];
		while(p!=NULL){
			cout << " " << p->y;
			p = p->next;
		}
		cout << "\n";

	}
}

void graph::init_search(){
	for(int i = 1; i <= nvertices ; i++){
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

void graph::bfs(int start){
	queue<int> q;			/* queue of vertices to visit */
	int v; 					/* current vertex */
	int y;					/* success vertex */
	edgenode *p;			/* temporary pointer */

	q.push(start);
	discovered[start] = true;
	while(!q.empty()){
		v = q.front();
		q.pop();
		process_vertex_early(v);
		processed[v] = true;
		p = edges[v];
		while(p!=NULL){
			y = p->y;
			if((processed[y] == false) || directed ){
				process_edge(v,y);
			}
			if(discovered[y] == false){
				q.push(y);
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;
		}
		process_vertex_late(v);
	}
}

void graph::process_vertex_late(int v){

}

void graph::process_vertex_early(int v){
	cout << "processed vertex " << v << "\n";
}

void graph::process_edge(int v, int y){
	cout << "processed edge (" << v << ", " << y << ")\n";

	/* Two coloring */
	if(color[v]== color[y]){
		bipartite = false;
		cout << "Warning: not bipartite due  to (" << v << ", " << y << "\n";
	}
	color[y] = complement(color[v]);
}

int graph::complement(int color){
	if(color == WHITE) return (BLACK);
	if(color == BLACK) return (WHITE);
	return (UNCOLORED);
}
void graph::find_path(int start, int end, int parents[]){
	if((start==end) || (end == -1)){
		cout << "\n" << start;
	}
	else{
		find_path(start, parents[end], parents);
		cout << " " << end;
	}
}

void graph::twocolor(){
	for (int i = 1; i<= nvertices; i++){
		color[i] = UNCOLORED;
	}
	bipartite = true;
	init_search();
	for(int i = 1; i<= nvertices; i++){
		if(discovered[i] == false){
			color[i]= WHITE;
			bfs(i);
		}
	}
}

void graph::dfs(int v){
	edgenode *p;		/* temporary pointer */
	if (finished) return;

	discovered[v] = true;
	time = time + 1;
	entry_time[v] = time;

	process_vertex_early(v);

	p = edges[v];
	while(p!=NULL){
		int y = p->y;
		if(discovered[y] == false){
			parent[y] = v;
			process_edge_topo(v,y);
			dfs(y);
		}
		else if((!processed[y] && parent[v] != y) || (directed)){
			process_edge_topo(v,y);
		}
		if(finished) return;
		p=p->next;
	}

	process_vertex_late_topo(v);
	time = time + 1;
	exit_time[v] = time;
	processed[v] = true;
}

int graph::edge_classification(int x, int y){
	if(parent[y] == x) return (TREE);
	if(discovered[y] && !processed[y]) return (BACK);
	if(processed[y] && (entry_time[y] > entry_time[x])) return (FORWARD);
	if(processed[y] && (entry_time[y] < entry_time[x])) return (CROSS);
	return (TREE);
}

void graph::process_vertex_late_topo(int v){
	sorted.push(v);
}

void graph::process_edge_topo(int x, int y){
	int c = edge_classification(x,y);
	if(c == BACK){
		cout << "Warning: directed cycle found, not a DAG \n";
	}
}

void graph::topo_sort(){
	for(int i = 1; i <= nvertices; i++){
		if(discovered[i] == false){
			dfs(i);
		}
	}
	print_stack();
}

void graph::print_stack(){
	while(!sorted.empty()){
		int i = sorted.top();
		sorted.pop();
		cout << i << ", ";
	}
	cout << "\n";
}

void graph::prim (int start){
	edgenode *p;		/* temporary pointer */
	bool intree[MAXV+1];	/* is the vertex in the tree yet? */
	int distance[MAXV+1];	/* cost of adding to tree */
	int v;					/* current vertex to process */
	int w;					/* candidate next vertex */
	int weight;				/* edge weight */
	int dist;				/* best current distance from start */
	for (int i = 1; i <= nvertices; i++){
		intree[i] = false;
		distance[i] = std::numeric_limits<int>::max();
		parent[i] = -1;
	}
	distance[start] = 0;
	v = start;
	cout << "Minimum spanning tree by Prim's algorithm: \n";
	while(intree[v] == false){
		cout << "("<< parent[v] << ", " << v << ")\n";
		intree[v] = true;
		p = edges[v];
		while(p!=NULL){
			w = p->y;
			weight = p->weight;
			if((distance[w] > weight) && (intree[w] == false)){
				distance[w] = weight;
				parent[w] = v;
			}
			p = p->next;
		}

		v = 1;
		dist = std::numeric_limits<int>::max();
		for(int i = 1; i <= nvertices; i++){
			if((intree[i] == false) && (dist > distance[i])){
				dist = distance[i];
				v = i;
			}
		}
	}
}
