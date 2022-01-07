#include "source.h"

int main()
{
    graph G;
    Queue Q;
    createQueue(Q);
    createGraph(G);
    addNode(G,'A');
    addNode(G,'B');
    addNode(G,'C');
    addNode(G,'D');
    addNode(G,'E');
     cout<<"nodes has been added"<<endl;
    connect(G,'A','B');
    connect(G,'A','C');
    connect(G,'B','D');
    connect(G,'E','C');
    connect(G,'E','B');
    cout<<"all has been connected"<<endl;
    createQueue(Q);
    printBFS(G,Q);
    cout<<endl;
    printDFSRecrusive(G.firstNode,Q);
    cout<<endl;
    adrNode n = findNodeBFS(G.firstNode,Q,'D');
    cout <<n->info<<" ";
    n = findNodeDFS(G.firstNode,Q,'C');
    cout <<n->info<<" ";
    return 0;
}
