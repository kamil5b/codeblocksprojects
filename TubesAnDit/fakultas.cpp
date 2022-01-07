#include <iostream>
#include "fakultas.h"

//KUMPULAN FUNGSI PERINTAH UNTUK FAKULTAS

void createList2 (List2 &L) {
    L.first = NULL;
}

address2 alokasi2 (string fak, string kode) {
    address2 p;
    p = new elmlist2;
    info(p).fak = fak;
    info(p).kode = kode;
    next(p) = NULL;
    return p;
}

void dealokasi (address2 &p) {
    delete p;
}

void insertFirst2 (List2 &L, address2 p) {
    address2 akhir;
    if (first(L) == NULL){
        first(L) = p;
        next(p) = first(L);
    }
    else{
        akhir = first(L);
        while(next(akhir) != first(L) ){
            akhir= next(akhir);
        }
    next(p) = first(L);
    next(akhir) = p;
    first(L) = p;
    }
}
address2 findElm2 (List2 L, string kode) {
    address2 p = first(L);
    while (next(p)!= first(L)&&(info(p).kode!= kode)){
        p = next(p);
    }
    if (info(p).kode == kode){
        return p;
    }
    else{
        return NULL;
    }

    /*address2 p = first(L);
    address2 lasted = first(L);
    while (next(lasted) != first(L)){
        lasted = next(lasted);
    }
    while ((p != lasted) && (info(p).kode != kode)) {
        p = next(p);
    }
    return p;
    */
}

void deleteFirst2 (List2 &L, address2 &p) {
    address2 akhir;
    if (first(L) == NULL) {
        p = NULL;
        cout<<"List Kosong"<<endl;
    }
    else if (next(first(L)) == first(L)){
        p = first(L);
        next(p) = NULL;
        first(L) =NULL;
        }
    else {
        akhir = first(L);
        while (next(akhir) != first(L)){
            akhir = next(akhir);
        }
        p = first(L);
        first(L) = next(p);
        next(p)= NULL;
        next(akhir) = first(L);
    }
}

void deleteLast2 (List2 &L, address2 &p) {
    address2 beforelast;

    if (first(L) == NULL){
        p = NULL;
        cout<<"List Kosong"<<endl;
    }
    else if (next(first(L)) == NULL) {
            p = first(L);
            next(p) = NULL;
            first(L) = NULL;
        }
        else {
            p = first(L);
            while (next(p)!= first(L)) {
                beforelast = p;
                p = next(p);
            }
            next(p) = NULL;
            next(beforelast) = first(L);
        }
    }

void deleteAfter2(List2 &L, address2 prec, address2 &p) {
    if (prec == NULL){
        p= NULL;
        cout<<"prec bernilai nil";
    }
    else if (next(prec) == prec) {
        p = prec;
        next(p)= NULL;
        first(L) = NULL;
        cout<<"Tidak ada elemen after prec";
    }
    else{
        p = next(prec);
        next(prec)= next(p);
        next(p) = NULL;
        if (p == first(L)) {
            first(L) = next(prec);
        }
    }
}

void printInfo2 (List2 L) {
    address2 p;
    if (next(first(L)) == first(L)) {
        cout<<"List Kosong"<<endl;
    }
    else {
        p = first(L);
        cout<<"Berikut adalah List Data Fakultas yang terdaftar!\n";
        while (next(p) != first(L)) {
            cout << "===============================================\n";
            cout << endl;
            cout << "Kode Fakultas\t: ";
            cout << info(p).kode<<endl;
            cout << "Fakultas\t: ";
            cout << info(p).fak<<endl;
            cout << endl;
            cout << "===============================================\n";
            p = next(p);
        }
        cout << "===============================================\n";
        cout << endl;
        cout << "Kode Fakultas\t: ";
        cout << info(p).kode<<endl;
        cout << "Fakultas\t: ";
        cout << info(p).fak<<endl;
        cout << endl;
        cout << "===============================================\n";
        cout << endl;
    }
}

void insertAfter2(List2 &L, address2 p, address2 prec){
    if (prec != NULL) {
        address2 lasted = first(L);
        while (next(lasted) != first(L)){
            lasted = next(lasted);
        }
        if(prec == lasted){
            insertLast2(L,p);
        }
        else if(prec != lasted){
            next(p) = next(prec);
            next(prec) = p;
        }
    }
    else {
        p = NULL;
        cout<<"List kosong "<< endl;
    }
}


void insertLast2(List2 &L, address2 p){
    address2 akhir;
    if (first(L) == NULL){
        first(L) = p;
        next(p) = first(L);
    }
    else{
        akhir = first(L);
        while (next(akhir) != first(L)){
            akhir = next(akhir);
        }
        next(p) = first(L);
        next(akhir) = p;
    }
}

void InsertSort2(List2 &L, address2 P){
    address2 Q = first(L);
    address2 lasted = first(L);
        while (next(lasted) != first(L)){
            lasted = next(lasted);
        }
    if((info(Q).kode >= info(P).kode) || (next(first(L)) == lasted)){
        insertFirst2(L,P);
    }
    else{
        address2 K = next(Q);
        while((next(Q) != lasted) && (info(K).kode) < info(P).kode){
            Q = next(Q);
            K = next(K);
        }
        insertAfter2(L,P,Q);
    }
}
