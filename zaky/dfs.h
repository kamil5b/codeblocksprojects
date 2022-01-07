#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct vertex *adr_vertex;
typedef struct edge *adr_edge;
typedef struct visitElm *adr_visit;
typedef adr_vertex graph;

struct vertex {
    string info;
    adr_vertex next;
    adr_edge firstEdge;
};

struct edge {
    adr_vertex toVertex;
    int bobot;
    adr_edge next;
    adr_edge prev;
};

struct visitElm{
    int bobot;
    adr_vertex toVertex;
    adr_visit next;
};

struct visited{
    adr_visit first;
    adr_visit last;
};

adr_vertex createVertex(string x);
void createGraph(graph &g);
adr_visit createVisitElm(adr_vertex n,int bobot);
void createVisited(visited &V);

void addVertex(graph &g, string x);

adr_vertex searchVertex(graph g, string x);
void addEdge(adr_vertex x, adr_vertex y,int bobot);

void masuk(visited &V, adr_vertex n,int bobot);
void lepasSemua(visited &V);

bool Visited(visited V, adr_vertex n);

void DFS(adr_vertex n, visited &V);
void printAll(visited &V, graph g);



#endif // DFS_H_INCLUDED
