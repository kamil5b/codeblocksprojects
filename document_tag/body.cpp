#include "header.h"

void createDocumentList(docList &Ld){
    Ld.first=NULL;
    Ld.last=NULL;
}
void createTagsList(tagList &Lt){
    Lt.first=NULL;
    Lt.last=NULL;
}
void createDocumentTagsList(doctagList &Ldt){
    Ldt.first=NULL;
    Ldt.last=NULL;
}

void addDocument(string nama,docList &Ld){
    doc D;
    D = new Document;
    D->nama=nama;
    D->jumlahTags=0;
    D->next=NULL;
    D->prev=NULL;

    if(Ld.first==NULL){
        Ld.first=D;
        Ld.last=D;
    }else{
        Ld.last->next=D;
        D->prev=Ld.last;
        Ld.last=D;
    }

}
void addTags(string nama, tagList &Lt){
    tag T;
    T = new Tags;
    T->nama=nama;
    T->jumlahDocs=0;
    T->next=NULL;
    T->prev=NULL;

    if(Lt.first==NULL){
        Lt.first=T;
        Lt.last=T;
    }else{
        Lt.last->next=T;
        T->prev=Lt.last;
        Lt.last=T;
    }

}
void documentTagging(doc &D,tag &T,doctagList &Ldt){
    doc_tag Dt,temp;
    Dt = new documentTags;
    Dt->document=D;
    Dt->tags=T;
    Dt->active=true;
    Dt->next=NULL;
    Dt->prev=NULL;

    D->jumlahTags=D->jumlahTags + 1;
    T->jumlahDocs=T->jumlahDocs + 1;

    if(Ldt.first==NULL){
        Ldt.first=Dt;
        Ldt.last=Dt;
    }else{
        temp=Ldt.first;
        while(temp!=NULL&&temp->document!=D){
            temp=temp->next;
        }
        if(temp==NULL){ //INSERT LAST
            Ldt.last->next=Dt;
            Dt->prev=Ldt.last;
            Ldt.last=Dt;
        }else{
            cout << "Masuk" << endl;
            while(temp->document==D&&temp!=NULL){
                cout << ".";
                temp=temp->next;
            }
            cout << "Terproses" << endl;
            if(temp==NULL){ //insert last
                temp=Ldt.last;
                temp->next=Dt;
                Dt->prev=temp;
                Ldt.last=Dt;
            }else{
                temp=temp->prev;
                //insert after temp
                Dt->prev=temp;
                Dt->next=temp->next;
                temp->next=Dt;
                Dt->next->prev=Dt;
            }
        }
    }
}

void deleteDocument(doc &D,docList &Ld,doctagList &Ldt,tagList &Lt){
    doc_tag Dt;

    if(D==Ld.first&&D==Ld.last){
        createDocumentList(Ld);
    }else if(D==Ld.first){
        Ld.first=D->next;
        D->next=NULL;

    }else if(D==Ld.last){
        Ld.last=D->prev;
        D->prev=NULL;
    }else{
        D->prev->next=D->next;
        D->next->prev=D->prev;
        D->next=NULL;
        D->prev=NULL;
    }
    D->jumlahTags=D->jumlahTags - 1;

    Dt=Ldt.first;
    while(Dt!=NULL){
        if(Dt->document==D&&Dt->active){
            Dt->active=false;
            Dt->tags->jumlahDocs=Dt->tags->jumlahDocs - 1;
        }
        Dt=Dt->next;
    }
}
void deleteTags(tag &T,tagList &Lt,doctagList &Ldt,docList &Ld){
    doc_tag Dt;
    if(T==Lt.first&&T==Lt.last){
        createTagsList(Lt);
    }else if(T==Lt.first){
        Lt.first=T->next;
        T->next=NULL;

    }else if(T==Lt.last){
        Lt.last=T->prev;
        T->prev=NULL;
    }else{
        T->prev->next=T->next;
        T->next->prev=T->prev;
        T->next=NULL;
        T->prev=NULL;
    }
    T->jumlahDocs=T->jumlahDocs - 1;

    Dt=Ldt.first;
    while(Dt!=NULL){
        if(Dt->tags==T&&Dt->active){
            Dt->active=false;
            Dt->document->jumlahTags=Dt->document->jumlahTags - 1;
        }
        Dt=Dt->next;
    }
}

doc searchDocument(string nama,docList &Ld){
    doc D;
    D=Ld.first;
    while(D!=NULL&&D->nama!=nama){
        D=D->next;
    }
    return D;
}
tag searchTag(string nama,tagList &Lt){
    tag T;
    T=Lt.first;
    while(T!=NULL&&T->nama!=nama){
        T=T->next;
    }
    return T;
}
tag popularTag(tagList &Lt){
    tag T,out;
    int popular;

    out=NULL;
    popular=0;
    T=Lt.first;
    while(T!=NULL){
        if(T->jumlahDocs > popular){
            popular=T->jumlahDocs;
            out=T;
        }
        T=T->next;
    }
    return out;
}
doc searchDocumentMaxTag(docList &Ld){
    doc D,out;
    int Max;

    out=Ld.first;
    Max=Ld.first->jumlahTags;
    D=Ld.first;
    while(D!=NULL){
        if(D->jumlahTags > Max){
            Max=D->jumlahTags;
            out=D;
        }
        D=D->next;
    }
    return out;
}
doc searchDocumentMinTag(docList &Ld){
    doc D,out;
    int Min;

    out=Ld.last;
    Min=Ld.first->jumlahTags;
    D=Ld.first;
    while(D!=NULL){
        if(D->jumlahTags < Min){
            Min=D->jumlahTags;
            out=D;
        }
        D=D->next;
    }
    return out;
}

void showDocumentsWithTags(doc D,doctagList Ldt){
    doc_tag Dt;
    Dt=Ldt.first;
    cout << "[Document] " << D->nama << endl;
    cout << "[Tags] ";
    while(Dt!=NULL){
        if(Dt->document==D&&Dt->active){
            cout << Dt->tags->nama << " ";
        }
        Dt=Dt->next;
    }
    cout << endl;
}
void showAllTags(tagList Lt){
    tag T;
    cout << "[Tags] " << endl;
    while(T!=NULL){
        cout << T->nama << " ";
        T=T->next;
    }
    cout << endl;
}
void showDocumentsFromTag(tag T,doctagList Ldt){
    doc_tag Dt;
    Dt=Ldt.first;
    while(Dt!=NULL){
        if(Dt->tags==T&&Dt->active){
            showDocumentsWithTags(Dt->document,Ldt);
        }
        Dt=Dt->next;
    }
}
void showDocumentsFrom2Tags(tag T1,tag T2,doctagList Ldt){
    doc_tag Dt;
    //kamil, ganteng
    showDocumentsFromTag(T1,Ldt);
    Dt=Ldt.first;
    while(Dt!=NULL){
        if(Dt->tags==T2&&Dt->tags!=T1&&Dt->active){
            showDocumentsWithTags(Dt->document,Ldt);
        }
        Dt=Dt->next;
    }

    //KAMIL
    // HAYKAL, SAYANG, PAPA
    // GANTENG
    //HAYKAL SAYANG, MAMA

    // HAYKAL<SAYANG,PAPA, MAMA
}
