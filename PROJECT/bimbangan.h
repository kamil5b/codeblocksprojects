#ifndef BIMBANGAN_H_INCLUDED
#define BIMBANGAN_H_INCLUDED

#define First(N) N.First
#define Last(N) N.Last
#define nim(N) N->nim
#define kelas(N) N->kelas
#define kuota(N) N->kuota
#define jumlah(N) N->jumlah
#define jenis(N) N->jenis
#define firstM(N) N->firstMahasiswa
#define nama(N) N->nama
#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

typedef struct Matakuliah *adrMK;
typedef struct Mahasiswa *adrM;

struct Matakuliah{
    //DLL
    string kelas,nama,jenis;
    int kuota,jumlah;
    adrM firstMahasiswa;
    adrMK next;
    adrMK prev;
};

struct Mahasiswa{
    //CDLL
    string nim,nama,kelas,jenis;
    adrM next;
    adrM prev;
};

struct ListMatakuliah{
    //DLL
    adrMK First,Last;
};

void createListMatakuliah(ListMatakuliah &L);
//1a
void addMatakuliah(ListMatakuliah &L, string nama,
                        string kelas, int kuota, string jenis);
//2a,3a,4a
void addMahasiswa(ListMatakuliah LM, adrMK &L,
                  string nama,string nim, string kelas, string jenis);
adrM searchMahasiswaFromMatkul(adrMK L, string kode);
void printMahasiswaFromMatkul(string nama, string kelas, string jenis, string kode);
int countMatakuliahMahasiswa(ListMatakuliah L, string kode);
adrMK searchMatakuliah(ListMatakuliah L, string nama, string kelas, string jenis);
//2b && 3b
void deleteMahasiswa(ListMatakuliah LP, string kode);
//1b
void deleteMatakuliah(ListMatakuliah &LP,string nama, string kelas, string jenis);
void printMatakuliah(adrMK P);
void printMahasiswa(adrM N);
//5
void printOnlyMatakuliah(ListMatakuliah LD);
//6
void printMatakuliahMahasiswa(ListMatakuliah LP,string nama, string kelas, string jenis);
//7
void printAll(ListMatakuliah LD);

//8


int pilihMenu();
void startMenu(ListMatakuliah &LP);


#endif // BIMBANGAN_H_INCLUDED
