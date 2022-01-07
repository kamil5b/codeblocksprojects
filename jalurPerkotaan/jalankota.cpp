#include "jalankota.h"

void createList(ListRelasi &LR,ListKota &LK,ListJalan &LJ){
    LR.first=NULL;
    LR.last=NULL;
    LK.first=NULL;
    LJ.first=NULL;
    LJ.last=NULL;
}

addresskota createKota(string nama){
    //SLL
    addresskota P = new Kota;
    jalan(P)=0;
    nama(P)=nama;
    P->next=NULL;
    return P;
}
addressjalan createJalan(string nama, string tipe){
    //CSLL
    addressjalan P = new Jalan;
    kota(P)=0;
    nama(P)=nama;
    tipe(P)=tipe;
    P->next=P;
    return P;
}
addressrelasi createRelasi(addresskota &k, addressjalan &j){
    //DLL
    addressrelasi P = new Relasi;
    P->next=NULL;
    P->prev=NULL;
    kota(P)=k;
    jalan(P)=j;
    return P;
}

//a. Penambahan data kota
void addKota(ListKota &LK, string nama){
    addresskota k=findKota(LK,nama);
    if(k!=NULL){
        cout << "Kota telah didata" <<endl;
    }else{
        k=createKota(nama);
        k->next=LK.first;
        LK.first=k;
    }
}
//b. Penambahan data jalan
void addJalan(ListJalan &LJ, string nama, string tipe){
    addressjalan j=findJalan(LJ,nama);
    if(j!=NULL){
        cout << "Jalan telah didata" <<endl;
    }else{
        j=createJalan(nama,tipe);
        if(LJ.first==NULL){
            LJ.first=j;
            LJ.last=j;
        }else{
            j->next=LJ.first;
            LJ.last->next=j;
            LJ.first=j;
        }
    }
}
//c. Penentuan relasi kota dan jalan
void connect(ListRelasi &LR, addresskota &k, addressjalan &j){
    addressrelasi r=findRelasi(LR,k,j);
    if(r==NULL){
        r=createRelasi(k,j);
        jalan(k)=jalan(k)+1;
        kota(j)=kota(j)+1;
        if(LR.first==NULL){
            LR.first=r;
            LR.last=r;
        }else{
            LR.last->next=r;
            r->prev=LR.last;
            LR.last=r;
        }
    }
}

addresskota findKota(ListKota LK,string nama){
    addresskota k=LK.first;
    while(k!=NULL&&nama(k)!=nama){
        k=k->next;
    }
    return k;
}
addressjalan findJalan(ListJalan LJ,string nama){
    addressjalan j = LJ.first;
    if(j!=NULL){
        do{
            if(nama(j)==nama){
                return j;
            }
            j=j->next;
        }while(j!=LJ.first);
    }
    return NULL;
}
addressrelasi findRelasi(ListRelasi LR, addresskota k, addressjalan j){
    addressrelasi r=LR.first;
    while(r!=NULL&&(kota(r)!=k||jalan(r)!=j)){
        r=r->next;
    }
    return r;
}
//d. Menghapus data kota
void deleteKota(ListKota &LK,ListRelasi &LR,string nama){
    addresskota k = findKota(LK,nama);
    if(k!=NULL){
        addressrelasi r=LR.first;
        while(r!=NULL){
            if(kota(r)==k){
                disconnect(LR,r);
                delete(r);
            }
            r=r->next;
        }

        if(LK.first==k){
            LK.first=LK.first->next;
        }else{
            addresskota s=LK.first;
            while(s->next!=k){
                s=s->next;
            }
            s->next=k->next;
        }
        k->next=NULL;
        delete(k);
    }else{
        cout<<"Kota belum terdata"<<endl;
    }
}
//e. Menghapus data jalan
void deleteJalan(ListJalan &LJ,ListRelasi &LR,string nama){
    addressjalan j = findJalan(LJ,nama);
    if(j!=NULL){
        addressrelasi r=LR.first;
        while(r!=NULL){
            if(jalan(r)==j){
                disconnect(LR,r);
                delete(r);
            }
            r=r->next;
        }
        addressjalan s=LJ.first;
        while(s->next!=j){
            s=s->next;
        }
        if(LJ.first==j){
            LJ.first=LJ.first->next;
            LJ.last->next=LJ.first;
        }else if(LJ.last==j){
            LJ.last=s;
            LJ.last->next=LJ.first;
        }else{
            s->next=j->next;
        }
        j->next=NULL;
        delete(j);
    }else{
        cout<<"Jalan belum terdata"<<endl;
    }
}
void disconnect(ListRelasi &LR,addressrelasi &r){
    if(r!=NULL){
        jalan(r)=jalan(r)-1;
        kota(r)=kota(r)-1;
        if(LR.first==r&&LR.last==r){
            LR.first=NULL;
            LR.last=NULL;
        }else if(LR.first==r){
            LR.first=LR.first->next;
            LR.first->prev=NULL;
        }else if(LR.last==r){
            LR.last=LR.last->prev;
            LR.last->next=NULL;
        }else{
            r->prev->next=r->next;
            r->next->prev=r->prev;
        }
        r->next=NULL;
        r->prev=NULL;

    }
}
//f. Menampilkan data keselurahan kota beserta jalan terdapat di kota tersebut
void printAll(ListRelasi LR,ListKota LK){
    addressrelasi r;
    addresskota k=LK.first;
    while(k!=NULL){
        cout<<endl;
        cout << "===================" <<endl;
        cout << "Nama Kota : " << nama(k) <<endl;
        cout << "List jalan : " <<endl;
        r=LR.first;
        while(r!=NULL){
            if(kota(r)==k){
                cout << tipe(jalan(r)) << " " << nama(jalan(r)) <<endl;
            }
            r=r->next;
        }
        k=k->next;
    }
}
//g. Menampilkan data kota yang memiliki nama jalan tertentu
void kotaPunyaJalan(ListRelasi LR,ListJalan LJ,string nama){
    addressjalan j=findJalan(LJ,nama);
    if(j!=NULL){
        cout<<endl;
        cout << "===================" <<endl;
        cout << tipe(j) << " " << nama(j) <<endl;
        cout << "Nama Jalan : " << nama(j) <<endl;
        cout << "Tipe jalan : " << tipe(j) <<endl;
        cout << "List Kota : "<<endl;
        addressrelasi r=LR.first;
        while(r!=NULL){
            if(jalan(r)==j){
                cout << "Nama Kota : " << nama(kota(r)) <<endl;
            }
            r=r->next;
        }
    }
}
//h. Menampilkan data jalan yang dimiliki suatu kota tertentu
void jalanKota(ListRelasi LR,ListKota LK,string nama){
    addresskota k=findKota(LK,nama);
    if(k!=NULL){
        cout<<endl;
        cout << "===================" <<endl;
        cout << "Nama Kota : " << nama(k) <<endl;
        cout << "List jalan : " <<endl;
        addressrelasi r=LR.first;
        while(r!=NULL){
            if(kota(r)==k){
                cout << tipe(jalan(r)) << " " << nama(jalan(r)) <<endl;
            }
            r=r->next;
        }
    }
}
//i. Menampilkan data kota dan nama jalan yang memilki tipe jalan tertentu
void tipeJalanKota(ListRelasi LR,ListJalan LJ,string tipe){
    addressjalan j=LJ.first;
    if(j!=NULL){
        do{
            if(tipe(j)==tipe){
                kotaPunyaJalan(LR,LJ,nama(j));
            }
            j=j->next;
        }while(j!=LJ.first);
    }
}
