#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct Document *doc;
typedef struct Tags *tag;
typedef struct documentTags *doc_tag;

struct Document {
    string nama;
    int jumlahTags;
    doc next;
    doc prev;
};

struct Tags {
    string nama;
    int jumlahDocs;
    tag next;
    tag prev;
};

struct documentTags{
    doc document;
    tag tags;
    bool active;
    doc_tag next;
    doc_tag prev;
};

struct docList {
    doc first;
    doc last;
};

struct tagList{
    tag first;
    tag last;
};

struct doctagList{
    doc_tag first;
    doc_tag last;
};

void createDocumentList(docList &Ld);
void createTagsList(tagList &Lt);
void createDocumentTagsList(doctagList &Ldt);

void addDocument(string nama,docList &Ld);
void addTags(string nama, tagList &Lt);
void documentTagging(doc &D,tag &T,doctagList &Ldt);

void deleteDocument(doc &D,docList &Ld,doctagList &Ldt,tagList &Lt);
void deleteTags(tag &T,tagList &Lt,doctagList &Ldt,docList &Ld);

doc searchDocument(string nama,docList &Ld);
tag searchTag(string nama,tagList &Lt);
tag popularTag(tagList &Lt);
doc searchDocumentMaxTag(docList &Ld);
doc searchDocumentMinTag(docList &Ld);

void showDocumentsWithTags(doc D,doctagList Ldt);
void showAllTags(tagList Lt);
void showDocumentsFromTag(tag T,doctagList Ldt);
void showDocumentsFrom2Tags(tag T1,tag T2,doctagList Ldt);

void menu(docList &Ld,tagList &Lt,doctagList &Ldt);

#endif // HEADER_H_INCLUDED
