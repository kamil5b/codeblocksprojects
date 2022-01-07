#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

//Mendefinisikan ID dengan 8 digit (yang terpakai index 0-7)
typedef char id[9];

//iterator
int i;

//List barang bentuknya adalah Tree
struct Barang
{
    id ID;
    char nama[30];
    int harga_pokok;
    struct Barang *left,*right;
}*treeBarang,*nodeBarang;

//untuk history transaksi, pakai metode Stack
struct linkedlist
{
	struct Barang *barang;
	struct Pegawai *kasir;
	int harga,nomor_transaksi,jumlah;
	struct linkedlist *next, *prev;
}*node,*top;

//Untuk list pegawai, bentuknya hash table
struct Pegawai{
    char nama[30];
    int umur;
     struct Pegawai *next;
}*hash_pegawai;

//Hash table untuk pegawai (ada 15 slot)
struct Pegawai *listPegawai[15];

bool idSama(id ID1,id ID2){

    /*Dikarenakan yang terpakai index 0-7, maka
        tidak bisa ID1==ID2 dikarenakan index ke 8
        bisa saja beda, maka fungsi ini mengecek
        apakah index 0-7 ID1 sama dengan ID2 atau tidak
    */
    //printf("%s %s\n",ID1,ID2);
    i=0;
    while(i<8){
        if(ID1[i]!=ID2[i]){
            return false;
        }
        i++;
    }
    return true;
}
bool namaSama(char nama1[30],char nama2[30]){

    int length;
    if(strlen(nama1)>=strlen(nama2)){
        length=strlen(nama1);
    }else{
        length=strlen(nama2);
    }
    i=0;
    while(i<length-1){
        if(nama1[i]!=nama2[i]){
            return false;
        }
        i++;
    }
    return true;
}

//-------------------FUNCTION PEGAWAI
void createListPegawai(){
    /*
    Hash table di set semuanya menunjuk NULL
    */
    i=0;
    while(i<15){
        listPegawai[i]=NULL;
        i++;
    }
}
unsigned int hashPegawai(char nama[30],int umur){
    /*
    Hashing, rumusnya yaitu setiap desimal char dari nama
    dan di kali umur, lalu di modulasi 15
    karna ada 15 slot dalam hash table
    */
    unsigned int value=0;
    int length=strlen(nama);
    i=0;
    while(i<length){
        value+=nama[i];
        value*=umur;
        i++;
    }
    value=value % 15;
    return value;
}
struct Pegawai * cariPegawai(char nama[30],int umur){
    /*
    cari dengan hash table sangat simple,
    dari nama dan umur di hashing lalu keluarlah
    value hash nya

    lalu menunjuk index tersebut dan cek apakah
    namanya sama atau tidak, kalau belum maka di next
    lalu jika ada keluarkan itu dan jika tidak ada keluarkan NULL

    */
    struct Pegawai * P;
    int index=hashPegawai(nama,umur);
    P=listPegawai[index];
    if(P!=NULL){
        while(P!=NULL&&!namaSama(P->nama,nama)){
            P=P->next;
        }
    }
    return P;
}
void insertHash(char nama[30],int umur){
    /*
    untuk insert hash simple saja, dengan
    nama dan umur di hashing dan akhirnya keluarlah
    value hash untuk index hash table

    jika NULL maka di-isi oleh elemen baru ini
    jika sudah ada maka sambung dengan sebelumnya dengan insert last
    */
    struct Pegawai *P,*Q;
    int index=hashPegawai(nama,umur);
    P = cariPegawai(nama,umur);
    if(P==NULL){
        P = (struct Pegawai*)malloc(sizeof(struct Pegawai));
        P->next=NULL;
        strcpy(P->nama,nama);
        P->umur=umur;

        if(listPegawai[index]==NULL){
           listPegawai[index]=P;
        }else{
            Q=listPegawai[index];
            while(Q->next!=NULL){
                Q=Q->next;
            }
            Q->next=P;
        }

    }
}
void deleteHash(char nama[30],int umur){
    /*
    cari elemen hashnya, jika ada delete last
    lalu di destroy atau delete atau di free
    */
    struct Pegawai *P,*Q;
    int index=hashPegawai(nama,umur);
    P = cariPegawai(nama,umur);
    if(P!=NULL){
        node = top;
        while(node!=NULL){
            if(node->kasir->nama==nama){
                node->kasir=NULL;
            }
            node=node->prev;
        }

        if(listPegawai[index]==P){
           listPegawai[index]=NULL;
        }else{
            Q=listPegawai[index];
            while(Q->next!=NULL){
                Q=Q->next;
            }
            Q->next=P->next;
            P->next=NULL;
        }
        free(P);
    }
}

//-------------------FUNCTION TRANSAKSI
struct linkedlist *createNode(struct Barang *barang,struct Pegawai * pegawai,int harga,int nomor_transaksi){
    /*
    buat node barangnya
    */
    node = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	node->barang=barang;
	//printf("%s %s\n",node->barang->ID,barang->ID);
	node->kasir=pegawai;
	node->jumlah=0;
	node->harga=harga;
	node->nomor_transaksi=nomor_transaksi;
	node->next=NULL;
	node->prev=NULL;
	return node;
}
//PUSH and POP ini buat stack transaksi
void push(struct linkedlist *n){
    if(top!=NULL){
        top->next=n;
        n->prev=top;
    }
    top=n;
}
void pop(){
    node=top;
    if(top->next==NULL&&top->prev==NULL){
        top=NULL;
    }else{
        top=node->prev;
        top->next=NULL;
        node->prev=NULL;
    }
    free(node);
}

//------------------FUNCTION TREE BARANG
//Cari buat dan tambah barang tree langsung ter-sort
struct Barang * cariBarang(struct Barang * root,id cari){
    if(root==NULL||idSama(root->ID,cari)){
        return root;
    }else if(root->ID < cari){
        return cariBarang(root->left,cari);
    }else{
        return cariBarang(root->right,cari);
    }
}
struct Barang * buatBarang(id idBarang, char nama[30],int harga){
    struct Barang * P;
    P=(struct Barang*)malloc(sizeof(struct Barang));
    strcpy(P->nama,nama);
    strcpy(P->ID,idBarang);
    P->harga_pokok=harga;
    P->left=NULL;
    P->right=NULL;
    return P;
}
struct Barang * tambahBarang(struct Barang * root,id idBarang, char nama[30],int harga){
    if(root==NULL){
        return buatBarang(idBarang,nama,harga);
    }
    if(idBarang > root->ID){
        root->right = tambahBarang(root->right,idBarang,nama,harga);
    }else if(idBarang < root->ID){
        root->left = tambahBarang(root->left,idBarang,nama,harga);
    }
    return root;
}
//Min Value untuk mencari value paling rendah
struct Barang * minValueNode(struct Barang * P)
{
    struct Barang * current = P;

    while (current != NULL && current->left != NULL){
        current = current->left;
    }
    return current;
}
//Delete akan ada 3 cara
struct Barang * deleteNode(struct Barang * root, id cari)
{
    //Disini untuk mencari node yang akan dihapus
    if (root == NULL) return root;
    if(idSama(root->ID,cari))
    {
        /*JIKA DITEMUKAN
            Cek apakah dia punya child atau tidak
            jika tidak ada langsung delete
            jika ada satu, maka child itu menggantikannya

            jika ada dua, cari minimum value dari node itu
            lalu gantikan node tersebut
        */
        printf("Ditemukan!\n");
        if (root->left == NULL)
        {
            printf("Terhapus!\n");
            struct Barang *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            printf("Terhapus!\n");
            struct Barang *temp = root->left;
            free(root);
            return temp;
        }
        struct Barang* temp = minValueNode(root->right);
        strcpy(root->ID,temp->ID);
        strcpy(root->nama,temp->nama);
        root->harga_pokok=temp->harga_pokok;
        root->right = deleteNode(root->right, temp->ID);
    }
    else if (cari < root->ID){
        root->left = deleteNode(root->left, cari);
    }
    else if (cari > root->ID)
    {
        root->right = deleteNode(root->right, cari);
    }
    return root;
}
void deleteBarang(id idBarang){

    /*Delete barang dengan cara null kan dahulu
    barang2 di stack barang
    lalu di delete nodenya */

    node=top;
    while(node!=NULL){
        if(node->barang->ID==idBarang){
            node->barang=NULL;
        }
        node=node->prev;
    }

    treeBarang=deleteNode(treeBarang,idBarang);

    printf("Telah dihapus\n");

}

//------------------PRINT FUNCTION
void printGudang(struct Barang * root){
    //Print In-Order seluruh barang
    if(root!=NULL){
        printGudang(root->left);
        printf("%s \t %s \t %d \n",root->ID,root->nama,root->harga_pokok);
        printGudang(root->right);
    }
}
void printTransaksi(struct linkedlist * top,int nomor_transaksi){
    //Print semua transaksi di stack
    int total=0;
    struct linkedlist * P=top;
    char karyawan[15];
    printf("\n");
    printf("ID barang\tNama Barang\tHarga Satuan\tJumlah\tTotal Harga\n");
    while(P!=NULL){
        if(P->nomor_transaksi==nomor_transaksi&&P->barang!=NULL&&P->kasir!=NULL){
            total=total+P->harga;
            printf("%s\t%s\t\t%d\t%d\t%d\n",P->barang->ID,P->barang->nama,P->harga,P->jumlah,total);
            strcpy(karyawan,P->kasir->nama);
        }
        P=P->prev;
    }
    if(total!=0){
        printf("Harga total : %d",total);
        printf("Karyawan : %s",karyawan);
        printf("Nomor Transaksi : %d",nomor_transaksi);
    }else{
        printf("Tidak ada transaksi dengan nomor tersebut");
    }
}
void printPegawai(struct Pegawai * P){
    //Print pegawai satuan
    if(P!=NULL){
        printf("\n");
        printf("Nama : %s\n",P->nama);
        printf("Umur : %d",P->umur);
    }
}

//-----------------EDIT FUNCTION
//TRANSAKSI TIDAK BISA DI EDIT
void editPegawai(char nama[30],int umur){
    struct Pegawai * temp;
    char nabur[30];
    int ubur;
    hash_pegawai=cariPegawai(nama,umur);
    if(hash_pegawai!=NULL){
        /*
        Jika elemen ditemukan, maka proses edit dilakukan
        setelah itu insertHash yang baru dan alihkan seluruh
        transaksi yang menunjuk ke pegawai yang lama ke pegawai yang baru
        lalu delete pegawai yang lama
        */
        printf("Nama ditemukan\n");
        temp=hash_pegawai;
        printf("\n");
        printf("Nama Pegawai Baru: ");
        scanf("%s",&nabur);
        printf("Umur Pegawai Baru : ");
        scanf("%d",&ubur);
        //Buat pegawai baru
        insertHash(nabur,ubur);
        node=top;
        //Alihkan seluruh transaksi yang menunjuk pegawai lama ke pegawai yang baru
        while(node!=NULL){
            if(node->kasir==temp){
                node->kasir=hash_pegawai;
            }
            node=node->prev;
        }
        //delete pegawai baru
        deleteHash(nama,umur);

    }else{
        printf("Nama karyawan tidak ditemukan");
    }
}
void editBarang(struct Barang * tree,id ID){
    struct Barang * P;
    P=cariBarang(tree,ID);
    if(P!=NULL){
        printf("ID Barang\tNama Barang\tHarga Pokok\n");
        printf("%s\t%s\t%d\n",tree->ID,tree->nama,tree->harga_pokok);
        printf("Nama barang : ");
        scanf("%s",&tree->nama);
        printf("Harga Pokok : ");
        scanf("%d",&tree->harga_pokok);
    }
}

//-----------------Fungsi transaksi
void Transaksi(struct Pegawai * kasir,int *noTransaksi){
    id ID;
    bool flag;
    char yn;
    int diskon,harga,jumlah;
    struct Barang *b;
    do{
        //FUNGSI INI AKAN LOOPING
        do{
            printf("\nID Barang (berhenti dengan masukan 00000000): ");
            scanf("%s",&ID);
        }while(strlen(ID)>8);
        //JIKA INPUT DIMASUKAN 0000000 MAKA FUNGSI BERHENTI
        flag=false;
        int i=0;
        while(i<8&&!flag){
            if(ID[i]!='0'){
                flag=true;
            }
            i++;
        }
        b=cariBarang(treeBarang,ID);
        if(b!=NULL&&flag){
            printf("Diskon (0 jika tidak ada diskon, 200 jika void): ");
            scanf("%d",&diskon);
            printf("Jumlah barang : ");
            scanf("%d",&jumlah);
            harga=(b->harga_pokok - ( b->harga_pokok * diskon / 100))*jumlah;
            node=createNode(b,kasir,harga,*noTransaksi);
            node->jumlah=jumlah;
            push(node);
            printf("%s\t",top->barang->ID);
            printf("%s\t",top->barang->nama);
            printf("%d\t",top->harga);
            printf("%d\t",top->jumlah);
            printf("%s\n",top->kasir->nama);
            do{
                printf("Cancel (Y/N) ? ");
                scanf("%c",&yn);
            }while(yn!='Y'&&yn!='N');
            if(yn=='Y'){
                pop();
                printf("Telah di cancel");
            }
        }else{
            printf("barang tidak ada\n");
        }
    }while(flag);
    printf("Nomor Transaksi : %d",top->nomor_transaksi);
    *noTransaksi++;
}

//-----------------FUNGSI MAIN
int main()
{
    id ID;
    int pilihan,nomor,umur,total;
    char nama[30];
    bool ada;
    createListPegawai();
    treeBarang=NULL;
    top=NULL;
    nomor=0;
    printf("Hello world!\n");
    do
    {
        //MENU akan looping sampai inputnya 0
        printf("\n");
        printf("0.Keluar\n");
        printf("1.Transaksi\n");
        printf("2.Tambah barang\n");
        printf("3.Tambah Karyawan\n");
        printf("4.Lihat Penghasilan Total\n");
        printf("5.Lihat Semua Barang\n");
        printf("6.Cari Barang\n");
        printf("7.Lihat Semua Karyawan\n");
        printf("8.Lihat Transaksi dari nomor\n");
        printf("9.Hapus barang\n");
        printf("10.Hapus karyawan\n");
        printf("11.Edit barang\n");
        printf("12.Edit karyawan\n");
        printf("Pilih : ");
        scanf("%d",&pilihan);
        switch(pilihan){
        case 1:
            printf("Nama Kasir : ");
            scanf("%s",&nama);
            printf("Umur : ");
            scanf("%d",&umur);
            hash_pegawai=cariPegawai(nama,umur);
            if(hash_pegawai!=NULL){
                Transaksi(hash_pegawai,&nomor);
            }else{
                printf("Nama kasir tidak dikenali, belum terdaftar");
            }
            break;
        case 2:
            do{
                printf("ID Barang (8 digit) : ");
                scanf("%s",&ID);
            }while(strlen(ID)>8);

            printf("Nama : ");
            scanf("%s",&nama);

            printf("Harga barang : ");
            scanf("%d",&total);

            nodeBarang=cariBarang(treeBarang,ID);
            printf("\n");
            if(nodeBarang==NULL){
                treeBarang=tambahBarang(treeBarang,ID,nama,total);

                printf("Baraang berhasil ditambahkan\n");
            }else{
                printf("Barang sudah pernah ada\n");
            }
            break;
        case 3:
            printf("Nama Kasir : ");
            scanf("%s",&nama);
            printf("Umur : ");
            scanf("%d",&umur);

            hash_pegawai=cariPegawai(nama,umur);
            if(hash_pegawai==NULL){
                insertHash(nama,umur);
                printf("Berhasil ditambahkan\n");
            }else{
                printf("Kasir sudah ada sebelumnya");
            }
            break;
        case 4:
            total=0;
            node=top;
            while(node!=NULL){
                total=total+node->harga;
                node=node->prev;
            }
            printf("Total pendapatan : %d\n",total);
            break;
        case 5:
            printGudang(treeBarang);
            break;
        case 6:
            do{
                printf("ID Barang (8 digit) : ");
                scanf("%s",&ID);
            }while(strlen(ID)>8);
            nodeBarang=cariBarang(treeBarang,ID);
            if(nodeBarang!=NULL){
                printf("%s \t %s \t %d \n",nodeBarang->ID,nodeBarang->nama,nodeBarang->harga_pokok);
            }else{
                printf("Barang tidak ditemukan");
            }
            break;
        case 7:
            i=0;
            while(i<15){
                hash_pegawai=listPegawai[i];
                while(hash_pegawai!=NULL){
                    printf("\n");
                    printPegawai(hash_pegawai);
                    hash_pegawai=hash_pegawai->next;
                }
                i++;
            }
            break;
        case 8:
            i=0;
            while(i<nomor){
                node=top;
                ada=false;
                while(node!=NULL&&!ada){
                    if(node->nomor_transaksi==i){
                        ada=true;
                    }
                    node=node->prev;
                }
                if(ada){
                    printf("%d ",i);
                }
                i++;
            }
            printf("\nPilih nomor transaksi : ");
            scanf("%d",&nomor);
            printTransaksi(top,nomor);
            break;
        case 9:
            do{
                printf("ID Barang yang dihapus (8 digit) : ");
                scanf("%s",&ID);
            }while(strlen(ID)>8);
            nodeBarang=cariBarang(treeBarang,ID);
            if(nodeBarang!=NULL){
                deleteBarang(ID);
            }
            break;
        case 10:
            printf("Nama Kasir : ");
            scanf("%s",&nama);
            printf("Umur : ");
            scanf("%d",&umur);

            hash_pegawai=cariPegawai(nama,umur);
            if(hash_pegawai!=NULL){
                deleteHash(nama,umur);
                printf("Berhasil dihapus\n");
            }else{
                printf("Kasir belum terdaftar\n");
            }
            break;
        case 11:

            do{
                printf("ID Barang (8 digit) : ");
                scanf("%s",&ID);
            }while(strlen(ID)>8);
            editBarang(treeBarang,ID);

            break;
        case 12:
            printf("Nama Kasir : ");
            scanf("%s",&nama);
            printf("Umur : ");
            scanf("%d",&umur);

            editPegawai(nama,umur);
            break;
        }
    }
    while(pilihan!=0);
    return 0;
}
