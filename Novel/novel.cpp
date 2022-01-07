#include "novel.h"


void createListPenulis(ListPenulis &L){
    //CDLL
    First(L)=NULL;
    Last(L)=NULL;
}
void createListNovel(ListNovel &L){
    //DLL
    First(L)=NULL;
    Last(L)=NULL;
}
void addPenulis(ListPenulis &L, string nama){
    adrP P;
    searchPenulis(L,nama,P);
    if(P!=NULL){
        cout << "Penulis telah ditambahkan sebelumnya" <<endl;
    }else{
        P=new Penulis;
        nama(P)=nama;
        counts(P)=0;
        collab(P)=false;
        P->next=P;
        P->prev=P;

        if(First(L)==NULL){
            First(L)=P;
            Last(L)=P;
        }else{
            P->next=First(L);
            P->prev=Last(L);
            First(L)->prev=P;
            Last(L)->next=P;
            First(L)=P;
        }
        cout << "Berhasil menambahkan penulis" <<endl;
    }
}
void addNovel(ListNovel &L, string judul,adrP &pen){
    adrN N;
    searchNovel(L,judul,N);
    if(N!=NULL){
        string yatidak;
        do{
        cout << "Novel sudah pernah ada, menambahkan penulis tambahan kedalam novel ini?(Ya/Tidak) ";
        cin >> yatidak;
        }while(yatidak!="Ya"&&yatidak!="Tidak"&&yatidak!="ya"&&yatidak!="tidak"&&yatidak!="");
        if(yatidak=="Ya"||yatidak=="ya"){
            tambahPenulisDariNovel(N,pen);
        }
    }else{
        N=new Novel;
        N->next=NULL;
        N->prev=NULL;
        counts(N)=1;
        judul(N)=judul;

        adrT T= new Tulis;
        penulis(T)=pen;
        T->next=NULL;
        firstT(N)=T;
        counts(pen)=counts(pen)+1;
        if(First(L)==NULL){
            First(L)=N;
        }else{
            Last(L)->next=N;
            N->prev=Last(L);
        }
        Last(L)=N;
    }
}
void tambahPenulisDariNovel(adrN &N, adrP &P){
    adrT T=firstT(N);
    while(T!=NULL){
        if(penulis(T)==P){
            cout << "Penulis sudah ditambahkan di Novel"<< endl;
            return;
        }
        T=T->next;
    }
    T=new Tulis;
    penulis(T)=P;
    T->next=firstT(N);
    firstT(N)=T;
    counts(N)=counts(N)+1;
    counts(P)=counts(P)+1;
    collab(P)=true;
}

void searchPenulis(ListPenulis L, string nama, adrP &P){
    if(First(L)!=NULL){
        P=First(L);
        do{
            if(nama(P)==nama){
                cout << "Ada!"<<endl;
                return;
            }
            P=P->next;
        }while(P!=First(L));
        cout << "Tidak ditemukan" <<endl;
    }
    P=NULL;
}
void searchNovel(ListNovel L, string judul, adrN &N){
    N=First(L);
    while(N!=NULL&&judul(N)!=judul){
        cout << "srch jdl : " << judul(N) << endl;
        N=N->next;
    }
}

void deleteNovel(ListNovel &LN, string judul){
    adrN N;
    adrT T,temp;
    searchNovel(LN,judul,N);
    if(N!=NULL){
        T=firstT(N);
        while(T!=NULL){
            counts(penulis(T))=counts(penulis(T))-1;
            penulis(T)=NULL;
            temp=T->next;
            T->next=NULL;
            delete(T);
            T=temp;
        }
        if(First(LN)==N&&Last(LN)==N){
            createListNovel(LN);
        }else if(First(LN)==N){
            First(LN)=N->next;
            First(LN)->prev=NULL;
            N->next=NULL;
        }else if(Last(LN)==N){
            Last(LN)=N->prev;
            Last(LN)->next=NULL;
            N->prev=NULL;
        }else{
            N->prev->next=N->next;
            N->next->prev=N->prev;
            N->next=NULL;
            N->prev=NULL;
        }
        delete(N);
    }
}
void deletePenulis(ListNovel &LN, ListPenulis &LP, string nama){
    adrN N=First(LN);
    adrP P;
    adrT T,temp;
    searchPenulis(LP,nama,P);

    if(P!=NULL){
        while(N!=NULL){
            T=firstT(N);
            while(T!=NULL){
                if(penulis(T)==P){
                    counts(N)=counts(N)-1;
                    penulis(T)=NULL;
                    temp=T->next;
                    T->next=NULL;
                    delete(T);
                    T=temp;
                }else{
                    T=T->next;
                }
            }
            N=N->next;
        }
        if(First(LP)==P&&Last(LP)==P){
            createListPenulis(LP);
        }else if(First(LP)==P){
            First(LP)=P->next;
            First(LP)->prev=Last(LP);
            Last(LP)->next=First(LP);
        }else if(Last(LP)==P){
            Last(LP)=P->prev;
            Last(LP)->next=First(LP);
            First(LP)->prev=Last(LP);
        }else{
            P->prev->next=P->next;
            P->next->prev=P->prev;
        }
        P->next=NULL;
        P->prev=NULL;
        delete(P);
    }
}

void printPenulisNovel(ListNovel LN,ListPenulis LP,string name){
    adrP P;
    adrT T;
    searchPenulis(LP,name,P);
    if(P!=NULL){
        cout << nama(P) << " " << counts(P) << " Buku:"<<endl;
        adrN N=First(LN);
        while(N!=NULL){
            T=firstT(N);
            while(T!=NULL){
                if(penulis(T)==P){
                    cout << judul(N) <<endl;
                }
                T=T->next;
            }
            N=N->next;
        }
    }
}
void duaPenulis(ListNovel LN){
     adrN N=First(LN);
     adrT T;
     while(N!=NULL){
        if(counts(N)==2){
            cout<<judul(N)<<" Karya:"<<endl;
            T=firstT(N);
            while(T!=NULL){
                cout << nama(penulis(T)) <<endl;
                T=T->next;
            }
        }

        N=N->next;
    }
}

void penulisAktif(ListPenulis LP){
    adrP P;
    int aktif=0;
    P=First(LP);
    if(P!=NULL){
        do{
            if(counts(P)>=aktif){
                aktif=counts(P);
            }
            P=P->next;
        }while(P!=First(LP));
        do{
            if(counts(P)==aktif){
                cout << nama(P) << " dengan " <<counts(P)<<" buku"<<endl;
            }
            P=P->next;
        }while(P!=First(LP));
    }
}
void penulisKuper(ListPenulis LP){
    adrP P=First(LP);
    if(P!=NULL){
        do{
            if(collab(P)==false){
                cout << nama(P) << " dengan " <<counts(P)<<" buku"<<endl;
            }
            P=P->next;
        }while(P!=First(LP));
    }
}

void printNovel(ListNovel LN){
    adrN N=First(LN);
     adrT T;
     while(N!=NULL){
        cout<<judul(N)<<" Karya:"<<endl;
        T=firstT(N);
        while(T!=NULL){
            cout << nama(penulis(T)) <<endl;
            T=T->next;
        }
        N=N->next;
    }
}

void startMenu(ListNovel &LN, ListPenulis &LP){

    adrN N;
    adrP P;
    string s;
    int menu;
    do{
        system("CLS");
        cout<<"========================================="<<endl;
        cout<<"=                MENU                   ="<<endl;
        cout<<"========================================="<<endl;
        cout<<"0. Tampilkan seluruh novel"<<endl;
        cout<<"1. Tambah penulis baru"<<endl;
        cout<<"2. Tambah novel baru"<<endl;
        cout<<"3. Penulis tambahan untuk sebuah novel"<<endl;
        cout<<"4. Hapus Novel"<<endl;
        cout<<"5. Pecat penulis"<<endl;
        cout<<"6. Lihat karya sebuah penulis"<<endl;
        cout<<"7. Novel dengan 2 penulis"<<endl;
        cout<<"8. Penulis yang paling produktif"<<endl;
        cout<<"9. Penulis yang tidak pernah kolaborasi"<<endl;
        cout<<"10.Exit Program"<<endl;
        cout<<"Pilih : ";
        cin >> menu;
        switch(menu){
        case 0:
            printNovel(LN);
            break;
        case 1:
            cout << "Nama penulis : ";
            cin>>s;
            addPenulis(LP,s);
            break;
        case 2:
            cout << "Nama penulis : ";
            cin>>s;
            searchPenulis(LP,s,P);
            if(P!=NULL){
                cout << "Judul buku : ";
                cin>>s;
                addNovel(LN,s,P);
            }else{
                cout << "Penulis belum ditambahkan" <<endl;
            }
            break;
        case 3:
            cout << "Nama penulis : ";
            cin>>s;
            searchPenulis(LP,s,P);
            if(P!=NULL){
                cout << "Judul buku : ";
                cin>>s;
                searchNovel(LN,s,N);
                cout << "JUDUL : " << judul(N) << endl;
                if(N!=NULL){
                    cout << "Menambahkan...." << endl;
                    tambahPenulisDariNovel(N,P);
                    cout << "Telah menambahkan!" << endl;
                }else{
                    cout << "Novel tidak ditemukan" <<endl;
                }
            }else{
                cout << "Penulis belum ditambahkan" <<endl;
            }
            break;
        case 4:
            cout << "Judul novel : ";
            cin >> s;
            deleteNovel(LN,s);
            break;
        case 5:
            cout << "Nama penulis : ";
            cin>>s;
            deletePenulis(LN,LP,s);
            break;
        case 6:
            cout << "Nama penulis : ";
            cin>>s;
            printPenulisNovel(LN,LP,s);
            break;
        case 7:
            duaPenulis(LN);
            break;
        case 8:
            penulisAktif(LP);
            break;
        case 9:
            penulisKuper(LP);
            break;
        }
        cout<<endl;
        system("pause");
    }while(menu!=10);
}
