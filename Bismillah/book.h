#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#define NIL NULL
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev
#define linked(P) P->linked
#include <iostream>

using namespace std;

typedef struct elmBuku *addressB;

struct Buku{
    string Judul, Penerbit, Penulis;
    int Tahun, ID;
};

struct elmBuku{
    Buku info;
    int linked;
    addressB next;
    addressB prev;
};

struct ListBuku{
    addressB First;
    addressB Last;
};

void createListBuku(ListBuku &L);
void createNewElmt(Buku X, addressB &P);
addressB createNewElmtBuku(string Judul, string Penerbit, string Penulis, int Tahun, int ID);
void insertBukuFirst(ListBuku &L, addressB P);
void insertBukuAfter(ListBuku &L, addressB Prec, addressB P);
void insertBukuLast(ListBuku &L, addressB P);
void deleteBukuFirst(ListBuku &L, addressB &P);
void deleteBukuAfter(ListBuku &L, addressB Prec, addressB &P);
void deleteBukuLast(ListBuku &L, addressB P);
addressB SearchBuku(ListBuku L, string judul);
void showBuku(ListBuku L);
void SortTahunDesc(ListBuku &L, addressB P);
void favBuku(ListBuku L);


#endif // BOOK_H_INCLUDEDD
