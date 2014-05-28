/*
 * networkflow.cpp
 *
 *  Created on: May 27, 2014
 *      Author: vietnguyen
 */

#include "networkflow.h"
#include <iostream>
#include <queue>
#include <limits>

using namespace std;


flow_graph::flow_graph() {
	// TODO Auto-generated constructor stub

}

flow_graph::~flow_graph() {
	// TODO Auto-generated destructor stub
}

void flow_graph::init_graph (bool isDirected){
	nvertices = 0;
	nedges = 0;
	directed = isDirected;
	maxflow = 0;

	for(int i = 1; i<= MAXV; i++){
		degree[i] = 0;
	}
	for(int i = 1; i <= MAXV; i++){
		edges[i] = NULL;
	}
}

void flow_graph::insert_edge_weight(int x, int y, int weight, bool directed){
	flowedgenode *p;		/* temporary pointer */
	p = (flowedgenode *)malloc(sizeof(flowedgenode));

	p->capacity = weight;
	p->flow = 0;
	p->residual = weight;
	p->v = y;
	p->next = edges[x];

	edges[x] = p;	/* insert at head of list */
	degree[x] ++;

	if(directed == false){
		insert_edge_weight(y, x, weight, true);
	}
	else{
		nedges ++;
	}
}

void flow_graph::add_residual_edges(){
	int x,y,weight,flow,residual;
	int m;		/* number of edges */
	init_graph(false);
	cin >> nvertices >> m;
	for(int i = 1; i<= m; i++){
		cin >> x >> y >> weight;
		insert_edge_weight(x,y,weight,false);
	}
}

void flow_graph::print_graph(){
	flowedgenode *p;
	for(int i = 1; i<= nvertices; i++){
		cout << i <<  ": ";
		p = edges[i];
		while(p!=NULL){
			cout << " " << p->v;
			p = p->next;
		}
		cout << "\n";

	}
}


void flow_graph::netflow(int source, int sink){
	int volume;				/* weight of the augmenting path */
	add_residual_edges();
	init_search();
	bfs(source);

	volume = path_volume(source,sink,parent);
	while(volume > 0){
		maxflow += volume;
		cout << "volume: " << volume << "\n";
		augment_path (source, sink, parent, volume);
		init_search();
		bfs(source);
		volume = path_volume(source,sink, parent);

	}
}



bool flow_graph::valid_edge(flowedgenode *e){
	if(e->residual > 0) return true;
	else return(false);
}

int flow_graph::path_volume(int start, int end, int parents[]){
	flowedgenode *e;				/* edge in question */

	if(parents[end] == -1 )return (0);
	e = find_edge(parents[end], end);

	if(start == parents[end])
		return (e->residual);
	else
		return (min(path_volume(start, parents[end], parents), e->residual));

}

flowedgenode * flow_graph::find_edge(int x, int y){
	flowedgenode *p;		/* temporary pointer */
	p = edges[x];
	while(p!= NULL){
		if(p->v == y) return (p);
		p = p-> next;
	}
	return (NULL);
}

void flow_graph::augment_path(int start, int end, int parents[], int volume){
	flowedgenode *e;				/* edge in question */
	if(start == end){
		cout << start << "\n";
		return;
	}

	cout << end  <<"<-";
	e = find_edge(parents[end], end);
	e->flow += volume;
	e->residual -= volume;
	e = find_edge(end, parents[end]);
	e->residual += volume;

	augment_path(start, parents[end], parents, volume);
}

void flow_graph::init_search(){
	for(int i = 1; i <= nvertices ; i++){
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

void flow_graph::bfs(int start){
	queue<int> q;			/* queue of vertices to visit */
	int v; 					/* current vertex */
	int y;					/* success vertex */
	flowedgenode *p;			/* temporary pointer */

	q.push(start);
	discovered[start] = true;
	while(!q.empty()){
		v = q.front();
		q.pop();
		process_vertex_early(v);
		processed[v] = true;
		p = edges[v];
		while(p!=NULL){
			if(!valid_edge(p)){
				p=p->next;
				continue;
			}
			y = p->v;
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

void flow_graph::process_vertex_late(int v){

}

void flow_graph::process_vertex_early(int v){
	//cout << "processed vertex " << v << "\n";
}

void flow_graph::process_edge(int v, int y){
	//cout << "processed edge (" << v << ", " << y << ")\n";

}
