#include "programmer.h"
using namespace std;

void createListProgram (list_programmer &L){
    L.first=NULL;
}

address_programmer createElmProgram (infotype_programmer data){
    address_programmer P;
    P=new elmlist_programmer;
    info(P)=data;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void insertLastProgram (address_programmer &P, list_programmer &L){
    address_programmer Prec;
    if(L.first==NULL){
        L.first=P;
        next(P)=P;
        prev(P)=P;
    }else{
        Prec=L.first;
        do{
            Prec=next(Prec);
        }while(next(Prec)!=L.first);
        next(P)=L.first;
        prev(P)=Prec;
        next(Prec)=P;
        prev(L.first)=P;
    }
}

void viewProgram (list_programmer L){
    address_programmer P=L.first;
    if(P!=NULL){
        do{
            cout << "Nama Programmer : " << info(P) << endl;
            P=next(P);
        }while(P!=L.first);
    }else{
        cout << "List kosong" <<endl;
    }
}

void deleteProgram (list_programmer &L, address_programmer &P){
    if(P!=NULL&&L.first!=NULL){
        if(P==L.first&&next(P)==P){
            next(P)=NULL;
            prev(P)=NULL;
            createListProgram(L);
        }else{
            if(P==L.first){
                L.first=next(P);
            }
            next(prev(P))=next(P);
            prev(next(P))=prev(P);
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
}

void ubahProgram (list_programmer L, infotype_programmer cari){
    address_programmer P,Q;
    string ubah;

    P=searchProgram(L,cari);
    if(P!=NULL){
        cout << "Nama Programmer : " << info(P) << endl;
        cout << "Nama baru : ";
        cin >> ubah;
        Q=searchProgram(L,ubah);
        if(Q!=NULL){
            info(P)=ubah;
        }else{
            cout << "Nama sudah pernah ada sebelumnya" << endl;
        }
    }
}

address_programmer searchProgram (list_programmer L, infotype_programmer cari){
    address_programmer P;
    P=L.first;
    if(P==NULL){
        return NULL;
    }
    do{
        P=next(P);
    }while(P!=L.first);
    if(info(P)!=cari){
        return NULL;
    }
    return P;
}
