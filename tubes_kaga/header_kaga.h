#ifndef HEADER_KAGA_H_INCLUDED
#define HEADER_KAGA_H_INCLUDED
#include <iostream>
#include <cctype>
#include <string>
#include <locale>
#include <fstream>
#include <stdlib.h>

using namespace std;

typedef struct history *HID;
typedef struct transaksi *IDT;
typedef struct barang *IDB;
typedef struct brand *BP;
typedef struct apparel *IDA;
typedef struct Size *SID;

struct history {
    IDT P_Transaksi;
    int total_harga;
    HID next;
};

struct transaksi {
    int ID_Transaksi;
    IDB P_Barang;
    string status;
    int total_price;
    IDT next;
    IDT prev;
};

struct barang {
    int ID_Gudang;
    string ID_Pabrik;
    string Nama_Barang;
    BP Brand_Barang;
    IDA Tipe_Barang;
    SID Size_Barang;
    int kuantitas;
    int price;
    //tangan
    IDB next;
    IDB prev;
};

struct brand {
    string namaBrand;
    BP next;
    BP prev;
};

struct apparel {
    string tipe_apparel;
    IDA next;
    IDA prev;
};

struct Size{
    string Size_apparel;
    SID next;
    SID prev;
};

//LIST

struct ListHistory {
    HID head;
    HID tail;
};

struct ListTransaksi {
    IDT top;
};

struct listBarang{
    IDB first;
    IDB last;
    int id;
};

struct listBrand{
    BP first;
    BP last;
};
struct listApparel{
    IDA first;
    IDA last;
};
struct listSize{
    SID first;
    SID last;
};

//KAMIL
//register
void fixedSize(listSize &S);
void fixedBrand(listBrand &Br);
void fixedApparel(listApparel &A);
//buat
void buatLS(listSize &L);
void buatLB(listBarang &L);
void buatLBrand(listBrand &L);
void buatLA(listApparel &L);
//tambah
void tambahSize(listSize &A,string S);
void tambahBrand(listBrand &B, string nama_brand);
void tambahApparel(listApparel &A, string nama_apparel);

//delete
void deleteSize(listSize &S,SID &ss,listBarang B);
void deleteApparel(listApparel &S,IDA &ss,listBarang B);
void deleteBrand(listBrand &S,BR &ss,listBarang B);

//Barang
void fixedBarang(listBarang &B,listApparel A,listBrand Br,listSize S);
void masukBarang(listBarang &B,listApparel A,listBrand Br,listSize S);
void tambahBarang(listBarang &B,IDB P);
void updateBarang(listBarang &B,listApparel A,listBrand Br,listSize S,string id);
void lihatBarang(listBarang B, IDB P);
void printBarang(listBarang B);
void deleteBarang(listBarang &B, IDB &P, );
//search
IDB searchBarang(listBarang B, string idbarang);
SID searchSize(listSize S,string ss);
IDA searchApparel(listApparel A,string tipe);
BP searchBrand(listBrand B,string br);

//AGOY
void menu();
void cekHistory();
void cekProfit();

#endif // HEADER_KAGA_H_INCLUDED
