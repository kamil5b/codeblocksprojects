#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

#define first(L) L.first
#define last(L) L.last
#define users(G) G.users
#define harga(G) G.harga
#define nama(G) G.nama
#define id(G) G.id

using namespace std;

typedef struct games *g_address;

struct infotypeG{
    string nama,id;
    int users,harga;
};

struct games {
    infotypeG info;
    g_address next;
    g_address prev;
};

struct listgames {
    g_address first;
    g_address last;
};

void createListgames(listgames &L);

g_address creategames(infotypeG info);

void insertgames(g_address &P, listgames &L);

void deletegames(g_address &P,listgames &L);

g_address searchgames (string kode,listgames &L);

void showGames(g_address P);

void showAllGames(listgames L);

#endif // PARENT_H_INCLUDED
