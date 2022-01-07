#ifndef NOVEL_H_INCLUDED
#define NOVEL_H_INCLUDED

#define First(N) N.First
#define Last(N) N.Last
#define judul(N) N->judul
#define counts(N) N->counts
#define nama(N) N->nama
#define penulis(N) N->penulis
#define collab(N) N->collab
#define firstT(T) T->firstTulis
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Penulis *adrP;
typedef struct Novel *adrN;
typedef struct Tulis *adrT;

struct Penulis{
    string nama;
    int counts;
    bool collab;
    adrP next;
    adrP prev;
};

struct Novel{
    string judul;
    int counts;
    adrT firstTulis;
    adrN next;
    adrN prev;
};

struct Tulis{
    adrP penulis;
    adrT next;
};

struct ListPenulis{
    //CDLL
    adrP First,Last;
};

struct ListNovel{
    //DLL
    adrN First,Last;
};

void createListPenulis(ListPenulis &L);
void createListNovel(ListNovel &L);
void addPenulis(ListPenulis &L, string nama);
void addNovel(ListNovel &L, string judul,adrP &pen);
void tambahPenulisDariNovel(adrN &N, adrP &P);

void searchPenulis(ListPenulis L, string nama, adrP &P);
void searchNovel(ListNovel L, string judul, adrN &N);

void deleteNovel(ListNovel &LN, string judul);
void deletePenulis(ListNovel &LN, ListPenulis &LP, string nama);

void printPenulisNovel(ListNovel LN,ListPenulis LP,string name);
void duaPenulis(ListNovel LN);
void penulisAktif(ListPenulis LP);
void penulisKuper(ListPenulis LP);

void printNovel(ListNovel LN);

void startMenu(ListNovel &LN, ListPenulis &LP);

#endif // NOVEL_H_INCLUDED
