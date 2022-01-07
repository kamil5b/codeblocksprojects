#include "GRAPH.h"

void createNode(char x, address_node &p){
    p=new node;
    p->firstEdge=NULL;
    p->next=NULL;
    p->info=x;
}
void createGraph(graph &g){
    g.firstNode=NULL;
}
void createQElm(address_queue &p, address_node n){
    p=new queueElm;
    p->next=NULL;
    p->toNode=n;
}

void createQueue(Queue &Q){
    Q.head=NULL;
    Q.tail=NULL;
}

void insertLast(graph &g, address_node p){
    address_node q=g.firstNode;
    if(q!=NULL){
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
    }else{
        g.firstNode=p;
    }
}
void addNode(graph &g, char x){
    address_node p;
    createNode(x,p);
    insertLast(g,p);
}
address_node findNode(graph g, char x){
    address_node P=g.firstNode;
    while(P!=NULL){
        if(P->info==x){
            return P;
        }
        P=P->next;
    }
    return NULL;
}
address_node findNodeDFS(address_node n, Queue &Q, char x){
    address_node m;
    address_edge e=n->firstEdge;
    if(Q.head==NULL){
        enqueue(Q,n);
    }
    if(n->info==x){
        while(Q.head!=NULL){
           dequeue(Q,m);
        }
        return n;
    }

    while(e!=NULL){
        if(!isInQueue(Q,e->toNode)){
            enqueue(Q,e->toNode);
            m = findNodeDFS(e->toNode, Q, x);
            if(m!=NULL){
                return m;
            }
        }
        e=e->next;
    }
    return NULL;
}
bool connected(graph g, address_node n, address_node m){

    address_edge e=NULL;
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
void connect(graph &g, char x, char y){
    address_edge e;
    address_node a=findNode(g,x);
    address_node b=findNode(g,y);
    if(!connected(g,a,b)&&a!=NULL&&b!=NULL){
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
void enqueue(Queue &Q, address_node n){
    address_queue sq;
    createQElm(sq,n);
    if(Q.head==NULL){
        Q.head=sq;
        Q.tail=sq;
    }else{
        Q.tail->next=sq;
        Q.tail=sq;
    }
}
void dequeue(Queue &Q, address_node &n){
    if(Q.head!=NULL){
        if(Q.head==Q.tail){
            createQueue(Q);
        }else{
            address_queue sq=Q.head;
            Q.head=Q.head->next;
            sq->next=NULL;
            n=sq->toNode;
            delete(sq);
        }
    }
}
bool isInQueue(Queue Q, address_node n){
    address_queue sq=Q.head;
    while(sq!=NULL){
        if(sq->toNode==n){
            return true;
        }
        sq=sq->next;
    }
    return false;
}
void printDFSRecrusive(address_node n, Queue &Q){
    address_edge e=n->firstEdge;
    if(Q.head==NULL){
        cout << n->info;
        enqueue(Q,n);
    }
    while(e!=NULL){
        if(!isInQueue(Q,e->toNode)){
            cout << ", " <<e->toNode->info;
            enqueue(Q,e->toNode);
            printDFSRecrusive(e->toNode, Q);
        }
        e=e->next;
    }
}

void inputFile(graph &g){
    ifstream thisfile("input.txt");
    address_node P,Q;
    char x,y;

    while(thisfile >> x >> y){
        cout << x << " connect " << y <<endl;
        P=findNode(g,x);
        if(P==NULL){
            addNode(g,x);
        }
        Q=findNode(g,y);
        if(Q==NULL){
            addNode(g,y);
        }
        if(!connected(g,P,Q)){
            connect(g,x,y);
        }
    }

    thisfile.close();
}
