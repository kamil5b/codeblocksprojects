#ifndef JALANKOTA_H_INCLUDED
#define JALANKOTA_H_INCLUDED

#define nama(P) P->nama
#define jalan(P) P->jalan
#define kota(P) P->kota
#define tipe(P) P->tipe
#include <iostream>

using namespace std;
typedef struct Kota *addresskota;
typedef struct Jalan *addressjalan;
typedef struct Relasi *addressrelasi;
struct Kota{
    string nama;
    int jalan;
    addresskota next;
};

struct ListKota{
    //SLL
    addresskota first;
};

struct Jalan{
    string nama;
    string tipe;
    int kota;
    addressjalan next;
};

struct ListJalan{
    //CIRCULAR
    addressjalan first,last;
};

struct Relasi{
    addresskota kota;
    addressjalan jalan;
    addressrelasi next, prev;
};
struct ListRelasi{
    //DLL
    addressrelasi first,last;
};

void createList(ListRelasi &LR,ListKota &LK,ListJalan &LJ);

addresskota createKota(string nama);
addressjalan createJalan(string nama, string tipe);
addressrelasi createRelasi(addresskota &k, addressjalan &j);

//a. Penambahan data kota
void addKota(ListKota &LK, string nama);
//b. Penambahan data jalan
void addJalan(ListJalan &LJ, string nama, string tipe);
//c. Penentuan relasi kota dan jalan
void connect(ListRelasi &LR, addresskota &k, addressjalan &j);

addresskota findKota(ListKota LK,string nama);
addressjalan findJalan(ListJalan LJ,string nama);
addressrelasi findRelasi(ListRelasi LR, addresskota k, addressjalan j);
//d. Menghapus data kota
void deleteKota(ListKota &LK,ListRelasi &LR,string nama);
//e. Menghapus data jalan
void deleteJalan(ListJalan &LJ,ListRelasi &LR,string nama);
void disconnect(ListRelasi &LR,addressrelasi &r);
//f. Menampilkan data keselurahan kota beserta jalan terdapat di kota tersebut
void printAll(ListRelasi LR,ListKota LK);
//g. Menampilkan data kota yang memiliki nama jalan tertentu
void kotaPunyaJalan(ListRelasi LR,ListJalan LJ,string nama);
//h. Menampilkan data jalan yang dimiliki suatu kota tertentu
void jalanKota(ListRelasi LR,ListKota LK,string nama);
//i. Menampilkan data kota dan nama jalan yang memilki tipe jalan tertentu
void tipeJalanKota(ListRelasi LR,ListJalan LJ,string tipe);

#endif // JALANKOTA_H_INCLUDED
