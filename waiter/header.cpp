#include "header.h"

void createLists(ListGuest &LT, ListWaiter &LW){
    LT.first=NULL;
    LT.last=NULL;
    LW.first=NULL;
    LW.last=NULL;
}

address_tamu createGuest(string nama){
    address_tamu T = new Guest;
    T->nama=nama;
    T->waiter=0;
    T->next=NULL;
    return T;
}
address_waiter createWaiter(string nama){
    address_waiter W = new Waiter;
    W->nama=nama;
    W->next=NULL;
    W->prev=NULL;
    W->tamu=0;
    W->firstRelation=NULL;
    return W;
}
address_rel createRelation(address_tamu T){
    address_rel R = new Relation;
    R->keGuest=T;
    R->next=NULL;
    return R;
}

//A
void tamuMasuk(ListGuest &L, string nama){
    address_tamu T = findGuest(L,nama);
    if(T!=NULL){
        cout << "Guest sudah masuk sebelumnya" <<endl;
    }else{
        T = createGuest(nama);
        if(L.first==NULL){
            L.first=T;
            L.last=T;
            T->next=T;
        }else{
            L.last->next=T;
            T->next=L.first;
            L.last=T;
        }
    }
}
//B
void recruitWaiter(ListWaiter &L, string nama){
    address_waiter W = findWaiter(L,nama);
    if(W!=NULL){
        cout << "Waiter telah terdaftar sebelumnya" <<endl;
    }else{
        W = createWaiter(nama);
        if(L.first==NULL){
            L.first=W;
            L.last=W;
        }else{
            L.last->next=W;
            W->prev=L.last;
            L.last=W;
        }
    }
}
//C
void waiterMelayaniGuest(address_waiter &W, address_tamu T){
    if(T->waiter<3){
    address_rel R = W->firstRelation;
        while(R!=NULL){
            if(R->keGuest==T){
                cout << "Waiter sudah melayani tamu tersebut" << endl;
                return;
            }
            R=R->next;
        }

        R=createRelation(T);
        R->next=W->firstRelation;
        W->firstRelation=R;
        W->tamu=W->tamu+1;
        R->keGuest->waiter=R->keGuest->waiter+1;
    }else{
        cout << "Maksimal 3 pelayan 1 tamu" <<endl;
    }
}

address_tamu findGuest(ListGuest L, string nama){
    address_tamu T = L.first;
    if(T!=NULL){
        do{
            if(T->nama==nama){
                return T;
            }
            T=T->next;
        }while(T!=L.first);
    }
    return NULL;
}
address_waiter findWaiter(ListWaiter L, string name){
    address_waiter W = L.first;
    while(W!=NULL){
        if(W->nama==name){
            return W;
        }
        W=W->next;
    }
    return NULL;
}

//D
void deleteWaiter(ListWaiter &LW, string nama){
    address_waiter W = findWaiter(LW,nama);

    if(W!=NULL){
        address_rel R = W->firstRelation;
        while(R!=NULL){
            W->firstRelation=R->next;
            R->keGuest->waiter=R->keGuest->waiter-1;
            R->keGuest=NULL;
            R->next=NULL;
            delete(R);
            R=W->firstRelation;
        }
        W->prev->next=W->next;
        W->next->prev=W->prev;
        W->next=NULL;
        W->prev=NULL;
        delete(W);
    }
}
//E
void deleteGuest(ListWaiter &LW, ListGuest &LT, string nama){
    address_waiter W = LW.first;
    address_tamu T = findGuest(LT,nama);
    if(T!=NULL){
        address_rel R;
        while(W!=NULL){
            R=W->firstRelation;
            while(R!=NULL){
                if(R->keGuest==T){
                    W->tamu=W->tamu-1;
                    if(W->firstRelation==R){
                        W->firstRelation=R->next;
                        R->next=NULL;
                        R->keGuest=NULL;
                        delete(R);
                        R=W->firstRelation;
                    }else{
                        address_rel temp=W->firstRelation;
                        while(temp->next!=R){
                            temp=temp->next;
                        }
                        temp->next=R->next;
                        R->next=NULL;
                        R->keGuest=NULL;
                        delete(R);
                        R=temp->next;
                    }
                }
                R=R->next;
            }
            W=W->next;
        }

        address_tamu temp=LT.first;
        while(temp->next!=T){
            temp=temp->next;
        }
        if(T==LT.last){
            LT.last=temp;
        }else if(T==LT.first){
            LT.first=T->next;
        }
        temp->next=T->next;
        T->next=NULL;
        delete(T);
    }
}

void printAll(ListWaiter LW, ListGuest LT){
    address_tamu T=LT.first;
    cout << "List Guest :" <<endl;
    if(T!=NULL){
        do{
            cout << T->nama << endl;
            T=T->next;
        }while(T!=LT.first);
        cout << endl;
    }
    address_waiter W=LW.first;
    cout << "List Waiter :" <<endl;
    while(W!=NULL){
        cout << W->nama <<endl;
        W=W->next;
    }

}
//F
void waiterGabut(ListWaiter LW){
    address_waiter W=LW.first;
    address_rel R;
    int tamu=W->tamu;
    while(W!=NULL){
        if(W->tamu<=tamu){
            tamu=W->tamu;
        }
        W=W->next;
    }
    W=LW.first;
    while(W!=NULL){
        if(W->tamu==tamu){
            cout <<endl;
            cout << W->nama << " Dengan " << W->tamu << " tamu" <<endl;
            R=W->firstRelation;
            while(R!=NULL){
                cout << R->keGuest->nama <<endl;
                R=R->next;
            }
        }
        W=W->next;
    }
}
//G
void printGuestWaiter(ListWaiter LW,string name){
    address_waiter W= findWaiter(LW,name);
    if(W!=NULL){
        address_rel R=W->firstRelation;
        while(R!=NULL){
            cout << R->keGuest->nama <<endl;
            R=R->next;
        }
    }else{
        cout << "Tidak ada Waiter dengan nama itu" <<endl;
    }
}
//H
void waiterAktif(ListWaiter LW){
    address_waiter W=LW.first;
    address_rel R;
    int tamu=W->tamu;
    while(W!=NULL){
        if(W->tamu>=tamu){
            tamu=W->tamu;
        }
        W=W->next;
    }
    W=LW.first;
    while(W!=NULL){
        if(W->tamu==tamu){
            cout <<endl;
            cout << W->nama << " Dengan " << W->tamu << " tamu" <<endl;
            R=W->firstRelation;
            while(R!=NULL){
                cout << R->keGuest->nama <<endl;
                R=R->next;
            }
        }
        W=W->next;
    }
}
//I
void tamuSpesial(ListGuest LT, ListWaiter LW){
    address_tamu T=LT.first;
    address_waiter W;
    address_rel R;
    int waiter=T->waiter;
    do{
        if(T->waiter>=waiter){
            waiter=T->waiter;
        }
        T=T->next;
    }while(T!=LT.first);
    do{
        if(T->waiter==waiter){
            cout<<endl;
            cout << T->nama << " dengan " << T->waiter << " waiter" <<endl;
            W=LW.first;
            while(W!=NULL){
                R=W->firstRelation;
                while(R!=NULL){
                    if(R->keGuest==T){
                        cout<<W->nama<<endl;
                    }
                    R=R->next;
                }
                W=W->next;
            }
        }
        T=T->next;
    }while(T!=LT.first);
}
