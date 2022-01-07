#include "juri.h"

void createListJuri (ListJuri &L){
    first(L)=NULL;
}
addressJ alokasiJuri (string username, string nama, int usia, string password){
    addressJ P;
    P=new elmJuri;
    info(P).username=username;
    info(P).nama=nama;
    info(P).umur=usia;
    info(P).password=password;
    next(P)=NULL;
    return P;
}
void dealokasiJuri (addressJ &p){
    delete p;
    p=NULL;
}

void insertFirstJuri(ListJuri &L, addressJ p){
    next(p)=first(L);
    first(L)=p;
}
void insertBeforeJuri (ListJuri &L, addressJ Prec,addressJ p){
    addressJ q=first(L);
    if(Prec!=NULL&&p!=NULL){
        while(q!=NULL&&next(q)!=Prec){
            q=next(q);
        }
        if(q!=NULL){
            next(p)=next(q);
            next(q)=p;
        }
    }
}
void insertLastJuri (ListJuri &L, addressJ p){
    addressJ q=first(L);
    if(p!=NULL){
        while(next(q)!=NULL){
            q=next(q);
        }
        next(q)=p;
    }
}
void insertJuri (ListJuri &L, addressJ &p){
    addressJ q;
    q=findElmJuri(L,info(p).username);
    if(q==NULL){
        q=first(L);
        if(q!=NULL){
            if(info(p).username>info(q).username){
                while(q!=NULL&&info(p).username>info(q).username){
                    q=next(q);
                }
                if(q!=NULL){
                    insertBeforeJuri(L,q,p);
                }else{
                    insertLastJuri(L,p);
                }
            }else{
                insertFirstJuri(L,p);
            }
        }else{
            first(L)=p;
        }
    }else{
        cout << "Username juri sudah terdaftar sebelumnya" << endl;
        dealokasiJuri(p);
    }
}
addressJ findElmJuri (ListJuri L, string username){
    addressJ P=first(L);
    while(P!=NULL&&info(P).username!=username){
        P=next(P);
    }
    return P;
}

void updateJuri(ListJuri L,string id){
    string nama;
    int umur;

    addressJ P=findElmJuri(L,id);
    if(P!=NULL){
        printJuri(P);
        cout << "Nama : ";
        cin >> nama;
        cout << "Umur : ";
        cin >> umur;
        info(P).nama=nama;
        info(P).umur=umur;
    }else{
        cout << "Juri tidak ada" << endl;
    }
}

void deleteFirstJuri (ListJuri &L, addressJ &p){
    if(first(L)!=NULL){
        first(L)=next(p);
        next(p)=NULL;
    }
}
void deleteMiddleLastJuri (ListJuri &L, addressJ &p){
    addressJ q;
    if(first(L)!=NULL){
        q=first(L);
        while(q!=NULL&&next(q)!=p){
            q=next(q);
        }
        if(q!=NULL){
            next(q)=next(p);
            next(p)=NULL;
        }
    }
}
void printJuri (addressJ p){
    if(p!=NULL){
        cout << "Username : " << info(p).username << endl;
        cout << "Nama : " << info(p).nama << endl;
        cout << "Umur : " << info(p).umur << endl;
    }
}
void printAllJuri (ListJuri L){
    addressJ P;
    while(P!=NULL){
        cout << endl;
        printJuri(P);
        P=next(P);
    }
}
