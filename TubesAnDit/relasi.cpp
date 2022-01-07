#include "relasi.h"
void createList_R (List_R &L) {
    first(L) = NULL;
}

address_R alokasi_R (address1 p, address2 q) {
    address_R r;
    r = new elmlist_R;
    info(r).e1 = p;
    info(r).e2 = q;
    next(r) = NULL;
    return r;
}

void dealokasi_R (address_R &p) {
    delete p;
}

void insertFirst_R (List_R &L, address_R p) {

        next(p) = first(L);
        first(L) = p;

}

void insertLast_R (List_R &L, address_R p) {
    if (first(L) == NULL) {
        first(L) = p;
    }
    else {
        address_R q = first(L);
        while (next(q) != NULL) {
            q = next(q);
        }
        next(q) = p;
    }
}

address_R findElm (List_R L,List1 LP, string id) {
    address_R p;
    address1 q;
    p = first(L);
    while ((p != NULL) && info(q).id != id) {
        p = next(p);
    }
    return p;
}

void deleteFirst_R (List_R &L, address_R &p) {
    if (first(L) == NULL) {
        p = NULL;
        cout<<"List Kosong"<<endl;
    }
    else {
            p = first(L);
            first(L)= next(p);
            next(p) = NULL;
    }
}

void deleteLast_R (List_R &L, address_R &P) {
    address_R Q;
    if (first(L) == NULL)
        cout<<"List Kosong"<<endl;
    else if (next(first(L)) == NULL){
            P = first(L);
            first(L) = NULL;
        }
    else {
            Q = NULL;
            P = first(L);

            while (next(P) != NULL) {
                Q = P;
                P = next(P);
            }
            next(Q)= NULL;
        }
    }


void deleteAfter_R(List_R &L, address_R prec, address_R &p) {
    if (prec == NULL){
        p = NULL;
        cout<<"prec bernilai nil";
    }
    else if (next(prec) == NULL) {
        p = NULL;
        cout<<"Tidak ada elemen after prec";
    }
    else{
        p = next(prec);
        next(prec)= next(p);
        if (next(p) != NULL) {
            next(p) = NULL;
        }
    }
}

void deleteKampusById (List_R &LR, List1 &LP, string id) {
    //address_R q;
    if (first(LP) == NULL) {
        cout<<" No ID"<<id<<" Tidak ditemukan"<<endl;
    }
    else {
        address_R p = first(LR);
        address_R lastLR = first(LR);
        while (next(lastLR) != NULL) {
            lastLR = next(lastLR);
        }
        while (p != NULL) {
            //if(p(info(e1))) //(p->info.e1->info.id == id)
                if (p == first(LR)) {
                    deleteFirst_R(LR,p);
                }
                else if (p == lastLR) {
                    deleteLast_R(LR, p);
                }
                else {
                    address_R prec = first(LR);
                    while (next(prec) != p) {
                        prec = next(prec);
                    }
                    deleteAfter_R(LR, prec,p);
                }
        }
            p = next(p);
    }
}

void deleteRelasiK (List1 &LP, List_R &LR, string inputID) {
    if(first(LR) != NULL){
        address_R R = first(LR);
        address1 K = info(R).e1;
        cout << "test1";
        while(R != NULL){
            cout << "test2";
            if (info(K).id == inputID){
                cout << "test3";
                if(R == first(LR)){
                    cout << "test4";
                    address_R HoldN = next(R);
                    next(first(LR)) = NULL;
                    first(LR) = HoldN;
                    cout << "test5";
                }
                else if(R != first(LR)){
                    cout << "test6";
                    address_R selected = R;
                    address_R P = first(LR);
                    address_R Q = next(R);
                    R = Q;
                    cout << "test7";
                    while(next(P) != selected){
                        P = next(P);
                        cout << "test8";
                    }
                    cout << "test9";
                    next(P) = R;
                    next(selected) = NULL;

                    address_R Temp = first(LR);
                    cout << "test10";
                    while(next(Temp) != R){
                        Temp = next(Temp);
                        cout << "test11";
                    }
                    R = Temp;
                    cout << "test12";
                }

                cout << "test13";
            }
            R = next(R);
            K = next(K);
        }

        cout << "test14";
    }
    else{
        cout << "Relasi tidak ditemukan!" << endl;
    cout << "test15";
    }
}


void deleteKampusAsli (List_R &LR, List1 &LP) {
    address1 p;
    string id;
    cout<<"Masukan Nomor ID Kampus yang akan dihapus : ";
    cin>>id;
    deleteRelasiK(LP,LR,id);
    p = findElm(LP,id);
    if (p != NULL) {
        address1 q;
        if (p == first(LP)) {
            deleteFirst(LP,p);
            cout<<"Penghapusan Berhasil"<<endl;
        }
        else if (p == last(LP)) {
            deleteLast(LP,p);
            cout<<"Penghapusan Berhasil"<<endl;
        }
        else {
            address1 prec = prev(p);
            deleteAfter(LP,prec,p);
            cout<<"Penghapusan Berhasil"<<endl;
        }
        cout << info(p).id;
    }

}

void deleteFakultasAsli (List_R &LR, List2 &LF) {
    address2 p;
    string kode;
    cout<<"Masukan Nomor Kode Fakultas yang akan dihapus : ";
    cin>>kode;
    deleteRelasiF(LF,LR,kode);
    cout << "testa1";
    p = findElm2(LF,kode);
    cout << "testa2";
    if (p != NULL) {
        address2 q = first(LF);
        cout << "testa3";
        if (p == first(LF)) {
            deleteFirst2(LF,p);
            cout<<"Penghapusan Berhasil"<<endl;
        }
        else if (next(p) == first(LF)) {
            cout << "testa4";
            deleteLast2(LF,p);
            cout<<"Penghapusan Berhasil"<<endl;
        }
        else {
            while (next(q) != first(LF)){
                q = next(q);
            }
            address2 prec = q;
            cout << "testa5";
            deleteAfter2(LF,prec,p);

            cout<<"Penghapusan Berhasil"<<endl;

        }
        cout << info(p).kode;
        cout << "testa6";
    }
}

void deleteCounterRF(){
    address2 P;
}

void deleteRelasiF (List2 &LF, List_R &LR, string inputCode) {
    if(first(LR) != NULL){
        address_R R = first(LR);
        address2 F = info(R).e2;
        cout << "test1";
        while(R != NULL){
            cout << "test2";
            if (info(F).kode == inputCode){
                cout << "test3";
                if(R == first(LR)){
                    cout << "test4";
                    address_R HoldN = next(R);
                    next(first(LR)) = NULL;
                    first(LR) = HoldN;
                    cout << "test5";
                }
                else if(R != first(LR)){
                    cout << "test6";
                    address_R selected = R;
                    address_R P = first(LR);
                    address_R Q = next(R);
                    R = Q;
                    cout << "test7";
                    while(next(P) != selected){
                        P = next(P);
                        cout << "test8";
                    }
                    cout << "test9";
                    next(P) = R;
                    next(selected) = NULL;

                    address_R Temp = first(LR);
                    cout << "test10";
                    while(next(Temp) != R){
                        Temp = next(Temp);
                        cout << "test11";
                    }
                    R = Temp;
                    cout << "test12";
                }

                cout << "test13";
            }
            R = next(R);
            F = next(F);
        }
        cout << "test14";
    }
    else{
        cout << "Relasi tidak ditemukan!" << endl;
    cout << "test15";
    }
}


void printInfoRelasiAll(List_R L){
    address_R P;
    if (first(L) == NULL) {
        cout<<"List Kosong"<<endl;
    }
    else {
        P = first(L);
        cout << endl;
        cout<<"Berikut adalah List Data Perguruan Tinggi yang berelasi!\n";
        while (P != NULL) {
            address1 Q = info(P).e1;
            address2 R = info(P).e2;
            cout << "===============================================\n";
            cout << endl;
            cout << "Nama Kampus terelasi\t: ";
            cout << info(Q).nama << endl;
            cout << "Nama Fakultas terelasi\t: ";
            cout << info(R).fak << endl;
            cout << endl;
            cout << "===============================================\n";
            P = next(P);
        }
        cout << endl;
    }
}

void printInfoRelasiKampus(List_R L){
    address_R P;
    string kampus;
    if (first(L) == NULL) {
        cout<<"List Kosong"<<endl;
    }
    else {
        P = first(L);
        cout << endl;
        cout << "Masukkan Nama Kampus yang berelasi\n";
        cin >> kampus;
        cout << endl;
        cout << "===============================================\n";
        cout << "Berikut adalah List Data Perguruan Tinggi yang berelasi!\n";
        while (P != NULL) {
            address1 Q = info(P).e1;
            address2 R = info(P).e2;
            if(info(Q).nama == kampus){
                cout << "===============================================\n";
                cout << endl;
                cout << "Nama Kampus terelasi\t: ";
                cout << info(Q).nama << endl;
                cout << "Nama Fakultas terelasi\t: ";
                cout << info(R).fak << endl;
                cout << endl;
                cout << "===============================================\n";
            }
            P = next(P);
        }
        cout << endl;
    }
}

void printInfoRelasiFakultas(List_R L){
    address_R P;
    string fakultas;
    if (first(L) == NULL) {
        cout<<"List Kosong"<<endl;
    }
    else {
        P = first(L);
        cout << endl;
        cout << "Masukkan Nama Fakultas yang berelasi\n";
        cin >> fakultas;
        cout << endl;
        cout << "===============================================\n";
        cout<<"Berikut adalah List Data Perguruan Tinggi yang berelasi!\n";
        while (P != NULL) {
            address1 Q = info(P).e1;
            address2 R = info(P).e2;
            if(info(R).fak == fakultas){
                cout << "===============================================\n";
                cout << endl;
                cout << "Nama Kampus terelasi\t: ";
                cout << info(Q).nama << endl;
                cout << "Nama Fakultas terelasi\t: ";
                cout << info(R).fak << endl;
                cout << endl;
                cout << "===============================================\n";
            }
            P = next(P);
        }
        cout << endl;
    }
}
