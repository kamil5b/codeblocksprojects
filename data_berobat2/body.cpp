#include "header.h"

//CREATE ELEMENT
void buatPenyakit(address_penyakit &P,string nama){
    P=new Penyakit;
    next(P)=NULL;
    prev(P)=NULL;
    nama(P)=nama;
    sakit(P)=NULL;
    linked(P)=0;
}
void buatPasien(address_pasien &P,string nama){
    P=new Pasien;
    next(P)=NULL;
    prev(P)=NULL;
    linked(P)=0;
    nama(P)=nama;
}
void kenaSakit(address_sakit &P,address_pasien &pas){
    P=new Sakit;
    next(P)=NULL;
    pasien(P)=pas;
    linked(pas)++;
}

//CREATE LIST
void buatListPenyakit(ListPenyakit &L){
    first(L)=NULL;
    last(L)=NULL;
}
void buatListPasien(ListPasien &L){
    first(L)=NULL;
}

//INSERT
void mendataPenyakit(ListPenyakit &L,address_penyakit P){ //insert last
    if(last(L)==NULL){
        first(L)=P;
        last(L)=P;
    }else{
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}
void mendataPasien(ListPasien &L,address_pasien P){ //insert first
    if(first(L)==NULL){
        first(L)=P;
        next(P)=P;
        prev(P)=P;
    }else{
        next(P)=first(L);
        prev(P)=prev(first(L));
        next(prev(P))=P;
        prev(first(L))=P;
        first(L)=P;
    }
}
void kenaPenyakit(address_penyakit &L,address_sakit &P){ //insert first
    if(sakit(L)==NULL){
        sakit(L)=P;
    }else{
        next(P)=sakit(L);
        sakit(L)=P;
    }
    linked(L)++;
}
//SEARCH
address_pasien cariPasien(ListPasien &L,string nama){
    address_pasien P;
    P=first(L);
    if(P==NULL){
        return NULL;
    }
    do{
        P=next(P);
    }while(P!=first(L)&&nama(P)!=nama);
    if(nama(P)==nama){
        return P;
    }else{
        return NULL;
    }
}
address_penyakit cariPenyakit(ListPenyakit &L, string nama){
    address_penyakit P;
    P=first(L);
    while(P!=NULL&&nama(P)!=nama){
        P=next(P);
    }
    return P;
}

//DELETE FUNCTION
void sembuh(address_penyakit &L,address_sakit &P){
    address_sakit Q;
    if(L!=NULL){
        if(sakit(L)!=NULL&&P!=NULL){
            if(sakit(L)==P){
                sakit(L)=next(P);
                next(P)=NULL;
            }else{
                Q=sakit(L);
                while(Q!=NULL&&next(Q)!=P){
                    Q=next(Q);
                }
                if(Q!=NULL){
                    next(Q)=next(P);
                    next(P)=NULL;
                }
            }
            linked(pasien(P))--;
            pasien(P)=NULL;
            delete P;
        }
    }
}
void hapusPenyakit(ListPenyakit &L,address_penyakit &P){
    address_sakit S;
    if(first(L)!=NULL&&P!=NULL){
        //LEPAS DARI LISTNYA DULU
        if(P==first(L)&&P==last(L)){
            first(L)=NULL;
            last(L)=NULL;
        }else if(P==first(L)){ //DELETE FIRST
            first(L)=next(P);
            prev(first(L))=NULL;
            next(P)=NULL;
        }else if(P==last(L)){ //DELETE LAST
            last(L)=prev(P);
            next(last(L))=NULL;
            prev(P)=NULL;
        }else{               //DELETE MIDDLE
            prev(next(P))=prev(P);
            next(prev(P))=next(P);
            next(P)=NULL;
            prev(P)=NULL;
        }

        //DELETE RELASI SEMUANYA
        S=sakit(P);
        while(S!=NULL){
            sembuh(P,S);
            S=next(S);
        }

        delete P;
    }
}
void pasienPulang(ListPasien &L,address_pasien &P,ListPenyakit Lp){
    address_penyakit Q;
    address_sakit S;
    if(first(L)!=NULL){
        if(P==first(L)&&next(P)==P){
            first(L)=NULL;
        }else if(P==first(L)){
            first(L)=next(P);
            prev(first(L))=prev(P);
            next(prev(P))=next(P);
            next(P)=NULL;
            prev(P)=NULL;
        }else{
            next(prev(P))=next(P);
            prev(next(P))=prev(P);
            next(P)=NULL;
            prev(P)=NULL;
        }

        Q=first(Lp);
        while(Q!=NULL){
            S=sakit(Q);
            while(S!=NULL){
                if(pasien(S)==P){
                    linked(Q)--;
                    sembuh(Q,S);
                }
                S=next(S);
            }
            Q=next(Q);
        }
        delete P;
    }
}

//SHOW
void liatPenyakit(address_penyakit P){
    if(P!=NULL){
        cout << "Nama penyakit : " << nama(P) << endl;
        cout << "Jumlah pasien : " << linked(P) << endl;
    }
}
void liatPasien(address_pasien P){
    if(P!=NULL){
        cout << "Nama pasien : " << nama(P) << endl;
        cout << "Jumlah penyakit : " << linked(P) << endl;
    }
}
void lihatPenyakitdariPasien(address_pasien P, ListPenyakit L){
    address_penyakit Q;
    address_sakit S;
    if(P!=NULL){
        Q=first(L);
        liatPasien(P);
        cout << "Penyakitnya :" << endl;
        while(Q!=NULL){
            S=sakit(Q);
            while(S!=NULL){
                if(pasien(S)==P){
                    cout<<endl;
                    liatPenyakit(Q);
                }
                S=next(S);
            }
            Q=next(Q);
        }
    }
}
void lihatPasienyangterinfeksi(address_penyakit P){
    address_sakit S;
    if(P!=NULL){
        liatPenyakit(P);
        cout << "Pasiennya :" <<endl;
        S=sakit(P);
        while(S!=NULL){
            cout << endl;
            liatPasien(pasien(S));
            S=next(S);
        }
    }
}

void top5Penyakit(ListPenyakit L){
    address_penyakit P,Q,Prec,Max;
    int MaxValue,i;
    P=first(L);
    if(first(L)!=last(L)){
        //SORT SELECTION
        while(P!=NULL){
            Q=P;
            Max=P;
            MaxValue=linked(P);
            while(Q!=NULL){
                if(linked(Q)>MaxValue){
                    MaxValue=linked(Q);
                    Max=Q;
                }
                Q=next(Q);
            }
            if(P==first(L)&&Max!=P){
                first(L)=next(P);
                prev(first(L))=Max;
                next(P)=NULL;

                Prec=prev(Max);
                next(P)=next(Max);
                prev(P)=Prec;
                next(Prec)=P;
                prev(Max)=NULL;

                next(Max)=first(L);
                prev(first(L))=Max;
                first(L)=prev(Max);
            }else if(Max!=P){
                Q=prev(P);
                next(Q)=next(P);
                prev(next(P))=Q;

                Prec=prev(Max);
                next(P)=next(Max);
                prev(P)=Prec;
                next(Prec)=P;

                next(Max)=next(Q);
                prev(Max)=Q;
                next(Q)=Max;
                prev(next(Max))=Max;
            }
            P=next(P);
        }
        P=first(L);
        i=0;
        while(P!=NULL&&i<5){
            i++;
            cout << i << endl;
            lihatPasienyangterinfeksi(P);
            P=next(P);
        }
    }
}

void menu(ListPasien &Lpas,ListPenyakit &Lpen){
    string nama;
    int pilih;
    address_pasien pas;
    address_penyakit pen;
    address_sakit S;

    do{
        cout << "===================" <<endl;
        cout << "0.Keluar" <<endl;
        cout << "1.Menambahkan penyakit baru" <<endl;
        cout << "2.Menambahkan pasien baru" <<endl;
        cout << "3.Pasien terkena penyakit" <<endl;
        cout << "4.Hapus data penyakit" <<endl;
        cout << "5.Pasien pulang" <<endl;
        cout << "6.Lihat seluruh pasien dan penyakitnya" <<endl;
        cout << "7.Penyakit pasien" <<endl;
        cout << "8.Pasien yang terinfeksi" <<endl;
        cout << "9.User yang bergabung minimal 3 grup" <<endl;
        cout << "Pilih angka :";
        cin >> pilih;

        while(pilih < 0 || pilih > 9){
            cout << "Pilih angka :";
            cin >> pilih;
        }

        switch(pilih){

        case 1:
            cout << "Nama penyakit :";
            cin >> nama;
            buatPenyakit(pen,nama);
            mendataPenyakit(Lpen,pen);
            cout << "Berhasil mendata penyakit baru " << nama <<endl;
            break;
        case 2:
            cout << "Nama pasien :";
            cin >> nama;
            buatPasien(pas,nama);
            mendataPasien(Lpas,pas);
            cout << "Berhasil mendata pasien dengan nama " << nama << endl;
            break;
        case 3:
            cout << "Nama pasien :";
            cin >> nama;
            pas=cariPasien(Lpas,nama);
            if(pas!=NULL){
                cout << "Nama penyakit :";
                cin >> nama;
                pen=cariPenyakit(Lpen,nama);
                if(pen!=NULL){
                    kenaSakit(S,pas);
                    kenaPenyakit(pen,S);
                    cout << "Berhasil mendata penyakit pasien " << nama(pas) << endl;
                }else{
                    cout << "Penyakit tidak ditemukan" << endl;
                }
            }else{
                cout << "Pasien tidak ditemukan" << endl;
            }
            break;
        case 4:
            cout << "Nama penyakit :";
            cin >> nama;
            pen=cariPenyakit(Lpen,nama);
            if(pen!=NULL){
                hapusPenyakit(Lpen,pen);
                cout << nama << " telah dihapuskan" << endl;
            }else{
                cout << "Nama penyakit tidak ditemukan" << endl;
            }
            break;
        case 5:
            cout << "Nama pasien :";
            cin >> nama;
            pas=cariPasien(Lpas,nama);
            if(pas!=NULL){
                pasienPulang(Lpas,pas,Lpen);
                cout <<"Pasien " << nama << " telah dipulangkan" << endl;
            }else{
                cout << "Nama pasien tidak ditemukan" << endl;
            }
            break;
        case 6:
            pas=first(Lpas);
            do{
                lihatPenyakitdariPasien(pas,Lpen);
                pas=next(pas);
            }while(pas!=first(Lpas));
            break;
        case 7:
            cout << "Masukan nama penyakit :";
            cin >> nama;
            pen=cariPenyakit(Lpen,nama);
            if(pen!=NULL){
                lihatPasienyangterinfeksi(pen);
            }else{
                cout << "Nama penyakit tidak ditemukan" << endl;
            }
            break;
        case 8:
            cout << "Masukan nama pasien :";
            cin >> nama;
            pas=cariPasien(Lpas,nama);
            if(pas!=NULL){
                lihatPenyakitdariPasien(pas,Lpen);
            }else{
                cout << "Nama pasien tidak ditemukan" << endl;
            }
            break;
        case 9:
            top5Penyakit(Lpen);
            break;
        }

    }while(pilih!=0);
}
