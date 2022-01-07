#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <fstream>
#include <iostream>
using namespace std;

typedef struct node *address_node;
typedef struct edge *address_edge;
typedef struct queueElm *address_queue;

struct node {
    char info;
    address_node next;
    address_edge firstEdge;
};

struct edge {
    address_node toNode;
    address_edge next;
};

struct graph {
    address_node firstNode;
};

struct queueElm{
    address_node toNode;
    address_queue next;
};

struct Queue{
    address_queue head;
    address_queue tail;
};

void createNode(char x, address_node &p);
void createGraph(graph &g);
void createQElm(address_queue &p, address_node n);
void createQueue(Queue &Q);

void insertLast(graph &g, address_node p);
void addNode(graph &g, char x);

address_node findNode(graph g, char x);
address_node findNodeDFS(address_node n, Queue &Q, char x);
bool connected(graph g, address_node n, address_node m);
void connect(graph &g, char x, char y);

void enqueue(Queue &Q, address_node n);
void dequeue(Queue &Q, address_node &n);

bool isInQueue(Queue Q, address_node n);

void printDFSRecrusive(address_node n, Queue &Q);

void inputFile(graph &g);


#endif // GRAPH_H_INCLUDED
