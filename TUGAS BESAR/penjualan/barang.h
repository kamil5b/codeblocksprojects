#ifndef BARANG_H_INCLUDED
#define BARANG_H_INCLUDED
#include <iostream>

using namespace std;
#define first(L) L.first
#define next(P) P->next
#define linked(P) P->linked
#define jumlah(L) L.jumlah
#define info(P) P->info

typedef struct Barang *addressB;
typedef string infotype;

struct Barang{
    infotype info;
    int linked;
    addressB next; //CLL
};
struct ListBarang{
    int jumlah;
    addressB first;
};

bool isEmptyListBarang(ListBarang L);
void createListBarang(ListBarang &L);
void createBarang(addressB &DataBarang);
void insertBarangFirst(ListBarang &L,addressB &P);
void deleteBarangFirst(ListBarang &L,addressB &P);
void deleteBarangAfter(ListBarang &L,addressB Prec,addressB &P);
addressB searchBarang(ListBarang &L,infotype x);
void printInfoBarang(ListBarang L);




#endif // BARANG_H_INCLUDED
