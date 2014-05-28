/*
 * test_network_flow.cpp
 *
 *  Created on: May 28, 2014
 *      Author: vietnguyen
 */

#include "networkflow.h"
#include <iostream>
using namespace std;
int main(){
	flow_graph fg;
	fg.init_graph(false);
	fg.netflow(1,7);
	cout << "Max flow between 1 and 7: " << fg.maxflow << "\n";
}
