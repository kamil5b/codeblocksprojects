#include "h.h"

void createList(multiList &L){
    first_Mobil(L) = NULL;
    last_Mobil(L) = NULL;
    first_Montir(L) = NULL;
    last_Montir(L) = NULL;
}

address_Mobil allocateMobil(infotype X){
    address_Mobil P = new Mobil;
    infoL(P) = X;
    nextL(P) = NULL;
    rel(P) = NULL;
    return  P;
}

void insertMobil(address_Mobil P, multiList &L){
    if (first_Mobil(L)==NULL){
        first_Mobil(L) = P;
        last_Mobil(L) = P;
    } else {
        address_Mobil Q = last_Mobil(L);
        nextL(Q) = P;
        last_Mobil(L) = P;
    }
}

address_Mobil searchMobil(infotype X,multiList L){
    address_Mobil P = first_Mobil(L);
    while (P!=NULL && infoL(P)!=X )
        P = nextL(P);
    return P;

}

void tampilSemuaMobil(multiList L){
    address_Mobil P = first_Mobil(L);
    while (P != NULL) {

        cout<<"mobil : "<<infoL(P)<<endl;

        cout<<endl;
        P = nextL(P);
    }
}

void tambahMobil(multiList &L){
    infotype nama_mobil;
    address_Mobil P = first_Mobil(L);
    system("CLS");
    cout<<"********** TAMBAH MOBIL **********\n\n";
    tampilSemuaMobil(L);
    cout<<"Masukkan Mobil Baru : ";cin>>nama_mobil;
    while(P != NULL && infoL(P)!=nama_mobil){
        P = nextL(P);
    }
    if (P==NULL) {
        P = allocateMobil(nama_mobil);
        insertMobil(P, L);
        cout<<"\nMobil "<<nama_mobil<<" berhasil di tambahkan";
    }else if (infoL(P)==nama_mobil){
        cout<<"\nMobil "<<nama_mobil<<" sudah terdaftar";
    }
    getch();
}

void HapusMobil(multiList &L) {
    infotype nama_mobil;
    address_Mobil P = first_Mobil(L);
    if (P!=NULL){
        system("CLS");
        cout<<"********** HAPUS MOBIL **********\n\n";
        tampilSemuaMobil(L);
        cout<<"Masukkan Mobil yang akan dihapus : ";
        cin>>nama_mobil;
        P = searchMobil(nama_mobil, L);
        if (P != NULL) {
            if (P == first_Mobil(L)) {
                first_Mobil(L) = nextL(P);
                nextL(P) = NULL;
            } else if (P == last_Mobil(L)) {
                address_Mobil Q = first_Mobil(L);
                while (nextL(Q) != P) {
                    Q = nextL(Q);
                }
                nextL(Q) = NULL;
                last_Mobil(L) = Q;
            } else {
                address_Mobil Q = first_Mobil(L);
                while (nextL(Q) != P) {
                    Q = nextL(Q);
                }
                nextL(Q) = nextL(P);
                nextL(P) = NULL;
            }
            delete P;
            cout<<"\nMobil Telah dihapus";
        } else {
            cout<<"\nMobil tidak tersedia";
        }
    }else{
        cout<<"\nMobil Kosong";
    }
    getch();
}

void tampilkanMobilTertentu(multiList L) {
    infotype nama;
    address_Mobil P = first_Mobil(L);
    if (P!=NULL){
        system("CLS");
        cout<<"********** DATA **********\n\n";
        tampilSemuaMobil(L);
        cout<<"Masukkan Data Mobil : ";
        cin>>nama;
        P = searchMobil(nama, L);
        if (P != NULL) {
            address_hubungan Q = rel(P);
            if (Q != NULL) {
                cout << "\Montir yang memperbaiki mobil " << infoL(P) << " : \n";
                int i = 0;
                while (Q != NULL) {
                    if (link(Q) != NULL) {
                        i += 1;
                        cout << i << ". " << infoA(link(Q)) << endl;
                    }
                    Q = nextR(Q);
                }
            }else{
                cout<<"\nTidak ada Montir yang memperbaiki mobil ini";
            }
        } else {
            cout<<"\nMobil tidak ada";
        }
    }else{
        cout<<"\nTidak ada MObil ini";
    }
    getch();
}

void tampilkanMontirTertentu(multiList L) {
    infotype nama;
    address_Montir P = first_Montir(L);
    if (P!=NULL){
        system("CLS");
        cout<<"********** DATA **********\n\n";
        tampilSemuaMontir(L);
        cout<<"Masukkan Data Montir : ";
        cin>>nama;
        P = searchMontir(nama, L);
        if (P != NULL) {
            address_hubungan Q = rel(P);
            if (Q != NULL) {
                cout << "\Mobil yang memperbaiki montir " << infoA(P) << " : \n";
                int i = 0;
                while (Q != NULL) {
                    if (link(Q) != NULL) {
                        i++;
                        cout << i << ". " << infoA(link(Q)) << endl;


            }else{
                cout<<"\nTidak ada Mobil yang memperbaiki montir ini";
            }
            }
        } else {
            cout<<"\nMontir tidak ada";
        }
    }else{
        cout<<"\nTidak ada Montir ini";
    }
    getch();
}
}

address_Montir allocateMontir(infotype X){

    address_Montir P = new Montir;
    infoA(P) = X;
    nextA(P) = NULL;
    return P;
}


void insertMontir(address_Montir P, multiList &L){
    if (first_Montir(L)==NULL){
        first_Montir(L) = P;
        last_Montir(L) = P;
    }else{
        address_Montir Q = last_Montir(L);
        nextA(Q) = P;
        last_Montir(L) = P;
    }
}

address_Montir searchMontir(infotype X,multiList L){
    address_Montir P = first_Montir(L);
    while (P!=NULL && infoA(P)!=X )
        P = nextA(P);
    return P;
}

void tambahMontir(multiList &L){
    infotype nama_montir;
    address_Montir P = first_Montir(L);
    system("CLS");
    cout<<"********** TAMBAH MONTIR **********\n\n";
    tampilSemuaMontir(L);
    cout<<"Masukkan Nama Montir : ";cin>>nama_montir;
    while(P != NULL && infoA(P)!=nama_montir){
        P = nextA(P);
    }
    if (P==NULL) {
        P = allocateMontir(nama_montir);
        insertMontir(P, L);
        cout<<"\nMontir dengan nama "<<nama_montir<<" berhasil di tambahkan";
    }else if (infoA(P)==nama_montir){
        cout<<"\nMontir dengan nama "<<nama_montir<<" sudah terdaftar";
    }
    getch();
}
void tampilSemuaMontir(multiList L){
    address_Montir P = first_Montir(L);
    while (P != NULL) {

        cout<<"montir : "<<infoA(P)<<endl;

        cout<<endl;
        P = nextA(P);
    }
}

void HapusMontir(multiList &L) {
    infotype nama_montir;
    address_Montir P = first_Montir(L);
    if (P!=NULL){
        system("CLS");
        cout<<"********** HAPUS MONTIR **********\n\n";
        tampilSemuaMontir(L);
        cout<<"Masukkan Montir yang akan dihapus : ";
        cin>>nama_montir;
        P = searchMontir(nama_montir, L);
        address_Mobil Q = first_Mobil(L);
        while (Q!=NULL){
            HapusHubungan(Q,P);
            Q = nextL(Q);
        }
        if (P != NULL) {
            if (P == first_Montir(L)) {
                first_Montir(L) = nextA(P);
                nextA(P) = NULL;
            } else if (P == last_Montir(L)) {
                address_Montir Q = first_Montir(L);
                while (nextA(Q) != P) {
                    Q = nextA(Q);
                }
                nextA(Q) = NULL;
                last_Montir(L) = Q;
            } else {
                address_Montir Q = first_Montir(L);
                while (nextA(Q) != P) {
                    Q = nextA(Q);
                }
                nextA(Q) = nextA(P);
                nextA(P) = NULL;
            }
            cout<<"\nMontir telah di hapus";
            delete P;
        } else{
        cout<<"\nMontir Kosong"<<endl;
        }
        getch();
        }
}

address_hubungan allocateHubungan(){
    address_hubungan P = new hubungan;
    nextR(P) = NULL;
    link(P) = NULL;
    return P;
}

bool cekHubungan(address_Mobil M, address_Montir D){
    bool cek = false;
    address_hubungan R = rel(M);
    while (R != NULL && !cek){
        if (link(R)==D){
            cek = true;
        }
        R = nextR(R);
    }
    return cek;
}

void tambahHubungan(multiList &L){
    infotype input;
    string Title = "********** TAMBAH HUBUNGAN MOBIL DAN MONTIR **********\n\n";
    address_Mobil P = first_Mobil(L);
    address_Montir Q = first_Montir(L);
    bool cek = false;
    if (P==NULL || Q==NULL){
        if (P!=NULL && Q==NULL){
            cout<<"\nData Montir Tidak ada";
        }else if (P==NULL && Q!=NULL){
            cout<<"\nData Mobil Tidak ada";
        }else{
            cout<<"\nData Montir dan Mobil Tidak ada";
        }
        getch();
    }else{
        do {
            system("CLS");
            cout<<Title;
            tampilSemuaMobil(L);
            cout<<"Masukkan Mobil [Ketik 'back' untuk kembali]: "; cin>>input;
            P = searchMobil(input,L);
            if (input == "back" || P != NULL){
                cek = true;
            }else {
                cout<<"Mobil Tidak Ada";
                getch();
            }
        }while (!cek);
        cek = false;
        while (!cek && input != "back"){
            system("CLS");
            cout<<Title;
            tampilSemuaMontir(L);
            cout<<"Masukkan Nama Montir [Ketik 'back' untuk kembali]: "; cin>>input;
            Q = searchMontir(input,L);
            if (input == "back" || Q != NULL){
                cek = true;
            }else{
                cout<<"Montir Tidak Ada";
                getch();
            }
        }
        if (input != "back"){
            if (!cekHubungan(P,Q)){
                address_hubungan R = allocateHubungan();
                if (rel(P)==NULL) {
                    rel(P) = R;
                }else{
                    address_hubungan relation = rel(P);
                    while (nextR(relation)!=NULL){
                        relation = nextR(relation);
                    }
                    nextR(relation) = R;
                }
                link(R) = Q;
                cout<<"\nBerhasil menghubungkan";
            }else{
                cout<<"\nMontir "<<infoA(Q)<<" sudah melayani mobil tersebut";
            }
            cout<<"\n\nTekan Enter untuk kembali";
            getch();
        }
    }
}

void HapusHubungan(address_Mobil &M, address_Montir A){
    if (cekHubungan(M,A)){
        address_hubungan R = rel(M);
        if (link(R)==A){
            rel(M)=nextR(R);
            link(R)=NULL;
            delete R;
        }else {
            address_hubungan R2 = nextR(R);
            while (link(R2) != A) {
                R = nextR(R);
                R2 = nextR(R2);
            }
            link(R2) = NULL;
            nextR(R) = nextR(R2);
            delete R2;
        }
    }
}


void tampilMobildanMontirtertentu(multiList L) {
    address_Mobil P = first_Mobil(L);
    address_Montir x;
    address_Mobil n;

}
