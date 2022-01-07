#include "header.h"
int main()
{

    ListGuest LT;
    ListWaiter LW;
    createLists(LT,LW);
    address_tamu T;
    address_waiter W;
    string waiter,tamu,in;

    int menu=0;
    while(menu!=99){
        system("CLS");
        cout<<endl;
        cout<<"1. Waiter datang"<<endl;
        cout<<"2. Guest datang"<<endl;
        cout<<"3. Waiter Melayani Guest"<<endl;
        cout<<"4. Waiter pulang"<<endl;
        cout<<"5. Guest pulang"<<endl;
        cout<<"6. Waiter gabut"<<endl;
        cout<<"7. Guest yang dilayani waiter tertentu"<<endl;
        cout<<"8. Waiter yang aktif"<<endl;
        cout<<"9. Guest Istimewa"<<endl;
        cout<<"10.Tampilkan seluruh tamu dan waiter"<<endl;
        cout<<"99.Exit Program"<<endl;
        cout<<"Pilih : ";
        cin >> menu;
        switch(menu){
        case 1:
            cout << "Nama waiter : ";
            cin>>waiter;
            recruitWaiter(LW,waiter);
            break;
        case 2:
            cout << "Nama tamu : ";
            cin>>tamu;
            tamuMasuk(LT,tamu);
            break;
        case 3:
            cout << "Nama tamu : ";
            cin>>tamu;
            T=findGuest(LT,tamu);
            if(T!=NULL){
                if(T->waiter<3){
                    cout << "Nama waiter : ";
                    cin >> waiter;
                    W=findWaiter(LW,waiter);
                    if(W!=NULL){
                        waiterMelayaniGuest(W,T);
                    }else{
                        cout << "Waiter belum datang" <<endl;
                    }
                }else{
                    cout<<"Guest sudah dilayani 3 waiter"<<endl;
                }
            }else{
                cout<<"Nama tamu tidak terdaftar"<<endl;
            }
            break;
        case 4:
            cout << "Nama waiter yang pulang : ";
            cin>>waiter;
            deleteWaiter(LW,waiter);
            break;
        case 5:
            cout << "Nama tamu yang pulang : ";
            cin>>tamu;
            deleteGuest(LW,LT,tamu);
            break;
        case 6:
            waiterGabut(LW);
            break;
        case 7:
            cout << "Nama waiter : ";
            cin >> waiter;
            printGuestWaiter(LW,waiter);
            break;
        case 8:
            waiterAktif(LW);
            break;
        case 9:
            tamuSpesial(LT,LW);
            break;
        case 10:
            printAll(LW,LT);
            break;
        }
        cout<<endl;
        cout << "Press enter to continue";
        cin>>in;
    }

    return 0;
}
