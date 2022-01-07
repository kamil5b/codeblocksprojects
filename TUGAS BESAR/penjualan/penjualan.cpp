#include "penjualan.h"

bool isEmptyListToko(ListToko L){
    return (first(L)==NULL) && (last(L)==NULL);
}
void createListToko(ListToko &L){
    jumlah(L)=0;
    first(L)=NULL;
    last(L) =NULL;
}
void createToko(addressT &DataToko){
    DataToko = new Toko;
    cout<<"== Input Data Toko =="<<endl;
    cout<<"Nama Toko: ";
    cin >> info(DataToko);
    linked(DataToko)=0;
    next(DataToko)=NULL;
    prev(DataToko)=NULL;
}

void insertTokoLast(ListToko &L, addressT &P){
    if(isEmptyListToko(L)){
        first(L)=P;
        last(L)=P;
    }
    else {
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
    }
    jumlah(L)++;
}

void deleteTokoFirst(ListToko &L, addressT &P){
    if(!isEmptyListToko(L) && (first(L)==last(L))){
        P=first(L);
        first(L)=NULL;
        last(L)=NULL;
        jumlah(L)--;
    }
    else if (!isEmptyListToko(L)){
        P=first(L);
        first(L)=next(P);
        next(P)=NULL;
        prev(first(L))=NULL;
        next(P)=NULL;
        jumlah(L)--;
    }
    else {
        cout<<"ListToko kosong"<<endl;
    }
}

void deleteTokoAfter(ListToko &L, addressT Prec, addressT &P){
    if(!isEmptyListToko(L)&&(next(Prec)==last(L))){
        P=last(L);
        last(L)=prev(P);
        next(last(L))=NULL;
        jumlah(L)--;
    }
    else if(!isEmptyListToko(L)){
        P=last(L);
        next(Prec)=next(P);
        prev(next(P))=Prec;
        prev(P)=NULL;
        next(P)=NULL;
        jumlah(L)--;
    }
    else {
        cout<<"Salah"<<endl;
    }
}

void deleteTokoLast(ListToko &L, addressT &P){
    if(!isEmptyListToko(L)&&first(L)!=last(L)){
        P=last(L);
        last(L)=prev(last(L));
        prev(P)=NULL;
        next(last(L))=NULL;
        jumlah(L)--;
    }
    else{
        deleteTokoFirst(L,P);
    }
}

addressT searchToko(ListToko &L,infotype x){
    addressT P;
    P=first(L);
    while(P!=NULL && info(P)!=x){
        P=next(P);
    }
    if(P==NULL){
        return NULL;
    }
    else{
        return P;
    }
}

void printInfoToko(ListToko L){
    addressT P;
    P=first(L);
    while(P!=NULL){
        cout<<" ======================================== "<<endl;
        cout<< "Nama toko : " << info(P) <<endl;
        cout<< "Jumlah barang : " << linked(P) << endl;
        P=next(P);
    }
}

void tokoPalingLengkap(ListToko L){
    addressT P;
    int MAX;
    P=first(L);
    MAX=linked(P);
    while(P!=NULL){
        if(linked(P)>MAX){
            MAX=linked(P);
        }
        P=next(P);
    }
    P=first(L);
    while(P!=NULL){
        if(linked(P)==MAX){
            cout<<" ======================================== "<<endl;
            cout<< "Nama toko : " << info(P) <<endl;
            cout<< "Jumlah barang : " << linked(P) << endl;
        }
        P=next(P);
    }
}
