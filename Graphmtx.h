//
// Created by tanrui on 17-12-19.
//

#ifndef GRAPH_GRAPHMTX_H
#define GRAPH_GRAPHMTX_H

#include "GraphBase.h"
template <class T, class E>
class Graphmtx : public Graph<T,E>{

    friend istream& operator >> (istream& in, Graphmtx<T,E>& G){
        int n, m;
        T e1, e2;
        E weight;
        in >> n;
        in >> m;
        for (int i = 0; i < n; ++i) {
            in >> e1;
            G.insertVertex(e1);
        }
        int i = 0;
        while (i < m){
            in >> e1 >> e2 >> weight;
            int j = G.getVertexPos(e1);
            int k = G.getVertexPos(e2);
            if (j == -1 || k == -1)
                cout << "Wrong input." << endl;
            else{
                G.insertEdge(j, k, weight);
                i++;
            }
        }
        return in;
    };
    friend ostream& operator << (ostream& out, Graphmtx<T,E>& G){
        int i, j, n, m;
        T e1, e2;
        E w;
        n = G.numVertices;
        m = G.numEdges;
        out << n << "," << m << endl;
        for (i = 0; i < n; i++) {
            for (j = i+1; j < n; j++) {
                w = G.getWeight(i, j);
                if (w>0&&w<maxWeight){
                    e1 = G.getValue(i);
                    e2 = G.getValue(j);
                    out << "(" << e1 << "," << e2 << "," << w << ")" << endl;
                }
            }
        }
        for (int k = 0; k < G.numVertices; ++k) {
            for (int l = 0; l < G.numVertices; ++l) {
                if(G.Edge[k][l]!=maxWeight){
                    out << G.Edge[k][l] << "\t";
                } else{
                    out << "∞\t";
                }
            }
            out << endl;
        }
        return out;
    };

private:
    int maxVertices;
    int numEdges;
    int numVertices;
    T * VerticesList;
    E ** Edge;
    int getVertexPos(T vertex){
        for (int i = 0; i < numVertices; ++i)
            if (VerticesList[i] == vertex)
                return i;
        return -1;
    }
    static const E maxWeight = pow(2, 16);
public:
    explicit Graphmtx(int size = DefaultVertices){
        maxVertices = size;
        numVertices = 0;
        numEdges = 0;
        VerticesList = new T[maxVertices];
        Edge =  new E *[maxVertices];
        for (int k = 0; k < maxVertices; ++k) {
            Edge[k] = new E[maxVertices];
        }
        for (int l = 0; l < maxVertices; ++l) {
            for (int i = 0; i < maxVertices; ++i) {
                Edge[i][l] = (i == l ? 0 : maxWeight);
            }
        }
    }
    ~Graphmtx(){
        delete []VerticesList;
        delete []Edge;
    };
    T getValue(int i){
        return i>=0&&i<=numVertices ? VerticesList[i] : -1;
    }
    E getWeight(int v1, int v2){
        return v1!=-1&&v2!=-1 ? Edge[v1][v2] : 0;
    }
    int getFirstNeighbor(int v);
    int getNextNeighbor(int v, int w);
    bool insertVertex(const T& vertex);
    bool insertEdge(int v1, int v2, E cost);
    bool removeVertex(int v);
    bool removeEdge(int v1, int v2);
    int NumOfVertices(){
        return numVertices;
    }
    int NumOfEdges(){
        return numEdges;
    }
};



template <class T, class E>
int Graphmtx<T,E>::getFirstNeighbor(int v) {
    if (v != -1){
        for (int i = 0; i < numVertices; ++i) {
            if (Edge[v][i] > 0 && Edge[v][i] < maxWeight)
                return i;
        }
    }
    return -1;
}

template <class T, class E>
int Graphmtx<T,E>::getNextNeighbor(int v, int w) {
    if (v != -1 && w != -1){
        for (int i = w+1; i < numVertices; ++i)
            if (Edge[v][i] > 0 && Edge[v][i] < maxWeight)
                return i;
    }
    return -1;
}

template <class T, class E>
bool Graphmtx<T,E>::insertVertex(const T &vertex) {
    if (numVertices == maxVertices)
        return false;
    VerticesList[numVertices++] = vertex;
    return true;
}

template <class T, class E>
bool Graphmtx<T,E>::removeVertex(int v) {
    if (v < 0 || v > numVertices)
        return false;
    if (numVertices == 1)
        return false;
    VerticesList[v] = VerticesList[numVertices - 1];
    for (int i = 0; i < numVertices; ++i) {
        if (Edge[i][v] > 0 && Edge[i][v] < maxWeight) numEdges--;
    }
    for (int j = 0; j < numVertices; ++j) {
        Edge[j][v] = Edge[j][numVertices-1];
    }
    numVertices--;
    for (int k = 0; k < numVertices; ++k) {
        Edge[v][k] = Edge[numVertices][k];
    }
    return true;
}

template <class T, class E>
bool Graphmtx<T,E>::insertEdge(int v1, int v2, E cost) {
    if (v1 > -1 && v1 < numVertices && v2 > -1 && v2 < numVertices && Edge[v1][v2] == maxWeight){
        //说明不能在现有边上直接插入边，可先删除该边，再插入新值
        Edge[v1][v2] = Edge[v2][v1] = cost;
        numEdges++;
        return true;
    } else return false;
}

template <class T, class E>
bool Graphmtx<T,E>::removeEdge(int v1, int v2) {
    if (v1 > -1 && v1 < numVertices && v2 > -1 && v2 < numVertices && Edge[v1][v2] > 0 && Edge[v1][v2] < maxWeight){
        Edge[v1][v2] = Edge[v2][v1] = maxWeight;
        numEdges--;
        return true;
    } else return false;

}


#endif //GRAPH_GRAPHMTX_H
