#include "header_paperkeyword.h"

int main()
{
    cout << "Nariswari Yoga" << endl;
    cout << "Yudha" << endl;

    int choose;
    string key,title;
    p_address P;
    r_address R;
    k_address K;

    listPaper Lp;
    listKeyword Lk;
    listRelation Lr;

    createList(Lk,Lp,Lr);

    choose=99;

    while(choose!=0){
        cout << endl;
        cout << "=============================" << endl;
        cout << "0 Exit" << endl;
        cout << "1 Add Paper" << endl;
        cout << "2 Add Keyword" << endl;
        cout << "3 Add Paper's keyword" << endl;
        cout << "4 Delete Paper" << endl;
        cout << "5 Delete Keyword" << endl;
        cout << "6 The most popular keyword" << endl;
        cout << "7 Show all Paper" << endl;
        cout << "8 Show all Keyword" << endl;
        cout << "Pilih angka : ";
        cin >> choose;

        switch(choose){
        case 1:
            cout << "Enter the paper's title (using \'_\' instead of spaces) : ";
            cin >> title;
            P=createPaper(title);
            insertPaper(P,Lp);
            break;
        case 2:
            cout << "Enter a keyword (using \'_\' instead of spaces) : ";
            cin >> key;
            K=createKeyword(key);
            insertKeyword(K,Lk);
            break;
        case 3:
            cout << "Enter the paper's title (using \'_\' instead of spaces) : ";
            cin >> title;
            P=searchPaper(title,Lp);
            if(P!=NULL){
                cout << "Paper has found!" << endl;
                cout << "Enter a keyword (using \'_\' instead of spaces) : ";
                cin >> key;
                K=searchKeyword(key,Lk);
                if(K!=NULL){
                    cout << "The keyword has found!" << endl;
                }else{
                    cout << "Creating a new keyword...." << endl;
                    K=createKeyword(key);
                    insertKeyword(K,Lk);
                }
                R=createRelation(P,K);
                insertRelation(R,Lr);
                cout << "The keyword has been added to the Paper" << endl;
            }else{
                cout << "The paper haven't added yet to the program" << endl;
            }
            break;
        case 4:
            cout << "Enter the paper's title (using \'_\' instead of spaces) : ";
            cin >> title;
            P=searchPaper(title,Lp);
            if(P!=NULL){
                deletePaper(P,Lp,Lr);
                cout << "The paper has been deleted" << endl;
            }else{
                cout << "The paper haven't added yet to the program" << endl;
            }
            break;
        case 5:
            cout << "Enter a keyword (using \'_\' instead of spaces) : ";
            cin >> key;
            K=searchKeyword(key,Lk);
            if(K!=NULL){
                deleteKeyword(K,Lk,Lr);
                cout << "The keyword has been deleted" << endl;
            }else{
                cout << "The keyword haven't added yet to the program" << endl;
            }
            break;
        case 6:
            popularKeyword(Lk,Lr);
            break;
        case 7:
            cout << "Filter the papers using keyword, enter \"all\" if you want to show it all" << endl;
            cout << "Enter a keyword (using \'_\' instead of spaces) : ";
            cin >> key;
            if(key=="all"){
                P=first(Lp);
                while(P!=NULL){
                    showPaper(P,Lr);
                    P=next(P);
                }
            }else{
                K=searchKeyword(key,Lk);
                if(K!=NULL){
                    showKeyword(K,Lr);
                }else{
                    cout << "The key is invalid" << endl;
                }
            }
            break;
        case 8:
            cout << "Too see a specific Paper's keyword, enter \"all\" if you want to show it all" << endl;
            cout << "Enter the Paper's title (using \'_\' instead of spaces) : ";
            cin >> title;
            if(title=="all"){
                K=first(Lk);
                while(K!=NULL){
                    showKeyword(K,Lr);
                    K=next(K);
                }
            }else{
                P=searchPaper(title,Lp);
                if(P!=NULL){
                    cout << "The paper has found" << endl;
                    showPaper(P,Lr);
                }else{
                    cout << "The title is invalid" << endl;
                }
            }
            break;
        }
    }
    return 0;
}
