#include "directedBFS.h"

void createGraph(graph &g){
    g=NULL;
}
void createList(List &L){
    L.first=NULL;
}

void addNode(graph &g, char x){
    anode n=searchNode(g,x);
    if(n==NULL){
        n= new Node;
        n->cons=NULL;
        n->info=x;
        n->next=NULL;
        if(g==NULL){
            g=n;
        }else{
            anode m=g;
            while(m->next!=NULL){
                m=m->next;
            }
            m->next=n;
        }
    }
}

anode searchNode(graph g, char x){
    anode m=g;
    while(m!=NULL&&m->info!=x){
        m=m->next;
    }
    return m;
}
bool menunjuk(anode n, anode m){
    acon c=n->cons;
    while(c!=NULL){
        if(c->toNode==m){
            return true;
        }
        c=c->next;
    }
    return false;
}
void sambung(graph &g, char x, char y){
    anode a,b;
    a=searchNode(g,x);
    b=searchNode(g,y);
    if(a!=NULL&&b!=NULL&&!menunjuk(a,b)){
        acon c = new Connector;
        c->toNode=b;
        c->next=a->cons;
        a->cons=c;
    }
}

void InserLast(List &L, anode n){
    adr o = new Elm;
    o->next=NULL;
    o->node=n;
    adr m = L.first;
    if(m!=NULL){
        while(m->next!=NULL){
            m=m->next;
        }
        m->next=o;
    }else{
        L.first=o;
    }
}
void DeleteFirst(List &L, anode &n){
    adr m=L.first;
    if(n!=NULL){
        L.first=L.first->next;
        m->next=NULL;
        n=m->node;
    }
}

bool isInList(List L, anode n){
    adr m = L.first;
    while(m!=NULL){
        if(m->node==n){
            return true;
        }
        m=m->next;
    }
    return false;
}

void printNodes(graph g,List &L){
    acon c;
    adr a;
    anode m=g;
    createList(L);
    InserLast(L,m);
    a=L.first;
    while(a!=NULL){
        m=a->node;
        c=m->cons;
        while(c!=NULL){
            if(!isInList(L,c->toNode)){
                InserLast(L,c->toNode);
            }
            c=c->next;
        }
        a=a->next;
    }
    while(L.first!=NULL){
        DeleteFirst(L,m);
        cout << m->info <<" ";
    }
    cout<<endl;
}
