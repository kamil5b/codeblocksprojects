#include "relasi.h"
#include "peminjam.h"

void createListRelasi(ListRelasi &L){
    First(L)=NULL;
}
addressR createNewElmtRelasi(addressB &B,addressP &P){
    addressR R;
    R=new elmRelasi;
    buku(R)=B;
    linked(P)++;
    linked(B)++;
    peminjam(R)=P;
    next(R)=NULL;
    return R;
}
void insertRelasiFirst(ListRelasi &L, addressR P){
    if(First(L)!= NULL){
        next(P) = First(L);
        First(L) = P;
    }
    else{
        First(L) = P;
    }
}
void insertRelasiAfter(ListRelasi &L, addressR Prec, addressR P){
    if(Prec!=NULL){
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void insertRelasiLast(ListRelasi &L, addressR P){
    if(First(L) != NULL){
        addressR Q=L.First;
        while(Q!=NULL&&next(Q)!=P){
            Q=next(Q);
        }
        if(Q!=NULL){
            insertRelasiAfter(L,Q,P);
        }
    }
    else{
        First(L) = P;
    }
}
void deleteRelasiFirst(ListRelasi &L, addressR &P){
    if(First(L) != NULL){
        if (next(First(L)) != NULL){
            P = First(L);
            First(L) = next(P);
            next(P) = NULL;
        }else{
            P = First(L);
            First(L) = NULL;
        }
        linked(peminjam(P))--;
        linked(buku(P))--;
    }else{
        cout<< "ListRelasi Kosong"<<endl;
    }
}
void deleteRelasiAfter(ListRelasi &L, addressR Prec, addressR &P){
    if(Prec != NULL){
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;

        linked(peminjam(P))--;
        linked(buku(P))--;
    }
}

void showPeminjamBuku(ListRelasi L, addressP P){
    if(P!=NULL){
        addressR R=First(L);
        cout << "Nama peminjam : " << info(P) << endl;
        cout << "Buku yang dipinjam :" << endl;
        while(R!=NULL){
            if(peminjam(R)==P){
                cout <<"Judul : "<<info(buku(R)).Judul<<endl;
                cout <<"Penerbit : " <<info(buku(R)).Penerbit <<endl;
                cout <<" Penulis : " <<info(buku(R)).Penulis<<endl;
                cout <<" Tahun : "<<info(buku(R)).Tahun<<endl;
                cout <<" ID : "<<info(buku(R)).ID<<endl;
            }
            R=next(R);
        }
    }
}
void showBukuDipinjam(ListRelasi L, addressB P){
    if(P!=NULL){
        addressR R=First(L);
        cout <<"Judul : "<<info(P).Judul<<endl;
        cout <<"Penerbit : " <<info(P).Penerbit <<endl;
        cout <<" Penulis : " <<info(P).Penulis<<endl;
        cout <<" Tahun : "<<info(P).Tahun<<endl;
        cout <<" ID : "<<info(P).ID<<endl;
        cout <<"Peminjam :" << endl;
        int i=1;
        while(R!=NULL){
            if(buku(R)==P){
                cout << i << ". " << info(peminjam(R)) << endl;
                i++;
            }
            R=next(R);
        }
    }
}
