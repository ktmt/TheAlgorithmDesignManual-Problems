/*
 * graph_adjacency_matrix.cpp
 *
 *  Created on: May 26, 2014
 *      Author: vietnguyen
 */

#include "graph_adjacency_matrix.h"

using namespace std;

void adjacency_matrix::floyd(){
	int through_k;			/* distance through vertex k */
	for(int k=1;k<=nvertices;k++)
		for(int i=1;i<=nvertices;i++)
			for(int j = 1; j <= nvertices; j++){
				through_k = weight[i][k] + weight[k][j];
				if(through_k < weight[i][j])
					weight[i][j]=through_k;
			}
}
void adjacency_matrix::init_graph(){
	for(int i = 1; i <= MAXV; i++)
		for(int j = 1; j <= MAXV; j++){
			weight[i][j] = MAXINT;
		}
}
void adjacency_matrix::read_graph(){
	int x,y,w;
	int m; 		/* number of edges */
	cin >> nvertices >> m;
	for (int i = 1; i<=m; i++){
		cin >> x >> y >> w;
		weight[x][y] = w;
		weight[y][x] = w;
	}
}

int adjacency_matrix::shortest_path(int i, int j){
	return weight[i][j];
}
