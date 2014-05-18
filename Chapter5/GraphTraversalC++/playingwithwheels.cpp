/*
 * playingwithwheels.cpp
 * Exercise 5-2. Chapter 5 - The Algorithm Design Manual
 * URL: http://www.programming-challenges.com/pg.php?page=downloadproblem&format=html&probid=110902
 *  Created on: May 17, 2014
 *      Author: vietnguyen
 */

#include <iostream>
#include <fstream>
#include <queue>

#define MAXVERTICES 10000

using namespace std;

class edgenode{
public:
	int y;
	edgenode *next;	/* next edge in list */
};

class graph{
private:
	edgenode *edges[MAXVERTICES+1];
	int degree[MAXVERTICES+1];
	int nvertices;		/* number of vertices in graph */
	int nedges;			/* number of edges in graph */
	vector<int> forbiddens;
	int steps[MAXVERTICES+1];			/* number of steps to each configs */
	int start;
	int stop;
	int result;

	/* For BFS */
	bool processed[MAXVERTICES + 1];
	bool discovered[MAXVERTICES + 1];
	int parent[MAXVERTICES+1];
public:
	graph(){

	}
	virtual ~graph(){

	}
	void init_graph(){
		nvertices = 0;
		nedges = 0;
		start = 0;
		stop = 9999;
		for(int i = 1; i <= MAXVERTICES; i++){
			degree[i] = 0;
			edges[i] = NULL;
			steps[i] = 0;
		}
	}
	void insert_edge(int x, int y, bool directed){
		edgenode *p; 	/* temp pointer */
		p = (edgenode *) malloc(sizeof(edgenode));

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
	void build_graph(){
		for (int i = 0; i<=9999; i++){
			if(i%10 < 9){
				insert_edge(i, i + 1, false);
			}
			if((i%100)/10 < 9){
				insert_edge(i, i+ 10, false);
			}
			if((i%1000) / 100 < 9){
				insert_edge(i, i +100, false);
			}
			if(i / 1000 < 9){
				insert_edge(i, i+1000, false );
			}
		}
	}
	void init_search(){
		for(int i = 1; i <= MAXVERTICES; i++){
			processed[i] = discovered[i] = false;
			parent[i] = -1;
		}
	}
	int bfs(){
		queue<int> q;
		int v;		/* current vertex */
		int y;		/* success vertex */
		edgenode *p;

		q.push(start);
		discovered[start] = true;
		while(!q.empty()){
			v = q.front();
			int s = steps[v];
			q.pop();
			process_vertex_early(v);
			processed[v] = true;
			p = edges[v];
			while(p!=NULL){
				y = p->y;
				if(processed[y] == false){
					process_edge(v,y);
				}
				if(discovered[y] == false){
					bool isForbidden = false;
					for(int i = 0; i < forbiddens.size(); i++){
						if(y == forbiddens[i]){
							isForbidden = true;
						}
					}
					if(!isForbidden){
						q.push(y);
						discovered[y] = true;
						parent[y] = v;
						steps[y] = s + 1;
					}

				}
				if(y == stop){
					return steps[y];
				}
				p = p->next;
			}
			process_vertex_late(v);
		}
		return -1;
	}
	void process_vertex_late(int v){

	}

	void process_vertex_early(int v){
		cout << "processed vertex " << v << "\n";
	}

	void process_edge(int v, int y){
		cout << "processed edge (" << v << ", " << y << ")\n";

	}

	void process(){
		ifstream ifs("wheel.txt", std::ifstream::in);
		int ncases;		/* number of test cases */
		ifs >> ncases;
		for(int i = 1; i<=ncases; i++){
			int x1,x2,x3,x4;
			ifs >> x1 >> x2 >> x3 >> x4;
			start = x1 * 1000 + x2 * 100 + x3 * 10 + x4;
			ifs >> x1 >> x2 >> x3 >> x4;
			stop = x1 * 1000 + x2 * 100 + x3 * 10 + x4;

			int nforbid;	/* number of forbidden configs */
			ifs >> nforbid;
			for(int j = 1; j<=nforbid; j++){
				ifs >> x1 >> x2 >> x3 >> x4;
				int forbidden = x1 * 1000 + x2 * 100 + x3 * 10 + x4;
				forbiddens.push_back(forbidden);
			}
			init_search();
			cout << bfs() << "\n";
		}
	}
};

int main(){
	graph g;
	g.init_graph();
	g.build_graph();
	g.process();
}
