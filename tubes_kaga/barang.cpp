#include "header_kaga.h"

void fixedBarang(listBarang &B,listApparel A,listBrand Br,listSize S){
    string tipe;
    IDB P;

    ifstream file1("barang.txt");

    string nama,idp,br,tipe,ukuran;
    int kwn;
    int prc;
    int i=1;
    ifstream infile;
    infile.open("nama.txt");

    if (infile.fail()){
        cerr << "Error membuka file nama" <<endl;
        exit(1);
    }

    while(file1 >> idp >> br >> tipe >> ukuran >> kwn >> prc){
        P=new barang;
        infile >> nama;
        P->ID_Gudang=i;
        P->ID_Pabrik=idp;
        P->Nama_Barang=nama;
        P->Brand_Barang=searchBarang(Br,br);
        P->Tipe_Barang=searchApparel(A,tipe);
        P->Size_Barang=searchSize(S,ukuran);
        P->kuantitas=kwn;
        P->price=prc;
        tambahBarang(B,P);
        i++
    }
}

void masukBarang(listBarang &B,listApparel A,listBrand Br,listSize S){
    IDB P,Q;
    SID ss;
    IDA aa;
    BP bbr;
    string SizeApp,TypeApp,BrandApp,nama,idpabrik;
    int kwn;
    cout << "Masukan nama barang :";
    cin >> nama;
    cout << "Masukan ID barang :";
    cin >> idpabrik;
    P=searchBarang(B,nama);
    Q=searchBarang(B,idpabrik);
    if(P!=NULL&&Q!=NULL){
        P=new barang;
        P->Nama_Barang=nama;
        P->ID_Pabrik=idpabrik;
        P->kuantitas=0;

        cout << "Tipe Apparel :";
        cin >> TypeApp;
        aa=searchApparel(A,TypeApp);
        if(aa==NULL){
            tambahApparel(A,TypeApp);
            aa=A.last;
        }
        P->Tipe_Barang=aa;

        cout << "Size Apparel :";
        cin >> SizeApp;
        ss=searchSize(S,SizeApp);
        if(ss==NULL){
            tambahSize(S,SizeApp);
            ss=S.last;
        }
        P->Size_Barang=ss;

        cout << "Brand Apparel :";
        cin >> BrandApp;
        bbr=searchBrand(Br,BrandApp);
        if(bbr==NULL){
            tambahBrand(Br,BrandApp);
        }

        cout << "Quantity :";
        cin >> kwn;
        P->kuantitas=P->kuantitas+kwn;

        cout << "Harga Apparel :";
        cin >> P->price;

        tambahBarang(B,P);

    }else{
        if(Q!=NULL&&P==NULL){
            P=Q;
        }
        cout << "Barang sudah pernah ada" <<endl;
        lihatBarang(B,P);
        cout << "Tambah/kurang kuantitas :";
        cin >> kwn;
        P->kuantitas=P->kuantitas+kwn;
        cout << "Kuantitas menjadi " << P->kuantitas <<endl;
    }
}

void tambahBarang(listBarang &B,IDB P){
    if(B.last==NULL){
        B.last=P;
        B.first=P;
    }else{
        (B.last)->next=P;
        P->prev=B.last;
        B.last=P;
    }
    B.id=B.id+1;
    P->ID_Gudang=B.id;
}

void lihatBarang(listBarang B, IDB P){
    SID S;
    IDA A;
    BP Br;
    if(P!=NULL){
        S=P->Size_Barang;
        A=P->Tipe_Barang;
        Br=P->Brand_Barang;
        cout << "ID Gudang\t:" << P->ID_Gudang <<endl;
        cout << "ID Barang\t:" << P->ID_Pabrik <<endl;
        cout << "Nama Barang\t:" << P->Nama_Barang <<endl;
        cout << "Brand Apparel\t:" << Br->namaBrand << endl;
        cout << "Tipe Apparel\t:" << A->tipe_apparel <<endl;
        cout << "Size Apparel\t:" << S->Size_apparel <<endl;
        cout << "Kuantitas\t:" << P->kuantitas << endl;
        cout << "Harga\t\t:" << P->price << endl;
    }
}

void updateBarang(listBarang &B,listApparel A,listBrand Br,listSize S,string id){
    IDB P,Q;
    BP BB;
    IDA AA;
    SID SS;
    int choose;
    string nama,idn,br,tipe,ukuran;
    int prc;
    P=searchBarang(B,id);
    if(P!=NULL){
        lihatBarang(B,P);
        cout << "Update kategori :" << endl;
        cout << "1. ID Barang" << endl;
        cout << "2. Nama Barang" << endl;
        cout << "3. Brand Barang" << endl;
        cout << "4. Tipe Barang" << endl;
        cout << "5. Size Barang" << endl;
        cout << "6. Harga" << endl;
        cout << "Pilih kategori (0 untuk keluar) :";
        cin >> choose;
        while(choose<0||choose>=7){
            cout << "Pilih kategori (0 untuk keluar) :";
            cin >> choose;
        }
        switch(choose){
        case 1:
            cout << "ID Barang yang baru :";
            cin >> idn;
            Q=searchBarang(B,idn);
            if(Q!=NULL){
                P->ID_Pabrik=idn;
            }else{
                cout << "ID Sudah pernah ada sebelumnya" <<endl;
            }
            break;
        case 2:
            cout << "Nama Barang baru :";
            cin >> nama;
            Q=searchBarang(B,nama);
            if(Q!=NULL){
                P->Nama_Barang=nama;
            }else{
                cout << "Nama barang pernah ada sebelumnya" <<endl;
            }
            break;
        case 3:
            cout << "Brand Barang baru :";
            cin >> br;
            BB=searchBrand(Br,br);
            if(BB==NULL){
                tambahBrand(Br,br);
                P->Brand_Barang=Br.last;
            }else{
                P->Brand_Barang=BB;
            }
            break;
        case 4:
            cout << "Tipe apparel barang baru :";
            cin >> tipe;
            AA=searchApparel(A,tipe);
            if(AA==NULL){
                tambahApparel(A,tipe);
                P->Tipe_Barang=A.last;
            }else{
                P->Tipe_Barang=AA;
            }
        case 5:
            cout << "Size barang baru :";
            cin >> ukuran;
            SS=searchSize(S,ukuran);
            if(SS==NULL){
                tambahSize(S,ukuran);
                P->Size_Barang=S.last;
            }else{
                P->Size_Barang=SS;
            }
        case 6:
            cout << "Kuantitas barang baru :";
            cin >> prc;
            P->price=prc;
        }
    }else{
        cout << "Barang tidak ditemukan"<<endl;
    }
}

void printBarang(listBarang B){
    ofstream file1,file2;
    IDB P;

    file1.open("barang.txt");
    file2.open("nama.txt");
    P=B.first;
    while(P!=NULL){
        file1 << P->ID_Pabrik <<" "<< P->Brand_Barang << " " << P->Tipe_Barang <<" "<< P->Size_Barang <<" "<< P->kuantitas <<" "<< P->price <<"\n";
        file2 << P->Nama_Barang << "\n";
        P=P->next;
    }
    file1.close();
    file2.close();
}
