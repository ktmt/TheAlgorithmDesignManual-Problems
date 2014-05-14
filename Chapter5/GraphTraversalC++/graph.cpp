/*
 * graph.cpp
 *
 *  Created on: May 14, 2014
 *      Author: vietnguyen
 */

#include "graph.h"
#include <iostream>
#include <queue>

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
