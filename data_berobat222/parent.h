#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define linked(P) P->linked
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
//DLL

using namespace std;

typedef struct Penyakit *address_pen;

struct Penyakit {
    string info;
    int linked;
    address_pen next;
    address_pen prev;
};

struct listPenyakit {
    address_pen first;
    address_pen last;
};

//CREATE ELEMENT
address_pen createPenyakit(string nama);
//CREATE LIST
void createListPenyakit(listPenyakit &L);
//INSERT LAST
void insertLastPenyakit(address_pen &P,listPenyakit &L);
//SEARCH
address_pen searchPenyakit(string nama,listPenyakit L);
//DELETE
void deleteFirstPenyakit(address_pen &P,listPenyakit &L);
void deleteLastPenyakit(address_pen &P,listPenyakit &L);
void deleteMiddlePenyakit(address_pen &P,listPenyakit &L);
//DELETE PENYAKIT DI RELASI
//SHOW
void showPenyakit(address_pen P);
void showAllPenyakit(listPenyakit L);
void top5Penyakit(listPenyakit &L);

#endif // PARENT_H_INCLUDED
