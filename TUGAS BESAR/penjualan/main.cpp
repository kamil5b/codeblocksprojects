#include <iostream>
#include "penjualan.h"
#include "relasi.h"
#include "barang.h"

using namespace std;

int main()
{
    ListBarang Lb;
    ListRelasi Lr;
    ListToko Lt;

    createListBarang(Lb);
    createListRelasi(Lr);
    createListToko(Lt);

    infotype nama;
    int pilih;
    addressB B;
    addressT T;
    addressR R;

    do{
        cout << "===================" <<endl;
        cout << "0.Keluar" <<endl;
        cout << "1.Menambahkan barang baru" <<endl;
        cout << "2.Menambahkan toko baru" <<endl;
        cout << "3.Toko mengambil barang" <<endl;
        cout << "4.Hapus data barang" <<endl;
        cout << "5.Hapus data toko" <<endl;
        cout << "6.Lihat semua toko dan barangnya" <<endl;
        cout << "7.Lihat barang toko" <<endl;
        cout << "8.Lihat toko yang menjual barang tertentu" <<endl;
        cout << "9.Data toko paling lengkap" <<endl;
        cout << "Pilih angka :";
        cin >> pilih;

        while(pilih < 0 || pilih > 9){
            cout << "Pilih angka :";
            cin >> pilih;
        }

        switch(pilih){

        case 1:
            createBarang(B);
            insertBarangFirst(Lb,B);
            cout << "Berhasil mendata barang" << endl;
            break;
        case 2:
            createToko(T);
            insertTokoLast(Lt,T);
            cout << "Berhasil mendata Toko" << endl;
            break;
        case 3:
            cout<<"== Cari Data Barang =="<<endl;
            cout<<"Nama Barang: ";
            cin >> nama;
            B=searchBarang(Lb,nama);
            cout<<"== Cari Data Toko =="<<endl;
            cout<<"Nama Toko: ";
            cin >> nama;
            T=searchToko(Lt,nama);
            if(B!=NULL&&T!=NULL){
                createRelasi(R,B,T);
                insertRelasiFirst(Lr,R);
            }else{
                cout << "Error" << endl;
            }
            break;
        case 4:
            cout<<"== Cari Data Barang =="<<endl;
            cout<<"Nama Barang : ";
            cin >> nama;
            B=searchBarang(Lb,nama);
            if(B!=NULL&&first(Lb)!=NULL){
                if(B==first(Lb)){
                    deleteBarangFirst(Lb,B);
                }else{
                    addressB Btemp=first(Lb);
                    while(next(Btemp)!=B){
                        Btemp=next(Btemp);
                    }
                    deleteBarangAfter(Lb,Btemp,B);
                }
                R=first(Lr);
                while(R!=NULL){
                    if(barang(R)==B){
                        if(R==first(Lr)){
                            deleteRelasiFirst(Lr,R);
                        }else{
                            addressR Rtemp=first(Lr);
                            while(next(Rtemp)!=R&&Rtemp!=NULL){
                                Rtemp=next(Rtemp);
                            }
                            deleteRelasiAfter(Lr,Rtemp,R);
                        }
                    }
                    R=next(R);
                }
                cout << nama << " telah dihapuskan" << endl;
            }else{
                cout << "Nama Barang tidak ditemukan" << endl;
            }
            break;
        case 5:
            cout<<"== Cari Data Toko =="<<endl;
            cout<<"Nama Toko: ";
            cin >> nama;
            T=searchToko(Lt,nama);
            if(T!=NULL){
                if(T==first(Lt)){
                    deleteTokoFirst(Lt,T);
                }else if(T==last(Lt)){
                    deleteTokoLast(Lt,T);
                }else{
                    addressT Ttemp=first(Lt);
                    while(Ttemp!=NULL&&next(Ttemp)!=T){
                        Ttemp=next(Ttemp);
                    }
                    if(Ttemp!=NULL){
                        deleteTokoAfter(Lt,Ttemp,T);
                    }
                }

                R=first(Lr);
                while(R!=NULL){
                    if(toko(R)==T){
                        if(R==first(Lr)){
                            deleteRelasiFirst(Lr,R);
                        }else{
                            addressR Rtemp=first(Lr);
                            while(next(Rtemp)!=R&&Rtemp!=NULL){
                                Rtemp=next(Rtemp);
                            }
                            deleteRelasiAfter(Lr,Rtemp,R);
                        }
                    }
                    R=next(R);
                }
                cout << nama << " telah dihapuskan" << endl;
            }else{
                cout << "Nama Toko tidak ditemukan" << endl;
            }
            break;
        case 6:
            T=first(Lt);
            while(T!=NULL){
                printBarangToko(Lr,T);
                T=next(T);
            }
            break;
        case 7:
            cout<<"== Cari Data Toko =="<<endl;
            cout<<"Nama Toko: ";
            cin >> nama;
            T=searchToko(Lt,nama);
            if(T!=NULL){
                printBarangToko(Lr,T);
            }else{
                cout << "Nama Toko tidak ditemukan" << endl;
            }
            break;
        case 8:
            cout<<"== Cari Data Barang =="<<endl;
            cout<<"Nama Barang: ";
            cin >> nama;
            B=searchBarang(Lb,nama);
            if(B!=NULL){
                printBarangadadiToko(Lr,B);
            }else{
                cout << "Nama barang tidak ditemukan" << endl;
            }
            break;
        case 9:
            tokoPalingLengkap(Lt);
            break;
        }

    }while(pilih!=0);

    return 0;
}
