#include "bimbangan.h"


void createListMatakuliah(ListMatakuliah &L){
    //CDLL
    First(L)=NULL;
    Last(L)=NULL;
}
//1a
void addMatakuliah(ListMatakuliah &L, string nama,
                        string kelas, int kuota, string jenis){
    adrMK P;
    P=new Matakuliah;
    nama(P)=nama;
    kelas(P)=kelas;
    kuota(P)=kuota;
    jenis(P)=jenis;
    jumlah(P)=0;
    firstM(P)=NULL;
    P->next=NULL;
    P->prev=NULL;
    if(First(L)==NULL){
        First(L)=P;
        Last(L)=P;
    }else{
        P->next=First(L);
        First(L)->prev=P;
        First(L)=P;
    }
    //cout << "Berhasil menambahkan matakuliah" <<endl;

}
//2a,3a,4a
void addMahasiswa(ListMatakuliah LM, adrMK &L,
                  string nama,string nim, string kelas, string jenis){
    adrM N = searchMahasiswaFromMatkul(L, nim);
    if(N==NULL && jenis(L)==jenis && jumlah(L) < kuota(L)
       && countMatakuliahMahasiswa(LM, nim) < 3){
        N=new Mahasiswa;
        N->next=N;
        N->prev=N;
        kelas(N)=kelas;
        nama(N)=nama;
        nim(N)=nim;
        jenis(N)=jenis;

        jumlah(L)=jumlah(L)+1;
        if(firstM(L)==NULL){
            firstM(L)=N;
        }else{
            N->next=firstM(L);
            N->prev=firstM(L)->prev;
            firstM(L)->prev->next=N;
            firstM(L)->prev=N;
            firstM(L)=N;
        }
        //cout << "Mahasiswa berhasil ditambahkan" << endl;
    }else{
        cout << "Gagal ditambahkan" << endl;
    }
}
//9
adrM searchMahasiswaFromMatkul(adrMK L, string kode){
    adrM P;
    if(firstM(L)!=NULL){
        P=firstM(L);
        do{
            if(nama(P)==kode || nim(P)==kode){
                return P;
            }
            P=P->next;
        }while(P!=firstM(L));
    }
    return NULL;
}
adrMK searchMatakuliah(ListMatakuliah L, string nama, string kelas, string jenis){
    adrMK N=First(L);
    while(N!=NULL){
        if(nama(N)==nama&&kelas(N)==kelas&&jenis(N)==jenis){
            return N;
        }
        N=N->next;
    }
    return NULL;
}

void printMahasiswaFromMatkul(ListMatakuliah LM,string nama, string kelas, string jenis, string kode){
    adrMK L=searchMatakuliah(LM,nama, kelas, jenis);
    if(L!=NULL){
        adrM N=searchMahasiswaFromMatkul(L,kode);
        if(N!=NULL){
            printMahasiswa(N);
        }
    }

}
int countMatakuliahMahasiswa(ListMatakuliah L, string kode){
    int totalmatkul=0;
    adrMK N=First(L);
    while(N!=NULL){
        if(searchMahasiswaFromMatkul(N,kode)!=NULL){
            totalmatkul++;
        }
        N=N->next;
    }
    return totalmatkul;
}

//2b && 3b
void deleteMahasiswa(ListMatakuliah LP, string kode){
    adrM N;
    adrMK P;
    P=First(LP);
    while(P!=NULL){
        N = searchMahasiswaFromMatkul(P,kode);
        if(N!=NULL){
            N->prev->next=N->next;
            N->next->prev=N->prev;
            if(N==firstM(P)){
                firstM(P)=next(firstM(P));
                if(next(firstM(P))==firstM(P)){
                    firstM(P)=NULL;
                }
            }
            delete(N);
            jumlah(P)--;
        }
        P=next(P);
    }
}

//1b
void deleteMatakuliah(ListMatakuliah &LP,string nama, string kelas, string jenis){
    adrMK P;
    P = searchMatakuliah(LP,nama, kelas, jenis);

    if(P!=NULL){

        while(firstM(P)!=NULL){
            adrM T=firstM(P);
            firstM(P)=firstM(P)->next;
            if(firstM(P)->next==firstM(P)){
                firstM(P)=NULL;
            }
            T->next=NULL;
            delete(T);
        }

        if(First(LP)==P&&Last(LP)==P){
            createListMatakuliah(LP);
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

void printMatakuliah(adrMK P){
    cout << "=========================" << endl;
    cout << "Nama Matkul :" << nama(P) <<endl;
    cout << "Kelas :" << kelas(P) <<endl;
    cout << "Jenis :" << jenis(P) <<endl;
    cout << "Kuota :" << kuota(P) <<endl;
    cout << "Jumlah :"<< jumlah(P)<<endl;
    cout << "=========================" << endl;
}

void printMahasiswa(adrM N){
    cout << "=========================" << endl;
    cout << nama(N) << " | NIM : " << nim(N) <<endl;
    cout << "Class :" << kelas(N) <<endl;
    cout << "Jenis :" << jenis(N) <<endl;
    cout << "=========================" << endl;
}

//5
void printOnlyMatakuliah(ListMatakuliah LD){
    adrMK P=First(LD);
    cout<<endl;
    cout<<"List Matakuliah :"<<endl;
    while(P!=NULL){
        printMatakuliah(P);
        P=P->next;
    }
}
//8
void printMatakuliahAvailable(ListMatakuliah LD,string nama,string jenis){
    adrMK P=First(LD);
    cout<<endl;
    cout<<"List Matakuliah :"<<endl;
    while(P!=NULL){
        if(nama(P)==nama && jenis(P)==jenis && jumlah(P) < kuota(P)){
            printMatakuliah(P);
        }
        P=P->next;
    }
}
//6
void printMatakuliahMahasiswa(ListMatakuliah LP,string nama, string kelas, string jenis){
    adrMK P;
    P=searchMatakuliah(LP, nama, kelas, jenis);
    if(P!=NULL){
        printMatakuliah(P);
        if(jumlah(P)>0){
            adrM N=firstM(P);
            do{
                printMahasiswa(N);
                N=N->next;
            }while(N!=firstM(P));
        }
    }
}
//7
void printAll(ListMatakuliah LD){
    adrMK P=First(LD);
    cout<<endl;
    cout<<"List Matakuliah :"<<endl;
    while(P!=NULL){
        printMatakuliah(P);
        if(jumlah(P)>0){
            adrM N=firstM(P);
            do{
                printMahasiswa(N);
                N=N->next;
            }while(N!=firstM(P));
        }
        P=P->next;
    }
}

int pilihMenu(){
    int pilihan;
    string in;
    getline(cin,in);
    pilihan=stoi(in);
    return pilihan;
}

void startMenu(ListMatakuliah &LP){

    adrM N;
    adrMK P;
    string s,id;
    string nama, kelas, jenis;
    string nim;
    int menu;
    int kuota;
    do{
        system("CLS");
        cout<<"========================================="<<endl;
        cout<<"=                MENU                   ="<<endl;
        cout<<"========================================="<<endl;
        printOnlyMatakuliah(LP);
        cout<<"1. Tambah matakuliah baru"<<endl;
        cout<<"2. Tambah mahasiswa baru"<<endl;
        cout<<"3. Hapus Mahasiswa"<<endl;
        cout<<"4. Hapus matakuliah"<<endl;
        cout<<"5. Mahasiswa dalam sebuah matakuliah"<<endl;
        cout<<"6. Tampilkan seluruh detail matakuliah"<<endl;
        cout<<"7. Mencari matakuliah tertentu dengan kuota masih tersedia"<<endl;
        cout<<"8. Mencari nama mahasiswa tertentu pada sebuah matakuliah"<<endl;
        cout<<"Pilih : ";
        menu=pilihMenu();
        switch(menu){
        case 1:
            cout << "Nama matakuliah : ";
            getline(cin,nama);
            cout << "Kelas matakuliah : ";
            getline(cin,kelas);
            do{
                cout << "Jenis matakuliah(INT/REG) : ";
                getline(cin,jenis);
            }while(jenis!="INT"&&jenis!="REG");
            do{
                cout << "Kuota matakuliah : ";
                kuota=pilihMenu();
            }while(kuota<=0);

            addMatakuliah(LP,nama,kelas,kuota,jenis);
            break;
        case 2:
            cout << "Nama matakuliah : ";
            getline(cin,nama);
            cout << "Kelas matakuliah : ";
            getline(cin,kelas);
            do{
                cout << "Jenis matakuliah(INT/REG) : ";
                getline(cin,jenis);
            }while(jenis!="INT"&&jenis!="REG");
            P = searchMatakuliah(LP,nama,kelas,jenis);
            if(P!=NULL){
                printMatakuliah(P);
                cout << "Nama : ";
                getline(cin,nama);
                cout << "NIM : ";
                getline(cin,nim);
                cout << "Kelas : ";
                getline(cin,kelas);
                do{
                    cout << "Jenis(INT/REG) : ";
                    getline(cin,jenis);
                }while(jenis!="INT"&&jenis!="REG");
                addMahasiswa(LP, P,nama,nim,kelas,jenis);
            }else{
                cout << "Matakuliah belum ditambahkan" <<endl;
            }
            break;
        case 3:
            cout << "NIM/Nama mahasiswa : ";
            getline(cin,id);
            deleteMahasiswa(LP, id);
            break;
        case 4:
            cout << "Nama matakuliah : ";
            getline(cin,nama);
            cout << "Kelas matakuliah : ";
            getline(cin,kelas);
            do{
                cout << "Jenis matakuliah(INT/REG) : ";
                getline(cin,jenis);
            }while(jenis!="INT"&&jenis!="REG");
            deleteMatakuliah(LP, nama,  kelas,  jenis);
            break;
        case 5:
            cout << "Nama matakuliah : ";
            getline(cin,nama);
            cout << "Kelas matakuliah : ";
            getline(cin,kelas);
            do{
                cout << "Jenis matakuliah(INT/REG) : ";
                getline(cin,jenis);
            }while(jenis!="INT"&&jenis!="REG");
            printMatakuliahMahasiswa(LP, nama,  kelas,  jenis);
            break;
        case 6:
            printAll(LP);
            break;
        case 7:
            cout << "Nama matakuliah : ";
            getline(cin,nama);
            do{
                cout << "Jenis matakuliah(INT/REG) : ";
                getline(cin,jenis);
            }while(jenis!="INT"&&jenis!="REG");
            printMatakuliahAvailable(LP, nama, jenis);
            break;
        case 8:
            cout << "Nama matakuliah : ";
            getline(cin,nama);
            cout << "Kelas matakuliah : ";
            getline(cin,kelas);
            do{
                cout << "Jenis matakuliah(INT/REG) : ";
                getline(cin,jenis);
            }while(jenis!="INT"&&jenis!="REG");
            P = searchMatakuliah(LP,nama,kelas,jenis);
            if(P!=NULL){
                printMatakuliah(P);
                cout << "NIM/Nama mahasiswa : ";
                getline(cin,id);
                N = searchMahasiswaFromMatkul(P, id);
                if(N!=NULL){
                    printMahasiswa(N);
                }
            }else{
                cout << "Matakuliah belum ditambahkan" <<endl;
            }
            break;
        }
        cout<<endl;
        system("pause");
    }while(menu!=0);
}
