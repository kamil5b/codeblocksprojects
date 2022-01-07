#include "header.h"

addressOT buatOT(string nama, string kelamin){
    addressOT P;
    P=new Orang_Tua;
    nama(P)=nama;
    kelamin(P)=kelamin;
    anak(P)=0;
    anakPertama(P)=NULL;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}
addressAnak buatAnak(string nama, string kelamin){
    addressAnak P;
    P=new Anak;
    nama(P)=nama;
    kelamin(P)=kelamin;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void buatList(listAnak &LA,listOT &LOT){
    first(LA)=NULL;
    last(LA)=NULL;

    first(LOT)=NULL;
    last(LOT)=NULL;
}
void buatHubungan(addressOT &P, addressAnak Q){
    addressHubungan H,temp;
    H=new Hubungan;
    anak(H)=Q;
    next(H)=NULL;

    if(anakPertama(P)==NULL){
        anakPertama(P)=H;
    }else{
        temp=anakPertama(P);
        while(next(temp)!=NULL){
            temp=next(temp);
        }
        next(temp)=H;
    }

}
void insertLastOT(addressOT P, listOT &L){
    if(last(L)==NULL){
        last(L)=P;
        first(L)=P;
    }else{
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}
void insertLastAnak(addressAnak P, listAnak &L){
    if(last(L)==NULL){
        last(L)=P;
        first(L)=P;
    }else{
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}

void deleteFirstOT(addressOT &P,listOT &L){
    first(L)=next(P);
    next(P)=NULL;
    if(first(L)!=NULL){
        prev(first(L))=NULL;
    }else{
        last(L)=NULL;
    }
}
void deleteAfterOT(addressOT Prec,addressOT &P){
    next(Prec)=next(P);
    prev(next(P))=Prec;
    next(P)=NULL;
    prev(P)=NULL;
}
void deleteLastOT(addressOT &P,listOT &L){
    last(L)=prev(P);
    prev(P)=NULL;
    if(last(L)!=NULL){
        next(last(L))=NULL;
    }else{
        first(L)=NULL;
    }
}
void deleteOT(addressOT &P,listOT &L){
    addressOT Prec;

    if(P==first(L)){
        deleteFirstOT(P,L);
    }else if(P==last(L)){
        deleteLastOT(P,L);
    }else{
        Prec=first(L);
        while(Prec!=NULL&&next(Prec)!=P){
            Prec=next(Prec);
        }
        if(Prec!=NULL){
            deleteAfterOT(Prec,P);
        }
    }
}

void deleteFirstAnak(addressAnak &P,listAnak &L){
    first(L)=next(P);
    next(P)=NULL;
    if(first(L)!=NULL){
        prev(first(L))=NULL;
    }else{
        last(L)=NULL;
    }
}
void deleteAfterAnak(addressAnak Prec,addressAnak &P){
    next(Prec)=next(P);
    prev(next(P))=Prec;
    next(P)=NULL;
    prev(P)=NULL;
}
void deleteLastAnak(addressAnak &P,listAnak &L){
    last(L)=prev(P);
    prev(P)=NULL;
    if(last(L)!=NULL){
        next(last(L))=NULL;
    }else{
        first(L)=NULL;
    }
}
void deleteAnak(addressAnak &P,listAnak &L){
    addressAnak Prec;

    if(P==first(L)){
        deleteFirstAnak(P,L);
    }else if(P==last(L)){
        deleteLastAnak(P,L);
    }else{
        Prec=first(L);
        while(Prec!=NULL&&next(Prec)!=P){
            Prec=next(Prec);
        }
        if(Prec!=NULL){
            deleteAfterAnak(Prec,P);
        }
    }
}

void deleteFirstHubungan(addressHubungan &P,addressOT &Q){
    anakPertama(Q)=next(P);
    next(P)=NULL;
}
void deleteAfterHubungan(addressHubungan Prec,addressHubungan &P){
    next(Prec)=next(P);
    next(P)=NULL;
}
void deleteHubungan(addressHubungan &P,addressOT &Q){
    addressHubungan Prec;
    if(P==anakPertama(Q)){
        deleteFirstHubungan(P,Q);
    }else{
        Prec=anakPertama(Q);
        while(Prec!=NULL&&next(Prec)!=P){
            Prec=next(Prec);
        }
        if(Prec!=NULL){
            deleteAfterHubungan(Prec,P);
        }
    }
}

addressOT cariOT(string nama,string kelamin,listOT &L){
    addressOT P;
    P=first(L);
    while(P!=NULL&&nama(P)!=nama&&kelamin(P)!=kelamin){
        P=next(P);
    }
    return P;
}
addressAnak cariAnak(string nama,string kelamin,listAnak &L){
    addressAnak P;
    P=first(L);
    while(P!=NULL&&nama(P)!=nama&&kelamin(P)!=kelamin){
        P=next(P);
    }
    return P;
}

void printAnak(addressAnak P,listOT L){
    addressOT Q;
    addressHubungan H;
    bool ada;

    cout << "Nama : " << nama(P) << endl;
    cout << "Kelamin : " << kelamin(P) << endl;
    Q=first(L);
    cout << "Anak dari ";
    ada=false;
    while(Q!=NULL){
        H=anakPertama(Q);
        while(H!=NULL){
            if(P==anak(H)){
                if(ada){
                    cout << "& " << nama(Q) << " ";
                }else{
                    cout << nama(Q) << " ";
                    ada=true;
                }
            }
            H=next(H);
        }
        Q=next(Q);
    }
    cout<<endl;

}
void printOT(addressOT P){
    addressHubungan H;
    cout << "Nama : " << nama(P) << endl;
    cout << "Kelamin : " << kelamin(P) << endl;

    H=anakPertama(P);
    if(H==NULL){
        cout << "Tidak mempunyai anak";
    }else{
        cout << "Orang tua dari : " << endl;
        while(H!=NULL){
            cout << "-> " << nama(anak(H)) << endl;
            H=next(H);
        }
    }

    cout << endl;
}

addressOT MinAnakOT(listOT L){
    addressOT P,minAnak;
    addressHubungan H;

    int Min,i;

    P=first(L);
    Min=anak(P);
    minAnak=P;
    while(P!=NULL){
        i=0;
        H=anakPertama(P);
        while(H!=NULL){
            i++;
            H=next(H);
        }
        if(i<Min){
            minAnak=P;
            Min=i;
        }
        P=next(P);
    }
    return minAnak;
}
addressOT MaxAnakOT(listOT L){
    addressOT P,maxAnak;
    addressHubungan H;

    int Max,i;

    P=first(L);
    Max=anak(P);
    maxAnak=P;
    while(P!=NULL){
        i=0;
        H=anakPertama(P);
        while(H!=NULL){
            i++;
            H=next(H);
        }
        if(i>Max){
            maxAnak=P;
            Max=i;
        }
        P=next(P);
    }
    return maxAnak;
}
