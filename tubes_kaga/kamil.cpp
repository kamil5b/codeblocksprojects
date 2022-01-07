#include "header_kaga.h"

//buat
void buatLS(listSize &L){
    L.first=NULL;
    L.last=NULL;
}
void buatLB(listBarang &L){
    L.first=NULL;
    L.id=0;
    L.last=NULL;
}
void buatLBrand(listBrand &L){
    L.first=NULL;
    L.last=NULL;
}
void buatLA(listApparel &L){
    L.first=NULL;
    L.last=NULL;
}
//register
void fixedSize(listSize &S){ //26-46,XS,S,M,L,XL,XXL,XXXL
    string ss;

    ifstream infile;
    infile.open("size.txt");

    if (infile.fail()){
        cerr << "Error membuka file size" <<endl;
        exit(1);
    }

    while(!infile.eof()){
        infile >> ss;
        tambahSize(S,ss);
    }
    /*
    tambahSize(S,"XS");
    tambahSize(S,"S");
    tambahSize(S,"M");
    tambahSize(S,"L");
    tambahSize(S,"XL");
    tambahSize(S,"XXL");
    tambahSize(S,"XXXL");
    tambahSize(S,"26");
    tambahSize(S,"27");
    tambahSize(S,"28");
    tambahSize(S,"29");
    tambahSize(S,"30");
    tambahSize(S,"31");
    tambahSize(S,"32");
    tambahSize(S,"33");
    tambahSize(S,"34");
    tambahSize(S,"35");
    tambahSize(S,"37");
    tambahSize(S,"38");
    tambahSize(S,"39");
    tambahSize(S,"40");
    tambahSize(S,"41");
    tambahSize(S,"42");
    tambahSize(S,"43");
    tambahSize(S,"44");
    tambahSize(S,"45");
    tambahSize(S,"46");
    */
}
void fixedBrand(listBrand &Br){
    string br;

    ifstream infile;
    infile.open("brand.txt");

    if (infile.fail()){
        cerr << "Error membuka file brand" <<endl;
        exit(1);
    }

    while(!infile.eof()){
        infile >> br;
        tambahBrand(Br,br);
    }
}
void fixedApparel(listApparel &A){
    string tipe;

    ifstream infile;
    infile.open("apparel.txt");

    if (infile.fail()){
        cerr << "Error membuka file apparel" <<endl;
        exit(1);
    }

    while(!infile.eof()){
        infile >> tipe;
        tambahApparel(A,tipe);
    }
}
//add
void tambahBrand(listBrand &B, string nama_brand){
    BP P,Q;
    P=new brand;
    P->namaBrand=nama_brand;
    Q=B.last;
    if(B.last==NULL){
        B.first=P;
        B.last=P;
    }else{
        P->prev=B.last;
        Q->next=P;
        P->next=NULL;
        B.last=P;
    }
}
void tambahApparel(listApparel &A, string nama_apparel){
    IDA P,Q;
    P=new apparel;
    P->tipe_apparel=nama_apparel;
    Q=A.last;
    if(A.last==NULL){
        A.first=P;
        A.last=P;
    }else{
        P->prev=A.last;
        Q->next=P;
        P->next=NULL;
        A.last=P;
    }
}
void tambahSize(listSize &L,string S){
    SID P,Q;
    P=new Size;
    P->Size_apparel=S;
    Q=L.last;
    if(L.last==NULL){
        L.first=P;
        L.last=P;
    }else{
        P->prev=L.last;
        Q->next=P;
        P->next=NULL;
        L.last=P;
    }
}
//search
IDB searchBarang(listBarang B, string idbarang){
    IDB P;
    P=B.first;
    while(P!=NULL&&P->Nama_Barang!=idbarang&&P->ID_Pabrik!=idbarang){
        P=P->next;
    }
    return P;
}
SID searchSize(listSize S,string ss){
    SID P;
    P=S.first;
    while(P!=NULL&&P->Size_apparel!=ss){
        P=P->next;
    }
    return P;
}
IDA searchApparel(listApparel A,string tipe){
    IDA P;
    P=A.first;
    while(P!=NULL&&P->tipe_apparel!=tipe){
        P=P->next;
    }
    return P;
}
BP searchBrand(listBrand B,string br){
    BP P;
    P=B.first;
    while(P!=NULL&&P->namaBrand!=br){
        P=P->next;
    }
    return P;
}
//delete
void deleteSize(listSize &S,SID &ss,listBarang B){
    SID P;
    IDB Q;

    if(ss!=NULL){
        Q=B.first;
        while(Q!=NULL){
            if(Q->Size_Barang==ss){
                Q->Size_Barang=NULL;
            }
            Q=Q->next;
        }
        P=S.first;
        if(P!=ss){
            while(P->next!=ss&&P!=NULL){
                P=P->next;
            }
            if(P!=NULL){
                P->next=ss->next;
                (P->next)->prev=P;
                ss->next=NULL;
                ss->prev=NULL;
            }
        }else{
            S.first=P->next;
            (S.first)->prev=NULL;
            P->next=NULL;
            ss=P;
        }
    }

}
void deleteApparel(listApparel &S,IDA &ss,listBarang B){
    IDA P;
    IDB Q;

    if(ss!=NULL){
        Q=B.first;
        while(Q!=NULL){
            if(Q->Tipe_Barang==ss){
                Q->Tipe_Barang=NULL;
            }
            Q=Q->next;
        }
        P=S.first;
        if(P!=ss){
            while(P->next!=ss&&P!=NULL){
                P=P->next;
            }
            if(P!=NULL){
                P->next=ss->next;
                (P->next)->prev=P;
                ss->next=NULL;
                ss->prev=NULL;
            }
        }else{
            S.first=P->next;
            (S.first)->prev=NULL;
            P->next=NULL;
            ss=P;
        }
    }

}
void deleteBrand(listBrand &S,BR &ss,listBarang B){

    BR P;
    IDB Q;

    if(ss!=NULL){
        Q=B.first;
        while(Q!=NULL){
            if(Q->Brand_Barang==ss){
                Q->Brand_Barang=NULL;
            }
            Q=Q->next;
        }
        P=S.first;
        if(P!=ss){
            while(P->next!=ss&&P!=NULL){
                P=P->next;
            }
            if(P!=NULL){
                P->next=ss->next;
                (P->next)->prev=P;
                ss->next=NULL;
                ss->prev=NULL;
            }
        }else{
            S.first=P->next;
            (S.first)->prev=NULL;
            P->next=NULL;
            ss=P;
        }
    }

}
