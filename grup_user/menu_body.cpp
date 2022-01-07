#include "grup_user_header.h"

void menu(listUser &Lu, listGroup &Lg){
    int pilih;
    string nama_grup,nama_user;
    user_pointer U;
    group_pointer G;

    do{
        cout << "===================" <<endl;
        cout << "0.Keluar" <<endl;
        cout << "1.Menambahkan grup baru" <<endl;
        cout << "2.Menambahkan user baru" <<endl;
        cout << "3.User masuk grup" <<endl;
        cout << "4.Hapus grup" <<endl;
        cout << "5.Hapus user" <<endl;
        cout << "6.Lihat semua grup" <<endl;
        cout << "7.Grup populer" <<endl;
        cout << "8.Grup yang diikuti user tertentu" <<endl;
        cout << "9.User yang bergabung minimal 3 grup" <<endl;
        cout << "Pilih angka :";
        cin >> pilih;

        while(pilih < 0 || pilih > 9){
            cout << "Pilih angka :";
            cin >> pilih;
        }

        switch(pilih){

        case 1:
            cout << "Nama grup :";
            cin >> nama_grup;
            newGroup(nama_grup,Lg);
            cout << "Berhasil membuat grup " << nama_grup <<endl;
            break;
        case 2:
            cout << "Nama user :";
            cin >> nama_user;
            newUser(nama_user,Lu);
            cout << "Berhasil membuat user dengan nama " << nama_user << endl;
            break;
        case 3:
            cout << "Nama user :";
            cin >> nama_user;
            U=searchUser(nama_user,Lu);
            if(U!=NULL){
                cout << "Nama grup :";
                cin >> nama_grup;
                G=searchGroup(nama_grup,Lg);
                if(G!=NULL){
                    joinGroup(U,G);
                }else{
                    cout << "Grup tidak ditemukan" << endl;
                }
            }else{
                cout << "User tidak ditemukan" << endl;
            }
            break;
        case 4:
            cout << "Nama grup :";
            cin >> nama_grup;
            G=searchGroup(nama_grup,Lg);
            if(G!=NULL){
                deleteGroup(G,Lg,Lu);
                cout << G->nama << " telah dihapuskan" << endl;
            }else{
                cout << "Nama grup tidak ditemukan" << endl;
            }
            break;
        case 5:
            cout << "Nama user :";
            cin >> nama_user;
            U=searchUser(nama_user,Lu);
            if(U!=NULL){
                deleteUser(U,Lu);
                cout << U->nama << " telah dihapuskan" << endl;
            }else{
                cout << "Nama user tidak ditemukan" << endl;
            }
            break;
        case 6:
            G=Lg.first;
            while(G!=NULL){
                showGroupMember(G,Lu);
                G=G->next;
            }
            break;
        case 7:
            G=popularGroup(Lg);
            if(G!=NULL){
                cout << "Grup paling populer adalah " << G->nama << endl;
                showGroupMember(G,Lu);
            }else{
                cout << "Tidak ada yang popular" << endl;
            }
            break;
        case 8:
            cout << "Masukan nama user :";
            cin >> nama_user;
            U=searchUser(nama_user,Lu);
            if(U!=NULL){
                showUserGroup(U);
            }else{
                cout << "Nama user tidak ditemukan" << endl;
            }
            break;
        case 9:
            showMinimal3Group(Lu);
            break;
        }

    }while(pilih!=0);
}
