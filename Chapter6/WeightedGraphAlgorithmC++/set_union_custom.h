/*
 * set_union.h
 * Reference: Section 6.1.3 The Algorithms Design Manual
 *
 *  Created on: May 24, 2014
 *      Author: vietnguyen
 */

#ifndef SET_UNION_H_
#define SET_UNION_H_

#define SET_SIZE 1000

class set_union_custom{
	int p[SET_SIZE + 1];			/* parent element */
	int size[SET_SIZE + 1];			/* number of elements in subtree i */
	int n;							/* number of elements in set */
public:
	void set_union_init(int n);
	int find(int x);
	void union_sets(int s1, int s2);
	bool same_component(int s1, int s2);
};

#endif /* SET_UNION_H_ */
