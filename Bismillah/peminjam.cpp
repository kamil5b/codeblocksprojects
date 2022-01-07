#include "peminjam.h"

void createListPeminjam(ListPeminjam &L){
    First(L)=NULL;
    Last(L)=NULL;
}
addressP createNewElmtPeminjam(string nama){
    addressP P;
    P=new elmPeminjam;
    linked(P)=0;
    info(P)=nama;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}
void insertPeminjamFirst(ListPeminjam &L, addressP P){
    if(First(L)!= NULL){
        next(P) = First(L);
        prev(First(L)) = P;
        First(L) = P;
        next(Last(L))=P;
        prev(P)=Last(L);
    }
    else{
        First(L) = P;
        Last(L) = P;
        next(P)=P;
        prev(P)=P;
    }
}
void insertPeminjamAfter(ListPeminjam &L, addressP Prec, addressP P){
    next(P) = next(Prec);
    prev(next(Prec)) = P;
    prev(P) = Prec;
    next(Prec) = P;
}
void insertPeminjamLast(ListPeminjam &L, addressP P){
    if(Last(L) != NULL){
       prev(P) = Last(L);
       next(Last(L))= P;
       Last(L) = P;
       next(P) = First(L);
       prev(First(L))=P;
    }
    else{
        Last(L) = P;
        First(L) = P;
        next(P)=P;
        prev(P)=P;
    }
}
void deletePeminjamFirst(ListPeminjam &L, addressP &P){
    if(First(L) != NULL){
        if (next(First(L)) != First(L)){
            P = First(L);
            First(L) = next(P);
            prev(First(L))=prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }else{
            P = First(L);
            First(L) = NULL;
            Last(L) = NULL;
        }
    }else{
        cout<< "ListPeminjam Kosong"<<endl;
    }
}
void deletePeminjamAfter(ListPeminjam &L, addressP Prec, addressP &P){
    if(Prec!=NULL){
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deletePeminjamLast(ListPeminjam &L, addressP P){
    if(P!=NULL&&next(Last(L))!=Last(L)){
        P = Last(L);
        Last(L) = prev(P);
        next(Last(L))=next(P);
        prev(First(L))=Last(L);
        prev(P) = NULL;
        next(P) = NULL;
    }else{
        P = Last(L);
        First(L) = NULL;
        Last(L) = NULL;
    }
}
addressP SearchPeminjam(ListPeminjam L, string nama){
    addressP cari = First(L);
    do{
        cari = next(cari);
    }while((cari!=First(L)) && info(cari) != nama );
    if(info(cari) == nama){
        return cari;
    }
    return NULL;
}
void showPeminjam(ListPeminjam L){
    if (First(L) != NULL){
        addressP P = First(L);
        do{
            cout <<"Nama : "<<info(P)<<endl;
            P = next(P);
        }while (P != First(L));
    }else{
        cout<<"ListBuku Kosong "<<endl;
    }
}
