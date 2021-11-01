#include <iostream>
#include <vector>
#ifndef vertex_H
#define vertex_H
using namespace std;
class vertex{
public:
    vertex();
    vertex(int a, float b, float c);///might not need i???

    int i;//original index  ///also acts as cost in the case of an edge???
    int minEdge;
    float cost;
    float x;
    float y;
    vector<int> verticesOfNeighbors;//store indices (in original vertex vector) of connecting edges
};
#endif