#include "header_MLL.h"

void createListDocument(listDocument &L){
    L.first=NULL;
    L.last=NULL;
}
void createListTags(listTags &L){
    L.first=NULL;
}
void addDocument(listDocument &L, string doc_name){
    doc_pointer D;
    D=new Document;
    D->doc_name=doc_name;
    createListTags(D->l_tags);
    D->next=NULL;
    D->prev=NULL;

    if(L.last==NULL){
        L.first=D;
        L.last=D;
    }else{
        (L.last)->next=D;
        D->prev=L.last;
        L.last=D;
    }
}
void addTags(listTags &L, string tag_name){
    tags_pointer T;
    T=new Tags;
    T->tag_name=tag_name;
    T->next=NULL;

    if(L.first==NULL){
        L.first=T;
    }else{
        T->next=L.first;
        L.first=T;
    }
}
void documentTagging(doc_pointer &D, listTags &L,string tag_name){
    tags_pointer T;
    doc_tag Td,temp;

    T=searchTags(L,tag_name);

    if(T==NULL){
        addTags(L,tag_name);
        T=L.last;
    }

    if((D->l_tags).first==NULL){
        Td=new documentTags;
        Td->tag=T;
        Td->next=NULL;
        (D->l_tags).first=Td;
    }else{
        temp=(D->l_tags).first;
        while(temp!=NULL&&temp->tag!=NULL){
            temp=temp->next;
        }
        if(temp==NULL){
            Td=new documentTags;
            Td->tag=T;
            Td->next=(D->l_tags).first;
            (D->l_tags).first=Td;
        }else{
            temp->tag=T;
        }
    }

}

tags_pointer searchTags(listTags &L,string tag_name){
    tags_pointer P;
    P=L.first;
    while(P!=NULL&&P->tag_name!=tag_name){
        P=P->next;
    }
    return P;
}
doc_pointer searchDocument(listDocument &L,string doc_name){
    doc_pointer P;
    P=L.first;
    while(P!=NULL&&P->doc_name!=doc_name){
        P=P->next;
    }
    return P;
}
tags_pointer searchPopularTags(listDocument Ld,listTags Lt){
    doc_pointer D;
    tags_pointer T,out;
    doc_tag Td;
    int Max,i;

    T=Lt.first;
    Max=0;
    while(T!=NULL){
        i=0;
        D=Ld.first;
        while(D!=NULL){
            Td=(D->l_tags).first;
            while(Td!=NULL){
                if((Td->tag)->tag_name==T->tag_name){
                    i++
                }
                Td=Td->next;
            }
            D=D->next;
        }
        if(i>Max){
            Max=i;
            out=T;
        }
        T=T->next;
    }
    return out;
}
listDocument searchDocumenTags(listDocument L, tags_pointer T){
    listDocument Ld;
    doc_pointer D;
    doc_tag P;

    createListDocument(Ld);
    D=L.first;

    while(D!=NULL){
        P=(D->l_tags).first;
        while(P!=NULL){
            if(P->tag==T){
                if(Ld.last==NULL){
                    Ld.last=P;
                    Ld.first=P;
                }else{
                    (Ld.last)->next=P;
                    P->prev=Ld.last;
                    Ld.last=P;
                }
            }
            P=P->next;
        }
        D=D->next;
    }


}

void mergeDocumentTemp(listDocument L1,L2){
    listDocument L3;
    doc_pointer D,Dd,D3;
    bool ada;
    createListDocument(L3);


    Dd=L1.first;
    while(Dd!=NULL){
        addDocument(L3,Dd->doc_name);
        D=L3.last;
        D->l_tags=Dd->l_tags;;
        Dd=Dd->next;
    }
    Dd=L2.first;
    while(Dd!=NULL){
        D3=L3.first;
        ada=false
        while(D3!=NULL&&!ada){
            if(D3->doc_name==Dd->doc_name){
                ada=true;
            }
            D3=D3->next;
        }
        if(!ada){
            addDocument(L3,Dd->doc_name);
            D=L3.last
            D->l_tags=Dd->l_tags;
        }
        Dd=Dd->next;
    }
    lihatDocument(L3);
}

tags_pointer deleteTags(listDocument Ld,listTags &Lt,string tag_name){
    tags_pointer T;
    doc_tag Td;
    doc_pointer D;

    T=searchTags(Lt,tag_name);
    if(T!=NULL){
        D=Ld.first;
        while(D!=NULL){
            Td=(D->l_tags).first;
            while(Td!=NULL){
                if(Td->tag==T){
                    Td->tag=NULL;
                }
                Td=Td->next;
            }
            D=D->next;
        }
    }
    return T;
}
doc_pointer deleteDocs(listDocument &Ld,string doc_name){
    doc_pointer D;

    D=searchDocument(Ld,doc_name);
    if(D!=NULL){
        if(D==Ld.first){
            Ld.first=D->next;
            (Ld.first)->prev=NULL;
            D->next=NULL;
        }else if(D==Ld.last){
            Ld.last=D->prev;
            (Ld.last)->next=NULL;
            D->prev=NULL;
        }else{
            (D->prev)->next=D->next;
            (D->next)->prev=D->prev;
            D->next=NULL;
            D->prev=NULL;
        }
    }
    return D;
}

void lihatDocument(listDocument &L){
    doc_pointer D;
    D=L.first;
    cout << "===============" <<endl;
    while(D!=NULL){
        cout << "[Document] "<<D->doc_name<<endl;
        lihatTags(D->l_tags);
        cout << "---------------" <<endl;
        D=D->next;
    }
}
void lihatDocumentTags(listDocumentTags &L){
    doc_tag Td;
    Td=L.first;
    cout << "[Tags] ";
    while(Td!=NULL){
        cout << (Td->tag)->tag_name << " ";
        Td=Td->next;
    }
    cout<<endl;
}
void lihatTags(listTags &L){
    tags_pointer T;
    T=L.first;
    cout << "[Tags] ";
    while(T!=NULL){
        cout << T->tag_name <<" ";
        T=T->next;
    }
    cout<<endl;
}


