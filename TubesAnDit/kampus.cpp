#include <iostream>
#include "kampus.h"

//KUMPULAN FUNGSI PERINTAH UNTUK KAMPUS

bool isEmpty(List1 &L) {
    bool status;
    if ((first(L) == NULL) && (last(L) == NULL)) {
        status = true;
    }
    else {
        status = false;
    }
    return status;
}

void createList1 (List1 &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address1 alokasi (string nama, string id, int usia, string alamat) {
    address1 p;
    p = new elmlist1;
    info(p).id = id;
    info(p).nama = nama;
    info(p).usia = usia;
    info(p).alamat = alamat;
    next(p) = NULL;
    prev(p) = NULL;

    return p;
}

void dealokasi (address1 &p) {
    delete p;
}

void insertFirst (List1 &L, address1 p) {
    if ((first(L) == NULL) && (last(L)== NULL)) {
        first(L) = p;
        last(L) = p;
    }
    else{
        next(p) = first(L);
        prev(next(p)) = p;
        first(L)= p;
    }
   next(last(L)) = first(L);
   prev(first(L)) = last(L);
}

void insertAfter (List1 &L, address1 prec, address1 p) {
    if (prec != last(L)) {
       next(p) = next(prec);
       prev(p) = prec;
       next(prec) = p;
       prev(next(p))= p;
    }
    else if (prec == last(L)){
        insertLast(L,prec);
    }

}

void insertLast (List1 &L, address1 p) {
    if ((first(L) == NULL) && (last(L) == NULL)) {
        first(L) = p;
        last(L) = p;

    }
    else {

        prev(p) = last(L);
        next(last(L))= p;
        last(L)= p;
    }
    next(last(L))= first(L);
    prev(first(L))= last(L);
}

address1 findElm (List1 L, string id) {
    address1 P = first(L);
    while ((P != last(L)) && (info(P).id != id)) {
        P = next(P);
    }
    if (info(P).id == id){
        return P;
    }
    else{
        P = NULL;
        cout<<"tidak ketemu";
        return P;
    }
}


void deleteFirst (List1 &L, address1 &p) {
    if ((first(L) == NULL) && (last(L) == NULL)) {
        p = NULL;
    }
    else {
        if (first(L) == last(L)) {
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else {
            p = first(L);
            first(L) = next(p);
            prev(first(L))=last(L);
            next(last(L))= first(L);
        }
            next(p) = NULL;
            prev(p) = NULL;
        }
    }

/**void counterDelete () {
    if (selected != NULL){
        if(first(LK) == selected){

        }
        else if(last(LK) == selected){

        }
        else if((first(LK) == selected) && (last(LK) == selected)){
            address1HoldP = prev(selected);
            HoldN = next(selected);
        }


    }
}*/

void deleteAfter (List1 &L,address1 prec, address1 &p) {
    if (prec == NULL) {
        p = NULL;
    }
    else if ((prec == last(L)) &&(prec==first(L))) {
        p = first(L);
        first(L) = NULL;
        last(L)= NULL;
        next(p) = NULL;
        prev(p) = NULL;
    }
    else{
        p = next(prec);
        next(prec)= next(p);
        prev(next(p))=prec;
        if (last(L)== p){
            last(L)= prec;

        }
        else if (first(L)==p){
            first(L)=next(prec);
        }
        prev(first(L))=last(L);
        next(last(L))=first(L);
        next(p)= NULL;
        prev(p)= NULL;
    }
}

void deleteLast (List1 &L, address1 &p) {
    if ((first(L) == NULL) && (last(L)== NULL)) {
        p = NULL;
    }
    else {
        if (first(L) == last(L)) {
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else {
            p = last(L);
            last(L) = prev(p);
            prev(first(L))=last(L);
            next(last(L))=first(L);
        }
            next(p) = NULL;
            prev(p) = NULL;
        }
    }

 void deletekampus1(List1 &L,address1 &P,int &i){
    address1 prec;
    i = i - 1;
    if (first(L) == P){
        deleteFirst(L,P);
    }
    else if (next(P)== NULL){
        deleteLast(L,P);
    }
    else{
        deleteAfter(L,prec,P);
    }
}

void printInfo1 (List1 L) {
     if (!isEmpty(L)) {
        address1 p = first(L);
        address1 Q = NULL;
        cout<<"Berikut adalah List Data Kampus yang terdaftar!\n";
        while (p != Q) {
            cout << "===============================================\n";
            cout << endl;
            cout<<"ID Kampus\t: "<<info(p).id<<endl;
            cout<<"Nama Kampus\t: "<<info(p).nama<<endl;
            cout<<"Umur Kampus\t: "<<info(p).usia<<endl;
            cout<<"Alamat Kampus\t: "<<info(p).alamat<<endl;
            cout << endl;
            cout << "===============================================\n";
            p = next(p);
            Q = first(L);
        }
        cout<<endl;
    }
    else {
        cout<<"List Kosong"<<endl;
    }
}

void InsertSort(List1 &L, address1 P){
    address1 Q = first(L);
    cout << "test1";
    if(first(L) == NULL){
        insertFirst(L,P);
    }
    else{
        if((info(Q).id >= info(P).id)){
            cout << "test2";
            insertFirst(L,P);
            cout << "test2";
        }
        else{
            cout << "test3";
            cout << "test4";
            cout << info(next(Q)).id;
            cout << info(P).id;
            while((next(Q) != last(L)) && (info(next(Q)).id < info(P).id)){
                cout << "test5";
                Q = next(Q);
                cout << "test6";
            }
            cout << "test7";
            insertAfter(L,Q,P);
            cout << "test8";
        }
    }
}
