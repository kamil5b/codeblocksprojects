#include "relasi.h"
#include "penjualan.h"
#include "barang.h"

bool isEmptyListRelasi(ListRelasi L){
    return (first(L)==NULL);
}
void createListRelasi(ListRelasi &L){
    first(L)=NULL;
}
void createRelasi(addressR &R,addressB &barang,addressT &toko){
    R=new Relasi;
    barang(R)=barang;
    toko(R)=toko;
    next(R)=NULL;
}
void insertRelasiFirst(ListRelasi &L,addressR &P){
    next(P)=first(L);
    first(L)=P;
    linked(barang(P))++;
    linked(toko(P))++;
}
void deleteRelasiFirst(ListRelasi &L,addressR &P){
    if(next(first(L))==NULL){
        first(L)=NULL;
    }else{
        first(L)=next(P);
        next(P)=NULL;
    }
    linked(barang(P))--;
    linked(toko(P))--;
}
void deleteRelasiAfter(ListRelasi &L,addressR Prec,addressR &P){
    next(Prec)=next(P);
    next(P)=NULL;
    linked(barang(P))++;
    linked(toko(P))++;
}
addressR searchRelasi(ListRelasi &L,infotype b,infotype t){
    addressR P;
    P=first(L);
    while(P!=NULL && info(barang(P))!=b  && info(toko(P))!=t){
        P=next(P);
    }
    if(P==NULL){
        return NULL;
    }
    else{
        return P;
    }
}

void printBarangToko(ListRelasi L,addressT toko){
    addressR R;
    cout << "Nama Toko : " << info(toko) << endl;
    R=first(L);
    cout << linked(toko)<<" Barang :" << endl;
    while(R!=NULL){
        if(toko(R)==toko){
            cout <<"-> "<< info(barang(R))<<endl;
        }
        R=next(R);
    }
}
void printBarangadadiToko(ListRelasi L,addressB barang){
    addressR R;
    cout << "Nama Barang : " << info(barang) << endl;
    R=first(L);
    cout << linked(barang)<<" toko :" << endl;
    while(R!=NULL){
        if(barang(R)==barang){
            cout <<"-> "<< info(toko(R))<<endl;
        }
        R=next(R);
    }
}
