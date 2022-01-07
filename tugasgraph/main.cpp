#include "graph.h"
int main()
{
    graph g;
    createGraph(g);
    Queue Q;
    createQueue(Q);

    inputFile(g);
    printDFSRecrusive(g.firstNode,Q);

    return 0;
}
