#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#define NIL NULL
#define First(L) ((L).First)
#define next(P) P->next
#define buku(P) P->buku
#define peminjam(P) P->peminjam
#include <iostream>
#include "book.h"
#include "peminjam.h"

using namespace std;

typedef struct elmRelasi *addressR;

struct elmRelasi{
    addressB buku;
    addressP peminjam;
    addressR next;
};

struct ListRelasi{
    addressR First;
};

void createListRelasi(ListRelasi &L);
addressR createNewElmtRelasi(addressB &B,addressP &P);
void insertRelasiFirst(ListRelasi &L, addressR P);
void insertRelasiAfter(ListRelasi &L, addressR Prec, addressR P);
void insertRelasiLast(ListRelasi &L, addressR P);
void deleteRelasiFirst(ListRelasi &L, addressR &P);
void deleteRelasiAfter(ListRelasi &L, addressR Prec, addressR &P);
void showPeminjamBuku(ListRelasi L, addressP P);
void showBukuDipinjam(ListRelasi L,addressB P);


#endif // RELASI_H_INCLUDED
