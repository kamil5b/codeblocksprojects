#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct Keyword *k_pointer;
typedef struct Paper *p_pointer;
typedef struct Relation *r_pointer;

struct Keyword { //parent
    string key;
    r_pointer relasi;
    k_pointer next;
    k_pointer prev;
};

struct Relation {
    r_pointer next;
    p_pointer paper;
};

struct Paper { //child
    string judul;
    p_pointer next;
    p_pointer prev;
};

struct paperList{
    p_pointer first;
    p_pointer last;
};

struct keywordList{
    k_pointer first;
    k_pointer last;
};

void buatPaperList(paperList &Lp);
void buatKeywordList(keywordList &Lk);

void tambahPaper(string judul,paperList &Lp);
void tambahKeyword(string key,keywordList &Lk);
void PaperKeyword(p_pointer P,k_pointer &K);

void deletePaper(p_pointer &P,paperList &Lp,keywordList Lk);
void deleteKeyword(k_pointer &K,keywordList &Lk);

p_pointer cariPaper (string judul,paperList &Lp);
k_pointer cariKeyword (string key,keywordList &Lk);

void lihatKeywordAndPaper(k_pointer K);
void lihatPaperAndKey(p_pointer P,keywordList Lk);
void popularKeywordPaper(keywordList Lk);


#endif // HEADER_H_INCLUDED
