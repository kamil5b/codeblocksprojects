#ifndef PROGRAMMER_H_INCLUDED
#define PROGRAMMER_H_INCLUDED
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#include <iostream>

using namespace std;

typedef string infotype_programmer;
typedef struct elmlist_programmer*address_programmer;

struct elmlist_programmer{
    infotype_programmer info;
    address_programmer next;
    address_programmer prev;
};

struct list_programmer{
    address_programmer first;
};

void createListProgram (list_programmer &L);
address_programmer createElmProgram (infotype_programmer data);
void insertLastProgram (address_programmer &P, list_programmer &L);
void viewProgram (list_programmer L);
void deleteProgram (list_programmer &L, address_programmer &P);
void ubahProgram (list_programmer L, infotype_programmer cari);
address_programmer searchProgram (list_programmer L, infotype_programmer cari);


#endif // PROGRAMMER_H_INCLUDED
