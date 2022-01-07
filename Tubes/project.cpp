#include "project.h"
using namespace std;

void createListProject (list_project &L){
    L.first=NULL;
}

address_project createElmProject (infotype_project data){
    address_project P;
    P=new elmlist_project;
    info(P)=data;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void insertLastProject (list_project &L, address_project &P){
    address_project Prec;
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

void viewProject (list_project L){
    address_project P=L.first;
    if(P!=NULL){
        do{
            cout << "Nama project : " << info(P) << endl;
            P=next(P);
        }while(P!=L.first);
    }else{
        cout << "List kosong" <<endl;
    }
}

void deleteProject (list_project &L, address_project &P){
    if(P!=NULL&&L.first!=NULL){
        if(P==L.first&&next(P)==P){
            next(P)=NULL;
            prev(P)=NULL;
            createListProject(L);
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

void ubahProject (list_project L, infotype_project cari){
    address_project P,Q;
    string ubah;

    P=searchProject(L,cari);
    if(P!=NULL){
        cout << "Nama project : " << info(P) << endl;
        cout << "Nama baru : ";
        cin >> ubah;
        Q=searchProject(L,ubah);
        if(Q!=NULL){
            info(P)=ubah;
            cout << "Nama berhasil diganti" << endl;
        }else{
            cout << "Nama sudah pernah ada sebelumnya" << endl;
        }
    }
}

address_project searchProject (list_project L, infotype_project cari){
    address_project P;
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
