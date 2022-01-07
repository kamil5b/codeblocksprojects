#ifndef H_H_INCLUDED
#define H_H_INCLUDED
#define nextL(P) P->nextL
#define nextA(P) P->nextA
#define nextR(P) P->nextR

#define infoL(P) P->infoL
#define infoA(P) P->infoA

#define rel(P) P->rel
#define link(P) P->link

#define first_Mobil(L) L.first_Mobil
#define first_Montir(L) L.first_Montir
#define last_Mobil(L) L.last_Mobil
#define last_Montir(L) L.last_Montir

#include <iostream>
#include <cstddef>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

typedef string infotype;
typedef struct Mobil *address_Mobil;
typedef struct hubungan *address_hubungan;
typedef struct Montir *address_Montir;

struct Mobil{
    infotype infoL;
    address_Mobil nextL;
    address_hubungan rel;

};
struct hubungan{
    address_Montir nextA;
    address_Mobil nextL;
    address_hubungan nextR;
    address_Montir link;
};
struct Montir{
    infotype infoA;
    address_Montir nextA;
    address_hubungan rel;
};
struct multiList{
    address_Mobil first_Mobil;
    address_Mobil last_Mobil;
    address_Montir first_Montir;
    address_Montir last_Montir;
};

void createList(multiList &L);
address_Mobil allocateMobil(infotype X);
void insertMobil(address_Mobil P, multiList &L);
address_Mobil searchMobil(infotype X,multiList L);
void tambahMobil(multiList &L);
void HapusMobil(multiList &L);
void tampilkanMobilTertentu(multiList L);
void tampilSemuaMobil(multiList L);



address_Montir allocateMontir(infotype X);
void insertMontir(address_Montir P, multiList &L);
address_Montir searchMontir(infotype X,multiList L);
void tambahMontir(multiList &L);
void HapusMontir(multiList &L);
void tampilSemuaMontir(multiList L);
void tampilkanMontirTertentu(multiList L);

address_hubungan allocatehubungan();
bool cekHubungan(address_Mobil M, address_Montir D);
void tambahHubungan(multiList &L);
void HapusHubungan(address_Mobil &M, address_Montir A);
void tampilMobildanMontirtertentu(multiList L);




#endif // H_H_INCLUDED
