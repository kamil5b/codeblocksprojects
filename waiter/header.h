#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;
typedef struct Waiter *address_waiter;
typedef struct Guest *address_tamu;
typedef struct Relation *address_rel;
struct Guest{
    string nama;
    int waiter;
    address_tamu next;
};

struct ListGuest{
    //CIRCULLAR
    address_tamu first,last;
};

struct Waiter{
    string nama;
    int tamu;
    address_rel firstRelation;
    address_waiter next,prev;
};

struct ListWaiter{
    //DLL
    address_waiter first,last;
};

struct Relation{
    //SLL
    address_tamu keGuest;
    address_rel next;
};

void createLists(ListGuest &LT, ListWaiter &LW);

address_tamu createGuest(string nama);
address_waiter createWaiter(string nama);
address_rel createRelation(address_tamu T);

//A
void tamuMasuk(ListGuest &L, string nama);
//B
void recruitWaiter(ListWaiter &L, string nama);
//C
void waiterMelayaniGuest(address_waiter &W, address_tamu T);

address_tamu findGuest(ListGuest L, string nama);
address_waiter findWaiter(ListWaiter L, string name);

//D
void deleteWaiter(ListWaiter &LW, string nama);
//E
void deleteGuest(ListWaiter &LW, ListGuest &LT, string nama);

void printAll(ListWaiter LW, ListGuest LT);
//F
void waiterGabut(ListWaiter LW);
//G
void printGuestWaiter(ListWaiter LW,string name);
//H
void waiterAktif(ListWaiter LW);
//I
void tamuSpesial(ListGuest LT, ListWaiter LW);

#endif // HEADER_H_INCLUDED
