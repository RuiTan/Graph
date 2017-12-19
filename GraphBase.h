//
// Created by tanrui on 17-12-19.
//

#ifndef GRAPHBASE_H
#define GRAPHBASE_H

#include <jmorecfg.h>
#include <iostream>
#include <cmath>

using namespace std;

#define DefaultVertices 30


template <class T, class E>
class Graph{
protected:
    int maxVertices;
    int numEdges;
    int numVertices;
    virtual int getVertexPos(T vertex)= 0;
public:
    bool GraphEmpty() const{
        return numEdges == 0;
    }
    bool GraphFull() const {
        return numVertices == maxVertices || numVertices == maxVertices * (maxVertices - 1) / 2;
    }
    virtual T getValue(int i) = 0;
    virtual E getWeight(int v1, int v2)= 0;
    virtual int getFirstNeighbor(int v)= 0;
    virtual int getNextNeighbor(int v, int w)= 0;
    virtual bool insertVertex(const T& vertex)= 0;
    virtual bool insertEdge(int v1, int v2, E cost)= 0;
    virtual bool removeVertex(int v) = 0;
    virtual bool removeEdge(int v1, int v2) = 0;
};

#endif //GRAPH_GRAPHMODOLE_H
