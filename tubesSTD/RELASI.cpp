#include "RELASI.h"

/* RAFLY AHMAD YANUAR - 1301194119
   SURYA TIMUR RIZKILLAH ARYATI - 1301194441
*/

// DOUBLE LINKED LIST
void createList_r(list_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
};
adr_r alokasi_r(adr_p P, adr_c C){
    adr_r R = new elm_relasi;
    parent(R) = P;
    child(R) = C;
    next(R) = NULL;

    return R;
};
void insertFirst_r(list_relasi &L, adr_r R){
    if(first(L) == NULL){
        first(L) = R;
        last(L) = R;
    } else {
        next(R) = first(L);
        prev(first(L)) = R;
        first(L) = R;
    }
};

void insertLast_r(list_relasi &L, adr_r R){
    if(first(L) == NULL){
        first(L) = R;
        last(L) = R;
    } else {
        next(last(L)) = R;
        prev(R) = last(L);
        last(L) = R;
    }
};
void deleteFirst_r(list_relasi &L, adr_r &R){
    if(first(L) == NULL){
        cout<<"  TIDAK ADA RELASI!  "<<endl;
        R = NULL;
    } else if(next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
        R = NULL;
    } else {
        R = first(L);
        first(L) = next(R);
        prev(next(R)) = first(L);
        next(R) = NULL;
    }
};
void deleteLast_r(list_relasi &L, adr_r &R){
    if(first(L) == NULL){
        cout<<"  TIDAK ADA RELASI!  "<<endl;
        R = NULL;
    } else if(next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
        R = NULL;
    } else {
        R = prev(last(L));
        next(R) = NULL;
        prev(R) = NULL;
        last(L) = R;
    }
};
void deleteAfter_r(list_relasi &L, adr_r Prec, adr_r &R){
    if(Prec == NULL){
        cout<<"  PREC TIDAK DITEMUKAN!  "<<endl;
        R = NULL;
    } else if(Prec == last(L)){
        cout<<"  TIDAK ADA ELEMEN SETELAH PREC  "<<endl;
        R = NULL;
    } else if(next(Prec) == last(L)){
        deleteLast_r(L, R);
    } else {
        R = next(Prec);
        next(Prec) = next(R);
        prev(next(R)) = Prec;
        next(R) = NULL;
        prev(R) = NULL;
    }
};
adr_r searchElmn_r(list_relasi L, adr_p P, adr_c C){
    if(first(L) != NULL){
        adr_r R = first(L);
        while(info(parent(R)) != info(P) && info(child(R)).nama != info(C).nama && R != NULL){
            R = next(R);
        }

        if(info(parent(R)) == info(P) && info(child(R)).nama == info(C).nama){
            return R;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
};
void printInfo_r(list_relasi L){
    int i = 1;
    adr_r R = first(L);

    cout<<endl<<"  Data Jalan Perkotaan : "<<endl;
    while(R != NULL){
        cout<<"    "<< i <<". Kota  : "<< info(parent(R)) <<endl<<
              "       Jalan : "<< info(child(R)).nama <<" - "<< info(child(R)).tipe <<endl;
        i++;
        R = next(R);
    }

    if(first(L) == NULL){
        cout<<endl<<"  DATA KOSONG!  "<<endl;
    }

    cout<<endl;
};

void cariRelasiJalan(list_relasi L, string jalan){
    int i = 1;
    adr_r R = first(L);

    if(first(L) != NULL){
        cout<<endl<<"  Data Jalan Perkotaan : "<<endl;
        while(R != NULL){
            if(info(child(R)).nama == jalan){
                cout<<"    "<< i <<". Kota  : "<< info(parent(R)) <<endl<<
                "       Jalan : "<< info(child(R)).nama <<" - "<< info(child(R)).tipe <<endl;
            }
            i++;
            R = next(R);
        }
    } else {
        cout<<endl<<"  DATA TIDAK DITEMUKAN!  "<<endl;
    }
    cout<<endl;
};
void cariRelasiKota(list_relasi L, string kota){
    int i = 1;
    adr_r R = first(L);

    if(first(L) != NULL){
        cout<<endl<<"  Data Jalan Di Kota "<<kota<<endl;
        while(R != NULL){
            if(info(parent(R)) == kota) {
                cout<<"    "<< i <<". Jalan : "<< info(child(R)).nama <<" - "<< info(child(R)).tipe <<endl;
            }
            i++;
            R = next(R);
        }
    } else {
        cout<<endl<<"  DATA TIDAK DITEMUKAN!  "<<endl;
    }
    cout<<endl;
};
void cariTipe(list_relasi L, string tipe){
    int i = 1;
    adr_r R = first(L);

    if(first(L) != NULL){
        cout<<endl<<"  Data (Jalan) "<<tipe<<endl;
        while(R != NULL){
            if(info(child(R)).tipe == tipe) {
                cout<<"    "<< i <<". Kota  : "<< info(parent(R)) <<
                endl<<"       Jalan : "<< info(child(R)).nama <<endl;
            }
            i++;
            R = next(R);
        }
    } else {
        cout<<endl<<"  DATA TIDAK DITEMUKAN!  "<<endl;
    }
    cout<<endl;
};
