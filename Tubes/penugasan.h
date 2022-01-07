#ifndef PENUGASAN_H_INCLUDED
#define PENUGASAN_H_INCLUDED
#define next(P) P->next
#define prog(P) P->prog
#define proj(P) P->proj
#define tugas(P) P->tugas
#define status(P) P->status

#include <iostream>
#include "project.h"
#include "programmer.h"

using namespace std;

typedef struct elmlist_penugasan * address_penugasan;

//SLL

struct elmlist_penugasan{
    address_programmer prog;
    address_project proj;
    string status;
    string tugas;
    address_penugasan next;
};

struct list_penugasan{
    address_penugasan first;
    address_penugasan last;
};

void createListPenugasan (list_penugasan &L);
address_penugasan createElmPenugasan (address_programmer prog,address_project proj,string status, string tugas);
void insertFirstPenugasan (list_penugasan &L, address_penugasan &P); //CONNECT
void deletePenugasan (list_penugasan &L, address_penugasan &P); //DISCONNECT
void deletePenugasanProgrammer(list_penugasan &L, address_programmer P);
void deletePenugasanProject(list_penugasan &L, address_project P);
address_penugasan searchPenugasan (list_penugasan L, address_programmer prog,address_project proj);
void ubahStatus(list_penugasan &L, address_penugasan &P);
void alihTugas(list_penugasan &L, address_penugasan &P);
void viewProjectsProgrammer(address_project P, list_penugasan L);
void viewProgrammersProject(address_programmer P,list_penugasan L);
void viewAllProjectandProgrammer (list_project Lpro,list_penugasan Lpen);
void viewAllProgrammerandProject (list_programmer Lpro,list_penugasan Lpen);



#endif // PENUGASAN_H_INCLUDED
