#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

#define nama(P) P->nama
#define kelamin(P) P->kelamin
#define anakPertama(P) P->anakPertama
#define next(P) P->next
#define prev(P) P->prev
#define anak(P) P->anak
#define first(L) L.first
#define last(L) L.last

using namespace std;

typedef struct Orang_Tua *addressOT;
typedef struct Anak *addressAnak;
typedef struct Hubungan *addressHubungan;

struct Orang_Tua{
    string nama;
    string kelamin;
    int anak;
    addressHubungan anakPertama;
    addressOT next;
    addressOT prev;
};

struct Anak {
    string nama;
    string kelamin;
    addressAnak next;
    addressAnak prev;
};

struct Hubungan{
    addressAnak anak;
    addressHubungan next;
};

struct listOT{
    addressOT first;
    addressOT last;
};

struct listAnak{
    addressAnak first;
    addressAnak last;
};

addressOT buatOT(string nama, string kelamin);
addressAnak buatAnak(string nama, string kelamin);

void buatList(listAnak &LA,listOT &LOT);
void buatHubungan(addressOT &P, addressAnak Q);
void insertLastOT(addressOT P, listOT &L);
void insertLastAnak(addressAnak P, listAnak &L);

void deleteFirstOT(addressOT &P,listOT &L);
void deleteAfterOT(addressOT Prec,addressOT &P);
void deleteLastOT(addressOT &P,listOT &L);
void deleteOT(addressOT &P,listOT &L);

void deleteFirstAnak(addressAnak &P,listAnak &L);
void deleteAfterAnak(addressAnak Prec,addressAnak &P);
void deleteLastAnak(addressAnak &P,listAnak &L);
void deleteAnak(addressAnak &P,listAnak &L);

void deleteFirstHubungan(addressHubungan &P,addressOT &Q);
void deleteAfterHubungan(addressHubungan Prec,addressHubungan &P);
void deleteHubungan(addressHubungan &P,addressOT &Q);

addressOT cariOT(string nama,string kelamin,listOT &L);
addressAnak cariAnak(string nama,string kelamin,listAnak &L);

void printAnak(addressAnak P,listOT L);
void printOT(addressOT P);
addressOT MinAnakOT(listOT L);
addressOT MaxAnakOT(listOT L);

#endif // HEADER_H_INCLUDED
