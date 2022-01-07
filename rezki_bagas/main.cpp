#include "header.h"

int main()
{
    int pilih;
    string key,judul;
    p_pointer P;
    r_pointer R;
    k_pointer K;

    paperList Lp;
    keywordList Lk;

    buatKeywordList(Lk);
    buatPaperList(Lp);

    pilih=0;

    while(pilih!=99){
        cout << endl;
        cout << "~~~~~~~~~~~~~" << endl;
        cout << "99 -> Keluar" << endl;
        cout << "1 -> Tambah Paper" << endl;
        cout << "2 -> Tambah kata kunci ke paper" << endl;
        cout << "3 -> Hapus Paper" << endl;
        cout << "4 -> Hapus kata kunci" << endl;
        cout << "5 -> Kata kunci paling populer" << endl;
        cout << "6 -> Cari Paper dari kata kunci" << endl;
        cout << "7 -> Cari kata kunci dari paper" << endl;
        cout << "8 -> Lihat semua Paper" << endl;
        cout << "9 -> Lihat semua Keyword" << endl;
        cout << "Pilih angka : ";
        cin >> pilih;

        switch(pilih){
        case 1:
            cout << "Judul paper (jangan ada spasi) : ";
            cin >> judul;
            tambahPaper(judul,Lp);
            cout << "Tambah kata kunci (untuk berhenti masukan STOP) :" << endl;
            cin >> key;
            while(key!="STOP"){
                K=cariKeyword(key,Lk);
                if(K==NULL){
                    tambahKeyword(key,Lk);
                    K=Lk.first;
                }
                PaperKeyword(Lp.first,K);
                cout << "Tambah kata kunci (untuk berhenti masukan STOP) :" << endl;
                cin >> key;
            }
            cout << "Penambahan kata kunci telah berhenti." << endl;
            cout << "Paper dan kata kunci berhasil ditambahkan!" << endl;
            break;
        case 2:
            cout << "Masukan judul paper : ";
            cin >> judul;
            P=cariPaper(judul,Lp);
            if(P!=NULL){
                lihatPaperAndKey(P,Lk);
                cout << "Tambah kata kunci (untuk berhenti masukan STOP) :" << endl;
                cin >> key;
                while(key!="STOP"){
                    K=cariKeyword(key,Lk);
                    if(K==NULL){
                        tambahKeyword(key,Lk);
                        K=Lk.first;
                    }
                    PaperKeyword(P,K);
                    cout << "Tambah kata kunci (untuk berhenti masukan STOP) :" << endl;
                    cin >> key;
                }
                cout << "Penambahan kata kunci telah berhenti." << endl;
                cout << "Paper dan kata kunci berhasil ditambahkan!" << endl;
            }else{
                cout << "Paper tidak ditemukan" << endl;
            }
            break;
        case 3:
            cout << "Judul Paper : ";
            cin >> judul;
            P=cariPaper(judul,Lp);
            if(P!=NULL){
                deletePaper(P,Lp,Lk);
            }else{
                cout << "Judul paper tidak ditemukan" << endl;
            }
            break;
        case 4:
            cout << "Kata kunci : ";
            cin >> key;
            K=cariKeyword(key,Lk);
            if(K!=NULL){
                deleteKeyword(K,Lk);
            }else{
                cout << "Kata kunci tidak ditemukan" << endl;
            }
            break;
        case 5:
            popularKeywordPaper(Lk);
            break;
        case 6:
            cout << "Kata kunci : ";
            cin >> key;
            K=cariKeyword(key,Lk);
            if(K!=NULL){
                R=K->relasi;
                while(R!=NULL){
                    cout << R->paper->judul << endl;
                    R=R->next;
                }
            }else{
                cout << "Tidak ada kata kunci " << key << endl;
            }
            break;
        case 7:
            cout << "Judul paper : ";
            cin >> judul;
            P=cariPaper(judul,Lp);
            if(P!=NULL){
                cout << "Kata kunci : ";
                K=Lk.first;
                while(K!=NULL){
                    R=K->relasi;
                    while(R!=NULL){
                        if(R->paper==P){
                            cout << K->key << " ";
                        }
                        R=R->next;
                    }
                    K=K->next;
                }
                cout << endl;
            }else{
                cout << "Tidak ada judul paper" <<endl;
            }
            break;
        case 8:
            P=Lp.first;
            while(P!=NULL){
                lihatPaperAndKey(P,Lk);
                P=P->next;
            }
            break;
        case 9:
            K=Lk.first;
            while(K!=NULL){
                lihatKeywordAndPaper(K);
                K=K->next;
            }
            break;
        }
    }
    return 0;
}
