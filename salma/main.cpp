#include "bfs.h"
int main()
{
    Graph g;
    VisitedList L;

    createGraph(g);
    createList(L);
    insertFromFile("input.txt",g,L);
    printAll(g,L);

    return 0;
}
