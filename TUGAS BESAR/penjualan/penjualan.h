#ifndef PENJUALAN_H_INCLUDED
#define PENJUALAN_H_INCLUDED
#include <iostream>

using namespace std;
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define linked(P) P->linked
#define jumlah(L) L.jumlah
#define prev(P) P->prev
#define info(P) P->info

typedef struct Toko *addressT;
typedef string infotype;

struct Toko{
    infotype info;
    int linked;
    addressT next;
    addressT prev;
};
struct ListToko{
    int jumlah;
    addressT first;
    addressT last;
};

bool isEmptyListToko(ListToko L);
void createListToko(ListToko &L);
void createToko(addressT &DataToko);
void insertTokoLast(ListToko &L,addressT &P);
void deleteTokoFirst(ListToko &L,addressT &P);
void deleteTokoLast(ListToko &L,addressT &P);
void deleteTokoAfter(ListToko &L,addressT Prec,addressT &P);
addressT searchToko(ListToko &L,infotype x);
void printInfoToko(ListToko L);
void tokoPalingLengkap(ListToko L);



#endif // PENJUALAN_H_INCLUDED
