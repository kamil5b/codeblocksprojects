#ifndef PEMINJAM_H_INCLUDED
#define PEMINJAM_H_INCLUDED

#define NIL NULL
#define First(L) L.First
#define Last(L) L.Last
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev
#define linked(P) P->linked
#include <iostream>

using namespace std;

typedef struct elmPeminjam *addressP;

struct elmPeminjam{
    string info; //nama
    int linked;
    addressP next;
    addressP prev;
};

struct ListPeminjam{
    addressP First;
    addressP Last;
};

void createListPeminjam(ListPeminjam &L);
addressP createNewElmtPeminjam(string nama);
void insertPeminjamFirst(ListPeminjam &L, addressP P);
void insertPeminjamAfter(ListPeminjam &L, addressP Prec, addressP P);
void insertPeminjamLast(ListPeminjam &L, addressP P);
void deletePeminjamFirst(ListPeminjam &L, addressP &P);
void deletePeminjamAfter(ListPeminjam &L, addressP Prec, addressP &P);
void deletePeminjamLast(ListPeminjam &L, addressP P);
addressP SearchPeminjam(ListPeminjam L, string nama);
void showPeminjam(ListPeminjam L);

#endif // PEMINJAM_H_INCLUDED
