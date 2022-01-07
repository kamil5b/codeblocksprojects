
#include "h.h"
using namespace std;

int main() {
    multiList L;
    int menu;

    createList(L);
    do{
        system("CLS");
        cout<<"+-------------------------------------------------------------------+\n";
        cout<<"|                    *  DATA BENGKEL  *                             |\n";
        cout<<"+-------------------------------------------------------------------+\n";
        cout<<"| 0.  Selesai                                                       |\n";
        cout<<"| 1.  Tambah Mobil Baru                                             |\n";
        cout<<"| 2.  Tambahkan Montir Baru                                         |\n";
        cout<<"| 3.  Tambahkan Hubungan Montir dan Mobil                           |\n";
        cout<<"| 4.  Hapus Mobil                                                   |\n";
        cout<<"| 5.  Hapus Montir                                                  |\n";
        cout<<"| 6.  Tampil semua Mobil dengan Montir                              |\n";
        cout<<"| 7.  Tampil Motir                                                  |\n";
        cout<<"| 8.  Tampil Mobil diperbaiki Montir tertentu                       |\n";
        cout<<"| 9.  Tampil mobil yang diperbaiki oleh lebih dari satu montir      |\n";
        cout<<"+-------------------------------------------------------------------+\n";
        cout<<"\nPILIH MENU YANG DIINGINKAN : ";cin>>menu;
        switch (menu){
            case 1:
                tambahMobil(L);
                break;
            case 2:
                tambahMontir(L);
                break;
            case 3:
                tambahHubungan(L);
                break;
            case 4:
                HapusMobil(L);
                break;
            case 5:
                HapusMontir(L);
                break;
            case 6:
                cekHubungan();
                break;
            case 7:
                tampilSemuaMontir(L);
                break;
            case 8:
                tampilMobildanMontirtertentu(L);
                break;
            case 9:
                tampilMobildanMontirtertentu(L);
                break;
            case 0:
                break;
            default:
                cout<<"Pilihan tidak ada...\n";
                getch();
        }
    }while (menu!=0);
    cout<<"\n                    +-----------------------------------------+";
    cout<<"\n                    |         TUBES STRUKTUR DATA 2020        |";
    cout<<"\n                    |     TERIMAKASIH TELAH BEKERJA KERAS     |";
    cout<<"\n                    |            INGAT 27 DESEMBER!           |";
    cout<<"\n                    |      AUDIA SHAFARINA JUSTY (1303194052) |";
    cout<<"\n                    | DAFFI RAKA PUTRA PRATAMA (1303190036)   |";
    cout<<"\n                    |               IT-43-GAB                 |";
    cout<<"\n                    +-----------------------------------------+\n";
    return 0;
}
