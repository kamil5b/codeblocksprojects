#ifndef DIRECTEDBFS_H_INCLUDED
#define DIRECTEDBFS_H_INCLUDED

#include <fstream>
#include <iostream>
using namespace std;

typedef struct Node *anode;
typedef struct Connector *acon;
typedef struct Elm *adr;

typedef anode graph;

struct Node {
    char info;
    anode next;
    acon cons;
};

struct Connector {
    anode toNode;
    acon next;
};

struct Elm{
    anode node;
    adr next;
};

struct List{
    adr first;
};

void createGraph(graph &g);
void createList(List &L);

void addNode(graph &g, char x);

anode searchNode(graph g, char x);
bool menunjuk(anode n, anode m);
void sambung(graph &g, char x, char y);

void InserLast(List &L, anode n);
void DeleteFirst(List &L, anode &n);

bool isInList(List L, anode n);

void printNodes(graph g,List &L);


#endif // DIRECTEDBFS_H_INCLUDED
