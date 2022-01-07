#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

typedef struct Vertex *addressVertex;
typedef struct Edge *addressEdge;
typedef struct queueElm *addressQueue;
typedef addressVertex Graph;

struct Vertex {
    int info;
    addressVertex next;
    addressEdge firstEdge;
};

struct Edge {
    addressVertex vertex;
    addressEdge next;
};

struct queueElm {
    addressVertex vertex;
    addressQueue next;
};

struct VisitedList{
    addressQueue first;
    addressQueue last;
};

void insertFromFile(string filename,Graph &g, VisitedList &L);
void createGraph(Graph &g);
void createList(VisitedList &L);

void addEdge(Graph &g, int x,int y, VisitedList &L);

addressVertex findNodeBFS(addressVertex v, VisitedList &L, int x);
bool isConnected(Graph g, addressVertex v, addressVertex w);
void connectVertecies(Graph &g, addressVertex v, addressVertex w);

void insertLast(VisitedList &L, addressVertex v);
void deleteAllInList(VisitedList &L);

bool inList(VisitedList L, addressVertex v);

void printAll(Graph g,VisitedList &L);

#endif // BFS_H_INCLUDED
