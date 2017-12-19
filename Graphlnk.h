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
        if (v1 != -1 && v2 != -1){

        }
    }
    bool insertVertex(const T& vertex){
        if (numVertices == maxVertices) return false;
        NodeTable[numVertices].data = vertex;
        return true;
    }
    bool removeVertex(int v){
        if (v >= numVertices || v < 0 || numVertices == 1) return false;
        auto removeNode = NodeTable[v];
        auto replaceNode = NodeTable[numVertices-1];
        removeNode.adj = replaceNode.adj;
        removeNode.data = replaceNode.data;
        numVertices--;
    }
    bool insertEdge(int v1, int v2, E cost){

    }
    bool removeEdge(int v1, int v2){

    }
    int getFirstNeighbor(int v){
        if (v != -1){
            auto node = NodeTable[v].adj;
            if (node != nullptr) return node->dest;
        }
        return -1;
    }
    int getNextNeighbor(int v, int w){
        if (v != -1 && w!= -1){
            auto node = NodeTable[v].adj;
            while (node!= nullptr && node->dest!=w){
                node = node->link;
            }
            if (node != nullptr && node->link != nullptr){
                return node->link->dest;
            }
        }
        return -1;
    }

};

#endif //GRAPH_GRAPHLNK_H
