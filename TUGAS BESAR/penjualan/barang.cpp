#include "barang.h"

bool isEmptyListBarang(ListBarang L){
    return (first(L)==NULL);
}
void createListBarang(ListBarang &L){
    jumlah(L)=0;
    first(L)=NULL;
}
void createBarang(addressB &DataBarang){
    DataBarang = new Barang;
    cout<<"== Input Data Barang =="<<endl;
    cout<<"Nama Barang: ";
    cin >> info(DataBarang);
    linked(DataBarang)=0;
    next(DataBarang)=NULL;
}

void insertBarangFirst(ListBarang &L, addressB &P){
    addressB Q;
    if(isEmptyListBarang(L)){
        first(L)=P;
        next(P)=P;
    }
    else {
        Q=first(L);
        while(next(Q)!=first(L)){
            Q=next(Q);
        }
        next(Q)=P;
        next(P)=first(L);
        first(L)=P;
    }
    jumlah(L)++;
}

void deleteBarangFirst(ListBarang &L, addressB &P){
    addressB Q;
    if(!isEmptyListBarang(L) && next(first(L))==first(L)){
        P=first(L);
        first(L)=NULL;
        jumlah(L)--;
    }
    else if (!isEmptyListBarang(L)){
        Q=first(L);
        while(next(Q)!=first(L)){
            Q=next(Q);
        }
        P=first(L);
        first(L)=next(P);
        next(Q)=first(L);
        next(P)=NULL;
        jumlah(L)--;
    }
    else {
        cout<<"ListBarang kosong"<<endl;
    }
}

void deleteBarangAfter(ListBarang &L, addressB Prec, addressB &P){
    addressB Q;
    if(!isEmptyListBarang(L)&&(next(Prec)==first(L))){
        Q=first(L);
        while(next(Q)!=Prec){
            Q=next(Q);
        }
        P=next(Prec);
        next(Prec)=next(P);
        next(P)=NULL;
        jumlah(L)--;
    }
    else {
        cout<<"Salah"<<endl;
    }
}

addressB searchBarang(ListBarang &L,infotype x){
    addressB P;
    P=first(L);
    do{
        P=next(P);
    }while(P!=first(L) && info(P)!=x);
    if(info(P)!=x){
        return NULL;
    }
    else{
        return P;
    }
}

void printInfoBarang(ListBarang L){
    addressB P;
    P=first(L);
    do{
        cout<<" ======================================== "<<endl;
        cout<< "Nama barang : " << info(P) <<endl;
        cout<< "Jumlah toko : " << linked(P) << endl;
        P=next(P);
    }while(P!=first(L));
}
