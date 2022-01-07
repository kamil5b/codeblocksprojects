#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define linked(P) P->linked
#define nama(P) P->nama
#define next(P) P->next
#define prev(P) P->prev
#define sakit(P) P->sakit
#define pasien(P) P->pasien

using namespace std;

typedef struct Penyakit *address_penyakit;
typedef struct Sakit *address_sakit;
typedef struct Pasien *address_pasien;

struct Penyakit {
    string nama;
    int linked;
    address_penyakit next;
    address_sakit sakit; //FIRST LIST SAKIT
    address_penyakit prev;
};

struct Sakit { //SLL Relation
    address_pasien pasien;
    address_sakit next;
};

struct Pasien {
    string nama;
    int linked;
    address_pasien next;
    address_pasien prev;
};

struct ListPenyakit{ //DLL Parent
    address_penyakit first;
    address_penyakit last;
};

struct ListPasien { //CLL Child
    address_pasien first;
};

//CREATE ELEMENT
void buatPenyakit(address_penyakit &P,string nama);
void buatPasien(address_pasien &P,string nama);
void kenaSakit(address_sakit &P,address_pasien &pas);

//CREATE LIST
void buatListPenyakit(ListPenyakit &L);
void buatListPasien(ListPasien &L);

//INSERT
void mendataPenyakit(ListPenyakit &L,address_penyakit P); //insert last
void mendataPasien(ListPasien &L,address_pasien P); //insert first
void kenaPenyakit(address_penyakit &L,address_sakit &P); //insert first

//SEARCH
address_pasien cariPasien(ListPasien &L,string nama);
address_penyakit cariPenyakit(ListPenyakit &L, string nama);

//DELETE FUNCTION
void hapusPenyakit(ListPenyakit &L,address_penyakit &P); //delete penyakit
void pasienPulang(ListPasien &L,address_pasien &P,ListPenyakit Lp); //delete pasien
void sembuh(address_penyakit &L,address_sakit &P); //delete sakit

//SHOW
void liatPenyakit(address_penyakit P);
void liatPasien(address_pasien P);
void lihatPenyakitdariPasien(address_pasien P, ListPenyakit L);
void lihatPasienyangterinfeksi(address_penyakit P);

void top5Penyakit(ListPenyakit L);

void menu(ListPasien &Lpas,ListPenyakit &Lpen);

#endif // HEADER_H_INCLUDED
