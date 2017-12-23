//
// Created by tanrui on 17-12-23.
//

#ifndef GRAPH_KRUSKAL_H
#define GRAPH_KRUSKAL_H
#include <cmath>
#include "GraphBase.h"
#include <set>

#define DefaultSize 30

const double MAXVALUE = pow(2, 10);
template <class T, class E>
struct MSTEdgeNode{
    int tail, head;
    E key;
    MSTEdgeNode():tail(-1),head(-1),head(0){};
    bool operator <= (MSTEdgeNode<T,E>& R){
        return key <= R.key;
    }
    bool operator > (MSTEdgeNode<T,E>& R){
        return key > R.key;
    }
};

template <class T, class E>
class MinSpanTree{
protected:
    MSTEdgeNode<T,E> *edgeNode;
    int maxSize, n;
public:
    MinSpanTree(int sz = DefaultSize-1):maxSize(sz), n(0){
        edgeNode = new MSTEdgeNode<T,E>[sz];
    }
    int Insert(MSTEdgeNode& item){

    }
};


template <class T, class E>
void Kruskal(Graph<T,E>& G, MinSpanTree<T,E>& MST){
    MSTEdgeNode<T,E> ed;
    int u, v, count;
    int n = G.getNumVertices();
    int m = G.getNumEdges();
    set<MSTEdgeNode<T,E>> H();
};


#endif //GRAPH_KRUSKAL_H
