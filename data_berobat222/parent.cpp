#include "parent.h"

//CREATE ELEMENT
address_pen createPenyakit(string nama){
    address_pen P;
    P=new Penyakit;
    info(P)=nama;
    linked(P)=0;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}
//CREATE LIST
void createListPenyakit(listPenyakit &L){
    first(L)=NULL;
    last(L)=NULL;
}
//INSERT LAST
void insertLastPenyakit(address_pen &P,listPenyakit &L){
    if(last(L)==NULL||first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }else{
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}
//SEARCH
address_pen searchPenyakit(string nama,listPenyakit L){
    address_pen P;
    P=first(L);
    while(P!=NULL&&info(P)!=nama){
        P=next(P);
    }
    return P;
}
//DELETE
void deleteFirstPenyakit(address_pen &P,listPenyakit &L){
    first(L)=next(P);
    next(P)=NULL;
    prev(first(L))=NULL;
}
void deleteLastPenyakit(address_pen &P,listPenyakit &L){
    last(L)=prev(P);
    prev(P)=NULL;
    next(last(L))=NULL;
}
void deleteMiddlePenyakit(address_pen &P,listPenyakit &L){
    prev(next(P))=prev(P);
    next(prev(P))=next(P);
    next(P)=NULL;
    prev(P)=NULL;
}
//DELETE PENYAKIT DI RELASI
//SHOW
void showPenyakit(address_pen P){
    if(P!=NULL){
        cout << "Nama penyakit\t : " << info(P) << endl;
        cout << "Jumlah pasien yang terjangkit : " << linked(P) << endl;
    }
}
void showAllPenyakit(listPenyakit L){
    address_pen P;
    int i=1;
    P=first(L);
    while(P!=NULL){
        cout <<i<<endl;
        showPenyakit(P);
        cout <<endl;
        i++;
        P=next(P);
    }
}

void top5Penyakit(listPenyakit &L){
    int maxLinked;
    address_pen P,Q,R,temp,Max;
    if(first(L)!=NULL){
        //SELECTION SORT
        P=first(L);
        while(P!=NULL){
            Q=P;
            Max=P;
            maxLinked=linked(Q);
            while(Q!=NULL){
                if(linked(Q)>maxLinked){
                    maxLinked=linked(Q);
                    Max=Q;
                }
                Q=next(Q);
            }
            temp=next(P);
            if(Max!=P){
                if(Max!=first(L)){
                    Q=P;
                    while(Q!=NULL&&next(Q)!=Max){
                            Q=next(Q);
                    }
                    if(Max!=last(L)){
                        deleteMiddlePenyakit(Max,L);
                    }else{
                        deleteLastPenyakit(Max,L);
                    }
                    if(P==first(L)){
                        deleteFirstPenyakit(P,L);
                        //INSERT FIRST MAX
                        next(Max)=first(L);
                        prev(first(L))=Max;
                        first(L)=Max;
                        //INSERT AFTER Q
                    }else{
                        R=prev(P);
                        deleteMiddlePenyakit(P,L);
                        //INSERT AFTER MAX
                        next(Max)=next(R);
                        prev(Max)=R;
                        next(R)=Max;
                        prev(next(Max))=Max;
                    }
                    //INSERT AFTER P
                    if(Q!=last(L)){
                        next(P)=next(Q);
                        prev(P)=Q;
                        next(Q)=P;
                        prev(next(P))=P;
                    }else{
                        insertLastPenyakit(Q,L);
                    }
                }

            }

            P=temp;
        }
         R=first(L);
        for(int j=1;j<=5;j++){
            if(R!=NULL){
                cout << j << endl;
                showPenyakit(R);
                R=next(R);
            }
        }
    }



}
