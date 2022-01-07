#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <cctype>
#include <string>
#include <locale>
#include <fstream>
#include <stdlib.h>

using namespace std;

typedef struct barang_bekas *ad_bb;
typedef struct tipe *ad_tipe;

struct barang_bekas{
    string nama;
    ad_tipe jenis;
    int harga;
    ad_bb next;
};

#endif // HEADER_H_INCLUDED
