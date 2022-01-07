#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#include <iostream>

using namespace std;

typedef string infotype_project;
typedef struct elmlist_project*address_project;
struct elmlist_project{
    infotype_project info;
    address_project next;
    address_project prev;
};

struct list_project{
    address_project first;
};

void createListProject (list_project &L);
address_project createElmProject (infotype_project data);
void insertLastProject (list_project &L, address_project &P);
void viewProject (list_project L);
void deleteProject (list_project &L, address_project &P);
void ubahProject (list_project L, infotype_project cari);
address_project searchProject(list_project L, infotype_project cari);


#endif // PROJECT_H_INCLUDED
