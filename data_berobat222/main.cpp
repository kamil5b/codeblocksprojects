#include "relasi.h"
#include <cstdlib>

int main()
{
    int pilihan;
    string nama;

    address_pas pas;
    address_pen pen;
    address_r R;

    listPasien Lpas;
    listPenyakit Lpen;
    listRelasi Lr;

    createListPasien(Lpas);
    createListPenyakit(Lpen);
    createListRelasi(Lr);

    do{
        system("cls");
        cout << "==================================================" << endl;
        cout << "=[0] Keluar                                      =" << endl;
        cout << "=[1] Pasien Baru                                 =" << endl;
        cout << "=[2] Penyakit Baru                               =" << endl;
        cout << "=[3] Pasien terkena penyakit                     =" << endl;
        cout << "=[4] Pasien sembuh                               =" << endl;
        cout << "=[5] Hapus data penyakit                         =" << endl;
        cout << "=[6] Hapus data pasien                           =" << endl;
        cout << "=[7] Lihat semua data pasien                     =" << endl;
        cout << "=[8] Lihat semua data penyakit                   =" << endl;
        cout << "=[9] Lihat semua data pasien beserta penyakitnya =" << endl;
        cout << "=[10]Cari pasien                                 =" << endl;
        cout << "=[11]Cari penyakit                               =" << endl;
        cout << "=[12]Top 5 Penyakit yang paling banyak pasiennya =" << endl;
        cout << "==================================================" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch(pilihan){
        case 1:
            cout << "Nama pasien : ";
            cin >> nama;
            pas=searchPasien(nama,Lpas);
            if(pas==NULL){
                pas=createPasien(nama);
                insertFirstPasien(pas,Lpas);
                cout << "Pasien berhasil didata" << endl;
            }else{
                cout << "Pasien sudah terdata sebelumnya" <<endl;
            }
            break;
        case 2:
            cout << "Nama penyakit : ";
            cin >> nama;
            pen=searchPenyakit(nama,Lpen);
            if(pen==NULL){
                pen=createPenyakit(nama);
                insertLastPenyakit(pen,Lpen);
                cout << "Penyakit berhasil didata" << endl;
            }else{
                cout << "Penyakit sudah terdata sebelumnya" << endl;
            }
            break;
        case 3:
            cout << "Nama pasien : ";
            cin >> nama;
            pas=searchPasien(nama,Lpas);
            if(pas!=NULL){
                cout << "Nama Penyakit : ";
                cin >> nama;
                pen=searchPenyakit(nama,Lpen);
                if(pen==NULL){
                    pen=createPenyakit(nama);
                    insertLastPenyakit(pen,Lpen);
                    cout << "Menambah data penyakit baru!" << endl;
                }
                R=createRelasi(pas,pen);
                insertFirstRelasi(R,Lr);
                cout << "Berhasil mendata relasi" << endl;
            }else{
                cout << "Pasien belum terdata sebelumnya" <<endl;
            }
            break;
        case 4:
            cout << "Nama pasien : ";
            cin >> nama;
            pas=searchPasien(nama,Lpas);
            if(pas!=NULL){
                cout << "Nama Penyakit : ";
                cin >> nama;
                pen=searchPenyakit(nama,Lpen);
                if(pen!=NULL){
                    R=searchRelasi(pas,pen,Lr);
                    if(R!=NULL){
                        deleteRelasi(R,Lr);
                        cout << "Pasien dinyatakan sembuh dari penyakit " << nama << endl;
                    }else{
                        cout << "Pasien tidak terjangkit penyakit " << nama << endl;
                    }
                }else{
                    cout << "Penyakit belum terdata sebelumnya" << endl;
                }
            }else{
                cout << "Pasien belum terdata sebelumnya" <<endl;
            }
            break;
        case 5:
            cout << "Nama pasien : ";
            cin >> nama;
            pas=searchPasien(nama,Lpas);
            if(pas!=NULL){
                showPenyakitDariPasien(pas,Lr);
                deletePasien(pas,Lpas,Lr);
                cout << "Data pasien berhasil dihapus" << endl;
            }else{
                cout << "Pasien belum terdata sebelumnya" <<endl;
            }
            break;
        case 6:
            cout << "Nama Penyakit : ";
            cin >> nama;
            pen=searchPenyakit(nama,Lpen);
            if(pen!=NULL){
                showPasienTerjangkit(pen,Lr);
                deletePenyakit(pen,Lpen,Lr);
                cout << "Data penyakit berhasil dihapus" << endl;
            }else{
                cout << "Penyakit belum terdata sebelumnya" <<endl;
            }
            break;
        case 7:
            showAllPasien(Lpas);
            break;
        case 8:
            showAllPenyakit(Lpen);
            break;
        case 9:
            showAllPasienBesertaPenyakitnya(Lpas,Lr);
            break;
        case 10:
            cout << "Nama pasien : ";
            cin >> nama;
            pas=searchPasien(nama,Lpas);
            if(pas!=NULL){
                showPenyakitDariPasien(pas,Lr);
            }else{
                cout << "Pasien belum terdata sebelumnya" <<endl;
            }
            break;
        case 11:
            cout << "Nama Penyakit : ";
            cin >> nama;
            pen=searchPenyakit(nama,Lpen);
            if(pen!=NULL){
                showPasienTerjangkit(pen,Lr);
            }else{
                cout << "Penyakit belum terdata sebelumnya" <<endl;
            }
            break;
        case 12:
            top5Penyakit(Lpen);
            break;
        }
        system("pause");
    }while(pilihan!=0);

    cout << "Hello world!" << endl;
    return 0;
}
