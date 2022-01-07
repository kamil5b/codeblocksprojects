#include <iostream>
#include "header.h"
using namespace std;

void menu(lecturerList &Ll,studentList &Ls){

    bool x = false;
    int a;
    do{
        system("pause");
        system("cls");
        cout<<"============================="<<endl;
        cout<<"========    MENU   =========="<<endl;
        cout<<"============================="<<endl;
        cout<<"[1] Tambahkan dosen baru"<<endl;
        cout<<"[2] Tambahkan mahasiswa/i baru"<<endl;
        cout<<"[3] Hapus mahasiswa/i tertentu"<<endl;
        cout<<"[4] Hapus dosen tertentu"<<endl;
        cout<<"[5] Tampilkan semua dosen atau mahasiswa/i"<<endl;
        cout<<"[6] Cari dosen atau mahasiswa/i"<<endl;
        cout<<"[7] Exit"<<endl;
        cout<<endl;
        cout<<"Input : ";
        cin>>a;

        if (a == 1){
            menu1(Ll,Ls);
            cout<<endl;
        } else if (a == 2){
            menu2(Ll,Ls);

        } else if (a == 3){
            menu3(Ll,Ls);

        } else if (a == 4){
            menu4(Ll,Ls);

        } else if (a == 5){
            menu5(Ll,Ls);
        } else if (a == 6){
            menu6(Ll,Ls);
        } else if (a == 7){
            x = true;
            exit(Ll,Ls);
        } else {
            cout<<"Masukan Input dengan benar (1..8)"<<endl;
            cout<<"input : ";
            cin>>a;
            cout<<endl;
        }
    }while (a != 7 && x != true);

}

void menu1(lecturerList &Ll,studentList &Ls){
    string nama, kode, x;
    address_l P;
    address_l Q;
    bool stop = false;
    cout<<"Menu [1]"<<endl;
    while (stop !=true){
        cout<<"Menambahkan dosen baru"<<endl;
        cout<<"Nama\t\t: ";
        getline(cin,nama);
        getline(cin,nama);
        cout<<"Kode dosen\t: ";
        getline(cin,kode);
        cout<<endl;
        P=searchLecturer(Ll,nama);
        Q=searchLecturer(Ll,kode);
        if(P!=NULL||Q!=NULL||nama==""||kode==""){
            cout << "Nama atau kode dosen sudah pernah ada" << endl;
        }else{
            P=createLecturer(nama,kode);
            addLecturer(Ll,P);
        }
        cout<<"Selesai mengisi data [YES/NO] ? ";
        cin>>x;
        if (x == "YES"){
            stop = true;
        } else if (x == "NO"){
            stop = false;
        } else {
            while(x != "YES" && x != "NO"){
                cout<<"Masukan Input dengan benar"<<endl;
                cout<<"input : ";
                cin>>x;
                if (x == "YES"){
                    stop = true;
                }
            }
            cout<<endl;
        }
    }

}

void menu2(lecturerList &Ll,studentList &Ls){
    string nama,id, kode, x;
    address_l P;
    address_s Q;
    address_r R;
    bool stop = false;
    cout<<"Menu [2]"<<endl;
    while (stop != true){
        cout<<"Kode dosen\t: ";
        getline(cin,kode);
        getline(cin,kode);
        cout<<endl;
        P=searchLecturer(Ll,kode);
        if(P!=NULL){
            cout<<"Menambahkan mahasiswa/i baru"<<endl;
            cout<<"Nama\t\t: ";
            getline(cin,nama);
            cout<<"NIM\t\t: ";
            getline(cin,id);
            Q=searchStudent(Ls,id);
            if(Q==NULL){
                Q=createStudent(nama,id);
                addStudent(Ls,Q);
            }
            R=createRelation(Q);
            addRelation(P,R);
            cout << "Berhasil menambahkan mahasiswa" << endl;
        }

        cout<<endl;
        cout<<"Selesai mengisi data [YES/NO] ? ";
        cin>>x;
         if (x == "YES"){
            stop = true;
        } else if (x == "NO"){
            stop = false;
        } else {
            while(x != "YES" && x != "NO"){
                cout<<"Masukan Input dengan benar"<<endl;
                cout<<"input : ";
                cin>>x;
                if (x == "YES"){
                    stop = true;
                }
            }
            cout<<endl;
        }
    }

}

void menu3(lecturerList &Ll,studentList &Ls){
    string nama, cari, hapus;
    address_s S;
    cout<<"Menu [3]"<<endl;
    cout<<"Nama/NIM mahasiswa yang dicari : ";
    getline(cin,cari);
    getline(cin,cari);
    S=searchStudent(Ls,cari);
    if (S==NULL){
        cout<<"Nama tidak ditemukan"<<endl;
    } else {
        // MENAMPILKAN DATA MAHASISWA DULU
        showStudentInfo(S);
        cout<<"Hapus [YES/NO] ? ";
        cin>>hapus;
        if (hapus == "YES"){
            deleteStudent(Ls,S,Ll);
            cout << "Berhasil dihapuskan" << endl;
        } else if (hapus=="NO"){
            cout << "Tidak jadi dihapuskan datanya" << endl;
        } else {
            while(hapus != "YES" && hapus != "NO"){
                cout<<"Masukan Input dengan benar"<<endl;
                cout<<"input : ";
                cin>>hapus;
                if (hapus == "YES"){
                    deleteStudent(Ls,S,Ll);
                    cout << "Berhasil dihapuskan" << endl;
                }else if (hapus=="NO"){
                    cout << "Tidak jadi dihapuskan datanya" << endl;
                }
            }
            cout << endl;
        }
    }
    cout<<endl;

}

void menu4(lecturerList &Ll,studentList &Ls){
    string nama, cari, hapus;
    address_l P;
    cout<<"Menu [4]"<<endl;
    cout<<"Nama/kode dosen yang dicari : ";
    getline(cin,cari);
    getline(cin,cari);
    P=searchLecturer(Ll,cari);
    if (P == NULL){
        cout<<"Nama/Kode tidak ditemukan"<<endl;
    } else {
        // MENAMPILKAN DATA MAHASISWA DULU
        showLecturerInfo(P);
        cout<<"Hapus [YES/NO] ? ";
        cin>>hapus;
        if (hapus == "YES"){
            deleteLecturer(Ll,P,Ls);
            cout << "Berhasil dihapuskan" << endl;
        } else if (hapus=="NO"){
            cout << "Tidak jadi dihapuskan datanya" << endl;
        } else {
            while(hapus != "YES" && hapus != "NO"){
                cout<<"Masukan Input dengan benar"<<endl;
                cout<<"input : ";
                cin>>hapus;
                if (hapus == "YES"){
                    deleteLecturer(Ll,P,Ls);
                    cout << "Berhasil dihapuskan" << endl;
                }else if (hapus=="NO"){
                    cout << "Tidak jadi dihapuskan datanya" << endl;
                }
            }
            cout << endl;
        }
    }
    cout<<endl;

}

void menu5(lecturerList &Ll,studentList &Ls){
    int i = 1;
    string cari;
    address_l P=Ll.first;
    address_s Q=Ls.first;
    cout<<"Menu [5]"<<endl;
    do{
        cout << "Semua data dosen atau mahasiswa ? ";
        getline(cin,cari);
        getline(cin,cari);
    }while(cari!="dosen"&&cari!="mahasiswa"&&cari!="");
    if(cari=="dosen"){
        while (P!=NULL){
            cout<<"Dosen ke- ["<<i<<"]"<<endl;
            showLecturerInfo(P);
            cout << endl;
            i++;
            P=P->next;
        }
        cout << "Banyaknya dosen : " << i-1 <<endl;
        cout << endl;
        cout << "Lanjutkan untuk melihat Dosen yang mengawasi dengan jumlah yang paling banyak dan paling sedikit" <<endl;
        do{
            cout << "Kembali ke menu? atau lanjutkan? (BACK/NEXT) ";
            getline(cin,cari);
        }while(cari!="BACK"&&cari!="NEXT");
        if(cari=="NEXT"){
            menu7(Ll,Ls);
        }
        cout << endl;



    }else if(cari=="mahasiswa"){
        while (Q!=NULL){
            cout<<"Mahasiswa ke- ["<<i<<"]"<<endl;
            showStudentInfo(Q);
            cout << endl;
            i++;
            Q=Q->next;
        }
        cout << "Banyaknya mahasiswa : " << i-1 <<endl;
        cout << endl;
        cout << "Lanjutkan untuk melihat Mahasiswa yang diawasi dengan jumlah dosen yang paling banyak dan paling sedikit" <<endl;
        do{
            cout << "Kembali ke menu? atau lanjutkan? (BACK/NEXT) ";
            getline(cin,cari);
        }while(cari!="BACK"&&cari!="NEXT");
        if(cari=="NEXT"){
            menu8(Ll,Ls);
        }
        cout << endl;
    }
    cout<<endl;

}

void menu6(lecturerList &Ll,studentList &Ls){
    string cari, nama;
    address_l P;
    address_s Q;
    cout<<"Menu [6]"<<endl;
    do{
        cout<<"Mencari dosen atau mahasiswa ? ";
        getline(cin,cari);
        getline(cin,cari);
    }while(cari!="dosen"&&cari!="mahasiswa"&&cari!="");
    if (cari == "dosen"){
        cout<<"Nama/Kode dosen yang dicari : ";
        getline(cin,nama);
        P=searchLecturer(Ll,nama);
        if(P==NULL){
            cout << "Nama dosen tidak ada" << endl;
        }else{
            showLecturersStudent(P);
        }

    } else if(cari == "mahasiswa"){
        cout<<"Nama/ID mahasiswa/i yang dicari : ";
        getline(cin,nama);
        Q=searchStudent(Ls,nama);
        if(Q==NULL){
            cout << "Nama mahasiswa belum terdaftar";
        }else{
            showStudentsLecturer(Q,Ll);
        }
    }

}

void menu7(lecturerList &Ll,studentList &Ls){
    int mark,i;
    address_l L;
    mark=minLecturersStudent(Ll);
    cout << "Dosen yang mengawasi dengan jumlah mahasiswa/i paling sedikit dengan " << mark << " Mahasiswa" << endl;
    i=1;
    L=Ll.first;
    while(L!=NULL){
        if(L->supervised==mark){
            cout<<"Dosen ke- ["<<i<<"]"<<endl;
            cout << "------------------" << endl;
            showLecturersStudent(L);
            cout << "==================" <<endl;
            cout << endl;
            i++;
        }
        L=L->next;
    }
    system("pause");
    cout << endl;
    mark=maxLecturersStudent(Ll);
    cout << "Dosen yang mengawasi dengan jumlah mahasiswa/i paling banyak dengan " << mark << " mahasiswa" << endl;
    i=1;
    L=Ll.first;
    while(L!=NULL){
        if(L->supervised==mark){
            cout<<"Dosen ke- ["<<i<<"]"<<endl;
            cout << "------------------" << endl;
            showLecturersStudent(L);
            cout << "==================" <<endl;
            cout << endl;
            i++;
        }
        L=L->next;
    }
}

void menu8(lecturerList &Ll,studentList &Ls){
    int mark,i;
    address_s L;
    mark=minStudentsLecturer(Ls);
    cout << "Mahasiswa/i yang diawasi dengan jumlah dosen paling sedikit dengan " << mark << " dosen" << endl;
    i=1;
    L=Ls.first;
    while(L!=NULL){
        if(L->supervised==mark){
            cout<<"Mahasiswa ke- ["<<i<<"]"<<endl;
            cout << "------------------" <<endl;
            showStudentsLecturer(L,Ll);
            cout << "==================" <<endl;
            cout << endl;
            i++;
        }
        L=L->next;
    }
    system("pause");
    cout << endl;
    mark=maxStudentsLecturer(Ls);
    cout << "Mahasiswa/i yang diawasi dengan jumlah dosen paling banyak dengan " << mark << " dosen" << endl;
    i=1;
    L=Ls.first;
    while(L!=NULL){
        if(L->supervised==mark){
            cout<<"Mahasiswa ke- ["<<i<<"]"<<endl;

            cout << "------------------" <<endl;
            showStudentsLecturer(L,Ll);
            cout << "==================" <<endl;
            cout << endl;
            i++;
        }
        L=L->next;
    }

}

void exit(lecturerList &Ll,studentList &Ls){
    printFileLecturer(Ll);
    printFileRelation(Ll);
    printFileStudent(Ls);
    cout<<"======================="<<endl;
    cout<<"==== TERIMAH KASIH ===="<<endl;
    cout<<"======================="<<endl;
    cout<<"Group 1 :         "<<endl;
    cout<<"Fadhlan Mochamad D. R. "<<endl;
    cout<<"Muhammad Haykal Kamil "<<endl;

}
