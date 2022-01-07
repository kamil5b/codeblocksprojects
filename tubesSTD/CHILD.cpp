#include "CHILD.h"

/* RAFLY AHMAD YANUAR - 1301194119
   SURYA TIMUR RIZKILLAH ARYATI - 1301194441
*/

// CIRCULAR DOUBLE LINKED LIST

void createList_c(list_child &L){
    first(L) = NULL;
    last(L) = NULL;
};
adr_c alokasi_c(string nama, string tipe){
    adr_c C = new elm_child;
    info(C).nama = nama;
    info(C).tipe = tipe;
    next(C) = NULL;
    prev(C) = NULL;
    return C;
};
void insertFirst_c(list_child &L, adr_c C){
    if(first(L) == NULL){
        first(L) = C;
        last(L) = C;
        prev(first(L)) = last(L);
        next(last(L)) = first(L);
    } else {
        next(C) = first(L);
        prev(first(L)) = C;
        first(L) = C;
        prev(first(L)) = last(L);
        next(last(L)) = first(L);
    }
};
void insertLast_c(list_child &L, adr_c C){
    if(first(L) == NULL){
        insertFirst_c(L, C);
    } else {
        next(C) = first(L);
        prev(first(L)) = C;
        next(last(L)) = C;
        last(L) = C;
    }
};
void deleteFirst_c(list_child &L, adr_c &C){
    if(first(L) == NULL){
        cout<<"  DATA KOSONG!  "<<endl;
        C = NULL;
    } else if(next(first(L)) == NULL){
        C = first(L);
        first(L) = NULL;
        last(L) = NULL;
        prev(first(L)) = NULL;
        next(last(L)) = NULL;
    } else {
        C = first(L);
        first(L) = next(C);
        prev(first(L)) = last(L);
        next(last(L)) = first(L);
        next(C) = NULL;
        prev(C) = NULL;
    }
};
void deleteLast_c(list_child &L, adr_c &C){
    if(first(L) == NULL){
        cout<<"  DATA KOSONG!  "<<endl;
        C = NULL;
    } else if(next(first(L)) == NULL){
        C = first(L);
        first(L) = NULL;
        last(L) = NULL;
        prev(first(L)) = NULL;
        next(last(L)) = NULL;
    } else {
        C = last(L);
        last(L) = prev(C);
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
        next(C) = NULL;
        prev(C) = NULL;
    }
};
void deleteAfter_c(list_child &L, adr_c Prec, adr_c &C){
    if(Prec == NULL){
        cout<<"  PREC TIDAK DITEMUKAN!  "<<endl;
    } else if(Prec == last(L)){
        cout<<"  TIDAK ADA ELEMEN SETELAH PREC  "<<endl;
    } else if(next(Prec) == last(L)){
        deleteLast_c(L, C);
    } else {
        C = next(Prec);
        next(Prec) = next(C);
        prev(next(C)) = Prec;
        next(C) = NULL;
        prev(C) = NULL;
    }
};
adr_c searchElmn_c(list_child L, string nama){
    if(first(L) != NULL){
        adr_c C = first(L);
        while(info(C).nama != nama && next(C) != first(L)){
            C = next(C);
        }

        if(info(C).nama == nama){
            return C;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
};
void printInfo_c(list_child L){
    int i = 2;

    cout<<endl<<"  Nama Jalan (Child): "<<endl;
    if(first(L) == NULL){
        cout<<endl<<"  DATA KOSONG!  "<<endl;
    } else {
        adr_c C = next(first(L));
        cout<<"    1. Jalan "<< info(first(L)).nama <<" - "<< info(first(L)).tipe <<endl;
        while(C != first(L)){
            cout<<"    "<< i <<". Jalan "<< info(C).nama <<" - "<< info(C).tipe <<endl;
            i++;
            C = next(C);
        }
    }
    cout<<endl;
};

void hapusData_c(list_child L, string nama){
    adr_c C, Q;
    C = searchElmn_c(L, nama);

    if(C == first(L)){
        deleteFirst_c(L, C);
    } else if(C == last(L)){
        deleteLast_c(L, C);
    } else {
        C = first(L);
        while(info(C).nama != nama && C != NULL){
            Q = C;
            C = next(C);
        }
        deleteAfter_c(L, Q, C);
    }
};
