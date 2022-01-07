#include <iostream>
#include "book.h"
#include "relasi.h"
#include "peminjam.h"
using namespace std;

int main(){
    ListBuku L;
    ListPeminjam Lp;
    ListRelasi Lr;
    createListPeminjam(Lp);
    createListRelasi(Lr);
    createListBuku(L);
    addressB P;
    addressB S;
    addressP Q;
    addressR R;


    int bil;

    Buku B;
    B.Judul = "Nanti Kita cerita tentang hari ini (NKCTHI)";
    B.Penerbit = "Gramedia";
    B.Penulis = "Marchella Febritrisia Putri";
    B.Tahun = 2018;
    B.ID = 1;
    createNewElmt(B,P);
    insertBukuFirst(L,P);

    cout<<endl;
    B.Judul = "Kamu terlalu banyak bercanda";
    B.Penerbit = "Gramedia";
    B.Penulis = "Marchella Febritrisia Putri";
    B.Tahun = 2019;
    B.ID = 2;
    createNewElmt(B,P);
    insertBukuFirst(L,P);

    B.Judul = "Bumi manusia";
    B.Penerbit = "Hasta Mitra";
    B.Penulis = "Pramoedya Ananta Toer";
    B.Tahun = 1980;
    B.ID = 3;
    createNewElmt(B,P);
    insertBukuLast(L,P);

    Q=createNewElmtPeminjam("Dimas Anggara");
    insertPeminjamFirst(Lp,Q);
    Q=createNewElmtPeminjam("Pandu Prawidanu");
    insertPeminjamLast(Lp,Q);

    //Menu
    do{
        cout<<"________________"<<endl;
        cout<<"Menu : "<<endl;
        cout<<"1. Buku baru"<<endl;
        cout<<"2. Member baru"<<endl;
        cout<<"3. Pinjam buku"<<endl;
        cout<<"4. Hapus data buku"<<endl;
        cout<<"5. Hapus data peminjam"<<endl;
        cout<<"6. Tampilkan Buku yang ada"<<endl;
        cout<<"7. Lihat Buku yang dipinjam"<<endl;
        cout<<"8. Lihat Member yang meminjam buku"<<endl;
        cout<<"9. Lihat Buku terfavorit dan tidak favorit"<<endl;
        cout<<"10. Urutkan data terbit buku secara descending"<<endl;
        cout<<"11. Keluar"<<endl;
        cout<<"Masukkan Pilihan : ";
        cin>>bil;
        switch(bil)
        {
            case 1 :{
                string uJudul;
                string uPenerbit;
                string uPenulis;
                int uTahun;
                int uID;
                cout << "Judul buku : ";
                getline(cin,uJudul);
                getline(cin,uJudul);
                cout << "Penerbit : ";
                getline(cin,uPenerbit);
                cout << "Penulis : ";
                getline(cin,uPenulis);
                cout << "Tahun : ";
                cin >> uTahun;
                cout << "ID Buku : ";
                cin >> uID;

                S = createNewElmtBuku(uJudul,uPenerbit,uPenulis,uTahun,uID);
                SortTahunDesc(L, S);
                showBuku(L);
                }break;
            case 2 :{
                string nama;
                cout << "Nama : ";
                getline(cin,nama);
                getline(cin,nama);
                Q=createNewElmtPeminjam(nama);
                insertPeminjamLast(Lp,Q);
                }break;
            case 3 :{
                string nama,judul;
                cout << "Nama member : ";
                getline(cin,nama);
                getline(cin,nama);
                Q=SearchPeminjam(Lp,nama);
                if(Q!=NULL){
                    cout << "Judul buku : ";
                    getline(cin,judul);
                    P=SearchBuku(L,judul);
                    if(P!=NULL){
                        R=createNewElmtRelasi(P,Q);
                        insertRelasiLast(Lr,R);
                        cout << nama << " Berhasil meminjam buku " << judul << endl;
                    }else{
                        cout << "Judul buku tidak ada" << endl;
                    }
                }else{
                    cout << "Tidak ada nama member itu" << endl;
                }
                }break;
            case 4 :{
                string judul;
                addressR tempR,Rn;
                addressB tempB;
                cout << "Judul buku yang akan di hapus : ";
                getline(cin,judul);
                getline(cin,judul);
                P=SearchBuku(L,judul);
                if(P!=NULL){
                    if(P==First(L)){
                        deleteBukuFirst(L,P);
                    }else if(P==Last(L)){
                        deleteBukuLast(L,P);
                    }else{
                        tempB=First(L);
                        while(tempB!=NULL&&next(tempB)!=P){
                            tempB=next(tempB);
                        }
                        deleteBukuAfter(L,tempB,P);
                    }
                    R=First(Lr);
                    while(R!=NULL){
                        if(buku(R)==P){
                            Rn=next(R);
                            if(R==First(Lr)){
                                deleteRelasiFirst(Lr,R);
                            }else{
                                tempR=First(Lr);
                                while(next(tempR)!=R){
                                    tempR=next(tempR);
                                }
                                deleteRelasiAfter(Lr,tempR,R);
                            }
                            R=Rn;
                        }else{
                            R=next(R);
                        }
                    }
                }
                }break;
            case 5 :{
                string nama;
                addressR tempR,Rn;
                addressP tempB;
                cout << "nama buku yang akan di hapus : ";
                getline(cin,nama);
                getline(cin,nama);
                Q=SearchPeminjam(Lp,nama);
                if(Q!=NULL){
                    if(Q==First(Lp)){
                        deletePeminjamFirst(Lp,Q);
                    }else{
                        tempB=First(Lp);
                        while(tempB!=NULL&&next(tempB)!=Q){
                            tempB=next(tempB);
                        }
                        deletePeminjamAfter(Lp,tempB,Q);
                    }
                    R=First(Lr);
                    while(R!=NULL){
                        if(peminjam(R)==Q){
                            Rn=next(R);
                            if(R==First(Lr)){
                                deleteRelasiFirst(Lr,R);
                            }else{
                                tempR=First(Lr);
                                while(next(tempR)!=R){
                                    tempR=next(tempR);
                                }
                                deleteRelasiAfter(Lr,tempR,R);
                            }
                            R=Rn;
                        }else{
                            R=next(R);
                        }
                    }
                }
                }break;
            case 6 :{
                showBuku(L);
                }break;
            case 7 :{
                string nama;
                cout << "Nama member : ";
                getline(cin,nama);
                getline(cin,nama);
                Q=SearchPeminjam(Lp,nama);
                if(Q!=NULL){
                    showPeminjamBuku(Lr,Q);
                }else{
                    cout << "Nama member tidak terdaftar" << endl;
                }
                }break;
            case 8 :{
                string judul;
                cout << "Judul Buku : ";
                getline(cin,judul);
                getline(cin,judul);
                P=SearchBuku(L,judul);
                if(P!=NULL){
                    showBukuDipinjam(Lr,P);
                }else{
                    cout << "Judul buku tidak terdaftar" <<endl;
                }
                }break;
            case 9 :{
                favBuku(L);
                }break;
            case 10:{
                SortTahunDesc(L, S);
                showBuku(L);
                }break;
            }
    }while (bil != 11);

    return 0;
}
