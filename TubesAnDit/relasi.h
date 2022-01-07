#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED


#include <iostream>
#include "kampus.h"
#include "fakultas.h"


using namespace std;

struct infotype_R {
    address1 e1;
    address2 e2;
};

typedef struct elmlist_R *address_R;

struct elmlist_R {
    infotype_R info;
    address_R next;
};

struct List_R {
    address_R first;
};


void createList_R (List_R &L);
address_R alokasi_R (address1 p, address2 q);
void dealokasi_R (address_R &p);
void insertLast_R (List_R &L, address_R p);
void insertFirst_R (List_R &L, address_R p);
address_R findElm_R (List_R L, infotype_R x);
void deleteFirst_R (List_R &L, address_R &p);
void deleteLast_R (List_R &L, address_R &p);
void deleteAfter_R (List_R &L,address_R prec, address_R &p);
void deleteKampusById (List_R &LR, List1 &LP, string noktp);
void deleteKampusAsli (List_R &LR, List1 &LP);
void deleteFakultasAsli (List_R &LR, List2 &LF);
void printInfoRelasiAll(List_R L);
void printInfoRelasiKampus(List_R L);
void printInfoRelasiFakultas(List_R L);
void deleteRelasiK (List1 &LP, List_R &LR, string inputID);
void deleteRelasiF (List2 &LF, List_R &LR, string inputCode);
#endif // RELASI_H_INCLUDED
