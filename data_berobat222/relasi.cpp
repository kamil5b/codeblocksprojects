#include "relasi.h"

//CREATE ELEMENT
address_r createRelasi(address_pas pas,address_pen pen){
    address_r R = new Relasi;
    pasien(R)=pas;
    penyakit(R)=pen;
    next(R)=NULL;
    return R;
}
//CREATE LIST
void createListRelasi(listRelasi &L){
    first(L)=NULL;
}
//INSERT LAST
void insertFirstRelasi(address_r &P,listRelasi &L){
    if(first(L)==NULL){
        first(L)=P;
    }else{
        next(P)=first(L);
        first(L)=P;
    }
    linked(pasien(P))++;
    linked(penyakit(P))++;
}
//SEARCH
address_r searchRelasi(address_pas pas,address_pen pen,listRelasi L){
    address_r P;
    P=first(L);
    while(P!=NULL&&pasien(P)!=pas&&penyakit(P)!=pen){
        P=next(P);
    }
    return P;
}
//DELETE RELASI
void deleteFirstRelasi(address_r &P,listRelasi &L){
    first(L)=next(P);
    next(P)=NULL;
}
void deleteMiddleLastRelasi(address_r &P,listRelasi &L){
    address_r Q;
    while(Q!=NULL&&next(Q)!=P){
        Q=next(Q);
    }
    if(Q!=NULL){
        next(Q)=next(P);
        next(P)=NULL;
    }
}
//DELETE ELEMEN
void deleteRelasi(address_r &P,listRelasi &L){
    if(P!=NULL&&first(L)!=NULL){
        if(P==first(L)&&next(P)==NULL){
            createListRelasi(L);
        }else if(P==first(L)){
            deleteFirstRelasi(P,L);
        }else{
            deleteMiddleLastRelasi(P,L);
        }
        linked(pasien(P))--;
        linked(penyakit(P))--;
        delete P;
        P=NULL;
    }
}
void deletePenyakit(address_pen &P,listPenyakit &L,listRelasi &Lr){
    address_r R=first(Lr);
    address_r Rtemp;
    if(P!=NULL&&first(L)!=NULL){

        while(R!=NULL){
            if(penyakit(R)==P){
                Rtemp=next(R);
                deleteRelasi(R,Lr);
                R=Rtemp;
            }else{
                R=next(R);
            }
        }

        if(P==first(L)&&P==last(L)){
            createListPenyakit(L);
        }else if(P==first(L)){
            deleteFirstPenyakit(P,L);
        }else if(P==last(L)){
            deleteLastPenyakit(P,L);
        }else{
            deleteMiddlePenyakit(P,L);
        }
        delete P;
        P=NULL;
    }
}
void deletePasien(address_pas &P,listPasien &L,listRelasi &Lr){
    address_r R=first(Lr);
    address_r Rtemp;
    if(P!=NULL&&first(L)!=NULL){

        while(R!=NULL){
            if(pasien(R)==P){
                Rtemp=next(R);
                deleteRelasi(R,Lr);
                R=Rtemp;
            }else{
                R=next(R);
            }
        }

        if(P==first(L)&&next(P)==P){
            createListPasien(L);
        }else if(P==first(L)){
            deleteFirstPasien(P,L);
        }else{
            deleteMiddleLastPasien(P,L);
        }
        delete P;
        P=NULL;
    }
}
//SHOW
void showPenyakitDariPasien(address_pas P,listRelasi L){
    address_r R=first(L);
    int i=1;
    if(P!=NULL){
        showPasien(P);
        cout << "Penyakit pasien :" << endl;
        while(R!=NULL){
            if(pasien(R)==P){
                cout << i << endl;
                i++;
                showPenyakit(penyakit(R));
            }
            R=next(R);
        }
    }
}
void showPasienTerjangkit(address_pen P,listRelasi L){
    address_r R=first(L);
    int i=1;
    if(P!=NULL){
        showPenyakit(P);
        cout << "Pasien yang terjangkit :" << endl;
        while(R!=NULL){
            if(penyakit(R)==P){
                cout << i << endl;
                i++;
                showPasien(pasien(R));
            }
            R=next(R);
        }
    }
}
void showAllPasienBesertaPenyakitnya(listPasien Lp,listRelasi L){
    address_pas P=first(Lp);

    if(P!=NULL){
        do{
            showPenyakitDariPasien(P,L);
            P=next(P);
        }while(P!=first(L));
    }

}
