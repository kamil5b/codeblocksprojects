#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "barang.h"
#include "penjualan.h"
#include <iostream>

using namespace std;
#define first(L) L.first
#define next(P) P->next
#define linked(P) P->linked
#define jumlah(L) L.jumlah
#define toko(P) P->toko
#define barang(P) P->barang

typedef struct Relasi *addressR;
typedef string infotype;

struct Relasi{
    addressB barang;
    addressT toko;
    addressR next;
};
struct ListRelasi{
    addressR first;
};

bool isEmptyListRelasi(ListRelasi L);
void createListRelasi(ListRelasi &L);
void createRelasi(addressR &DataRelasi,addressB &barang,addressT &toko);
void insertRelasiFirst(ListRelasi &L,addressR &P);
void deleteRelasiFirst(ListRelasi &L,addressR &P);
void deleteRelasiAfter(ListRelasi &L,addressR Prec,addressR &P);
addressR searchRelasi(ListRelasi &L,infotype b,infotype t);
void printBarangToko(ListRelasi L,addressT toko);
void printBarangadadiToko(ListRelasi L,addressB barang);


#endif // RELASI_H_INCLUDED
