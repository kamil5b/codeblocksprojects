#include "Database.h"

int main()
{
    system("cls");
    int i = 0;
    while(i < 3){
        cout << endl;
        i++;
    }
    i = 0;
    cout <<"\t.______......_.........______............................................._____._..................._..\n"
         <<"\t.|  _  |....| |........| ___ |...........................................|_   _(_).................(_).\n"
         <<"\t.| |.| |....| |_.__._..| |_/ /__._.__.__._._..._._.__._..._..__._._.__.....| |.._._.__...__._..__._._..\n"
         <<"\t.| |.| / _` | __/ _` |.|  __/ _ | |__/ _` | |.| | |__| | | |/ _` | |_.|....| |.| | '_ |./ _` |/ _` | |.\n"
         <<"\t.| |/ / (_| | || (_| |.| |.|  __/ | | (_| | |_| | |..| |_| | (_| | |.| |...| |.| | |.| | (_| | (_| | |.\n"
         <<"\t.|___/.|__,_||__|__,_|.|_|..|___|_|..|__, ||__,_|_|...|__,_||__,_|_|.|_|...|_/.|_|_|.|_||__, ||__, |_|.\n"
         <<"\t......................................__/ |..............................................__/ | __/ |...\n"
         <<"\t.....................................|___/..............................................|___/ |___/....\n" <<endl;

    while(i < 2){
        cout << endl;
        i++;
    }
    i = 0;

    cout << "\t\t\t\t   Selamat datang di Aplikasi Data Perguruan Tinggi\n";
    cout << "\t\t\t   Aplikasi penampung keseluruhan Data dari seluruh Perguruan Tinggi\n";

    while(i < 5){
        cout << endl;
        i++;
    }

    system("pause");


    List1 Lkampus;
    List2 Lfak;
    List_R LR;
    char menu;
    createList1(Lkampus);
    createList2(Lfak);
    createList_R(LR);
    do {
        system("cls");
        header();
        menus();
        int pil;
        int pilihan;
        char ulang;
        cin >> pilihan;
        if(pilihan == 1){
            system("cls");
            headerInsert();
            menuInsert();
            cin >> pil;
            if (pil == 1) {
            do {
                system("cls");
                headerInsertKampus();
                insertKampus(Lkampus);
                cout<<"Insert Lagi? (y/n)";
                cin>>ulang;
            }
            while((ulang == 'y') || (ulang == 'Y'));
            }
            else if (pil == 2) {
                do {
                    system("cls");
                    headerInsertFakultas();
                    insertFakultas(Lfak);
                    cout<<"Insert Lagi? (y/n)";
                    cin>>ulang;
                }
                while((ulang == 'y') || (ulang == 'Y'));
            }
            else if (pil == 3) {
                do {
                    system("cls");
                    headerInsertRelasi();
                    printInfo1(Lkampus);
                    printInfo2(Lfak);
                    insertRelasi(Lkampus,Lfak,LR);
                    cout<<"Insert Lagi? (y/n)";
                    cin>>ulang;
                }
                while((ulang == 'y') || (ulang == 'Y'));
            }
        }
        else if(pilihan == 2){
            system("cls");
            headerUpdate();
            menuUpdate();
            cin >> pil;
            if (pil == 1) {
                do {
                    updateKampus(Lkampus);
                    cout<<"Update Lagi? (y/n)";
                    cin>>ulang;
                }
                while ((ulang == 'y') || (ulang == 'Y'));
            }
            else if (pil == 2) {
                do {
                    updateFakultas(Lfak);
                    cout<<"Update Lagi? (y/n)";
                    cin>>ulang;
                }
                while ((ulang == 'y') || (ulang == 'Y'));
            }
        }
        else if(pilihan == 3){
            system("cls");
            headerView();
            menuView();
            cin >> pil;
            if (pil == 1) {
                address1 p;
                if (first(Lkampus) == NULL) {
                    cout<<"List Kosong"<<endl;
                }
                else {
                    p = first(Lkampus);
                    do{
                        cout << "===============================================\n";
                        cout << endl;
                        cout<<"No ID\t: "<<info(p).id<<endl;
                        cout<<"Nama\t: "<<info(p).nama<<endl;
                        cout<<"Usia\t: "<<info(p).usia<<endl;
                        cout<<"Alamat\t: "<<info(p).alamat<<endl;
                        cout << endl;
                        cout << "===============================================\n";
                        p = next(p);
                    }while (p != first(Lkampus));
                }
            }
            else if (pil == 2) {
                viewFakultas(Lfak);
            }
            else if (pil == 3) {
                printInfoRelasiAll(LR);
            }
            else if (pil == 4) {
                printInfoRelasiKampus(LR);
            }
            else if (pil == 5) {
                printInfoRelasiFakultas(LR);
            }
        }
        else if(pilihan == 4){
            system("cls");
            headerDelete();
            menuDelete();
            cin >> pil;
            if (pil == 1) {
                do {

                    deleteKampus(Lkampus,LR);
                    cout<<"Delete Lagi? (y/n)";
                    cin>>ulang;
                } while ((ulang == 'y') || (ulang == 'Y'));
            }
            else if (pil == 2) {
                do {
                    deleteFakultas(Lfak,LR);
                    cout<<"Delete Lagi? (y/n)";
                    cin>>ulang;
                } while ((ulang == 'y') || (ulang == 'Y'));
            }
        }
        cout<<"Kembali ke Menu? (y/n) ";
        cin>>menu;
    }
    while ((menu == 'Y') || (menu == 'y'));
}
