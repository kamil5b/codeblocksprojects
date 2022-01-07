#include "film.h"

int main()
{

    ListDirector LD;
    ListBridge LB;
    ListFilm LF;
    adrD D,A;
    adrF F;

    createList(LB,LD,LF);
    string name,genre;
    int choose;
    do{
        cout<<"0. Exit"<<endl;
        cout<<"1. Menambahkan sutradara baru"<<endl;
        cout<<"2. Menambahkan film baru"<<endl;
        cout<<"3. Menambahkan hubungan film dan sutradara/astrada"<<endl;
        cout<<"4. Menghapus sutradara tertentu"<<endl;
        cout<<"5. Menghapus film tertentu"<<endl;
        cout<<"6. Menampilkan sutradara yang banyak film"<<endl;
        cout<<"7. Menampilkan semua film dari sutradara tertentu"<<endl;
        cout<<"8. Menampilkan semua film yang mempunyai 2 sutradara"<<endl;
        cout<<"9. Menampilkan asisten sutradara yang paling sedikit terlibat di film"<<endl;
        cout<<"10.Menampilkan seluruh film"<<endl;
        cout<<"Pilih : ";
        cin>>choose;
        switch(choose){
            case 1:
                cout << "Nama sutradara : ";
                cin >> name;
                addDirector(LD,name);
                break;
            case 2:
                cout << "Nama film : ";
                cin >> name;
                cout << "Genre Film : ";
                cin >> genre;
                addFilm(LF,name,genre);
                break;
            case 3:
                cout << "Nama film : ";
                cin >> name;
                F=findFilm(LF,name);
                if(F!=NULL){
                    cout << "Nama sutradara : ";
                    cin >> name;
                    D=findDirector(LD,name);
                    if(D!=NULL){
                        cout << "Nama astrada (kosongkan bila taada): ";
                        cin >> name;
                        A=findDirector(LD,name);
                        if(A!=NULL){
                            connect(LB,D,A,F);
                        }else{
                            connect(LB,D,F);
                        }
                    }
                }
                break;
            case 4:
                cout << "Nama sutradara : ";
                cin >> name;
                deleteDirector(LD,LB,name);
                break;
            case 5:
                cout << "Nama Film : ";
                cin >> name;
                deleteFilm(LF,LB,name);
                break;
            case 6:
                maxFilmFirector(LD,LB);
                break;
            case 7:
                cout << "Nama Sutradara : ";
                cin >> name;
                filmFromDirector(LB,name);
                break;
            case 8:
                filmWithTwoDirector(LB);
                break;
            case 9:
                minAstrada(LD,LB);
                break;
            case 10:
                printAll(LB,LD,LF);
                break;
        }
    }while(choose!=0);

    return 0;
}
