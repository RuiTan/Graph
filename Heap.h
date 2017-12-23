//
// Created by tanrui on 17-12-23.
//

#ifndef GRAPH_HEAP_H
#define GRAPH_HEAP_H

#include <iostream>
using namespace std;

#define DefaultSize 100

template <class E>
class MinHeap{
protected:
    E *heap;
    int currentSize;
    int maxHeapSize;
    void siftDown(int start, int m);
    void siftUp(int start);
    MinHeap(){};
public:
    explicit MinHeap(int size);
    MinHeap(E arr[], int n);
    ~MinHeap();
    bool Insert(const E& x);
    bool RemoveMin(const E& x);
    bool IsEmpty() const{
        return currentSize == 0;
    };
    bool IsFull() const{
        return currentSize == maxHeapSize;
    };
    void MakeEmpty(){
        currentSize = 0;
    }
};

template <class E>
MinHeap<E>::MinHeap(int size){
    maxHeapSize = size <= DefaultSize ? size : DefaultSize;
    currentSize = 0;
    heap = new E[maxHeapSize];
    if (!heap) {
        cerr << "内存不足！";
        exit(1);
    }
}

template <class E>
MinHeap<E>::MinHeap(E *arr, int n){
    maxHeapSize = n;
    heap = new E[maxHeapSize];
    if (!heap) {
        cerr << "内存不足！";
        exit(1);
    }
    currentSize = 0;
    for (int i = 0; i < maxHeapSize; ++i) {
        currentSize++;
        if (!Insert(arr[i])){
            cerr << "建立失败！";
            exit(2);
        }
    }
}

MinHeap::~MinHeap() {
    delete(heap);
    maxHeapSize = currentSize = 0;
}

void MinHeap::siftDown(int start, int m) {

}

void MinHeap::siftUp(int start) {

}

bool MinHeap::RemoveMin(const E &x) {
    return false;
}

bool MinHeap::Insert(const E &x) {
    return false;
}

#endif //GRAPH_HEAP_H
