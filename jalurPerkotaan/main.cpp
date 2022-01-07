#include "jalankota.h"
#include <cstdlib>
int main()
{
    ListJalan LJ;
    ListKota LK;
    ListRelasi LR;
    createList(LR,LK,LJ);
    addressjalan j;
    addresskota k;
    string nama,tipe;
    char menu=' ';
    while(menu!='x'&&menu!='X'){
        cout << endl;
        cout << endl;
        cout<<"=========================="<<endl;
        cout<<"|| Data Jalan Perkotaan ||"<<endl;
        cout<<"=========================="<<endl;
        cout<<"a. Penambahan data kota."<<endl;
        cout<<"b. Penambahan data jalan."<<endl;
        cout<<"c. Penentuan relasi kota dan jalan."<<endl;
        cout<<"d. Menghapus data kota."<<endl;
        cout<<"e. Manghapus data jalan."<<endl;
        cout<<"f. Menampilkan data keseluruhan kota beserta jalan yang terdapat di kota tersebut."<<endl;
        cout<<"g. Menampilkan data kota yang memiliki nama jalan tertentu."<<endl;
        cout<<"h. Menampilkan data jalan yang dimiliki suatu kota tertentu."<<endl;
        cout<<"i. Menampilkan data kota dan nama jalan yang memiliki tipe jalan tertentu."<<endl;
        cout<<"x. Keluar dari program"<<endl;
        cout<<"Pilih : ";
        cin >> menu;
        system("CLS");
        switch(menu){
        case 'A':
        case 'a':
            cout << "Nama kota (tanpa spasi, gunakan '-' atau '_'): ";
            cin >> nama;
            addKota(LK,nama);
            break;
        case 'B':
        case 'b':
            cout << "Nama jalan (tanpa spasi, gunakan '-' atau '_'): ";
            cin >> nama;
            cout << "Contoh Tipe jalan : toll, jalan_utama, satu_arah, by-pass, fly-over, dll" << endl;
            cout << "Tipe jalan (tanpa spasi, gunakan '-' atau '_'): ";
            cin >> tipe;
            addJalan(LJ,nama,tipe);
            break;
        case 'C':
        case 'c':
            cout << "Nama kota (tanpa spasi, gunakan '-' atau '_'): ";
            cin >> nama;
            k=findKota(LK,nama);
            if(k!=NULL){
                cout << "Nama jalan (tanpa spasi, gunakan '-' atau '_'): ";
                cin >> nama;
                j=findJalan(LJ,nama);
                if(j!=NULL){
                    connect(LR,k,j);
                }else{
                    cout << "Jalan belum didata" <<endl;
                }
            }else{
                cout << "Kota belum didata" << endl;
            }
            break;
        case 'D':
        case 'd':
            cout << "Nama kota (tanpa spasi, gunakan '-' atau '_'): ";
            cin >> nama;
            deleteKota(LK,LR,nama);
            break;
        case 'E':
        case 'e':
            cout << "Nama jalan (tanpa spasi, gunakan '-' atau '_'): ";
            cin >> nama;
            deleteJalan(LJ,LR,nama);
            break;
        case 'F':
        case 'f':
            printAll(LR,LK);
            break;
        case 'G':
        case 'g':
            cout << "Nama jalan (tanpa spasi, gunakan '-' atau '_'): ";
            cin >> nama;
            kotaPunyaJalan(LR,LJ,nama);
            break;
        case 'H':
        case 'h':
            cout << "Nama kota (tanpa spasi, gunakan '-' atau '_'): ";
            cin >> nama;
            jalanKota(LR,LK,nama);
            break;
        case 'I':
        case 'i':
            cout << "Contoh Tipe jalan : toll, jalan_utama, satu_arah, by-pass, fly-over, dll" << endl;
            cout << "Tipe jalan (tanpa spasi, gunakan '-' atau '_'): ";
            cin >> tipe;
            tipeJalanKota(LR,LJ,tipe);
            break;
        }
        if(menu!='x'&&menu!='X'){
            system("pause");
        }
    }
    return 0;
}
