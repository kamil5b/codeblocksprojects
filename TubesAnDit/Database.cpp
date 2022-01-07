#include "Database.h"

//KUMPULAN FUNGSI PERINTAH

void insertKampus (List1 &LP) {
    string nama,id,alamat;
    int usia;
    cout<<"Nama Kampus\t: ";
    cin>>nama;
    cout<<"No ID\t\t: ";
    cin>>id;
    cout<<"Alamat Kampus\t: ";
    cin>>alamat;
    cout<<"Usia\t\t: ";
    cin>>usia;
    address1 p = alokasi(nama,id,usia,alamat);
    InsertSort(LP,p);
    //insertAscending(LP, nama,ttlahir,noid,alamat,usia,p);
}
void deleteKampus (List1 &LP, List_R &LR) {
    deleteKampusAsli(LR,LP);

}
void deleteFakultas (List2 &LF, List_R &LR) {
    deleteFakultasAsli(LR,LF);

}
void viewKampus (List1 LP) {
    printInfo1(LP);
}
void updateKampus (List1 &L) {
    string cari;
    printInfo1(L);
    if (first(L) != NULL){
        cout<<"ID Kampus\t: ";
    }
    cin>>cari;
    address1 p = findElm(L,cari);

    if (p != NULL) {
        cout<<"ID Kampus\t: ";
        cin>>info(p).id;
        cout<<"Nama Kampus\t: ";
        cin>>info(p).nama;
        cout<<"Usia Kampus\t: ";
        cin>>info(p).usia;
        cout<<"Alamat Kampus\t: ";
        cin>>info(p).alamat;
    }
    else {
        cout<<"Kampus dengan nomor ID "<<cari<<" tidak ditemukan"<<endl;
    }
}
void insertFakultas (List2 &LB) {
    string fak,kode;
    cout<<"Nama Fakultas : ";
    cin>>fak;
    cout<<"Kode Fakultas : ";
    cin>>kode;
    address2 p = alokasi2(fak,kode);
    InsertSort2(LB,p);
}
void updateFakultas (List2 &LB) {
    string cari;
    printInfo2(LB);
    cout<<"Kode Fakultas : ";
    cin>>cari;
    address2 p = findElm2(LB, cari);
    if (p != NULL) {
        cout<<"Nama Fakultas : ";
        cin>>info(p).fak;
        cout<<"Kode Fakultas : ";
        cin>>info(p).kode;
    }
    else {
        cout<<"Fakultas dengan kode "<<cari<<" tidak ditemukan"<<endl;
    }

}
void viewFakultas (List2 LB) {
    printInfo2(LB);
}
void insertRelasi (List1 LP, List2 LB, List_R &LR) {
    string cariID,carifak;
    cout<<"Nomor ID Kampus\t: ";
    cin>>cariID;
    cout<<"Kode Fakultas\t: ";
    cin>>carifak;
    address1 p = findElm(LP,cariID);
    address2 q = findElm2(LB,carifak);
    if ((p != NULL) && (q != NULL)) {
        address_R r = alokasi_R(p,q);
        insertFirst_R(LR,r);
    }
    else if (p != NULL) {
        cout<<"Fakultas dengan kode "<<carifak<<" tidak ada"<<endl;
    }
    else {
        cout<<"Kampus dengan Nomor ID "<<cariID<<" tidak ada"<<endl;
    }
}

void header(){
    cout << "==================================================================\n";
    cout << "/\n";
    cout << "==================================================================\n";
    cout << "Silahkan memilih diantara menu yang disediakan dibawah ini!\n";
    cout << endl;
}

void headerInsert(){
    cout << "==================================================================\n";
    cout << "/Insert\n";
    cout << "==================================================================\n";
    cout << "Silahkan memilih diantara menu yang disediakan dibawah ini!\n";
    cout << "Kategori Apa yang akan Anda masukkan?\n";
    cout << endl;
}

void headerInsertKampus(){
    cout << "==================================================================\n";
    cout << "/Insert/Kampus\n";
    cout << "==================================================================\n";
    cout << "Silahkan masukkan Data Kampus dari Opsi yang disediakan dibawah ini!\n";
    cout << endl;
    cout << "DIHARAPKAN UNTUK MENGGANTI SPASI DENGAN SIMBOL '_'\n";
    cout << endl;
}

void headerInsertFakultas(){
    cout << "==================================================================\n";
    cout << "/Insert/Fakultas\n";
    cout << "==================================================================\n";
    cout << "Silahkan masukkan Data Fakultas dari Opsi yang disediakan dibawah ini!\n";
    cout << endl;
}

void headerInsertRelasi(){
    cout << "==================================================================\n";
    cout << "/Insert/Relasi\n";
    cout << "==================================================================\n";
    cout << "Silahkan Relasikan Data dari Opsi yang disediakan dibawah ini!\n";
    cout << endl;
}

void headerDelete(){
    cout << "==================================================================\n";
    cout << "/Delete\n";
    cout << "==================================================================\n";
    cout << "Silahkan memilih diantara menu yang disediakan dibawah ini!\n";
    cout << "Kategori Apa yang akan Anda hapus?\n";
    cout << endl;
}

void headerUpdate(){
    cout << "==================================================================\n";
    cout << "/Update\n";
    cout << "==================================================================\n";
    cout << "Silahkan memilih diantara menu yang disediakan dibawah ini!\n";
    cout << "Kategori Apa yang akan Anda perbarui?\n";
    cout << endl;
}

void headerView(){
    cout << "==================================================================\n";
    cout << "/View\n";
    cout << "==================================================================\n";
    cout << "Silahkan memilih diantara menu yang disediakan dibawah ini!\n";
    cout << "Kategori Apa yang akan Anda tampilkan?\n";
    cout << endl;
}

void menus(){
    cout << " 1. Insert\t(Menambahkan)\n";
    cout << " 2. Update\t(Memperbarui)\n";
    cout << " 3. View\t(Menampilkan)\n";
    cout << " 4. Delete\t(Menghapus)\n";
    cout<<"Pilih Menu : ";
}

void menuInsert(){
    cout << " 1. Insert Kampus\n";
    cout << " 2. Insert Fakultas\n";
    cout << " 3. Insert Relasi\n";
    cout << "Pilih Menu : ";
}

void menuUpdate(){
    cout << " 1. Update Data Kampus\n";
    cout << " 2. Update Data Fakultas\n";
    cout << "Pilih Menu : ";
}

void menuView(){
    cout << " 1. View Data Kampus\n";
    cout << " 2. View Data Fakultas\n";
    cout << " 3. View Data Relasi Keseluruhan\n";
    cout << " 4. View Data Kampus dengan Fakultas Tertentu\n";
    cout << " 5. View Data Fakultas yang Dimiliki Kampus Tertentu\n";
    cout << " 6. View Data Fakultas yang Paling Banyak Direlasikan\n";
    cout << " 7. View Data Fakultas yang Paling Sedikit Direlasikan\n";
    cout << "Pilih Menu : ";
}

void menuDelete(){
    cout << " 1. Delete Data Kampus\n";
    cout << " 2. Delete Data Fakultas\n";
    cout << "Pilih Menu : ";
}
