#include "HEADER.h"


/* RAFLY AHMAD YANUAR - 1301194119
   SURYA TIMUR RIZKILLAH ARYATI - 1301194441
*/

list_child Lc;
list_parent Lp;
list_relasi Lr;

void MENU(){
    int pilihan;

    do{
        cout<<"  ========================================================"<<endl;
        cout<<"         D A T A    J A L A N    P E R K O T A A N        "<<endl;
        cout<<"  ========================================================"<<endl;
        cout<<"  =======================  M E N U  ======================"<<endl;
        cout<<"    [1]  Tambahkan Data Kota                         [1]  "<<endl;
        cout<<"    [2]  Tambahkan Data Jalan                        [2]  "<<endl;
        cout<<"    [3]  Relasikan Kota - Jalan                      [3]  "<<endl;
        cout<<"    [4]  Relasikan Jalan - Kota                      [4]  "<<endl;
        cout<<"    [5]  Hapus Data Kota                             [5]  "<<endl;
        cout<<"    [6]  Hapus Data Jalan                            [6]  "<<endl;
        cout<<"    [7]  Tampilkan Semua Data Kota Dan Jalan         [7]  "<<endl;
        cout<<"    [8]  Tampilkan Data Kota Berdasarkan Nama Jalan  [8]  "<<endl;
        cout<<"    [9]  Tampilkan Data Jalan Berdasarkan Nama Kota  [9]  "<<endl;
        cout<<"    [10] Tampilkan Data Berdasarkan Tipe Jalan      [10]  "<<endl<<endl;
        cout<<"    [0]  EXIT PROGRAM                                [0]  "<<endl;
        cout<<"  ========================================================"<<endl;
        cout<<"  Masukan Pilihan : ";
        cin>>pilihan;

        switch(pilihan){
            case 1: insert_parent();break;
            case 2: insert_child();break;
            case 3: relasikan_PC();break;
            case 4: relasikan_CP();break;
            case 5: delete_parent();break;
            case 6: delete_child();break;
            case 7: viewAll();break;
            case 8: searchView_child();break;
            case 9: searchView_parent();break;;
            case 10: searchView_Tipe();break;
            case 0: close();break;
            default :
                cout<<"  WRONG INPUT!  "<<endl;break;
        }
        cout<<"  Tekan Enter...  ";
        getch();
        cout<<endl;
        system("cls");
    }while(pilihan != 0);
};
void insert_parent(){
    system("cls");
    string namaKota;
    adr_p P;
    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Kota: ";
    cin>>namaKota;

    P = alokasi_p(namaKota);
    insertLast_p(Lp, P);

    cout<<endl<<"  ========================================================"<<endl;
    cout<<"  Sukses! Data Berhasil Ditambahkan  "<<endl;
    cout<<"  ========================================================"<<endl;

};

void insert_child(){
    system("cls");
    string nama, tipe;
    adr_c C;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Jalan: ";
    cin>>nama;
    cout<<"  Masukan Tipe Jalan: ";
    cin>>tipe;

    C = alokasi_c(nama, tipe);
    insertLast_c(Lc, C);

    cout<<endl<<"  ========================================================"<<endl;
    cout<<"  Sukses! Data Berhasil Ditambahkan  "<<endl;
    cout<<"  ========================================================"<<endl;
};

void relasikan_PC(){
    system("cls");
    adr_c C;
    adr_p P;
    adr_r R;
    string kota, jalan;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Kota : ";
    cin>>kota;
    cout<<"  Masukan Nama Jalan: ";
    cin>>jalan;

    C = searchElmn_c(Lc, jalan);
    P = searchElmn_p(Lp, kota);
    cout<<endl<<"  ========================================================"<<endl;
    if(C == NULL || P == NULL){
        if(C == NULL){
            cout<<"  Nama Jalan Tidak Ditemukan!  "<<endl;
        }
        if(P == NULL){
            cout<<"  Nama Kota Tidak Ditemukan!  "<<endl;
        }
    } else {
        R = alokasi_r(P, C);
        insertLast_r(Lr, R);

        cout<<"  Sukses! Data Berhasil Di Relasikan  "<<endl;
    }
    cout<<"  ========================================================"<<endl;
};

void relasikan_CP(){
    system("cls");
    adr_c C;
    adr_p P;
    adr_r R;
    string kota, jalan;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Jalan : ";
    cin>>jalan;
    cout<<"  Masukan Nama Kota: ";
    cin>>kota;

    C = searchElmn_c(Lc, jalan);
    P = searchElmn_p(Lp, kota);

    cout<<endl<<"  ========================================================"<<endl;
    if(C == NULL || P == NULL){
        if(C == NULL){
            cout<<"  Nama Jalan Tidak Ditemukan!  "<<endl;
        }
        if(P == NULL){
            cout<<"  Nama Kota Tidak Ditemukan!  "<<endl;
        }
    } else {
        R = alokasi_r(P, C);
        insertLast_r(Lr, R);

        cout<<"  Sukses! Data Berhasil Di Relasikan  "<<endl;
    }
    cout<<"  ========================================================"<<endl;
};

void delete_parent(){
    system("cls");
    string kota;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Kota Yang Akan Dihapus: ";
    cin>>kota;

    cout<<endl<<"  ========================================================"<<endl;

    hapusData_p(Lp, kota);

    cout<<"  ========================================================"<<endl;

};
void delete_child(){
    system("cls");
    string jalan;


    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Jalan Yang Akan Dihapus: ";
    cin>>jalan;
    cout<<endl<<"  ========================================================"<<endl;
    hapusData_c(Lc, jalan);

    cout<<"  ========================================================"<<endl;
};
void viewAll(){
    system("cls");
    cout<<endl<<"  ========================================================"<<endl;
    printInfo_r(Lr);
    cout<<endl<<"  ========================================================"<<endl;
};
void searchView_child(){
    system("cls");
    string jalan;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Jalan: ";
    cin>>jalan;

    cout<<endl<<"  ========================================================"<<endl;
    cariRelasiJalan(Lr, jalan);
    cout<<"  ========================================================"<<endl;
};
void searchView_parent(){
    system("cls");
    string kota;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Kota: ";
    cin>>kota;

    cout<<endl<<"  ========================================================"<<endl;
    cariRelasiKota(Lr, kota);
    cout<<"  ========================================================"<<endl;
};

void searchView_Tipe(){
    system("cls");
    string tipe;

    cout<<"  ========================================================"<<endl;
    cout<<endl<<"  Masukan Nama Tipe: ";
    cin>>tipe;
    cout<<endl<<"  ========================================================"<<endl;
    cariTipe(Lr, tipe);
    cout<<"  ========================================================"<<endl;
};
void close(){
    system("cls");
    cout<<endl<<"  +======================================================+"<<endl;
    cout<<endl<<"  ||               A N D A   K E L U A R                ||"<<endl;
    cout<<endl<<"  |======================================================|"<<endl;
    cout<<endl<<"  ||              	PROGRAM SUCCES		                 ||"<<endl;
    cout<<endl<<"  +======================================================+"<<endl;
    exit(0);
};
int main(){

    createList_c(Lc);
    createList_p(Lp);
    createList_r(Lr);

    MENU();

    return 0;
}
