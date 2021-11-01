#include <iostream>
#include <sstream>
#include <string>
#include "prim.h"
#include "vertex.h"
#include <vector>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    //cout<< setprecision(17);//////////////IS THIS OUR PROBLEM
    int n;//num vertices(vertexs)
    cin>>n;
    vector<vertex> vertices;
    for(int i=0; i<n; i++){
        /*
        string ex;///?
        cin>>ex;
        stringstream ecks(ex);
        float x=0.0;
        ecks>>x;
        string why;
        cin>>why;
        stringstream wai(why);
        float y=0.0;
        wai>>y;
        */
        string ex;
        cin>>ex;
        string why;
        cin>> why;
        //cout<<ex<<", "<<why<<"!!!!!!"<<endl;
        float x = stod(ex);
        float y =stod(why);
        vertex p(i,x,y);
        vertices.push_back(p);//might be compiler specific///can assume that correct values are stored at this vertex?, but cannot print them///maybe do something to compare and assert?
    }
    
    int m;//num edges //DO SPECIAL CASE WHEN M==0
    cin>>m;
    vector<vertex> edges;
    if(m==0){
        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                float cost = sqrt(pow((vertices[j].x-vertices[i].x),2)+pow((vertices[j].y-vertices[i].y),2)*1.0);
                vertex edge;
                edge.x=i;
                edge.y=j;
                edge.cost=cost;
                edges.push_back(edge);
            }
        }
    }
    else{
        for(int j=0;j<m;j++){///use vertex class?
            int v1;//index of first vertex in vertices
            cin>>v1;
            ///vertices[v1].verticesOfNeighbors.push_back(j);stores the index of this edge in v1 so we can easily return its cost, cost not included yet
            int v2;//index of 2nd vertex in vertices
            cin>>v2;
            //vertices[v2].verticesOfNeighbors.push_back(j);///////////////////
            ///find distance
            float cost = sqrt(pow((vertices[v2].x-vertices[v1].x),2)+pow((vertices[v2].y-vertices[v1].y),2)*1.0);
            vertex edge;//(cost,v1,v2); ///index is -1 because we are using the vertex class just for efficiency( not actually a vertex here)
            edge.cost = cost;
            edge.x=v1;
            edge.y=v2;
            edges.push_back(edge);
            //cout<< "x1: "<<vertices[v1].x<<" y1: "<<vertices[v1].y<<endl;
            //cout<< "x2: "<<vertices[v2].x<<" y2: "<<vertices[v2].y<<endl;
            //cout<< "edge: "<<j<<" cost: "<< cost<<endl;
        }
    }
    /*for(int i=0; i<n; i++){
        cout<<vertices[i].x<<" "<<vertices[i].y<<endl;
    }*/
    prim a;
    a.createMST(vertices,edges);
    //cout<< fixed << setprecision(4);
    ///test print for verifying input:
    /*for(int i=0; i<n; i++){
        cout<<vertices[i].x<<" "<<vertices[i].y<<endl;
    }
    cout<<endl;
    for(int i=0; i<m; i++){
        cout<<edges[i].x<<" "<<edges[i].y<<endl;
    }*/
    
    /*string s = "0.2357324";///keep this for chECKING PRECISION ON PIAZZA
    //stringstream stre(s);
    float a = stod(s,0);
    ///stre>>a;
    cout<<a<<endl;*/
    return 0;
}