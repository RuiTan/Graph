//
// Created by tanrui on 17-12-19.
//

#ifndef GRAPH_GRAPHLNK_H
#define GRAPH_GRAPHLNK_H

#include <thread_db.h>
#include "GraphBase.h"

template <class T, class E>
struct Edge{
    int dest;
    E cost;
    Edge<T,E> *link;
    Edge(){}
    Edge(int num, E weight) : dest(num), cost(weight), link(nullptr){}
    bool operator != (Edge<T,E>& R) const {
        return dest != R.dest;
    }
};

template <class T, class E>
struct Vertex{
    T data;
    Edge<T,E> *adj;
};

template <class T, class E>
class Graphlnk {
    friend istream&operator >> (istream& in, Graphlnk<T,E> &G){

    }
    friend ostream&operator << (ostream& out, Graphlnk<T,E> &G){

    }

private:
    int maxVertices;
    int numEdges;
    int numVertices;
    const int maxWeight = pow(2, 32);
    Vertex<T,E> *NodeTable;
    int getVertexPos(const T vertex){
        for (int i = 0; i < numVertices; ++i) {
            if (NodeTable[i].data == vertex) return i;
        }
        return -1;
    }

public:
    explicit Graphlnk(int sz = DefaultVertices){
        maxVertices = sz;
        numVertices = 0;
        numEdges = 0;
        NodeTable = new Vertex<T,E>[maxVertices];
        if (NodeTable == nullptr){
            cerr << "no more space!" << endl;
            exit(1);
        }
        for (int i = 0; i < maxVertices; ++i) {
            NodeTable[i].adj = nullptr;
        }
    };

    ~Graphlnk(){
        for (int i = 0; i < numVertices; i++) {
            auto node = NodeTable[i].adj;
            while (node != nullptr){
                NodeTable[i].adj = node->link;
                delete node;
                node = node->link;
            }
        }
        delete []NodeTable;
    }
    T getValue(int i){
        return (i >= 0 && i < maxVertices) ? NodeTable[i].data : 0;
    }
    E getWeight(int v1, int v2){
        if (v1 ！= -1 && )
    }
    bool insertVertex(const T& vertex){

    }
    bool removeVertex(int v){

    }
    bool insertEdge(int v1, int v2, E cost){

    }
    bool removeEdge(int v1, int v2){

    }
    int getFirstNeighbor(int v){

    }
    int getNextNeighbor(int v, int w){

    }

};

#endif //GRAPH_GRAPHLNK_H
