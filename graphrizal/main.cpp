#include "rizal.h"
#include <fstream>

int main()
{
    graph G;
    Queue Q;
    createGraph(G);
    createQueue(Q);
    adrNode n,m;

    int x,y;
    char strip;
    ifstream File("input.txt");
    while(File >> x >>strip>> y){
        n=findNode(G,x);
        m=findNode(G,y);
        if(n==NULL){
            addNode(G,x);
        }
        if(m==NULL){
            addNode(G,y);
        }
        connect(G,x,y);
    }

    File.close();
    printBFS(G,Q);
    return 0;
}
