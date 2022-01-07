#include "PARENT.h"

/* RAFLY AHMAD YANUAR - 1301194119
   SURYA TIMUR RIZKILLAH ARYATI - 1301194441
*/

// SINGLE LINKED LIST
void createList_p(list_parent &L){
    first(L) = NULL;
    last(L) = NULL;
};
adr_p alokasi_p(infotype x){
    adr_p P = new elm_parent;
    info(P) = x;
    next(P) = NULL;

    return P;
};
void insertFirst_p(list_parent &L, adr_p P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = first(L);
    } else {
        next(P) = first(L);
        first(L) = P;
    }
};
void insertLast_p(list_parent &L, adr_p P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = first(L);
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
};
void deleteFirst_p(list_parent &L, adr_p &P){
    if(first(L) == NULL){
        cout<<"  DATA KOSONG!  "<<endl;
        P = NULL;
    } else if(next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
        P = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
};
void deleteLast_p(list_parent &L, adr_p &P){
    adr_p Q;
    if(first(L) == NULL){
        cout<<"  DATA KOSONG!  "<<endl;
        P = NULL;
    } else if(next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
        P = NULL;
    } else {
        P = first(L);
        while(next(P) != NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
        last(L) = Q;
    }
};
void deleteAfter_p(list_parent &L, adr_p Prec, adr_p &P){
    if(Prec == NULL){
        cout<<"  PREC TIDAK DITEMUKAN!  "<<endl;
        P = NULL;
    } else if(Prec == last(L)){
        cout<<"  TIDAK ADA ELEMEN SETELAH PREC  "<<endl;
        P = NULL;
    } else if(next(Prec) == last(L)){
        deleteLast_p(L, P);
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
};
adr_p searchElmn_p(list_parent L, infotype x){
    if(first(L) != NULL){
        adr_p P = first(L);
        while(P != NULL && info(P) != x){
            P = next(P);
        }
        return P;
    } else {
        return NULL;
    }
};
void printInfo_p(list_parent L){
    int i = 1;
    adr_p P = first(L);

    cout<<endl<<"  Nama Kota (Parent): "<<endl;
    while(P != NULL){
        cout<<"    "<< i <<". Kota "<< info(P) <<endl;
        i++;
        P = next(P);
    }

    if(first(L) == NULL){
        cout<<endl<<"  DATA KOSONG!  "<<endl;
    }
    cout<<endl;
};

void hapusData_p(list_parent L, infotype x){
    adr_p P, Q;
    P = searchElmn_p(L, x);

    if(P == first(L)){
        deleteFirst_p(L, P);
    } else if(P == last(L)){
        deleteLast_p(L, P);
    } else {
        P = first(L);
        while(info(P) != x && P != NULL){
            Q = P;
            P = next(P);
        }
        deleteAfter_p(L, Q, P);
    }
};
