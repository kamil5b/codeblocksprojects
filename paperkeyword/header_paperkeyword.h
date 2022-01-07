#ifndef HEADER_PAPERKEYWORD_H_INCLUDED
#define HEADER_PAPERKEYWORD_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define p(R) R->p
#define k(R) R->k

#define first(L) L.first
#define last(L) L.last

using namespace std;

typedef struct paper *p_address;
typedef struct keyword *k_address;
typedef struct relation *r_address;

struct paper {
    string info;
    p_address next;
    p_address prev;
};

struct keyword {
    string info;
    k_address next;
    k_address prev;
};

struct relation {
    p_address p;
    k_address k;
    r_address next;
    r_address prev;
};

struct listPaper {
    p_address first;
    p_address last;
};

struct listKeyword {
    k_address first;
    k_address last;
};
struct listRelation {
    r_address first;
    r_address last;
};

void createList(listKeyword &Lk, listPaper &Lp, listRelation &Lr);

p_address createPaper(string title);
k_address createKeyword(string key);
r_address createRelation(p_address &P,k_address &K);

void insertPaper(p_address &P, listPaper &Lp);
void insertKeyword(k_address &K, listKeyword &Lk);
void insertRelation(r_address &R, listRelation &Lr);

void deletePaper(p_address &P,listPaper &Lp,listRelation &Lr);
void deleteKeyword(k_address &K,listKeyword &Lk,listRelation &Lr);
void deleteRelation(r_address &R,listRelation &Lr);

p_address searchPaper (string title,listPaper &Lp);
k_address searchKeyword (string key,listKeyword &Lk);

void showKeyword(k_address K,listRelation Lr);
void showPaper(p_address P,listRelation Lr);
void popularKeyword(listKeyword Lk,listRelation Lr);


#endif // HEADER_PAPERKEYWORD_H_INCLUDED
