#ifndef prim_H
#define prim_H
#include <iostream>
#include <sstream>
#include <string>
#include "vertex.h"
#include <vector>
#include <map>
using namespace std;
class prim{

	public:
    //no constructors?????
		void createMST(vector<vertex> vertices, vector<vertex> edges);
		//int minKey(int V);
		//void printMST(vector<vertex> graphX);
	private:
		
		//heapmap heap;//push vertexs with their key and edge cost
		//map<int,float> costs;//use map to determine o(1) is key(cost)is included? THIS LINE IS REPLACED BY ABOVE HEAPMAP

		//map<int,vertex> parentEdges;//stores which edge provides minimum link to a particular vertex
		vector<vertex> MSTedges; //stores parent and child edges in order//may need to be sorted after
		

	    vector<bool> used; //store usage status of vertices
		vector<vertex> parents;


		//vector<int> used;//stores values of already used nodes

		//bool initialized;
		//vector<int> parent;//store constructed mst
		//vector<int> key;//store values used to pick minimum edge
				


};
#endif