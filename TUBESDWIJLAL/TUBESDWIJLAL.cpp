#include "TUBESDWIJLAL.h"

void createList (ListArticle &L) {
    first(L) = nil;
    last(L) = nil;
}

void createListKeyword (ListKeyword &Q) {
    first(Q) = nil;
}

void createListRelasi (ListRelasi &R) {
    first(R) = nil;
}

void createArticle (address_article &P, string judul, string penulis, string publisher, int tahun, string abstrak) {
    P = new elmArticle;
    judul(P) = judul;
    penulis(P) = penulis;
    publisher(P) = publisher;
    tahun(P) = tahun;
    abstrak(P) = abstrak;
    next(P) = nil;
    linked(P) = 0;
}

void createKeyword (address_keyword &C,  string keyword) {
    C = new elmKeyword;
    keyword(C) = keyword;
    next(C) = nil;
    prev(C) = nil;
    linked(C) = 0;
}

void createRelasi (address_relasi &Q, address_keyword C){
    Q = new elmRelasi;
//    to_keyword(Q) = C;
    next(Q) = nil;
}

bool is_empty_article (ListArticle L) {
    return ((first(L) == nil) && (last(L) == nil));
}

bool is_empty_keyword (ListKeyword Q) {
    return first(Q) == nil;
}

bool is_empty_relasi (ListRelasi R) {
    return first(R) == nil;
}

void insertKeyword (ListKeyword &Q, address_keyword C) {
    if (is_empty_keyword(Q)) {
        first(Q) = C;
    } else {
        address_keyword R = first(Q);
        while (next(R) != nil) {
            R = next(R);
        }
        next(R) = C;
        prev(C) = R;
        next(C) = nil;
    }
}
void insertArticle (ListArticle &L, address_article P) {
    if (is_empty_article(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        address_article R = last(L);
        next(R) = P;
        next(P) = first(L);
    }
}
void insertRelasi (ListRelasi &R, address_relasi Q) {
    if (is_empty_relasi(R)) {
        first(R) = Q;
    } else {
        address_relasi P = first(R);
        while (next(P) != nil) {
            P = next(P);
        }
        next(P) = Q;
        next(Q) = nil;
    }
}
address_article searchArticle (ListArticle L , string judul) {
    address_article P = first(L);
    do {
        P = next(P);
    } while ((P == last(L) ) && (judul(P) != judul));
    if (judul(P) == judul) {
        return P;
    } else {
        return nil;
    }
}
address_keyword seachKeyword_In_Listkeyword (ListKeyword Q, string keyword) {
    address_keyword C = first(Q);
    while ((next(C) != nil) && (keyword(C) != keyword)) {
        C = next(C);
    }
    if (keyword(C) == keyword) {
        return C;
    } else {
        return nil;
    }
}

void connection (ListArticle &L, ListKeyword &L1, ListRelasi &L2,string judul, string keyword) {
    address_article P = searchArticle(L, judul);
    address_keyword Q = seachKeyword_In_Listkeyword(L1, keyword);
    address_relasi R;
    if ((P == nil) || (Q == nil)) {
        cout << "Article or Keyword is not in list \n";
    } else {
        createRelasi(R,Q);
        insertRelasi(L2,R);
        linked(P)++;
        linked(Q)++;
    }
}

void printArticle (ListArticle L) {
    if (is_empty_article(L)) {
        cout << "Article is empty \n";
    } else {
        address_article P = first(L);
        cout << "Article : \n";
        do {
            cout << ". \t Judul : " << judul(P) << endl;
            cout << ". \t Penulis : " << penulis(P) << endl;
            cout << ". \t Publisher : " << publisher(P) << endl;
            cout << ". \t Tahun Posting : " << tahun(P) << endl;
            cout << ". \t Abstrak : " << abstrak(P) << endl;
            P = next(P);
        } while (P != first(L));
        cout << endl;
    }
}
void printKeyword (ListKeyword Q) {
    if (!is_empty_keyword(Q)) {
        address_keyword P = first(Q);
        cout << "Keyword : ";
        while (P != nil) {
            cout << keyword(P) << " ";
            P = next(P);
        }
        cout << endl;
    } else {
        cout << "Keyword is empty\n";
    }
}
void printArticle_Keyword(ListArticle L, ListKeyword L1) {
    if (!is_empty_article(L) && !is_empty_keyword(L1)) {
        address_article P = first(L);
        address_keyword Q = first(L1);
        int i = 1;
        do {
            cout << i << ". \t Judul : " << judul(P) << endl;
            cout << i << ". \t Penulis : " << penulis(P) << endl;
            cout << i << ". \t Publisher : " << publisher(P) << endl;
            cout << i << ". \t Tahun Posting : " << tahun(P) << endl;
            cout << i << ". \t Abstrak : " << abstrak(P) << endl;
            Q = first(L1);
            // Print semua keyword
            if (Q != nil) {
                cout << "\t keyword : ";
                while (Q != nil) {
//                    cout << keyword(to_keyword(Q)) << " ";
                    Q = next(Q);
                }
            }
            // end
            cout <<endl;
            i++;
            P = next(P);
        } while (P != first(L));
    }
}
void deleteArticle (ListArticle &L, address_article P, string judul) {
    address_article R = first(L);
    bool error = false;
    if (first(L) != nil) {
        P = searchArticle(L,judul);
        if (P != nil) {
            address_relasi Q = first(relasi(P));
            while (Q != nil) {
                if (to_keyword(Q) != nil) {
                    linked(to_keyword(Q))--;
                    to_keyword(Q) = nil;
                }
                Q = next(Q);
            }
            if (P == first(L)) {
                first(L) = next(P);
                next(last(L)) = first(L);
                next(P) = nil;
            } else {
                while (next(R) != P) {
                    R = next(R);
                }
                next(R) = next(P);
                next(P) = nil;
            }
            cout << "Article has been deleted \n";
        } else {
            cout << "Article not found \n";
            return;
        }
    } else {
        cout << "Empty Article \n";
    }
}
void deleteKeyword (ListArticle &L, ListKeyword &Q, address_keyword P, string keyword) {
    address_keyword R = first(Q);
    if (first(Q) != nil) {
        P = seachKeyword_In_Listkeyword(Q,keyword);
        if (P != nil) {
            /**Delete child yang to_keywordnya keyword**/
            address_article S = first(L);
            address_relasi A;
            address_relasi B;
            address_relasi temp;
            while (S != nil) {
                A = first(relasi(S));
                while (A != nil) {
                    temp = next(A);
                    if (to_keyword(A) == P) {
                        /**delete relasi**/
                        if (A == first(relasi(S))) {
                            first(relasi(S)) = next(A);
                            next(A) = nil;
                        } else {
                            B = first(relasi(S));
                            while (next(B) != A) {
                                B = next(B);
                            }
                            next(B) = nil;
                            next(A) = nil;
                        }
                    }
                    A = temp;
                }
                S = next(S);
            }
            /**=================**/
            /** delete keyword **/
            if (P == first(Q)) {
                first(Q) = next(P);
                next(P) = nil;
            } else {
                while (next(R) != P) {
                    R = next(R);
            }
            next(R) = next(P);
            prev(next(P)) = R;
            next(P) = nil;
            prev(P) = nil;
            }
            /**=================**/

        } else {
            cout << "Keyword not found \n";
        }
    }
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
bool validation_double (ListArticle L, ListKeyword Q, address_article P, address_keyword R) {
//mengvalidasi keyword yang terindikasi double dalam satu artcile
/** proses : mencari judul artikel dalam list article, mencari keyword dalam list keyword, lalu mengecek child dari
judul article tsb apakah ada yang terhubung dengan keyword, jika tidak maka kirimkan false, true jika sebaliknya **/
    address_relasi A = first(relasi(P));
    bool error = false;
    while ((A != nil) && (error != true)) {
        if (to_keyword(A) == R) {
            error = true;
        }
        A = next(A);
    }
    return error;
}
void availablekeyword (ListArticle L, ListKeyword Q, address_article P) {
//mencetak keyword yang tersedia di konek
/** proses : mengecek satu persatu keyword, jika keyword tersebut ditunjuk oleh relasi P
maka tidak bisa dicetak, begitu sebaliknya **/
    address_keyword R = first(Q);
    address_relasi A = first(relasi(P));
    int i = 1;
    while (R != nil) {
        if (!validation_double(L,Q,P,R)) {
            cout << "\t" << i << ". " << keyword(R) << endl;
        }
        R = next(R);
        i++;
    }
}
