#ifndef HEADER_MLL_H_INCLUDED
#define HEADER_MLL_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct Tags *tags_pointer;

typedef struct Document *doc_pointer;

typedef struct documentTags *doc_tag;


struct listDocument {
    doc_pointer first;
    doc_pointer last;
};

struct listDocumentTags {
    doc_tag first;
};

struct listTags{
    tags_pointer first;
};

struct Document {
    string doc_name;
    listDocumentTags l_tags;
    doc_pointer next;
    doc_pointer prev;
};

struct documentTags{
    tags_pointer tag;
    doc_tag next;
};

struct Tags {
    string tag_name;
    tags_pointer next;
};


void createListDocument(listDocument &L);
void createListTags(listTags &L);

void addDocument(listDocument &D, string doc_name); //insert
void addTags(listTags &T, string tag_name); //insert
void documentTagging(doc_pointer &D, listTags &L,string tag_name);
void mergeDocumentTemp(listDocument L1, listDocument L2);

tags_pointer searchTags(listTags &L,string tag_name);
doc_pointer searchDocument(listDocument &L,string doc_name);
tags_pointer searchPopularTags(listDocument Ld,listTags Lt);
listDocument searchDocumenTags(listDocument L, tags_pointer T);

tags_pointer deleteTags(listDocument Ld,listTags &Lt,string tag_name);
doc_pointer deleteDocs(listDocument &Ld,string doc_name);

void menu(listDocument &global_doc, listTags &global_tags);
void lihatDocument(listDocument &L);
void lihatDocumentTags(listDocumentTags &L);
void lihatTags(listTags &L);

#endif // HEADER_MLL_H_INCLUDED
