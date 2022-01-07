#ifndef KAMPUS_H_INCLUDED
#define KAMPUS_H_INCLUDED

#define next(p) p->next
#define prev(p) p->prev
#define info(p) p->info
#define first(L) L.first
#define last(L) L.last

using namespace std;

struct infotype {
    string nama;
    string id;
    int usia;
    string alamat;
};

typedef struct elmlist1 *address1;

struct elmlist1 {
    infotype info;
    address1 next;
    address1 prev;
};

struct List1 {
    address1 first;
    address1 last;
};

void createList1 (List1 &L);
address1 alokasi (string nama, string id, int usia, string alamat);
void dealokasi (address1 &p);
void insertFirst (List1 &L, address1 p);
void insertAfter (List1 &L, address1 prec, address1 p);
void insertLast (List1 &L, address1 p);
address1 findElm (List1 L, string id);
void deleteFirst (List1 &L, address1 &p);
void deleteAfter (List1 &L,address1 prec, address1 &p);
void deleteLast (List1 &L, address1 &p);
void printInfo1 (List1 L);
bool isEmpty(List1 &L);
void deletekampus1(List1 &L,address1 &P,int &i);
void InsertSort(List1 &L, address1 P);
#endif // KAMPUS_H_INCLUDED
