#include <iostream>
#include <sstream>
#include <string>
#include "vertex.h"
#include <vector>
#include "prim.h"
#include <map>
#include <algorithm>
using namespace std;
 bool comparator(vertex &a, vertex &b){
        if(a.x==b.x)
            return a.y<b.y;
        else
            return a.x<b.x;
    }
void prim::createMST(vector<vertex> vertices, vector<vertex> edges){
    
    //push input verts to heap, increment to infinite cost except for first index?
    //vertices[0].cost=0;
    for(int i=0;i<vertices.size();i++){
        vertices[i].cost=99999999;
    }
    /*
    ///remove below loop as we test heapmap
    for(int i=0;i<vertices.size();i++){
        //heap.insert(vertices[i]);
        //insert vertices to heap
    }
    //heap.print();
    //heap.popMin();
    //heap.print();
    for(int i=0;i<vertices.size();i++){
        //cout<<heap[i].cost<<endl;
    }*/
    
    
    
    
    for(int i=0; i<vertices.size();i++){
        used.push_back(false);
    }/*

    int now = 0;
    used[0]=true;
    while(MSTedges.size()<vertices.size()-1){
        int mincos=99999999;///or does it need to be <vertices.size()-1?
        for(int e=0; e<edges.size();e++){///go thru eges to find those attached to Now
            if(edges[e].x==now||edges[e].y==now && !used[edges[e].x]){///check if now is on this edge, and make sure not cycle
                if(edges[e].cost<mincos){
                    vertices[now].cost=edges[e].cost;
                }
                    //change current mincost,
            }
        }
        int min = 9999999;///max int to start

    }*/
    //cout<< "comparing costs "<< edges[]
    used[0]=true;
    parents.push_back(vertices[0]);
    while(parents.size()<vertices.size()){
        bool found=false;
        float minc=9999999999;
        int edgeToAdd=-1;
        for(int i=0; i<parents.size();i++){//find min among viable edge options at this point
            for(int e=0; e<edges.size();e++){
                if((edges[e].x==parents[i].i||edges[e].y==parents[i].i) && (used[edges[e].x]+used[edges[e].y]<2)){///check if now is on this edge, and make sure not cycle
                    //cout<<"INSIDE THE viable if, does not create cycle"<<endl;
                    //cout<<"edge cost of e: "<< e <<" "<<edges[e].cost;///problem with calculating costs
                    if(edges[e].cost<minc){//parents[i].cost){
                        //cout<<"made it in as cheapest edge"<<endl;
                        minc=edges[e].cost;
                        edgeToAdd=e;
                        found=true;
                        //parents[i].cost=edges[e].cost;
                       // parents[i].minEdge=e;//////use this for the next loop
                    }
                    //cout<<endl;
                }
            }
        }
        //cout<<"looped, found an edge to add: "<< found<<endl;
        MSTedges.push_back(edges[edgeToAdd]);
        vertex adding;
        if(used[edges[edgeToAdd].x])//////finding which vertex on edgeToAdd now is a parent
            adding=vertices[edges[edgeToAdd].y];///do we need to deep copy here?
        else
            adding=vertices[edges[edgeToAdd].x];
        parents.push_back(adding);
        used[adding.i]=true;
        //at this point, loop again thru parents to choose which updated minpath to follow?
        //for(int i=0; i<parents.size();i++){}

       

    }
   
    //sort edges
        sort(MSTedges.begin(), MSTedges.end(), comparator);
        //cout<<endl;
        //print
        for(int i=0; i<MSTedges.size();i++){
            cout<<MSTedges[i].x<<" "<<MSTedges[i].y<<endl;
        }
}
