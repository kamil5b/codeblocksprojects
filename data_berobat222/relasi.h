#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "child.h"
#include "parent.h"
#define first(L) L.first
#define pasien(P) P->pasien
#define penyakit(P) P->penyakit
#define next(P) P->next
//SLL

using namespace std;

typedef struct Relasi *address_r;

struct Relasi {
    address_pas pasien;
    address_pen penyakit;
    address_r next;
};

struct listRelasi {
    address_r first;
};

//CREATE ELEMENT
address_r createRelasi(address_pas pas,address_pen pen);
//CREATE LIST
void createListRelasi(listRelasi &L);
//INSERT LAST
void insertFirstRelasi(address_r &P,listRelasi &L);
//SEARCH
address_r searchRelasi(address_pas pas,address_pen pen,listRelasi L);
//DELETE RELASI
void deleteFirstRelasi(address_r &P,listRelasi &L);
void deleteMiddleLastRelasi(address_r &P,listRelasi &L);
//DELETE ELEMEN
void deleteRelasi(address_r &P,listRelasi &L);
void deletePenyakit(address_pen &P,listPenyakit &L,listRelasi &Lr);
void deletePasien(address_pas &P,listPasien &L,listRelasi &Lr);
//SHOW
void showPenyakitDariPasien(address_pas P,listRelasi L);
void showPasienTerjangkit(address_pen P,listRelasi L);
void showAllPasienBesertaPenyakitnya(listPasien Lp,listRelasi L);



#endif // RELASI_H_INCLUDED
