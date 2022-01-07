#include <iostream>
using namespace std;

typedef struct node *adrNode;
typedef struct edge *adrEdge;
typedef struct sqNode *adrSQNode;

struct Graph {
    adrNode kotaAwal;
    int jumlah;
};

struct node {
    string nama;
    adrNode next;
    adrEdge firstEdge;
};

struct edge {
    adrNode toNode;
    int cost;
    adrEdge next;
};

struct sqNode{
    adrNode toNode;
    adrSQNode next;
};

struct Queue{
    adrSQNode head;
    adrSQNode pointer;
    adrSQNode tail;
    int jumlah;
};

void createSQNode(adrSQNode &p, adrNode n){
    p=new sqNode;
    p->next=NULL;
    p->toNode=n;
}


void createQueue(Queue &Q){
    Q.head=NULL;
    Q.tail=NULL;
    Q.pointer=NULL;
    Q.jumlah=0;
}

void enqueue(Queue &Q, adrNode n){
    adrSQNode sq;
    //cout << "Enqueue Initiated"<<endl;
    createSQNode(sq,n);
    if(Q.head==NULL){
        Q.head=sq;
        Q.tail=sq;
    }else{
        Q.tail->next=sq;
        Q.tail=sq;
    }
    Q.jumlah++;
}
void push(Queue &Q, adrNode n){
    adrSQNode sq;
    //cout << "Enqueue Initiated"<<endl;
    createSQNode(sq,n);
    if(Q.head==NULL){
        Q.head=sq;
        Q.tail=sq;
    }else{
        sq->next=Q.head;
        Q.head=sq;
    }
    Q.jumlah++;
}
void pop(Queue &Q, adrNode &n){
    if(Q.head!=NULL){
        if(Q.head==Q.tail){
            n=Q.tail->toNode;
            createQueue(Q);
        }else{
            adrSQNode sq=Q.head;
            while(sq->next!=Q.tail){
                sq=sq->next;
            }
            n=Q.tail->toNode;
            Q.tail=sq;
            sq->next=NULL;
        }
    }
    Q.jumlah--;
}

void dequeue(Queue &Q, adrNode &n){
    if(Q.head!=NULL){
        if(Q.head==Q.tail){
            n=Q.head->toNode;
            createQueue(Q);
        }else{
            adrSQNode sq=Q.head;
            Q.head=Q.head->next;
            sq->next=NULL;
            n=sq->toNode;
            delete(sq);
        }
    }
    Q.jumlah--;
}

bool isInQueue(Queue Q, adrNode n){
    adrSQNode sq=Q.head;
    while(sq!=NULL){
        if(sq->toNode==n){
            return true;
        }
        sq=sq->next;
    }
    return false;
}

adrNode createNode(string tempat){
    adrNode R = new node;
    R->nama = tempat;
    R->next=NULL;
    R->firstEdge = NULL;
    return R;
}

Graph createGraph(string kotaAwal){
    Graph T;
    T.kotaAwal = createNode(kotaAwal);
    T.jumlah=0;
    return T;
}

//insertLast
void insertNode(Graph &G, string tempat){
    adrNode n = G.kotaAwal;
    adrNode m = createNode(tempat);
    while(n->next!=NULL){
        n=n->next;
    }
    G.jumlah++;
    n->next=m;
}

void connectNode(Graph G, string awal, string tujuan,int cost){
    adrNode pointer=G.kotaAwal;
    while(pointer!=NULL){
        if(pointer->nama == awal){
            break;
        }
        pointer=pointer->next;
    }
    if(pointer == NULL){
        return;
    }
    adrNode p=G.kotaAwal;
    while(p!=NULL){
        if(p->nama == tujuan){
            break;
        }
        p=p->next;
    }
    if(p == NULL){
        return;
    }
    adrEdge e = new edge;
    e->cost = cost;
    e->toNode = p;
    e->next=pointer->firstEdge;
    pointer->firstEdge = e;

    adrEdge f = new edge;
    f->cost = cost;
    f->toNode = pointer;
    f->next=p->firstEdge;
    p->firstEdge = f;
}

void greedy(Graph G){
    adrNode P = G.kotaAwal;
    Queue Q;
    createQueue(Q);
    enqueue(Q,P);
    int totalCost=0;
    while(Q.jumlah != G.jumlah){
        adrEdge e = P->firstEdge;
        int minimal = e->cost;
        adrEdge edgetmp = P->firstEdge;
        while(edgetmp!=NULL){
            if(edgetmp->cost<=minimal && !isInQueue(Q,edgetmp->toNode)){
                minimal=edgetmp->cost;
                e = edgetmp;
            }
            edgetmp=edgetmp->next;
        }
        totalCost += e->cost;
        enqueue(Q,e->toNode);
        P = Q.tail->toNode;
    }
    Q.pointer=Q.head;
    while(Q.pointer!=NULL){
        cout << Q.pointer->toNode->nama << "-";
    }
}

Graph initGraph(){
    Graph G = createGraph("Cilacap");
    insertNode(G,"Kroya");
    insertNode(G,"Purwokerto");
    insertNode(G,"Kebumen");
    insertNode(G,"Slawi");
    insertNode(G,"Brebes");
    insertNode(G,"Tegal");
    insertNode(G,"Pemalang");
    insertNode(G,"Purbalingga");
    insertNode(G,"Banjarnegara");
    insertNode(G,"Purworejo");
    insertNode(G,"Magelang");
    insertNode(G,"Wonosobo");
    insertNode(G,"Temanggung");
    insertNode(G,"Pekalongan");
    insertNode(G,"Kendal");
    insertNode(G,"Boyolali");
    insertNode(G,"Salatiga");
    insertNode(G,"Semarang");
    insertNode(G,"Demak");
    insertNode(G,"Solo");
    insertNode(G,"Purwodadi");
    insertNode(G,"Kudus");
    insertNode(G,"Rembang");
    insertNode(G,"Blora");
    insertNode(G,"Sragen");
    return G;
}

Graph initGraph2(){
    Graph G = initGraph();
    connectNode(G,"Cilacap","Kroya",1);
    connectNode(G,"Cilacap","Purwokerto",2);
    connectNode(G,"Kroya","Purwokerto",1);
    connectNode(G,"Kroya","Kebumen",3);
    connectNode(G,"Purwokerto","Kebumen",4);
    connectNode(G,"Purwokerto","Purbalingga",2);
    connectNode(G,"Purwokerto","Slawi",4);
    connectNode(G,"Slawi","Brebes",2);
    connectNode(G,"Slawi","Tegal",1);
    connectNode(G,"Brebes","Tegal",2);
    connectNode(G,"Kebumen","Purworejo",1);
    connectNode(G,"Purworejo","Magelang",1);
    connectNode(G,"Magelang","Wonosobo",1);
    connectNode(G,"Magelang","Temanggung",1);
    connectNode(G,"Magelang","Boyolali",1);
    connectNode(G,"Purbalingga","Banjarnegara",1);
    connectNode(G,"Banjarnegara","Wonosobo",1);
    connectNode(G,"Wonosobo","Temanggung",1);
    connectNode(G,"Temanggung","Salatiga",1);
    connectNode(G,"Purbalingga","Pemalang",1);
    connectNode(G,"Tegal","Pemalang",1);
    connectNode(G,"Pemalang","Pekalongan",1);
    connectNode(G,"Pekalongan","Kendal",1);
    connectNode(G,"Kendal","Temanggung",1);
    connectNode(G,"Kendal","Semarang",1);
    connectNode(G,"Semarang","Salatiga",1);
    connectNode(G,"Salatiga","Boyolali",1);
    connectNode(G,"Boyolali","Solo",1);
    connectNode(G,"Solo","Sragen",1);
    connectNode(G,"Sragen","Blora",1);
    connectNode(G,"Solo","Purwodadi",1);
    connectNode(G,"Semarang","Demak",1);
    connectNode(G,"Demak","Kudus",1);
    connectNode(G,"Demak","Purwodadi",1);
    connectNode(G,"Kudus","Purwodadi",1);
    connectNode(G,"Kudus","Rembang",1);
    connectNode(G,"Rembang","Blora",1);
    connectNode(G,"Purwodadi","Blora",1);
}

int main()
{
    Graph G = initGraph();
    return 0;
}

