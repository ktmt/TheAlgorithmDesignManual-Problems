/*
 * set_union.cpp
 *
 *  Created on: May 24, 2014
 *      Author: vietnguyen
 */

#include "set_union_custom.h"

void set_union_custom::set_union_init(int _n){
	for (int i = 1; i<=n; i++){
		p[i] = i;
		size[i] = 1;
	}
	n = _n;
}

int set_union_custom::find(int x){
	if(p[x] == x)
		return (x);
	else
		return (find (p[x]));
}

void set_union_custom::union_sets(int s1, int s2){
	int r1, r2;				/* roots of sets */
	r1 = find(s1);
	r2 = find(s2);

	if(r1==r2) return;		/* already in same set */

	if(size[r1] >= size[r2]){
		size[r1] = size[r1] + size[r2];
		p[r2] = r1;
	}
	else{
		size[r2] = size[r1] + size[r2];
		p[r1] = r2;
	}
}

bool set_union_custom::same_component(int s1, int s2){
	return (find(s1) == find(s2));
}
