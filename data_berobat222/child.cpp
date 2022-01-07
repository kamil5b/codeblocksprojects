#include "child.h"

//CREATE ELEMENT
address_pas createPasien(string nama){
    address_pas P;
    P=new Pasien;
    info(P)=nama;
    linked(P)=0;
    next(P)=NULL;
    return P;
}
//CREATE LIST
void createListPasien(listPasien &L){
    first(L)=NULL;
}
//INSERT LAST
void insertFirstPasien(address_pas &P,listPasien &L){
    address_pas Q=first(L);
    if(first(L)==NULL){
        first(L)=P;
        next(P)=P;
    }else{
        do{
            Q=next(Q);
        }while(next(Q)!=first(L));
        next(P)=first(L);
        next(Q)=P;
    }
}
//SEARCH
address_pas searchPasien(string nama,listPasien L){
    address_pas P;
    P=first(L);
    if(P==NULL){
        return NULL;
    }
    do{
        P=next(P);
    }while(P!=first(L)&&info(P)!=nama);
    if(info(P)!=nama){
        return NULL;
    }
    return P;
}
//DELETE
void deleteFirstPasien(address_pas &P,listPasien &L){
    first(L)=next(P);
    next(P)=NULL;
}
void deleteMiddleLastPasien(address_pas &P,listPasien &L){
    address_pas Q=first(L);
    do{
        Q=next(Q);
    }while(next(Q)!=P&&Q!=first(L));

    if(next(Q)==P){
        next(Q)=next(P);
        next(P)=NULL;
    }
}
//DELETE Pasien DI RELASI
//SHOW
void showPasien(address_pas P){
    if(P!=NULL){
        cout << "Nama Pasien\t : " << info(P) << endl;
        cout << "Jumlah penyakit pasien : " << linked(P) << endl;
    }
}
void showAllPasien(listPasien L){
    address_pas P;
    int i=1;
    P=first(L);
    if(P!=NULL){
        do{
            cout <<i<<endl;
            showPasien(P);
            cout <<endl;
            i++;
            P=next(P);
        }while(P!=first(L));
    }else{
        cout << "Tidak ada pasien" << endl;
    }
}
