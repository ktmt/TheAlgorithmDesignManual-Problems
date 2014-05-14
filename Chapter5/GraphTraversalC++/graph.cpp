/*
 * graph.cpp
 *
 *  Created on: May 14, 2014
 *      Author: vietnguyen
 */

#include "graph.h"
#include <iostream>

using namespace std;

graph::graph() {
	// TODO Auto-generated constructor stub

}

graph::~graph() {
	// TODO Auto-generated destructor stub
}

void graph::init_graph (bool directed){
	nvertices = 0;
	nedges = 0;
	directed = directed;

	for(int i = 1; i<= MAXV; i++){
		degree[i] = 0;
	}
	for(int i = 1; i <= MAXV; i++){
		edges[i] = NULL;
	}
}

void graph::insert_edge(int x, int y, bool directed){
	edgenode *p;		/* temporary pointer */
	p = malloc(sizeof(edgenode));

	p->weight = 0;
	p->y = y;
	p->next = edges[x];

	edges[x] = p;	/* insert at head of list */
	degree[x] ++;

	if(directed == false){
		insert_edge(y, x, TRUE);
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
