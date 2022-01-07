#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

/* RAFLY AHMAD YANUAR - 1301194119
   SURYA TIMUR RIZKILLAH ARYATI - 1301194441
*/

#include "PARENT.h"
#include "CHILD.h"
#include <iostream>
using namespace std;

#define parent(R) R->parent
#define child(R) R->child

// DOUBLE LINKED LIST

typedef struct elm_relasi *adr_r;
struct elm_relasi{
    adr_r next, prev;
    adr_p parent;
    adr_c child;
};
struct list_relasi{
    adr_r first, last;
};

void createList_r(list_relasi &L);
adr_r alokasi_r(adr_p P, adr_c C);
void insertFirst_r(list_relasi &L, adr_r R);
void insertLast_r(list_relasi &L, adr_r R);
void deleteFirst_r(list_relasi &L, adr_r &R);
void deleteLast_r(list_relasi &L, adr_r &R);
void deleteAfter_r(list_relasi &L, adr_r Prec, adr_r &R);
adr_r searchElmn_r(list_relasi L, adr_p P, adr_c C);
void printInfo_r(list_relasi L);
void cariRelasiJalan(list_relasi L, string jalan);
void cariRelasiKota(list_relasi L, string kota);
void cariTipe(list_relasi L, string tipe);



#endif // RELASI_H_INCLUDED
