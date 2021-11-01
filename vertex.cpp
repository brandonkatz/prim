#include <iostream>
#include "vertex.h"
using namespace std;
    vertex::vertex(){
        i=0;
        x=0;
        y=0;
    }
    vertex::vertex(int a, float b, float c){
        i=a;
        x=b;
        y=c;
    }
    bool operator==(const vertex& lhs, const vertex& rhs){
        return lhs.i==rhs.i;
    }