#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

/* RAFLY AHMAD YANUAR - 1301194119
   SURYA TIMUR RIZKILLAH ARYATI - 1301194441
*/

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(C) C->next
#define prev(C) C->prev
#define info(C) C->info

// CIRCULAR DOUBLE LINKED LIST
typedef struct elm_child *adr_c;
struct data_jalan{
    string nama, tipe;
};
struct elm_child{
    data_jalan info;
    adr_c next, prev;
};
struct list_child{
    adr_c first, last;
};
void createList_c(list_child &L);
adr_c alokasi_c(string nama, string tipe);
void insertFirst_c(list_child &L, adr_c C);
void insertLast_c(list_child &L, adr_c C);
void deleteFirst_c(list_child &L, adr_c &C);
void deleteLast_c(list_child &L, adr_c &C);
void deleteAfter_c(list_child &L, adr_c Prec, adr_c &C);
adr_c searchElmn_c(list_child L, string nama);
void printInfo_c(list_child L);
void hapusData_c(list_child L, string nama);



#endif // CHILD_H_INCLUDED
