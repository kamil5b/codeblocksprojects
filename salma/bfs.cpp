#include "bfs.h"
void insertFromFile(string filename,Graph &g, VisitedList &L){
    int x,y;
    ifstream File(filename);
    while(File >> x >> y){
        addEdge(g,x,y,L);
    }
}
void createGraph(Graph &g){
    g=NULL;
}
void createList(VisitedList &L){
    L.first=NULL;
    L.last=NULL;
}

void addEdge(Graph &g, int x,int y, VisitedList &L){
    cout << "Adding " << x <<" and " <<y <<endl;
    addressVertex V = findNodeBFS(g,L,x);
    addressVertex W = findNodeBFS(g,L,y);
    if(V==NULL){
        cout << "creating " << x<<endl;
        V=new Vertex;
        V->next=NULL;
        V->info=x;
        V->firstEdge=NULL;
        if(g!=NULL){
            V->next=g;
        }
        g=V;
    }
    if(W==NULL){
        cout << "creating " <<y<<endl;
        W=new Vertex;
        W->next=NULL;
        W->info=y;
        W->firstEdge=NULL;
        if(g!=NULL){
            W->next=g;
        }
        g=W;
    }
    connectVertecies(g,V,W);
}

addressVertex findNodeBFS(addressVertex v, VisitedList &L, int x){
    addressVertex w;
    addressQueue Q;
    addressEdge e;
    createList(L);
    if(v!=NULL){
        if(L.first==NULL){
            insertLast(L,v);
            Q=L.first;
        }
        while(Q!=NULL){
            w=Q->vertex;
            if(w->info==x){
                createList(L);
                delete(Q);
                return w;
            }
            e=w->firstEdge;
            while(e!=NULL){
                if(!inList(L,e->vertex)){
                    insertLast(L,e->vertex);
                }
                e=e->next;
            }
            Q=Q->next;
        }
        while(L.first!=NULL){
            Q=L.first;
            L.first=L.first->next;
            Q->next=NULL;
            delete(Q);
        }
    }
    return NULL;
}
bool isConnected(Graph g, addressVertex v, addressVertex w){
    addressEdge e;
    addressVertex x=g;
    while(x!=NULL){
        if(x==v||x==w){
            e=x->firstEdge;
            while(e!=NULL){
                if(e->vertex==v||e->vertex==w){
                    return true;
                }
                e=e->next;
            }
        }
        x=x->next;
    }
    return false;
}
void connectVertecies(Graph &g, addressVertex v, addressVertex w){
    addressEdge E;
    if(!isConnected(g,v,w)){
        E= new Edge;
        E->vertex=w;
        E->next=v->firstEdge;
        v->firstEdge=E;
        E= new Edge;
        E->vertex=v;
        E->next=w->firstEdge;
        w->firstEdge=E;
    }
}

void insertLast(VisitedList &L, addressVertex v){
    addressQueue Q = new queueElm;
    Q->next=NULL;
    Q->vertex=v;
    if(L.first==NULL){
        L.first=Q;
        L.last=Q;
    }else{
        L.last->next=Q;
        L.last=Q;
    }
}
void deleteAllInList(VisitedList &L){
    addressQueue Q;
    if(L.first!=NULL){
        while(L.first!=NULL){
            cout << L.first->vertex->info <<" ";
            Q=L.first;
            L.first=Q->next;
            Q->next=NULL;
            delete(Q);
        }
        L.last=NULL;
    }
}

bool inList(VisitedList L, addressVertex v){
    addressQueue Q=L.first;
    while(Q!=NULL){
        if(Q->vertex==v){
            return true;
        }
        Q=Q->next;
    }
    return false;
}

void printAll(Graph g,VisitedList &L){
    addressVertex w;
    addressQueue Q;
    addressEdge e;
    if(L.first==NULL){
        insertLast(L,g);
        Q=L.first;
    }
    while(Q!=NULL){
        w=Q->vertex;
        e=w->firstEdge;
        while(e!=NULL){
            if(!inList(L,e->vertex)){
                insertLast(L,e->vertex);
            }
            e=e->next;
        }
        Q=Q->next;
    }
    deleteAllInList(L);
}
