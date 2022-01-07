#include "menu.h"
using namespace std;

void menu(list_programmer &L1, list_project &L2, list_penugasan &L){
    int X;
    do{
    cout<<endl;
    cout<<"--------------------TUGAS BESAR M ZALFA THORIQ & MUH AKIB A YANI--------------------"<<endl;
    cout<<endl;
    cout<<"1. LOGIN ADMIN"<<endl;
    cout<<"2. LOGIN MANAGER"<<endl;
    cout<<"3. LOGIN PROGRAMER"<<endl;
    cout<<"4. KELUAR"<<endl;

    cout<<"MASUKKAN PILIHAN : ";
    cin>>X;
    if (X == 1) {
        loginadmin(L1,L2,L);
    } else if (X == 2) {
        loginmanager(L1,L2,L);
    } else if (X == 3) {
        loginprogramer(L1,L2,L);
    }
    }while(X != 4);
}

void loginadmin(list_programmer &L1, list_project &L2, list_penugasan &L){
    string user = "admin";
    string pass = "admin";
    string username;
    string password;
    address_programmer prog;
    address_project proj;
    address_penugasan pen;

    cout<<"MASUKKAN USERNAME :";
    cin >> username;
    cout << "MASUKKAN PASSWORD :";
    cin >> password;
    if (username != user || password != pass) {
        cout<<"USERNAME ATAU PASSWORD SALAH";
    } else {
        int x;
        cout<<"1. MASUKKAN NAMA PROGRAMMER"<<endl;
        cout<<"2. HAPUS DATA PROGRAMMER"<<endl;
        cout<<"3. UBAH DATA PROGRAMMER"<<endl;
        cout<<"4. LIHAT DATA PROGRAMMER"<<endl;
        cout<<"5. MASUKKAN NAMA PROJECT"<<endl;
        cout<<"6. HAPUS DATA PROJECT"<<endl;
        cout<<"7. UBAH DATA PROJECT"<<endl;
        cout<<"8. LIHAT DATA PROJECT"<<endl;
        cout<<"MASUKKAN PILIHAN : ";
        cin>>x;
        if (x == 1) {
            string nama;
            cout<<"MASUKKAN NAMA PROGRAMMER : ";
            cin>>nama;
            prog=searchProgram(L1,nama);
            if(prog==NULL){
                prog=createElmProgram(nama);
                insertLastProgram(prog,L1);
                cout << "BERHASIL" << endl;
            }else{
                cout << "Nama programmer telah terdaftar sebelumnya" << endl;
            }

        } else if(x == 2) {

            string name;
            cout<<"MASUKKAN NAMA PROGRAMMER YANG INGIN ANDA HAPUS : ";
            cin>>name;
            prog= searchProgram(L1,name);
            if(prog!=NULL){
                deletePenugasanProgrammer(L,prog);
                deleteProgram(L1,prog);
                delete prog;
                prog=NULL;
                cout << "Data programmer telah dihapuskan" << endl;
            }else{
                cout << "Nama programmer belum terdaftar" << endl;
            }
            //delete_relasi_parent_1(L, name);
        } else if(x == 3) {

            string ubah ;
            cout<<"MASUKKAN NAMA PROGRAMMER YANG INGIN ANDA UBAH : ";
            cin>>ubah;
            ubahProgram(L1,ubah);
        } else if(x == 4) {
            viewProgram(L1);
        } else if (x == 5) {
            string nama;
            cout<<"MASUKKAN NAMA PROJECT : ";
            cin>>nama;
            proj=searchProject(L2,nama);
            if(proj==NULL){
                proj=createElmProject(nama);
                insertLastProject(L2, proj);
                cout << "BERHASIL" << endl;
            }else{
                cout << "Nama project sudah pernah ada" << endl;
            }

        }else if (x == 6){

            string name;
            cout<<"Masukan Nama Project  yang ingin dihapus : ";
            cin>>name;
            proj=searchProject(L2,name);
            if(proj!=NULL){
                deletePenugasanProject(L,proj);
                deleteProject(L2,proj);
                delete proj;
                proj=NULL;
                cout << "BERHASIL MENGHAPUS PROJECT" << endl;
            }else{
                cout << "Nama project tidak ada" << endl;
            }

        } else if(x == 7) {
            string ubah;
            cout<<"MASUKKAN NAMA PROGRAMMER YANG INGAN ANDA UBAH : ";
            cin>>ubah;
            ubahProject(L2,ubah);
        }else if ( x == 8){

            viewProject(L2);


        }


    }
}

void loginmanager(list_programmer &L1, list_project &L2, list_penugasan &L){

    string user = "manager";
    string pass = "manager";
    string username;
    string password;
    address_programmer prog;
    address_project proj;
    address_penugasan pen;
    cout<<"MASUKKAN USERNAME : ";
    cin>>username;
    cout<<"MASUKKAN PASSWORD : ";
    cin>>password;
    if (username != user || password != pass) {
        cout<<"USERNAME ATAU PASSWORD SALAH";
    } else {
        int x;
        cout<<"1. MASUKKAN PENUGASAN PROJECT "<<endl;
        cout<<"2. LIHAT DETAIL UNTUK PENUGASAN PROGRAMMER"<<endl;
        cout<<"3. LIHAT DETAIL SETIAP PENUGASAN PROJECT"<<endl;
        cout<<"4. LIHAT SEMUA PROGRAMMER BESERTA TOTAL PENUGASAN"<<endl;
        cout<<"5. LIHAT SEMUA PROJECT BESERTA TOTAL PROGRAMMER"<<endl;
        cout<<"6. UBAH STATUS PENUGASAN"<<endl;
        cout<<"7. ALIH PENUGASAN"<<endl;
        cout<<"8. HAPUS PENUGASAN UNTUK PROGRAMMER"<<endl;

        cin>>x;

        if (x == 1){
            string name,status,tugas;
            cout<<"Masukan Nama Project : ";
            cin>>name;
            proj=searchProject(L2,name);
            if(proj!=NULL){
                cout<<"Masukan Nama programmer : ";
                cin>>name;
                prog = searchProgram(L1,name);
                if(prog!=NULL){
                    pen=searchPenugasan(L,prog,proj);
                    if(pen==NULL){
                        cout << "Status : ";
                        cin >> status;
                        cout << "Tugas : ";
                        cin >> tugas;
                        pen=createElmPenugasan(prog,proj,status,tugas);
                        insertFirstPenugasan(L,pen);
                        cout << "BERHASIL" << endl;
                    }else{
                        cout << info(prog) << " telah ditugaskan dalam Project " << info(proj) << " sebagai " << tugas(pen) << " dengan status " << status(pen) << endl;
                    }
                }else{
                    cout << "Programmer tidak ditemukan" << endl;
                }
            }else{
                cout << "Project tidak ditemukan" << endl;
            }
        }else if ( x == 2){
            string nama;
            cout << "Masukan nama programmer : ";
            cin >> nama;
            prog=searchProgram(L1,nama);
            if(prog!=NULL){
                viewProgrammersProject(prog,L);
            }else{
                cout << "Programmer tidak dalam list" << endl;
            }
        }else if (x == 3){
            string nama;
            cout << "Masukan nama project : ";
            cin >> nama;
            proj=searchProject(L2,nama);
            if(proj!=NULL){
                viewProjectsProgrammer(proj,L);
            }else{
                cout << "Project ridak dalam list" << endl;
            }
        }else if ( x == 4){
            viewAllProgrammerandProject(L1,L);
        }else if ( x == 5){
            viewAllProjectandProgrammer(L2,L);
        }else if ( x == 6){
            string name,status,tugas;
            cout<<"Masukan Nama Project : ";
            cin>>name;
            proj=searchProject(L2,name);
            if(proj!=NULL){
                cout<<"Masukan Nama programmer : ";
                cin>>name;
                prog = searchProgram(L1,name);
                if(prog!=NULL){
                    pen=searchPenugasan(L,prog,proj);
                    if(pen!=NULL){
                        ubahStatus(L,pen);
                        cout << "BERHASIL" << endl;
                    }else{
                        cout << info(prog) << " belum ditempatkan di project " << info(proj) << endl;
                    }
                }else{
                    cout << "Programmer tidak ditemukan" << endl;
                }
            }else{
                cout << "Project tidak ditemukan" << endl;
            }
        }else if ( x == 7){
            string name,status,tugas;
            cout<<"Masukan Nama Project : ";
            cin>>name;
            proj=searchProject(L2,name);
            if(proj!=NULL){
                cout<<"Masukan Nama programmer : ";
                cin>>name;
                prog = searchProgram(L1,name);
                if(prog!=NULL){
                    pen=searchPenugasan(L,prog,proj);
                    if(pen!=NULL){
                        alihTugas(L,pen);
                        cout << "BERHASIL" << endl;
                    }else{
                        cout << info(prog) << " belum ditempatkan di project " << info(proj) << endl;
                    }
                }else{
                    cout << "Programmer tidak ditemukan" << endl;
                }
            }else{
                cout << "Project tidak ditemukan" << endl;
            }
        }else if( x == 8 ){
            string name,status,tugas;
            cout<<"Masukan Nama Project : ";
            cin>>name;
            proj=searchProject(L2,name);
            if(proj!=NULL){
                cout<<"Masukan Nama programmer : ";
                cin>>name;
                prog = searchProgram(L1,name);
                if(prog!=NULL){
                    pen=searchPenugasan(L,prog,proj);
                    if(pen!=NULL){
                        deletePenugasan(L,pen);
                        cout << "BERHASIL" << endl;
                    }else{
                        cout << info(prog) << " belum ditempatkan di project " << info(proj) << endl;
                    }
                }else{
                    cout << "Programmer tidak ditemukan" << endl;
                }
            }else{
                cout << "Project tidak ditemukan" << endl;
            }
        }else{



        }
         menu(L1, L2, L);

    }
}

void loginprogramer(list_programmer &L1, list_project &L2, list_penugasan &L){
    string user = "programmer";
    string pass = "programmer";
    string username;
    string password;
    cout<<"MASUKKAN USERNAME : ";
    cin>>username;
    address_programmer prog;
    prog=searchProgram(L1,username);
    if(prog!=NULL){
        int x;
        cout<<"1. LIHAT TOTAL PENUGASAN"<<endl;
        cout<<"2. LIHAT DETAIL PROJECT"<<endl;
        cout<<"MASUKKAN PILIHAN : ";
        cin>>x;
        if (x == 1){
            int i=0;
            address_penugasan pen=L.first;
            while(pen!=NULL){
                if(prog(pen)==prog){
                    i++;
                }
                pen=next(pen);
            }
            cout << "Ada " << i << " Project" << endl;
            viewProgrammersProject(prog,L);
        }else if (x == 2 ){
            string nama;
            bool ada=false;
            cout << "Masukan nama project : ";
            cin >> nama;
            address_project proj=searchProject(L2,nama);
            if(proj!=NULL){
                address_penugasan pen=searchPenugasan(L,prog,proj);
                if(pen!=NULL){
                    viewProjectsProgrammer(proj,L);
                }else{
                    cout << "Anda tidak dalam project teresebut" <<endl;
                }
            }else{
                cout << "Project ridak dalam list" << endl;
            }
        }
    }else{
        cout << "USERNAME BELUM TERDAFTAR" << endl;
    }

}


