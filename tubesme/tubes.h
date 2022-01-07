#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#define Nil NULL
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define child(P) P->child
#define last(L) L.last
#define awal(L) L.awal
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>


using namespace std;


typedef struct elmtPenulis *adrPenulis;
typedef struct elmtNovel *adrNovel;
typedef struct elmtRelasi *adrRelasi;

// Penulis
struct infoPenulis{
    string namaPenulis;
    string umurPenulis;
    int JumlahBukuPenulis;
};

struct elmtPenulis{
    infoPenulis info;
    adrPenulis next;
    adrRelasi child;
};
struct Penulis{
    adrPenulis awal;
    adrPenulis last;
};

// Novel

struct infoNovel{
    string namaNovel;
    string genreNovel;
    string colabTidak;

};

struct elmtNovel{
    infoNovel info;
    adrNovel next;

};
struct Novel{
    adrNovel awal;
    adrNovel last;
};

// RELASI

struct elmtRelasi{
    adrRelasi next;
    adrRelasi prev;
    adrBarang info;
};

// Penulis
void createPenulis(Penulis &T);
adrPenulis createElmPenulis(infoPenulis input);
void insertawalPenulis(Penulis &T, adrPenulis P);
void insertLastPenulis(Penulis &T, adrPenulis P);
void deleteawalPenulis(Penulis &T, adrPenulis &P);
void deleteLastPenulis(Penulis &T, adrPenulis &P);
void deleteElmtPenulis(Penulis &T, adrPenulis &P);

// Novel
void createNovel(Novel &N);
adrBuku createElmNovel(infoNovel input);
void insertawalNovel(Novel &N, adrNovel P);
void insertLastNovel(Novel &N, adrNovel P);
void deleteawalNovel(Novel &N, adrNovel &P);
void deleteawalNovel(Novel &N, adrNovel &P);
void deleteElmNovel(Novel &N, adrNovel &P);

// RELASI
adrRelasi createElmRelasi(adrBuku &P);
void insertfirstRelasi(adrPenulis &Q, adrRelasi P);
void insertLastRelasi(adrPenulis &Q, adrRelasi P);
void deletefirstRelasi(adrPenulis &Q, adrRelasi &P);
void deleteLastRelasi(adrPenulis &Q, adrRelasi &P);
void deleteElmRelasi(adrPenulis &Q, adrRelasi &P);
void relTokoBarang(Penulis &T, Novel N);

//PRINTINFO
void printAllPenulis(Penulis T);
void printPenulis(Penulis T, string namaNovel);
void printNovel(Penulis T, string namaPenulis);


//SEARCHING
adrPenulis searchPenulis(Penulis T, string namaPenulis);
adrBuku searchNovel(adrPenulis P, string namaNovel);
adrBuku searchNovelList(Novel N, string namaNovel);
adrRelasi searchNovelRelasi(adrPenulis P, adrNovel Q);

//PROCEDURE
void inputPenulis(Penulis &T, Novel &N);
void inputNovel(Novel &B, adrPenulis P);
void pilihNovel(Penulis &T, Novel &N);
void hapusPenulis(Penulis &T, Novel &N);
void hapusNovel(Penulis &T, Novel &N);
void tipeNovel();
void PenulisAlwaysSolo();
void PenulisColab();


#endif // TUBES_H_INCLUDED


