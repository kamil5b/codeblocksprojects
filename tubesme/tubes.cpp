#include "tubes.h"
// Penulis
void createPenulis(Penulis &T) {
    awal(T) = NULL;
    last(T) = NULL;
    }
adrPenulis createElmPenulis(infoPenulis input) {
    adrPenulis P = new elmtPenulis;
    info(P) = input;
    child(P) = NULL;
    next(P) = NULL;
    return P;
}

void insertFirstPenulis(Penulis &T, adrPenulis P) {
    if (awal(T) == NULL) {
        awal(T) = P;
        last(T) = P;
    }else {
        next(P) = awal(T);
        awal(T) = P;
    }
}
void insertLastPenulis(Penulis &T, adrPenulis P){
    if (awal(T) == NULL) {
        insertawalPenulis(T, P);
    }else {
        next(last(T)) = P;
        last(T) = P;
    }
}
void deleteFirstPenulis(Penulis &T, adrPenulis &P){
if (awal(T) == last(T)) {
        awal(T) = NULL;
        last(T) = NULL;
        delete P;
    }else {
        awal(T) = next(awal(T));
        next(P) = NULL;
        delete P;
    }
}
void deleteLastPenulis(Penulis &T, adrPenulis &P){
 if (awal(T) == last(T)) {
        deleteawalPenulis(T, P);
    }else {
        adrToko Q = awal(T);
        while (next(Q) != P) {
            Q = next(Q);
        }
        last(T) = Q;
        next(Q) = NULL;
        next(P) = NULL;
        delete P;
    }
}

void deleteElmtPenulis(Penulis &T, adrPenulis &P){
if (P == NULL) {
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
    }else if (awal(T) == P) {
        deleteawalPenulis(T, P);
    }else if (last(T) == P) {
        deleteLastPenulis(T, P);
    }else {
        adrToko prec = awal(T);
        while (next(prec) != P) {
            prec = next(prec);
        }
        next(prec) = next(P);
        next(P) = NULL;
        delete P;
    }
}

// Buku
void createNovel(Buku &N){
    awal(B) = NULL;
    last(B) = NULL;
}
adrBuku createElmNovel(infoNovel input){
    awal(B) = NULL;
    last(B) = NULL;
}
void insertFirstNovel(Novel &N, adrNovel P){
    if(awal(B) == NULL) {
        awal(B) = P;
        last(B) = P;
        next(P) = P;
    }else {
        next(P) = awal(B);
        awal(B) = P;
        next(last(B)) = P;
    }
}
void insertLastNovel(Novel &N, adrNovel P){
    if (awal(B) == NULL) {
        insertawalNovel(B, P);
    }else {
        next(last(B)) = P;
        last(B) = P;
        next(P) = awal(B);
    }
}
void deleteFirstNovel(Novel &N, adrBuku &P){
    if (awal(N) == last(N)) {
        awal(N) = NULL;
        last(N) = NULL;
        next(P) = NULL;
        delete P;
    }else {
        awal(N) = next(P);
        next(last(N)) = awal(N);
        next(P) = NULL;
        delete P;
    }
}
void deleteLastNovel(Novel &N, adrBuku &P){
    if (awal(N) == last(N)) {
        deleteawalNovel(N, P);
    }else {
        adrBarang Q = awal(N);
        while (next(Q) != P) {
            Q = next(Q);
        }
        last(N) = Q;
        next(Q) = awal(N);
        next(P) = NULL;
        delete P;
    }
}
void deleteElmBuku(Buku &N, adrNovel &P) {
    if (P == NULL) {
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
    }else if (awal(N) == P) {
        deleteawalNovel(N, P);
    }else if (last(N) == P) {
        deleteLastNovel(N, P);
    }else {
        adrBarang prec = awal(N);
        while (next(prec) != P) {
            prec = next(prec);
        }
        next(prec) = next(P);
        next(P) = NULL;
        delete P;
    }
}


// RELASI
adrRelasi createElmRelasi(adrNovel &P) {
    adrRelasi R = new elmtRelasi;
    info(R) = P;
    next(R) = NULL;
    prev(R) = NULL;
    return R;
}
void insertfirstRelasi(adrPenulis &Q, adrRelasi P){
    if (child(Q) == NULL) {
        child(Q) = P;
    }else {
        next(P) = child(Q);
        child(Q) = P;
        prev(next(P)) = P;
    }
}
void insertLastRelasi(adrPenulis &Q, adrRelasi P){
    if (child(Q) == NULL) {
        child(Q) = P;
    }else {
        next(P) = child(Q);
        child(Q) = P;
        prev(next(P)) = P;
    }
}
void deletefirstRelasi(adrPenulis &Q, adrRelasi &P){
    if (next(child(Q))== NULL) {
        child(Q) = NULL;
        next(P) = NULL;
        delete P;
    }else {
        child(Q) = next(P);
        prev(next(P)) = NULL;
        next(P) = NULL;
        delete P;
    }
}
void deleteLastRelasi(adrPenulis &Q, adrRelasi &P){
    if (next(child(Q)) == NULL) {
        deletefirstRelasi(Q, P);
    }else {
        adrRelasi R = prev(P);
        next(R) = NULL;
        prev(P) = NULL;
        delete P;
    }
}
void deleteElmRelasi(adrPenulis &Q, adrRelasi &P){
    if (P == NULL) {
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
    }else if (child(Q) == P) {
        deletefirstRelasi(Q, P);
    }else if (next(P) == NULL) {
        deleteLastRelasi(Q, P);
    }else {
        adrRelasi prec = prev(P);
        next(prec) = next(P);
        prev(next(P)) = prec;
        next(P) = NULL;
        prev(P) = NULL;
        delete P;
    }
}
void relTokoBarang(Penulis &T, Buku B);

//PRINTINFO
void printAllPenulis(Penulis T){
    adrPenulis P = awal(T);
    adrRelasi Q;
    while (P != NULL) {
        cout<<"Nama Penulis : "<<info(P).namaPenulis<<endl;
        cout<<"Umur Penulis : "<<info(P).UmurPenulis<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"|| NAMA Novel || Genre Novel || Colabboration info ||"<<endl;
        Q = child(P);
        while (Q != NULL) {
            cout<<"|| "<<info(info(Q)).namaPenulis<<" || || "
            <<info(info(Q)).UmurPenulis<<" || || "<<endl;
            Q = next(Q);
        }
        P = next(P);
        cout<<"-------------------------------"<<endl;
        cout<<endl;
    }
    system("pause");
}
void printPenulis(Penulis T, string namaNovel){
    adrPenulis P = awal(T);
    adrNovel Q;
    while (P != NULL) {
        Q = searchNovel(P, namaNovel);
        if (Q == NULL) {
            cout<<"DATA TIDAK DITEMUKAN"<<endl;
        }else {
            cout<<"|| "<<info(P).namaPenulis
            <<" || || "<<info(P).umurPenulis
            <<" || || "<<info(P).JumlahBukuPenulis
            <<" ||"<<endl;
        }
        P = next(P);
    }
    cout<<"-------------------------------"<<endl;
    cout<<endl;
    system("pause");
}
void printNovel(Penulis T, string namaPenulis){
    adrToko P = searchPenulis(T, namaNovel);
    if (P == NULL) {
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
    }else {
        cout<<"---------DATA DITEMUKAN-------"<<endl;
        cout<<endl;
        cout<<"Nama Novel : "<<info(P).namaNovel<<endl;
        cout<<"Genre Novel : "<<info(P).GenreNovel<<endl;
        cout<<"Collab : "<<info(P).colabTidak<<endl;
        cout<<"|| Novel || "<<endl;
        adrRelasi Q = child(P);
        while (Q != NULL) {
            cout<<"|| "<<info(info(Q)).namaNovel<<" || || "
            <<info(info(Q)).GenreNovel<<" || || "<<info(info(Q)).ColabTidak
            <<" ||"<<endl;
            Q = next(Q);
        }
        cout<<"-------------------------------"<<endl;
        cout<<endl;
    }
    system("pause");
}


//SEARCHING
adrPenulis searchPenulis(Penulis T, string namaPenulis){
    adrPenulis P = awal(T);
    while ((P != NULL) && (info(P).namaNovel != namaNovel)) {
        P = next(P);
    }
    return P;
}
adrBuku searchBuku(adrPenulis P, string namaNovel){
    adrRelasi Q;
    Q = child(P);
    while ((Q != NULL) && (info(info(Q)).namaNovel != namaNovel)) {
        Q = next(Q);
    }
    if (Q != NULL ) {
        return info(Q);
    }else {
        return NULL;
    }

}
adrNovel searchNovelList(Novel N, string namaNovel){
    adrNovel P = awal(B);
    if (P == NULL){
        return P;
    }else if (info(P).namaNovel == namaNovel) {
        return P;
    }else {
        P = next(P);
        while((P != awal(B)) && (info(P).namaNovel != namaNovel)) {
            P = next(P);
        }
        if (P == awal(B)) {
            return NULL;
        }else {
            return P;
        }
    }
}
adrRelasi searchNovelRelasi(adrPenulis P, adrNovel Q){
    adrRelasi R = child(P);
    while ((R != NULL) && (info(R) != Q)) {
        R = next(R);
    }
    return R;
}

//PROCEDURE
void inputPenulis(Penulis &T, Novel &N){
    system("cls");
    infoPenulis inPenulis;
    char input;
    adrPenulis P;
    cout<<"Nama Penulis : ";
    cin>>inPenulis.namaPenulis;
    adrPenulis Q = searchPenulis(T, inPenulis.namaPenulis);
    if (Q == NULL) {
        cout<<"Umur Penulis : ";
        cin>>inToko.umurPenulis;
        cout<<"JumlahBukuPenulis : ";
        cin>>inToko.Jumlah Novel Penulis;
        P = createElmtoko(inToko);
        insertLastToko(T, P);
        cout<<endl;
    }else {
        cout<<"--nama Penulis sudah terdaftar--"<<endl;
        system("pause");
        inputPenulis(T, N);
    }
    cout<<"------------------------------------"<<endl;
    cout<<"--------- PENDAFTARAN Penulis -------"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<endl;
    inputNovel(B, P);
    cout<<"Apakah anda ingin mendaftar Penulis lagi? (y/n)"<<endl;
    cin>>input;
        switch(input) {
            case 'y':
                inputToko(T, B);
                break;
            case 'n':
                cout<<"--nama Penulis telah terdaftar--"<<endl;
                menu(T, B);
                break;
        }
}
void inputNovel(Novel &N, adrPenulis P) {
    infoNovel inNovel;
    char input;
    cout<<"Nama Novel : ";
    cin>>inNovel.namaNovel;
    adrNovel Q = searchNovelList(B, inNovel.namaNovel);
    if (Q == NULL) {
        cout<<"Genre Novel : ";
        cin>>inBarang.genreNovel;
        cout<<"Collaboration : ";
        cin>>inBarang.colabTidak;
        adrBarang Br = createElmBarang(inBarang);
        insertLastBarang(B, Br);
        adrRelasi R = createElmRelasi(Br);
        insertLastRelasi(P, R);
    }else {
        adrRelasi T = searchBarangRelasi(P, Q);
        if (T != NULL) {
            cout<<"Novel Berhasil di input"<<endl;
        }else {
            adrRelasi A = createElmRelasi(Q);
            insertLastRelasi(P, A);
        }

    }
    cout<<"Apakah anda ingin mendaftar barang lagi? (y/n)";
        cin>>input;
        switch(input) {
            case 'y':
                inputBarang(B, P);
                break;
            case 'n':
                cout<<"Barang Telah terdaftar"<<endl;
                system("pause");
                break;
        }
}
void pilihBuku(Penulis &T, Buku &B){
    system("cls");
    string input;
    cout<<"----------------------------------"<<endl;
    cout<<"--------- MASUKAN NAMA TOKO -------"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<endl;
    cout<<"Nama Toko : ";
    cin>>input;
    adrToko P = searchToko(T, input);
    if (P == NULL){
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
        pilihBarang(T, B);
    }else {
        inputBarang(B, P);
    }

}
void hapusPenulis(Penulis &T, Buku &B){
    string input;
    cout<<"Nama Penulis Yang ingin dihapus : ";
    cin>>input;
    adrToko P = searchToko(T, input);
    if (P == NULL) {
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
        hapusPenulis(T, B);
    }else {
        adrRelasi Q;
        while(child(P) != NULL) {
            Q = child(P);
            deletefirstRelasi(P, Q);
        }
        deleteElmtPenulis(T, P);
    }
}
void hapusNovel(Penulis &T, Novel &N){
    string input;
    cout<<"Nama Novel yang ingin dihapus : ";
    cin>>input;
    adrNovel Nr = searchNovelList(N, input);
    if (Nr == NULL) {
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
        hapusBarang(T, N);
    }else {
        adrPenulis P = awal(T);
        adrRelasi R;
        while (P != NULL) {
            R = searchBarangRelasi(P, Nr);
            if (R != NULL) {
                deleteElmRelasi(P, R);
            }
            P = next(P);
        }
        deleteNovel(N, Nr);
    }
}
void tipeBuku();
void PenulisAlwaysSolo();
void PenulisColab();



#endif // TUBES_H_INCLUDED



