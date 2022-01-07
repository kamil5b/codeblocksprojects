#ifndef JURI_H_INCLUDED
#define JURI_H_INCLUDED

#include <iostream>
#define next(p) p->next
#define info(p) p->info
#define first(L) L.first

using namespace std;

struct Juri {
    string username;
    string nama;
    int umur;
    string password;
};

typedef struct elmJuri *addressJ;

struct elmJuri {
    Juri info;
    addressJ next;
};

struct ListJuri {
    addressJ first;
};

void createListJuri (ListJuri &L);
addressJ alokasiJuri (string username, string nama, int usia, string password);
void dealokasiJuri (addressJ &p);
void insertFirstJuri(ListJuri &L, addressJ p);
void insertBeforeJuri (ListJuri &L, addressJ Prec,addressJ p);
void insertLastJuri (ListJuri &L, addressJ p);
void insertJuri (ListJuri &L, addressJ &p);
addressJ findElmJuri (ListJuri L, string username);
void updateJuri(ListJuri L, string id);
void deleteFirstJuri (ListJuri &L, addressJ &p);
void deleteMiddleLastJuri (ListJuri &L, addressJ &p);
void printJuri (addressJ p);
void printAllJuri (ListJuri L);

#endif // JURI_H_INCLUDED
