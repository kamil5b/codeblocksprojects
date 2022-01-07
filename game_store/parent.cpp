#include "parent.h"

void createListgames(listgames &L){
    first(L)=NULL;
    last(L) = NULL;
}

g_address creategames(infotypeG info){
    g_address P;
    P=new games;
    info(P)=info;
    users(info(P))=0;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void insertgames(g_address &P, listgames &L){
    g_address G;
    G=searchgames((info(P)).id,L);
    if(G==NULL){
        if(last(L)==NULL){
            last(L)=P;
        }
        if(first(L)!=NULL){
            next(P)=first(L);
            prev(first(L))=P;
        }
        first(L)=P;
    }else{
        cout << "Duplication ID Detected" << endl;
        cout << "Deallocate Game" << endl;
        delete P;
        P=NULL;
    }
}

void deletegames(g_address &P,listgames &L){
    g_address Q=first(L);

    if(P!=NULL){
        if(P==first(L)&&last(L)==NULL){
            first(L)=NULL;
            last(L)=NULL;
            cout << "List menjadi kosong!" << endl;
        }else if(P==first(L)){
            first(L)=next(P);
            next(P)=NULL;
            prev(first(L))=NULL;
        }else if(P==last(L)){
            last(L)=prev(P);
            prev(P)=NULL;
            next(last(L))=NULL;
        }else{
            while(Q!=NULL&&Q!=P){
                Q=next(Q);
            }
            if(Q!=NULL){
                Q=prev(Q);
                next(Q)=next(P);
                prev(next(P))=Q;
                prev(P)=NULL;
                next(P)=NULL;
            }
        }
        cout << "Game telah dihapus" << endl;
        delete P;
        P=NULL;
    }else{
        cout << "Game tidak ditemukan" << endl;
    }
}

g_address searchgames (string kode,listgames &L){
    g_address P=first(L);
    while(P!=NULL&&nama(info(P))!=kode&&id(info(P))!=kode){
        P=next(P);
    }
    return P;
}

void showGames(g_address P){
    cout << "Nama Games\t: " << nama(info(P)) <<endl;
    cout << "ID Games\t: " << id(info(P)) <<endl;
    cout << "Jumlah pemain\t: " << users(info(P)) <<endl;
    cout << "Harga Games\t: " << harga(info(P)) << endl;
}

void showAllGames(listgames L){
    int i=1;
    g_address P=first(L);

    while(P!=NULL){
        cout << i <<endl;
        showGames(P);
        i++;
        P=next(P);
    }

}
