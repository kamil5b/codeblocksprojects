#include "header.h"

void menu(docList &Ld,tagList &Lt,doctagList &Ldt){
    int pilihan;
    string nama_doc,nama_tag;
    tag T,T2;
    doc D;
    doc_tag Dt;

    do{
        cout << endl;
        cout << "================" <<endl;
        cout << "0.Keluar" << endl;
        cout << "1.Tambah document" << endl;
        cout << "2.Tambah tag" << endl;
        cout << "3.Tambahkan document tag" << endl;
        cout << "4.Delete document" << endl;
        cout << "5.Delete tag" << endl;
        cout << "6.Lihat semua document" << endl;
        cout << "7.Tag paling popular" << endl;
        cout << "8.Document dengan tag terbanyak" << endl;
        cout << "9.Document dengan tag tersedikit" << endl;
        cout << "10.Cari document dengan 2 tags" << endl;
        cout << "11.Cari document" << endl;
        cout << "12.Cari tag" << endl;
        cout << "Pilih (angka) :";
        cin >> pilihan;

        while(pilihan < 0 || pilihan > 12){
            cout << "Pilih (angka) :";
            cin >> pilihan;
        }

        switch(pilihan){
        case 1:
            cout << "Nama document :";
            cin >> nama_doc;
            D=searchDocument(nama_doc,Ld);
            if(D==NULL){
                addDocument(nama_doc,Ld);
                cout << "Document berhasil di tambahkan!" << endl;
            }else{
                cout << "Sudah ada nama document yang sama" << endl;
                showDocumentsWithTags(D,Ldt);
            }
            break;
        case 2:
            cout << "Nama tag :";
            cin >> nama_tag;
            T=searchTag(nama_tag,Lt);
            if(T==NULL){
                addTags(nama_tag,Lt);
                cout << "Tag " << T->jumlahDocs <<" berhasil ditambahkan!" << endl;
            }else{
                cout << "Sudah ada nama tag yang sama!" << endl;
                showDocumentsFromTag(T,Ldt);
            }
            break;
        case 3:
            cout << "Nama document :";
            cin >> nama_doc;
            D=searchDocument(nama_doc,Ld);
            if(D!=NULL){
                cout << "Nama tag :";
                cin >> nama_tag;
                T=searchTag(nama_tag,Lt);
                if(T==NULL){
                    addTags(nama_tag,Lt);
                    T=Lt.last;
                }
                documentTagging(D,T,Ldt);
                cout << "Berhasil!" << endl;
            }else{
                cout << "Nama document tidak ditemukan" << endl;
            }
            break;
        case 4:
            cout << "Nama document :";
            cin >> nama_doc;
            D=searchDocument(nama_doc,Ld);
            if(D!=NULL){
                deleteDocument(D,Ld,Ldt,Lt);
                cout << "Document telah berhasil dihapus" << endl;
            }else{
                cout << "Nama document tidak ditemukan" << endl;
            }
        break;
        case 5:
            cout << "Nama tag :";
            cin >> nama_tag;
            T=searchTag(nama_tag,Lt);
            if(T!=NULL){
                deleteTags(T,Lt,Ldt,Ld);
                cout << "Tag "<<T->jumlahDocs << " berhasil dihapus" << endl;
            }else{
                cout << "Nama tag tidak ditemukan" << endl;
            }
            break;
        case 6:
            D=Ld.first;
            while(D!=NULL){
                showDocumentsWithTags(D,Ldt);
                D=D->next;
            }
            break;
        case 7:
            T=popularTag(Lt);
            if(T!=NULL){
                cout << "Tag paling popular adalah " << T->jumlahDocs << " karena mempunyai " << T->jumlahDocs << " Document" << endl;
                showDocumentsFromTag(T,Ldt);
            }else{
                cout << "Tidak ada tags yang popular";
            }
            break;
        case 8:
            D=searchDocumentMaxTag(Ld);
            cout << "Document yang mempunyai tags terbanyak adalah " << D->nama << " dengan " << D->jumlahTags << " tags" << endl;
            showDocumentsWithTags(D,Ldt);
            break;
        case 9:
            D=searchDocumentMinTag(Ld);
            cout << "Document yang mempunyai tags tersedikit adalah " << D->nama << " dengan " << D->jumlahTags << " tags" << endl;
            showDocumentsWithTags(D,Ldt);
            break;
        case 10:
            cout << "Tags pertama :";
            cin >> nama_tag;
            T=searchTag(nama_tag,Lt);
            if(T!=NULL){
                cout << "Tags kedua :";
                cin >> nama_tag;
                T2=searchTag(nama_tag,Lt);
                if(T2!=NULL){
                    showDocumentsFrom2Tags(T,T2,Ldt);
                }else{
                    cout << "Tags tidak ditemukan" << endl;
                }
            }else{
                cout << "Tags tidak ditemukan" << endl;
            }
            break;
        case 11:
            break;
        case 12:
            break;
        }

    }while(pilihan!=0);
}
