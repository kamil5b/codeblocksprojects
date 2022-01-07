#include "TUBESDWIJLAL.h"


void cls() {
    system("cls");
}

void mainmenu (ListArticle &L, ListKeyword &Q) {
    int kode;
    do {
        cout << "------Welcome to our program------ \n";
        cout << "1. Insert new Data Article \n";
        cout << "2. Insert new Keyword \n";
        cout << "3. Insert connection between article and keyword \n";
        cout << "4. Delete certain article \n";
        cout << "5. Delete certain keyword \n";
        cout << "6. Print all articles and keywords \n";
        cout << "7. Print all keywords \n";
        cout << "8. Print all articles \n";
        cout << "9. Print Article based on many of study field \n";
        cout << "10. Print articles based on keyword \n";
       // cout << "11. Print keywords based on article \n ";
        cout << "0.Quit \n";
        cout << "enter code : ";
        cin >> kode;
        switch(kode) {
            case 0 : break;
            case 1 : menu_Insert_Article(L);
                     break;
            case 2 : menu_Insert_Keyword(Q);
                     break;
            case 3 : menu_Insert_connection(L,Q);
                     break;
            case 4 : menu_delete_certain_article(L);
                     break;
            case 5 : menu_delete_keyword(L,Q);
                     break;
            case 6 : system("cls");
                     printArticle_Keyword(L);
                     break;
            case 7 : printKeyword(Q);
                     break;
            case 8 : printArticle(L);
                     break;
            case 9 : printkajian_terbanyak_terdikit(L);
                     break;
            case 10: menu_print_article_baseonkeyword(L,Q);
                     break;
            case 11: menu_print_keyword_baseonarticle(L,Q);
                     break;
            default : cout << "Wrong Input Code ! \n";
                     break;
        }
        system("pause");
        system("CLS");
    } while ((kode != 0));
}

void menu_Insert_Article (ListArticle &L) {
    system("cls");
    string judul;
    string penulis;
    string publisher;
    int tahun;
    string abstrak;
    string again;
    do {
        do {
            cout << "type 'cancel' in judul to cancel adding data article \n";
            cout << "Judul : ";
            cin >> judul;
            cout << "\n";
            cout << "Penulis : ";
            cin >> penulis;
            cout << "\n";
            cout << "Publisher : ";
            cin >> publisher;
            cout << "\n";
            cout << "Tahun Posting : ";
            cin >> tahun;
            cout << "\n";
            cout << "Abstrak : ";
            cin >> abstrak;
            cout << "\n";
        } while (judul == "");
        if (judul != "cancel") {
            address_article P;
            createArticle(P,judul,penulis,publisher,tahun,abstrak);
            insertArticle(L,P);
            cout << "---Data Article has been add--- \n";
            system("pause");
            do {
                cout << "Insert new Data Article (yes/no) ? ";
                cin >> again;
            } while ((again != "yes") && (again != "no"));
        } else {
            cout << "Input has been cancel \n";
            again = "no";
        }
    } while (again != "no");
}

void menu_Insert_Keyword (ListKeyword &Q) {
    system("cls");
    string X;
    string again;
    do {
        do {
            cout << "type 'cancel' to cancel adding Keyword \n";
            cout << "Keyword : ";
            cin >> X;
        } while (X == "");
        if (X != "cancel") {
            address_keyword P;
            createKeyword(P,X);
            cout << "---Keyword has been add--- \n";
            system("pause");
            do {
                cout << "Insert new keyword (yes/no) ? ";
                cin >> again;
            } while ((again != "yes") && (again != "no"));
        } else {
            cout << "Input has been cancel \n";
            again = "no";
        }
    } while (again != "no");
}
void menu_Insert_connection (ListArticle &L, ListKeyword &Q) {
    string judul, keyword;
    address_article P;
    address_keyword R;
    bool error;
    string again;
    cls();
    if ( (is_empty_keyword(Q)) || (is_empty_article(L)) ) {
        cout << "no data, please insert first in menu \n";
    } else {
         do {
            cls();
            error = false;
            printArticle(L);
            printKeyword(Q);
            cout << "type 'cancel to cancel adding connection \n";
            cout << "enter article's title : ";
            cin >> judul;
            P = searchArticle(L,judul);
            if (P != nil) {
                cout << "available keyword name insert to " << judul << " : " <<endl;
                availablekeyword(L,Q,P);
                cout << "enter keyword : ";
                cin >> keyword;
            }
            R = seachKeyword_In_Listkeyword(Q,keyword);
            if ( (P == nil) || (R == nil)) {
                error = true;
                if (judul == "cancel") {
                    cout << "insert connection has been cancel \n";
                    again = "no";
                } else {
                    cout << "enter correct article's title or keyword \n";
                }
            } else {
                if (validation_double(L,Q,P,R)) {
                    cout << "Article already have that keyword! \n";
                    error = true;
                } else {
                    connection(L,Q,judul,keyword);
                    cout << "connection is successful \n";
                }
            }
            if (error == false) {
            do {
                cout << "Insert new connection (yes/no) ?";
                cin >> again;
                } while ((again != "yes") && (again != "n"));
            } else {
            if (judul != "cancel") system ("pause");
            }
            if (judul == "cancel") {
                error = false;
                again = "no";
            }
        } while ((error == true) || (again == "y"));
    }
}

void menu_delete_certain_article (ListArticle &L) {
    string judul;
    address_article P;
    bool error = false;
    if (!is_empty_article(L)) {
        do {
            error = false;
            cls();
            printArticle(L);
            cout << "type 'cancel' to cancel delet tweet \n";
            cout << "enter article's title : ";
            cin >> judul;
            P = searchArticle(L,judul);
            if (judul != "cancel") {
                if (P == nil) {
                    cout << "article's title not found \n";
                    error = true;
                } else {
                    deleteArticle(L,P,judul);
                    delete P;
                }
            }
            if (error == true) system("pause");
        } while (error == true);
    } else {
        cls();
        cout << "empty article ! \n";
    }
}
void menu_delete_keyword (ListArticle &L, ListKeyword &Q) {
    string keyword;
    address_keyword P;
    bool error = false;
    if (!is_empty_keyword(Q)) {
        do {
            error = false;
            cls();
            printKeyword(Q);
            cout << "type 'cancel' to cancel delete keyword \n";
            cout << "enter keyword : ";
            cin >> keyword;
            P = seachKeyword_In_Listkeyword(Q,keyword);
            if (keyword != "cancel") {
                if (P == nil) {
                    cout << "keyword not found \n";
                    error = true;
                } else {
                    deleteKeyword(L,Q,P,keyword);
                    delete P;
                    cout << "keyword has been deleted \n";
                }
            }
            if (error == true) system("pause");
        } while (error == true);
    } else {
        cls();
        cout << "empty keyword ! \n";
    }
}
void menu_print_article_baseonkeyword (ListArticle L, ListKeyword Q) {
    bool error;
    string keyword;
    address_keyword P;
    do {
        error = false;
        cls();
        printKeyword(Q);
        cout << "type 'cancel' to cancel print Article \n";
        cout << "enter keyword name : ";
        cin >> keyword;
        if (keyword != "cancel") {
            P = seachKeyword_In_Listkeyword(Q,keyword);
            if (P == nil) {
                cout << "keyword not found! \n";
                error = true;
            } else {
                printArticle_base_on_keyword(L,Q,keyword);
            }
        } else {
            cout << "print has been cancel \n";
        }
        if (error == true) system("pause");
    } while (error == true);
}
void menu_print_keyword_baseonarticle (ListArticle L, ListKeyword Q) {
    bool error;
    string judul;
    address_article P;
    do {
        error = false;
        cls();
        printArticle(L);
        cout << "type 'cancel' to cancel print Keyword \n";
        cout << "enter article's name : ";
        cin >> judul;
        if (judul != "cancel") {
            P = searchArticle(L,judul);
            if (P == nil) {
                cout << "article's title not found \n";
                error = true;
            } else {
                printKeyword_base_on_article(L,Q,judul);
            }
        } else {
            cout << "print has been cancel \n";
        }
        if (error == true) system("pause");
    } while (error == true);
}

void printkajian_terbanyak_terdikit(ListArticle L) {
    // mencetak article dengan bidang kajian terbanyak dan terdikit
    int maks = 0;
    int mini = 0;
    if (first(L) != nil) {
        address_article P = first(L);
        maks = linked(P);
        mini = linked(P);
        /** mencari maksimal dan minimum**/
        do {
            if (linked(P) >= maks) {
                maks = linked(P);
            } else if (linked(P) < mini) {
                mini = linked(P);
            }
            P = next(P);
        } while (P != first(L));
        /**=================**/
        if ((maks == 0) && (mini == 0)) {
            cout << "Article is empty or no connection with keyword \n";
        } else {
            /** mencetak article yang linkednya berjumlah maksimal **/
            P = first(L);
            cout << "Article dengan bidang kajian terbanyak : ";
            do {
                if (linked(P) == maks) {
                    cout << ". \t Judul : " << judul(P) << endl;
                    cout << ". \t Penulis : " << penulis(P) << endl;
                    cout << ". \t Publisher : " << publisher(P) << endl;
                    cout << ". \t Tahun Posting : " << tahun(P) << endl;
                    cout << ". \t Abstrak : " << abstrak(P) << endl;
                }
                P = next(P);
            } while (P != first(L));
            cout << endl;
             /** mencetak article yang linkednya berjumlah minimal **/
            P = first(L);
            cout << "Article dengan bidang kajian terdikit : ";
            do {
                if (linked(P) == mini) {
                    cout << ". \t Judul : " << judul(P) << endl;
                    cout << ". \t Penulis : " << penulis(P) << endl;
                    cout << ". \t Publisher : " << publisher(P) << endl;
                    cout << ". \t Tahun Posting : " << tahun(P) << endl;
                    cout << ". \t Abstrak : " << abstrak(P) << endl;
                }
                P = next(P);
            } while (P != first(L));
            cout <<endl;
            /**=================**/
        }
    } else {
        cout << "Article is empty \n";
    }
}

void printArticle_base_on_keyword(ListArticle L, ListKeyword Q, string keyword) {
// mencetak article berdasarkan keyword tertentu
    if ((first(L) == nil) && (first(Q) == nil)) {
        cout << "Data is not available";
    } else if (first(L) == nil) {
        cout << "Article List didn't add yet \n";
    } else if (first(Q) == nil) {
        cout << "Keyword List didn't add yet \n";
    } else {
        address_article P = first(L);
        address_keyword R = seachKeyword_In_Listkeyword(Q,keyword);
        if (R != nil) {
            do {
                /**Mencari relasi yang terhubung dengan keyword yang telah didapatkan di R**/
                address_relasi A = first(relasi(P));
                while (A != nil) {
                    if (to_keyword(A) == R) {
                        cout << ". \t Judul : " << judul(P) << endl;
                        cout << ". \t Penulis : " << penulis(P) << endl;
                        cout << ". \t Publisher : " << publisher(P) << endl;
                        cout << ". \t Tahun Posting : " << tahun(P) << endl;
                        cout << ". \t Abstrak : " << abstrak(P) << endl;
                    }
                    A = next(A);
                }
                /**=================**/
                P = next(P);
            } while (P != first(L));
            cout << endl;
        } else {
            cout << "keyword not found \n";
        }
    }
}

void printKeyword_base_on_article(ListArticle L, ListKeyword Q, string judul) {
// mencetak keyword berdasarkan judul artikel tertentu
    if ((first(L) == nil) && (first(Q) == nil)) {
        cout << "Data is not available";
    } else if (first(L) == nil) {
        cout << "Article List didn't add yet \n";
    } else if (first(Q) == nil) {
        cout << "Keyword List didn't add yet \n";
    } else {
        address_keyword P = first(Q);
        address_article R = searchArticle(L,judul);
        if (R != nil) {
            while (P != nil) {
                address_relasi A = first(relasi(P));
                while (A != nil) {
                    if (to_keyword(A) == R) {
                        cout << keyword(P) << " ";
                    }
                    A = next(A);
                }
                /**=================**/
               P = next(P);
            }
            cout << endl;
        } else {
            cout << "Article not found \n";
        }
    }
}
