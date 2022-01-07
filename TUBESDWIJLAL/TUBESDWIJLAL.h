#ifndef TUBESDWIJLAL_H_INCLUDED
#define TUBESDWIJLAL_H_INCLUDED
#include <iostream>
#include <stdlib.h>

using namespace std;
#define prev(P) P->prev
#define next(P) P->next
#define judul(P) P->judul
#define penulis(P) P->penulis
#define publisher(P) P->publisher
#define tahun(P) P->tahun
#define abstrak(P) P->abstrak
#define keyword(P) P->keyword
#define relasi(P) P->relasi
#define linked(P) P->linked
#define first(L) L.first
#define last(L) L.last
#define to_keyword(Q) Q->to_keyword

#define nil NULL

typedef struct elmArticle *address_article;
typedef struct elmKeyword *address_keyword;
typedef struct elmRelasi *address_relasi;

struct elmKeyword {
    address_keyword next;
    address_keyword prev;
    string keyword;
    int linked;
    address_relasi relasi;
};
struct ListKeyword{
    address_keyword first;
};

struct elmRelasi {
    address_keyword to_keyword;
    address_relasi next;
};
struct ListRelasi {
    address_relasi first;
    address_relasi relasi;
};

struct elmArticle {
    address_article next;
    string judul;
    string penulis;
    string publisher;
    int tahun;
    string abstrak;
    int linked;
    address_relasi relasi;
};
struct ListArticle {
    address_article first;
    address_article last;
};


void createList (ListArticle &L);
void createListKeyword (ListKeyword &Q);
void createListRelasi (ListRelasi &R);
void createArticle (address_article &P, string judul, string penulis, string publisher, int tahun, string abstrak);
void createKeyword (address_keyword &C,  string keyword);
void createRelasi (address_relasi &Q, address_keyword C);
bool is_empty_article (ListArticle L);
bool is_empty_keyword (ListKeyword Q);
bool is_empty_relasi (ListRelasi R);

//insert
void insertKeyword (ListKeyword &Q, address_keyword C);
void insertArticle (ListArticle &L, address_article P);
void insertRelasi (ListRelasi &R, address_relasi Q);

//search
address_article searchArticle (ListArticle L , string judul);
address_keyword seachKeyword_In_Listkeyword (ListKeyword Q, string keyword);

//connection
void connection (ListArticle &L, ListKeyword &L1,ListRelasi L2, string judul, string penulis, string publisher, int tahun, string abstrak , string keyword);

//print
void printArticle (ListArticle L);
void printKeyword (ListKeyword Q);
void printArticle_Keyword(ListArticle L);
void printkajian_terbanyak_terdikit(ListArticle L);
void printArticle_base_on_keyword(ListArticle L, ListKeyword Q, string keyword);
void printKeyword_base_on_article(ListArticle L, ListKeyword Q, string judul);

//delete
void deleteArticle (ListArticle &L, address_article P, string judul);
void deleteKeyword (ListArticle &L, ListKeyword &Q, address_keyword P, string keyword);

//menu
void menu_Insert_Article (ListArticle &L);
void menu_Insert_Keyword (ListKeyword &Q);
void menu_Insert_connection (ListArticle &L, ListKeyword &Q);
void mainmenu (ListArticle &L, ListKeyword &Q);
void menu_delete_certain_article (ListArticle &L);
void menu_delete_keyword (ListArticle &L, ListKeyword &Q);
void menu_print_article_baseonkeyword (ListArticle L, ListKeyword Q);
void menu_print_keyword_baseonarticle (ListArticle L, ListKeyword Q);

//own code
void cls();
bool validation_double (ListArticle L, ListKeyword Q, address_article P, address_keyword R);
void availablekeyword (ListArticle L, ListKeyword Q, address_article P);





#endif // TUBESDWIJLAL_H_INCLUDED
