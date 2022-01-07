#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <iostream>

using namespace std;
typedef struct Director *adrD;
typedef struct Film *adrF;
typedef struct Bridge *adrB;
struct Director{
    string nama;
    int film;
    adrD next;
};

struct ListDirector{
    //SLL
    adrD first;
};

struct Film{
    string filmName;
    string genre;
    adrF next;
};

struct ListFilm{
    //CIRCULAR
    adrF first,last;
};

struct Bridge{
    adrD sutradara,astrada;
    adrF film;
    adrB next, prev;
};
struct ListBridge{
    //DLL
    adrB first,last;
};

void createList(ListBridge &LB,ListDirector &LD,ListFilm &LF);

adrD createDirector(string nama);
adrF createFilm(string nama, string genre);
adrB createBridge(adrD &sutradara, adrF film);
adrB createBridge(adrD &sutradara, adrD &astrada, adrF film);

void addDirector(ListDirector &LD, string name);
void addFilm(ListFilm &LF, string name, string genre);
void connect(ListBridge &LB, adrD sutradara, adrF film);
void connect(ListBridge &LB, adrD sutradara,adrD astrada, adrF film);

adrD findDirector(ListDirector LD,string nama);
adrF findFilm(ListFilm LF,string nama);

void deleteDirector(ListDirector &LD,ListBridge &LB,string nama);
void deleteFilm(ListFilm &LF,ListBridge &LB,string name);
void disconnect(ListBridge &LB,adrB &connector);

void printAll(ListBridge LB,ListDirector LD,ListFilm LF);
void filmFromDirector(ListBridge LB,string sutradara);
void filmWithTwoDirector(ListBridge LB);
void maxFilmFirector(ListDirector LD, ListBridge LB);
void minAstrada(ListDirector LD, ListBridge LB);
#endif // FILM_H_INCLUDED
