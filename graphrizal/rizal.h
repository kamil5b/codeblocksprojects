#ifndef RIZAL_H_INCLUDED
#define RIZAL_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct node *adrNode;
typedef struct edge *adrEdge;
typedef struct qNode *adrQNode;

struct node {
    int info;
    adrNode next;
    adrEdge firstEdge;
};

struct edge {
    adrNode toNode;
    adrEdge next;
};

struct graph {
    adrNode firstNode;
};

struct qNode{
    adrNode toNode;
    adrQNode next;
};

struct Queue{
    adrQNode head;
    adrQNode pointer;
    adrQNode tail;
};

void createNode(int x, adrNode &p);
void createGraph(graph &g);
void createQNode(adrQNode &p, adrNode n);
void createQueue(Queue &Q);

void insertLast(graph &g, adrNode p);
void addNode(graph &g, int x);

adrNode findNode(graph g, int x);
adrNode findNodeBFS(adrNode n, Queue &Q, int x);
bool connected(graph g, adrNode n, adrNode m);
void connect(graph &g, int x, int y);

void enqueue(Queue &Q, adrNode n);
void dequeue(Queue &Q, adrNode &n);

bool isInQueue(Queue Q, adrNode n);

void printBFS(graph g,Queue &Q);




#endif // RIZAL_H_INCLUDED
