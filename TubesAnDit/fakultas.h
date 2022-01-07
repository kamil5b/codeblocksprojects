#ifndef FAKULTAS_H_INCLUDED
#define FAKULTAS_H_INCLUDED

#define next(p) p->next
#define prev(p) p->prev
#define info(p) p->info
#define first(L) L.first


using namespace std;

struct infotype2 {
    string fak;
    string kode;
    int jum;
};

typedef struct elmlist2 *address2;
struct elmlist2 {
    infotype2 info;
    address2 next;
};

struct List2 {
    address2 first;

};


void createList2 (List2 &L);
address2 alokasi2 (string fak, string kode);
void dealokasi2 (address2 &p);
void insertFirst2 (List2 &L, address2 p);
address2 findElm2 (List2 L, string kode);
void deleteFirst2 (List2 &L, address2 &p);
void deleteLast2 (List2 &L, address2 &p);
void deleteAfter2 (List2 &L,address2 prec, address2 &p);
void printInfo2 (List2 L);
void insertAfter2(List2 &L, address2 p,address2 prec);
void insertLast2(List2 &L, address2 p);
void InsertSort2(List2 &L, address2 P);



#endif // FAKULTAS_H_INCLUDED
