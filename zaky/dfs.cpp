#include "dfs.h"

void insertFromFile(string filename,Graph &g, VisitedList &L){

    ifstream File("input.txt");
    while(File >> x >> y){
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
}
adr_vertex createVertex(string x){
    adr_vertex X = new vertex;
    X->firstEdge=NULL;
    X->info=x;
    X->next=NULL;
    return X;
}
void createGraph(graph &g){
    g=NULL;
}
adr_visit createVisitElm(adr_vertex n,int bobot){
    adr_visit V=new visitElm;
    V->bobot=bobot;
    V->next=NULL;
    V->toVertex=n;
    return V;
}
void createVisited(visited &V){
    V.first=NULL;
    V.last=NULL;
}

void addVertex(graph &g, string x){
    if(g==NULL){
        g=createVertex(x);
    }else{
        adr_vertex v = createVertex(x);
        v->next=g;
        g=v;
    }
}

adr_vertex searchVertex(graph g, string x){
    adr_vertex v = g;
    while(v!=NULL){
        if(v->info==x){
            return v;
        }
        v=v->next;
    }
    return NULL;
}
void addEdge(adr_vertex x, adr_vertex y,int bobot){
    adr_edge e=new edge;
    e->toVertex=y;
    e->bobot=bobot;\
    if(x->firstEdge==NULL){
        x->firstEdge=e;
        e->next=NULL;
        e->prev=NULL;
    }else{
        adr_edge temp=x->firstEdge;
        while(temp->next!=NULL&&temp->bobot>e->bobot){
            temp=temp->next;
        }
        if(temp->bobot>e->bobot){
            e->next=temp;
            e->prev=temp->prev;
            temp->prev->next=e;
            temp->prev=e;
            if(temp==x->firstEdge){
                x->firstEdge=e;
            }
        }else{
            temp->next=e;
            e->prev=temp;
        }
    }
}

void masuk(visited &V, adr_vertex n, int bobot){
    adr_visit v = createVisitElm(n,bobot);
    if(V.first==NULL){
        V.first=v;
        V.last=v;
    }else{
        V.last->next=v;
        V.last=v;
    }
}
void lepasSemua(visited &V){
    int total=0;
    adr_visit vis;
    if(V.first!=NULL){
        while(V.first!=NULL){
            total=total+V.first->bobot;
            cout << V.first->toVertex->info <<" "<< V.first->bobot <<"\t| Total : " << total << endl;
            vis=V.first;
            V.first=vis->next;
            vis->next=NULL;
            delete(vis);
        }
    }
}

bool Visited(visited V, adr_vertex n){

    adr_visit vis=V.first;
    while(vis!=NULL){
        if(vis->toVertex==n){
            return true;
        }
        vis=vis->next;
    }
    return false;
}

void DFS(adr_vertex n, visited &V){
    adr_edge e=n->firstEdge;
    if(V.first==NULL){
        masuk(v,n,0);
    }
    while(e!=NULL){
        if(!Visited(V,e->toVertex)){
            masuk(V,e->toVertex,e->bobot);
            DFS(e->toVertex,V);
        }
        e=e->next;
    }
}
void printAll(visited &V, graph g){
    DFS(g,V);
    lepasSemua(V);
}
