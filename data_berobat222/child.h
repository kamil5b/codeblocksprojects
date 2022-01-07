#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define linked(P) P->linked
#define info(P) P->info
#define next(P) P->next
//CLL

using namespace std;

typedef struct Pasien *address_pas;

struct Pasien {
    string info;
    int linked;
    address_pas next;
};

struct listPasien {
    address_pas first;
};

//CREATE ELEMENT
address_pas createPasien(string nama);
//CREATE LIST
void createListPasien(listPasien &L);
//INSERT LAST
void insertFirstPasien(address_pas &P,listPasien &L);
//SEARCH
address_pas searchPasien(string nama,listPasien L);
//DELETE
void deleteFirstPasien(address_pas &P,listPasien &L);
void deleteMiddleLastPasien(address_pas &P,listPasien &L);
//DELETE PASIEN DI RELASI
//SHOW
void showPasien(address_pas P);
void showAllPasien(listPasien L);

#endif // CHILD_H_INCLUDED
