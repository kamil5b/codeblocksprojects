#include "directedBFS.h"

int main()
{
    graph g;
    createGraph(g);
    List L;
    char a,b;
    ifstream inputFile("input.txt");
    while(inputFile >> a >> b){
        addNode(g,a);
        addNode(g,b);
        sambung(g,a,b);
    }
    inputFile.close();
    printNodes(g,L);
    return 0;
}
