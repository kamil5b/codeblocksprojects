#include "rizal.h"

void createNode(int x, adrNode &p){
    p=new node;
    p->firstEdge=NULL;
    p->next=NULL;
    p->info=x;
}
void createGraph(graph &g){
    g.firstNode=NULL;
}
void createQNode(adrQNode &p, adrNode n){
    p=new qNode;
    p->next=NULL;
    p->toNode=n;
}
void createQueue(Queue &Q){
    Q.head=NULL;
    Q.tail=NULL;
    Q.pointer=NULL;
}

void insertLast(graph &g, adrNode p){
    adrNode q=g.firstNode;
    if(q!=NULL){
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
    }else{
        g.firstNode=p;
    }
}
void addNode(graph &g, int x){
    adrNode p;
    createNode(x,p);
    insertLast(g,p);
}

adrNode findNode(graph g, int x){
    adrNode P=g.firstNode;
    while(P!=NULL){
        if(P->info==x){
            return P;
        }
        P=P->next;
    }
    return NULL;
}
adrNode findNodeBFS(adrNode n, Queue &Q, int x){
    createQueue(Q);
    adrNode m;
    adrEdge e;
    if(Q.head==NULL){
        enqueue(Q,n);
        Q.pointer=Q.head;
    }
    while(Q.pointer!=NULL){
        m=Q.pointer->toNode;
        if(m->info==x){
            adrNode temp;
            while(Q.head!=NULL){
                dequeue(Q,temp);
            }
            return m;
        }
        e=m->firstEdge;
        while(e!=NULL){
            if(!isInQueue(Q,e->toNode)){
                enqueue(Q,e->toNode);
            }
            e=e->next;
        }
        Q.pointer=Q.pointer->next;
    }
    adrNode temp;
    while(Q.head!=NULL){
        dequeue(Q,temp);
    }
    return NULL;
}

bool connected(graph g, adrNode n, adrNode m){

    adrEdge e=NULL;
    if(n!=NULL){
        e=n->firstEdge;
    }

    while(e!=NULL){
        if(e->toNode==m){
            return true;
        }
        e=e->next;
    }

    return false;
}
void connect(graph &g, int x, int y){
    adrEdge e;
    adrNode a=findNode(g,x);
    adrNode b=findNode(g,y);
    if(!connected(g,a,b)){
        e=a->firstEdge;
        if(e!=NULL){
            while(e->next!=NULL){
                e=e->next;
            }
            e->next=new edge;
            e=e->next;
        }else{
            e=new edge;
            a->firstEdge=e;
        }
        e->next=NULL;
        e->toNode=b;


        e=b->firstEdge;
        if(e!=NULL){
            while(e->next!=NULL){
                e=e->next;
            }
            e->next=new edge;
            e=e->next;
        }else{
            e=new edge;
            b->firstEdge=e;
        }
        e->next=NULL;
        e->toNode=a;

    }
}

void enqueue(Queue &Q, adrNode n){
    adrQNode sq;
    createQNode(sq,n);
    if(Q.head==NULL){
        Q.head=sq;
        Q.tail=sq;
    }else{
        Q.tail->next=sq;
        Q.tail=sq;
    }
}
void dequeue(Queue &Q, adrNode &n){
    if(Q.head!=NULL){
        if(Q.head==Q.tail){
            createQueue(Q);
        }else{
            adrQNode sq=Q.head;
            Q.head=Q.head->next;
            sq->next=NULL;
            n=sq->toNode;
            delete(sq);
        }
    }
}

bool isInQueue(Queue Q, adrNode n){
    adrQNode sq=Q.head;
    while(sq!=NULL){
        if(sq->toNode==n){
            return true;
        }
        sq=sq->next;
    }
    return false;
}

void printBFS(graph g,Queue &Q){
    adrEdge e;
    adrNode m;
    if(Q.head==NULL){
        enqueue(Q,g.firstNode);
        Q.pointer=Q.head;
        cout << Q.pointer->toNode->info << " ";

    }
    while(Q.pointer!=NULL){
        m=Q.pointer->toNode;
        e=m->firstEdge;
        while(e!=NULL){
            if(!isInQueue(Q,e->toNode)){
                cout << e->toNode->info << " ";
                enqueue(Q,e->toNode);
            }
            e=e->next;
        }
        Q.pointer=Q.pointer->next;
    }
    adrNode temp;
    while(Q.head!=NULL){
        dequeue(Q,temp);
    }
}
