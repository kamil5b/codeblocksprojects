#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

/* RAFLY AHMAD YANUAR - 1301194119
   SURYA TIMUR RIZKILLAH ARYATI - 1301194441
*/

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info

// SINGLE LINKED LIST

typedef string infotype;
typedef struct elm_parent *adr_p;

struct elm_parent{
    infotype info;
    adr_p next;
};

struct list_parent{
    adr_p first, last;
};

void createList_p(list_parent &L);
adr_p alokasi_p(infotype x);
void insertFirst_p(list_parent &L, adr_p P);
void insertLast_p(list_parent &L, adr_p P);
void deleteFirst_p(list_parent &L, adr_p &P);
void deleteLast_p(list_parent &L, adr_p &P);
void deleteAfter_p(list_parent &L, adr_p Prec, adr_p &P);
adr_p searchElmn_p(list_parent L, infotype x);
void printInfo_p(list_parent L);
void hapusData_p(list_parent L, infotype x);
#endif // PARENT_H_INCLUDED
