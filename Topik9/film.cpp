#include "film.h"

void createList(ListBridge &LB,ListDirector &LD,ListFilm &LF){
    LB.first=NULL;
    LB.last=NULL;
    LD.first=NULL;
    LF.first=NULL;
    LF.last=NULL;
}

adrD createDirector(string nama){
    adrD P;
    P=new Director;
    P->film=0;
    P->nama=nama;
    P->next=NULL;
    return P;
}
adrF createFilm(string nama, string genre){
    adrF P;
    P=new Film;
    P->filmName=nama;
    P->genre=genre;
    P->next=P;
    return P;
}
adrB createBridge(adrD &sutradara, adrF film){
    adrB P;
    P=new Bridge;
    P->sutradara=sutradara;
    sutradara->film=sutradara->film+1;
    P->astrada=NULL;
    P->film=film;
    P->next=NULL;
    P->prev=NULL;
    return P;
}
adrB createBridge(adrD &sutradara, adrD &astrada, adrF film){
    adrB P;
    P=new Bridge;
    sutradara->film=sutradara->film+1;
    astrada->film=astrada->film+1;
    P->sutradara=sutradara;
    P->astrada=astrada;
    P->film=film;
    P->next=NULL;
    P->prev=NULL;
    return P;
}

void addDirector(ListDirector &LD, string name){
    adrD P=findDirector(LD,name);
    if(P==NULL){
        cout << "menambahkan sutradara" <<endl;
        P=createDirector(name);
        P->next=LD.first;
        LD.first=P;
    }
}
void addFilm(ListFilm &LF, string name, string genre){
    adrF P=findFilm(LF,name);
    if(P==NULL){
        cout << "adding film" <<endl;
        P=createFilm(name,genre);
        if(LF.first==NULL){
            LF.first=P;
            LF.last=P;
        }else{
            P->next=LF.first;
            LF.last->next=P;
            LF.last=P;
        }
    }
}
void connect(ListBridge &LB, adrD sutradara, adrF film){
    adrB P=createBridge(sutradara,film);
    if(LB.first==NULL){
        LB.first=P;
        LB.last=P;
    }else{
        LB.last->next=P;
        P->prev=LB.last;
        LB.last=P;
    }
}
void connect(ListBridge &LB, adrD sutradara,adrD astrada, adrF film){
    adrB P=createBridge(sutradara,astrada,film);
    if(LB.first==NULL){
        LB.first=P;
        LB.last=P;
    }else{
        LB.last->next=P;
        P->prev=LB.last;
        LB.last=P;
    }
}

adrD findDirector(ListDirector LD,string nama){
    adrD P=LD.first;
    while(P!=NULL&&P->nama!=nama){
        P=P->next;
    }
    if(P==NULL){
        cout<<"tidak ditemukan"<<endl;
    }
    return P;
}
adrF findFilm(ListFilm LF,string nama){
    adrF P=LF.first;
    if(P!=NULL){
        do{
            if(P->filmName==nama){
                return P;
            }
            P=P->next;
        }while(P!=LF.first);
    }
    cout<<"tidak ditemukan"<<endl;
    return NULL;
}

void deleteDirector(ListDirector &LD,ListBridge &LB,string nama){
    adrD D=findDirector(LD,nama);
    adrB B=LB.first;
    adrD Q=LD.first;
    while(B!=NULL){
        if(B->astrada->nama==nama){
            B->astrada=NULL;
        }
        if(B->sutradara->nama==nama){
            B->sutradara=NULL;
            if(B->astrada!=NULL){
                B->sutradara=B->astrada;
                B->astrada=NULL;
            }
        }
        if(B->astrada==NULL&&B->sutradara==NULL){
            adrB temp=B->next;
            disconnect(LB,B);
            B=temp;
        }
        B=B->next;
    }
    if(Q->nama==nama){
        LD.first=Q->next;
        Q->next=NULL;
        delete(Q);
    }else{
        if(D!=NULL){
            while(Q->next!=D){
                Q=Q->next;
            }
            Q->next=D->next;
            D->next=NULL;
            delete(D);
        }
    }
}
void deleteFilm(ListFilm &LF,ListBridge &LB,string name){
    adrF F=findFilm(LF,name);
    adrB B=LB.first;
    adrF E=LF.first;
    adrB temp;
    if(F!=NULL){
        while(B!=NULL){
            if(B->film->filmName==name){
                temp=B->next;
                disconnect(LB,B);
                B=temp;
            }else{
                B=B->next;
            }
        }
    //CHECK
        if(E->filmName==name){
            LF.last->next=LF.first->next;
            LF.first=E->next;
            E->next=NULL;
            delete(E);
        }else{
            do{
                E=E->next;
            }while(E!=LF.first && E->next!=F);
            if(E!=LF.first){
                E->next=F->next;
                if(LF.last==F){
                    LF.last=E;
                }
                F->next=NULL;
                delete(F);
            }
        }
    }
}
void disconnect(ListBridge &LB,adrB &connector){
    if(connector!=NULL){
        adrB B=LB.first;
        if(B==connector){
            LB.first=connector->next;
            if(LB.first!=NULL){
                LB.first->prev=NULL;
            }else{
                LB.last=NULL;
            }
        }else{
            while(B->next!=connector){
                B=B->next;
            }
            if(connector==LB.last){
                LB.last=LB.last->prev;
            }else{
                connector->next->prev=B;
            }
            B->next=connector->next;
        }
        connector->next=NULL;
        if(connector->astrada!=NULL){
            connector->astrada->film=connector->astrada->film-1;
            connector->astrada=NULL;
        }
        connector->film=NULL;
        if(connector->sutradara!=NULL){
            connector->sutradara->film=connector->sutradara->film-1;
            connector->sutradara=NULL;
        }
        delete(connector);
    }
}


void printAll(ListBridge LB,ListDirector LD,ListFilm LF){

    adrB B=LB.first;
    while(B!=NULL){
        cout << "======================" <<endl;
        cout<<B->film->filmName<<" | Genre :" << B->film->genre << endl;
        cout<<"Director :" << B->sutradara->nama;
        if(B->astrada!=NULL){
            cout << " | Director Assistant :" << B->astrada->nama <<endl;
        }else{
            cout<<endl;
        }
        B=B->next;
    }

}
void filmFromDirector(ListBridge LB,string sutradara){
    adrB B=LB.first;
    while(B!=NULL){
        if(B->sutradara->nama==sutradara||B->astrada->nama==sutradara){
            cout << "======================" <<endl;
            cout<<B->film->filmName<<" | Genre :" << B->film->genre << endl;
            cout<<"Director :" << B->sutradara->nama;
            if(B->astrada!=NULL){
                cout << " | Director Assistant :" << B->astrada->nama <<endl;
            }else{
                cout<<endl;
            }
        }
        B=B->next;
    }
}
void filmWithTwoDirector(ListBridge LB){
    adrB B=LB.first;
    while(B!=NULL){
        if(B->sutradara!=NULL&&B->astrada!=NULL){
            cout << "======================" <<endl;
            cout<<B->film->filmName<<" | Genre :" << B->film->genre << endl;
            cout<<"Director :" << B->sutradara->nama;
            if(B->astrada!=NULL){
                cout << " | Director Assistant :" << B->astrada->nama <<endl;
            }else{
                cout<<endl;
            }
        }
        B=B->next;
    }
}
void maxFilmFirector(ListDirector LD, ListBridge LB){
    adrD D=LD.first;
    adrD B=D;
    while(D!=NULL){
        if(D->film>=B->film){
            B=D;
        }
        D=D->next;
    }
    adrB bd=LB.first;
    while(bd!=NULL){
        if(bd->sutradara==B||bd->astrada==B){
            cout << "======================" <<endl;
            cout<<bd->film->filmName<<" | Genre :" << bd->film->genre << endl;
            cout<<"Director :" << bd->sutradara->nama;
            if(bd->astrada!=NULL){
                cout << " | Director Assistant :" << bd->astrada->nama <<endl;
            }else{
                cout<<endl;
            }
        }
        bd=bd->next;
    }
}
void minAstrada(ListDirector LD, ListBridge LB){
    adrB B=LB.first;
    adrD astrada=NULL;
    while(B!=NULL){
        if(B->astrada!=NULL){
            if(astrada==NULL){
                astrada=B->astrada;
            }else{
                if(B->astrada->film >= astrada->film){
                    astrada=B->astrada;
                }
            }
        }
        B=B->next;
    }
    B=LB.first;
    while(B!=NULL){
        if(B->astrada==astrada){
            cout << "======================" <<endl;
            cout<<B->film->filmName<<" | Genre :" << B->film->genre << endl;
            cout<<"Director :" << B->sutradara->nama;
            cout << " | Director Assistant :" << B->astrada->nama <<endl;
        }
        B=B->next;
    }
}
