#include "tubes.cpp"
#include <iostream>

using namespace std;

int main()
{
Penulis T;
Barang B;
createToko(T);
createBarang(B);
system("cls");
    int input;
    char input1;
        cout<<"**************************************************"<<endl;
        cout<<"||   SELAMAT DATANG DI APLIKASI PENULIS NOVEL   ||"<<endl;
        cout<<"**************************************************"<<endl;
        cout<<""<<endl;
        cout<<"===================== MENU ======================="<<endl;
        cout<<" || 1. Tambah Data Penulis                      ||"<<endl;
        cout<<" || 2. Tambah Data Novel                        ||"<<endl;
        cout<<" || 3. Relasi Antar Penulis dan Novel           ||"<<endl;
        cout<<" || 4. Hapus Data Penulis                       ||"<<endl;
        cout<<" || 5. Hapus Data Novel                         ||"<<endl;
        cout<<" || 6. View Data Penulis beserta Novel          ||"<<endl;
        cout<<" || 7. View Data Novel dengan Dua Penulis       ||"<<endl;
        cout<<" || 8. View Data Penulis Dengan Novel Terbanyak ||"<<endl;
        cout<<" || 9. View Data Penulis Non-Kolaborasi         ||"<<endl;
        cout<<" || 0. Exit                                     ||"<<endl;
        cout<<"=================================================="<<endl;
        cout<< endl;
        cout<<"(Silahkan Pilih Menu Antara 1-9)"<<endl;
        cout<<endl;
        cout<<" Input Pilihan : ";
        cin>>pilihan;
        cout<<endl;
    }
    return 0;
}
