#include "book.h"

using namespace std;

void createListBuku(ListBuku &L){
    First(L) = NULL;
    Last(L) = NULL;
};

void createNewElmt(Buku X, addressB &P){
    P=new elmBuku;
    linked(P)=0;
    next(P)=NULL;
    prev(P)=NULL;
    info(P)=X;
}

addressB createNewElmtBuku(string Judul, string Penerbit, string Penulis, int Tahun, int ID){
    addressB P;
    Buku B;
    B.Judul=Judul;
    B.Penerbit=Penerbit;
    B.Penulis=Penulis;
    B.Tahun=Tahun;
    B.ID=ID;
    createNewElmt(B,P);
    return P;
};

void insertBukuFirst(ListBuku &L, addressB P){
    if(First(L)!= NULL){
        next(P) = First(L);
        prev(First(L)) = P;
        First(L) = P;
    }
    else{
        First(L) = P;
        Last(L) = P;
    }
};

void insertBukuAfter(ListBuku &L, addressB Prec, addressB P){
    next(P) = next(Prec);
    prev(next(Prec)) = P;
    prev(P) = Prec;
    next(Prec) = P;
};

void insertBukuLast(ListBuku &L, addressB P){
    if(Last(L) != NULL){
       prev(P) = Last(L);
       next(Last(L))= P;
       Last(L) = P;
    }
    else{
        Last(L) = P;
        First(L) = P;
    }
};

void deleteBukuFirst(ListBuku &L, addressB &P){
    if(First(L) != NULL){
        if (next(First(L)) != NULL){
            P = First(L);
            First(L) = next(P);
            next(P) = NULL;
            prev(next(P)) = NULL;
        }else{
            P = First(L);
            First(L) = NULL;
            Last(L) = NULL;
        }
    }else{
        cout<< "ListBuku Kosong"<<endl;
    }
};

void deleteBukuAfter(ListBuku &L, addressB Prec, addressB &P){
    if(next(Prec) != NULL){
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
    else if(next(Prec) == Last(L)){
        P = Last(L);
        Last(L) = prev(P);
        next(Last(L)) = NULL;
        prev(P) = NULL;
    }
};

void deleteBukuLast(ListBuku &L, addressB P){
    P = Last(L);
    Last(L) = prev(P);
    next(Last(L)) = NULL;
    prev(P) = NULL;
};

addressB SearchBuku(ListBuku L, string judul){
    addressB cari = First(L);
    while((next(cari)!=NULL) && info(cari).Judul != judul ){
        cari = next(cari);
    }
    if(info(cari).Judul == judul){
        return cari;
    }
    return NULL;
};

void showBuku(ListBuku L){
    if (First(L) != NULL){
        addressB P = First(L);
        while (P != NULL){
            cout <<"Judul : "<<info(P).Judul<<endl;
            cout <<"Penerbit : " <<info(P).Penerbit <<endl;
            cout <<" Penulis : " <<info(P).Penulis<<endl;
            cout <<" Tahun : "<<info(P).Tahun<<endl;
            cout <<" ID : "<<info(P).ID<<endl;
            P = next(P);
        }
    }else{
        cout<<"ListBuku Kosong "<<endl;
    }
}


void SortTahunDesc(ListBuku &L, addressB P){
    addressB Q = First(L);
    if ((First(L) == NULL) || (info(P).Tahun > info(First(L)).Tahun)){
        insertBukuFirst(L,P);
    }
    else if (info(P).Tahun < info(Last(L)).Tahun){
        insertBukuLast(L,P);
    }
    else {
        while(Q != NULL){
            if(info(P).Tahun < info(Q).Tahun){
                addressB temp = P;
                P = Q;
                Q = temp;

            }
            Q = next(Q);
        }
        insertBukuAfter(L,Q,P);
    }
}
void favBuku(ListBuku L){
    addressB P=First(L);
    int Max,Min;
    Max=linked(P);
    Min=linked(P);

    while(P!=NULL){
        if(linked(P)>Max){
            Max=linked(P);
        }
        if(linked(P)<Min){
            Min=linked(P);
        }
        P=next(P);
    }
    P=First(L);
    cout << "Buku buku terfavorit dengan " << Max << "peminjam :" <<endl;
    while(P!=NULL){
        if(linked(P)==Max){
            cout << endl;
            cout <<"Judul : "<<info(P).Judul<<endl;
            cout <<"Penerbit : " <<info(P).Penerbit <<endl;
            cout <<" Penulis : " <<info(P).Penulis<<endl;
            cout <<" Tahun : "<<info(P).Tahun<<endl;
            cout <<" ID : "<<info(P).ID<<endl;
            cout << endl;
        }
        P=next(P);
    }
    P=First(L);
    cout << "Buku buku ter tidak-favorit dengan " << Min << "peminjam :" <<endl;
    while(P!=NULL){
        if(linked(P)==Min){
            cout << endl;
            cout <<"Judul : "<<info(P).Judul<<endl;
            cout <<"Penerbit : " <<info(P).Penerbit <<endl;
            cout <<" Penulis : " <<info(P).Penulis<<endl;
            cout <<" Tahun : "<<info(P).Tahun<<endl;
            cout <<" ID : "<<info(P).ID<<endl;
            cout << endl;
        }
        P=next(P);
    }
}
