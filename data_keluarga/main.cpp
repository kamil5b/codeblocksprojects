#include "header.h"

int main()
{
    cout << "Hello world!" << endl;

    listAnak LA;
    listOT LOT;

    addressAnak A;
    addressOT OT;

    string nama_ot,nama_a,kelamin_ot,kelamin_a;

    buatList(LA,LOT);

    int pilih=99;
    while(pilih!=0){
        cout << endl;
        cout << "++================================++" << endl;
        cout << "MENU DATA KELUARGA" << endl;
        cout << "0 -> Keluar" << endl;
        cout << "1 -> Penambahan data orang tua" << endl;
        cout << "2 -> Penambahan data anak" << endl;
        cout << "3 -> Penentuan relasi" << endl;
        cout << "4 -> Menghapus data orang tua" << endl;
        cout << "5 -> Menghapus data anak tertentu" << endl;
        cout << "6 -> Cari data anak dari orang tua" << endl;
        cout << "7 -> Cari data orang tua dari anak" << endl;
        cout << "8 -> Lihat semua data anak" << endl;
        cout << "9 -> Lihat semua data orang tua" << endl;
        cout << "Pilih dengan angka : ";
        cin >> pilih;

        switch(pilih){
        case 1:
            cout << "Nama orang tua (tanpa spasi/boleh panggilan) : ";
            cin >> nama_ot;
            cout << "Kelamin(P/L) : ";
            cin >> kelamin_ot;
            while(kelamin_ot!="P"&&kelamin_ot!="L"){
                cout << "Kelamin(P/L) : ";
                cin >> kelamin_ot;
            }
            OT=buatOT(nama_ot,kelamin_ot);
            insertLastOT(OT,LOT);
            cout << "Berhasil menambahkan data Orang Tua" << endl;
            break;
        case 2:
            cout << "Nama anak (tanpa spasi/boleh panggilan) : ";
            cin >> nama_a;
            cout << "Kelamin(P/L) : ";
            cin >> kelamin_a;
            while(kelamin_a!="P"&&kelamin_a!="L"){
                cout << "Kelamin(P/L) : ";
                cin >> kelamin_a;
            }
            A=buatAnak(nama_a,kelamin_a);
            insertLastAnak(A,LA);
            cout << "Berhasil menambahkan data anak" << endl;
            break;
        case 3:
            cout << endl;
            cout << "0 -> Keluar program" << endl;
            cout << "1 -> Orang tua ke anak" << endl;
            cout << "2 -> Anak dari orang tua" << endl;
            cout << "3 -> Kembali ke menu" << endl;
            cout << "Pilih dengan angka : ";
            cin >> pilih;
            if(pilih==1){
                cout << "Nama orang tua(tanpa spasi/boleh panggilan) : ";
                cin >> nama_ot;
                cout << "Kelamin(P/L) : ";
                cin >> kelamin_ot;
                while(kelamin_ot!="P"&&kelamin_ot!="L"){
                    cout << "Kelamin(P/L) : ";
                    cin >> kelamin_ot;
                }
                OT=cariOT(nama_ot,kelamin_ot,LOT);
                if(OT==NULL){
                    cout << "Tidak ada data orang tua" << endl;
                }else{
                    cout << "Nama anak(tanpa spasi/boleh panggilan) : ";
                    cin >> nama_a;
                    cout << "Kelamin(P/L) : ";
                    cin >> kelamin_a;
                    while(kelamin_a!="P"&&kelamin_a!="L"){
                        cout << "Kelamin(P/L) : ";
                        cin >> kelamin_a;
                    }
                    A=cariAnak(nama_a,kelamin_a,LA);
                    if(A==NULL){
                        cout << "Tidak ada data anak" <<endl;
                    }else{
                        buatHubungan(OT,A);
                        cout << "Relasi telah ditambahkan" << endl;
                    }
                }
            }else if(pilih==2){
                cout << "Nama anak (tanpa spasi/boleh panggilan) : ";
                cin >> nama_a;
                cout << "Kelamin(P/L) : ";
                cin >> kelamin_a;
                while(kelamin_a!="P"&&kelamin_a!="L"){
                    cout << "Kelamin(P/L) : ";
                    cin >> kelamin_a;
                }
                A=cariAnak(nama_a,kelamin_a,LA);
                if(A==NULL){
                    cout << "Data anak belum terdaftar" <<endl;
                }else{
                    cout << "Nama orang tua(tanpa spasi/boleh panggilan) : ";
                    cin >> nama_ot;
                    cout << "Kelamin(P/L) : ";
                    cin >> kelamin_ot;
                    while(kelamin_ot!="P"&&kelamin_ot!="L"){
                        cout << "Kelamin(P/L) : ";
                        cin >> kelamin_ot;
                    }
                    OT=cariOT(nama_ot,kelamin_ot,LOT);
                    if(OT==NULL){
                        cout << "Data orang tua belum terdaftar" << endl;
                    }else{
                        buatHubungan(OT,A);
                        cout << "Relasi telah ditambahkan" << endl;
                    }
                }
            }
            break;
        case 4:
            cout << "Nama orang tua(tanpa spasi/boleh panggilan) : ";
            cin >> nama_ot;
            cout << "Kelamin(P/L) : ";
            cin >> kelamin_ot;
            while(kelamin_ot!="P"&&kelamin_ot!="L"){
                cout << "Kelamin(P/L) : ";
                cin >> kelamin_ot;
            }
            OT=cariOT(nama_ot,kelamin_ot,LOT);
            if(OT==NULL){
                cout << "Tidak ada data orang tua" << endl;
            }else{
                deleteOT(OT,LOT);
                cout << "Data orang telah dihapus" <<endl;
            }
            break;
        case 5:
            cout << "Nama anak(tanpa spasi/boleh panggilan) : ";
            cin >> nama_a;
            cout << "Kelamin(P/L) : ";
            cin >> kelamin_a;
            while(kelamin_a!="P"&&kelamin_a!="L"){
                cout << "Kelamin(P/L) : ";
                cin >> kelamin_a;
            }
            A=cariAnak(nama_a,kelamin_a,LA);
            if(A==NULL){
                cout << "Tidak ada data orang tua" << endl;
            }else{
                deleteAnak(A,LA);
                cout << "Data orang telah dihapus" <<endl;
            }
            break;
        case 6:
            cout << "Nama anak(tanpa spasi/boleh panggilan) : ";
            cin >> nama_a;
            cout << "Kelamin(P/L) : ";
            cin >> kelamin_a;
            while(kelamin_a!="P"&&kelamin_a!="L"){
                cout << "Kelamin(P/L) : ";
                cin >> kelamin_a;
            }
            A=cariAnak(nama_a,kelamin_a,LA);
            if(OT==NULL){
                cout << "Tidak ada data orang tua" << endl;
            }else{
                printAnak(A,LOT);
            }
            break;
        case 7:
            cout << "Nama orang tua(tanpa spasi/boleh panggilan) : ";
            cin >> nama_ot;
            cout << "Kelamin(P/L) : ";
            cin >> kelamin_ot;
            while(kelamin_ot!="P"&&kelamin_ot!="L"){
                cout << "Kelamin(P/L) : ";
                cin >> kelamin_ot;
            }
            OT=cariOT(nama_ot,kelamin_ot,LOT);
            if(OT==NULL){
                cout << "Tidak ada data orang tua" << endl;
            }else{
                printOT(OT);
            }
            break;
        case 8:
            A=first(LA);
            while(A!=NULL){
                printAnak(A,LOT);
                cout << "--------------" << endl;
                A=next(A);
            }
            break;
        case 9:
            OT=first(LOT);
            while(OT!=NULL){
                printOT(OT);
                cout << "--------------" << endl;
                OT=next(OT);
            }
            break;
        }

    }

    return 0;
}
