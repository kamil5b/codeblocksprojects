#include"penulis.h"
#include <iostream>
//Inisialisasi
void createList_Penulis(listPenulis &L){
    first(L) = NULL;
    last(L) = NULL;
}
void createList_Novel(listNovel &L){
    first(L) = NULL;
    last(L) = NULL;
}
addressPenulis createPenulis(int id,string name,string tempat){
    addressPenulis P = new Penulis;
    info(P).name = name;
    info(P).id = id;
    info(P).tempat = tempat;
    info(P).sumNovel = 0;
    createList_Novel(info(P).nameNovel);
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
addressNovel createNovel(int id,string name,string tahun,string terbit){
    addressNovel P = new Novel;
    info(P).name = name;
    info(P).id = id;
    info(P).tahun = tahun;
    info(P).terbit = terbit;
    info(P).sumPenulis = 0;
    createList_Penulis(info(P).namePenulis);
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

//MAIN
void addPenulis(listPenulis &L,addressPenulis P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;

    }else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void addNovel(listNovel &L,addressNovel P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

addressPenulis searchPenulis(listPenulis L,string name){
    addressPenulis P = first(L);
    while(P != NULL && info(P).name != name)
        P = next(P);
    return P;
}
addressNovel searchNovel(listNovel L,string name){
    addressNovel P = first(L);
    while(P != NULL && info(P).name != name)
        P = next(P);
    return P;
}

void HubunganPenulisNovel(listPenulis &L1,listNovel &L2,string namePenulis,string nameNovel){
    addressPenulis P = searchPenulis(L1,namePenulis);
    addressNovel   Q = searchNovel(L2,nameNovel);
    if(P != NULL && Q != NULL){
        if(searchNovel(info(P).nameNovel,nameNovel) == NULL){
            addressNovel R = createNovel(info(Q).id,info(Q).name,info(Q).tahun,info(Q).terbit);
            addressPenulis S = createPenulis(info(P).id,info(P).name,info(P).tempat);
            addNovel(info(P).nameNovel,R);
            addPenulis(info(Q).namePenulis,S);
            info(P).sumNovel++;
            info(Q).sumPenulis++;
        }else{
            cout<<endl;
            cout<<endl;
            cout<<"|| RELASI BERHASIL ||"<<endl;
            cout<<endl;
            cout<<endl;
        }
    }else{
        if(P == NULL){
            cout<<endl;
            cout<<endl;
            cout<<"|| PENULIS BELUM TERDAFTAR ||"<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(Q == NULL){
            cout<<endl;
            cout<<endl;
            cout<<"|| NOVEL BELUM TERDAFTAR ||"<<endl;
            cout<<endl;
            cout<<endl;
        }
    }
}

void deleteHubungan(listPenulis &L1, listNovel &L2, string namePenulis,string nameNovel){

    addressPenulis P = searchPenulis(L1,namePenulis);
    addressNovel   Q = searchNovel(L2,nameNovel);
    if(P != NULL && Q != NULL){
        addressNovel R = searchNovel(info(P).nameNovel,nameNovel);
        addressPenulis S = searchPenulis(info(Q).namePenulis,namePenulis);
        if(R != NULL && S!=NULL){
            deleteNovelADD(info(P).nameNovel,R);
            deletePenulisADD(info(Q).namePenulis,S);
            info(P).sumNovel--;
            info(Q).sumPenulis--;
        }else{
            cout<<endl;
            cout<<endl;
            cout<<"|| RELASI BERHASIL DIHAPUS ||"<<endl;
            cout<<endl;
            cout<<endl;
        }
    }else{
        if(P == NULL){
            cout<<endl;
            cout<<endl;
            cout<<"|| PENULIS BELUM TERDAFTAR ||"<<endl;
            cout<<endl;
            cout<<endl;
        }
        if(Q == NULL){
            cout<<endl;
            cout<<endl;
            cout<<"|| NOVEL BELUM TERDAFTAR ||"<<endl;
            cout<<endl;
            cout<<endl;
        }
    }

}

void deleteNovelADD(listNovel &L,addressNovel &P){
        if(first(L) == last(L)){
            createList_Novel(L);
        }else if(P == first(L)){
            first(L) = next(P);
            prev(first(L)) = NULL;
        }else if(P == last(L)){
            last(L) = prev(P);
            next(last(L)) = NULL;
        }else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
        }
        next(P) = NULL;
        prev(P) = NULL;

}
void deleteNovel(listNovel &L1, listPenulis &L2,string nameNovel){
    addressNovel P = searchNovel(L1,nameNovel);
    if(P!=NULL){
        addressPenulis N = first(info(P).namePenulis);
        if(N!=NULL){
            deleteHubungan(L2,L1,info(N).name,nameNovel);
            N=next(N);
        }
        deleteNovelADD(L1,P);
        delete P;
    }
}

//InADT
void deletePenulisADD(listPenulis &L,addressPenulis &P){
    if(P != NULL){
        if(first(L) == last(L)){
            createList_Penulis(L);
        }else if(P == first(L)){
            first(L) = next(P);
            prev(first(L)) = NULL;
        }else if(P == last(L)){
            last(L) = prev(P);
            next(last(L)) = NULL;
        }else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
        }
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deletePenulis(listNovel &L1, listPenulis &L2,string namePenulis){
    addressPenulis P = searchPenulis(L2,namePenulis);
    if(P!=NULL){
        addressNovel N = first(info(P).nameNovel);
        if(N!=NULL){
            deleteHubungan(L2,L1,namePenulis,info(N).name);
            N=next(N);
        }
        deletePenulisADD(L2,P);
        delete P;
    }
}

//Print
void printNovel(addressNovel P){
    cout<<"ID NOVEL       : "<<info(P).id<<endl;
    cout<<"JUDUL          : "<<info(P).name<<endl;
    cout<<"TAHUN          : "<<info(P).tahun<<endl;
    cout<<"PENERBIT       : "<<info(P).terbit<<endl;
    cout<<"Jumlah Penulis : "<<info(P).sumPenulis<<endl;

    }
void printPenulis(addressPenulis P){
    cout<<"ID PENULIS         : "<<info(P).id<<endl;
    cout<<"NAMA PENULIS       : "<<info(P).name<<endl;
    cout<<"DOMISILI           : "<<info(P).tempat<<endl;
    cout<<"Jumlah Novel       : "<<info(P).sumNovel<<endl;
    addressNovel Q = first(info(P).nameNovel);
    cout<<"Daftar Judul Novel : ";
    int i = 1;
    if (Q ==NULL) {
         cout<<" Kosong "<<endl;
    }else{
        while(Q != NULL){
            cout<<i<<".  "<<info(Q).name;
            Q = next(Q);
            if(Q != NULL)
                cout<<endl<<"\t\t";
            i++;
        }
    }
}
void printNovelALL(listNovel L){
    addressNovel P = first(L);
    if (P != NULL){
        while(P != NULL){
            printNovel(P);
            cout<<endl;
            P = next(P);
        }
    }else {
        cout<<endl;
        cout<<"Data Novel Masih Kosong"<<endl;
        cout<<endl;
    }
}
void printPenulisALL(listPenulis L){
    addressPenulis P = first(L);
    if (P != NULL){
        while(P != NULL){
            printPenulis(P);
            cout<<endl;
            P = next(P);
        }
    }else {
        cout<<endl;
        cout<<"Data Penulis Masih Kosong"<<endl;
        cout<<endl;
    }
}
void printNovelKaryaPenulis(listPenulis L, string namaPenulis){
    addressPenulis P = searchPenulis(L,namaPenulis);
    if(P!=NULL){
        printPenulis(P);
    }else{
        cout<<endl;
        cout<<endl;
        cout<<"|| PENULIS BELUM TERDAFTAR ||"<<endl;
        cout<<endl;
        cout<<endl;
    }
}
void printNovelDuaPenulis(listNovel L){
    addressNovel N = first(L);
    if(N!=NULL){
        N = first(L);
        while(N!=NULL){
            if(info(N).sumPenulis==2){
                printNovel(N);
            }
            N=next(N);
        }

    }
}
void printPenulisAktif(listPenulis L){
    addressPenulis P = first(L);
    int maxSum;
    if(P!=NULL){
        maxSum = info(P).sumNovel;
        while(P!=NULL){
            if(info(P).sumNovel >= maxSum){
                maxSum = info(P).sumNovel;
            }
            P=next(P);
        }

        P = first(L);
        while(P!=NULL){
            if(info(P).sumNovel==maxSum){
                printPenulis(P);
            }
            P=next(P);
        }

    }
}
void printPenulisSendiri(listPenulis L1, listNovel L2){
    addressPenulis P=L1.first;
    bool kuper=true;
    addressNovel N,M;
    if(P!=NULL){
        while(P!=NULL){
            N=first(info(P).nameNovel);
            while(N!=NULL){
                M = searchNovel(L2,info(N).name);
                if(M!=NULL){
                    //
                    if(info(M).sumPenulis>1){
                            //
                        kuper=false;
                    }
                }
                N=next(N);
            }
            if(kuper){
                printPenulis(P);
            }
            P=next(P);
        }
    }
}
