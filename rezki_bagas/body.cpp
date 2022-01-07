#include "header.h"

void buatPaperList(paperList &Lp){
    Lp.first=NULL;
    Lp.last=NULL;
}
void buatKeywordList(keywordList &Lk){
    Lk.first=NULL;
    Lk.last=NULL;
}

void tambahPaper(string judul,paperList &Lp){
    p_pointer P;
    P = new Paper;
    P->judul=judul;
    P->next=NULL;
    P->prev=NULL;

    //insert first
    if(Lp.first==NULL){
        Lp.first=P;
        Lp.last=P;
    }else{
        P->next=Lp.first;
        Lp.first->prev=P;
        Lp.first=P;
    }

}
void tambahKeyword(string key,keywordList &Lk){
    k_pointer k;
    k = new Keyword;
    k->key=key;
    k->relasi=NULL;
    k->next=NULL;
    k->prev=NULL;

    //insert first
    if(Lk.first==NULL){
        Lk.first=k;
        Lk.last=k;
    }else{
        k->next=Lk.first;
        Lk.first->prev=k;
        Lk.first=k;
    }

}
void PaperKeyword(p_pointer P,k_pointer &K){
    r_pointer R,temp;
    R = new Relation;
    R->next=NULL;
    R->paper=P;

    if(K->relasi==NULL){
        K->relasi=R;
    }else{
        temp=K->relasi;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=R;
    }
}

void deletePaper(p_pointer &P,paperList &Lp,keywordList Lk){
    k_pointer K;
    r_pointer R,Rk;
    K=Lk.first;

    while(K!=NULL){
        R=K->relasi;
        while(R!=NULL&&R->next->paper!=P){
            R=R->next;
        }
        if(R!=NULL){
            if(R!=K->relasi){
                R->next=Rk;
                R->next=Rk->next;
                Rk->next=NULL;
            }else{
                K->relasi=R->next;
                R->next=NULL;
            }
        }
        K=K->next;
    }

    if(P==Lp.first&&P==Lp.first){
        buatPaperList(Lp);
    }else if(P==Lp.first){
        Lp.first=P->next;
        P->next=NULL;
    }else if(P==Lp.last){
        Lp.last=P->prev;
        P->prev=NULL;
    }else{
        P->next->prev=P->prev;
        P->prev->next=P->next;
        P->next=NULL;
        P->prev=NULL;
    }
}
void deleteKeyword(k_pointer &K,keywordList &Lk){
    if(K==Lk.first&&K==Lk.last){
        buatKeywordList(Lk);
    }else if(K==Lk.first){
        Lk.first=K->next;
        K->next=NULL;
    }else if(K==Lk.last){
        Lk.last=K->prev;
        K->prev=NULL;
    }else{
        K->next->prev=K->prev;
        K->prev->next=K->next;
        K->next=NULL;
        K->prev=NULL;
    }
}

p_pointer cariPaper (string judul,paperList &Lp){
    p_pointer P;
    P=Lp.first;
    while(P!=NULL&&P->judul!=judul){
        P=P->next;
    }
    return P;
}
k_pointer cariKeyword (string key,keywordList &Lk){
    k_pointer k;
    k=Lk.first;
    while(k!=NULL&&k->key!=key){
        k=k->next;
    }
    return k;
}

void lihatKeywordAndPaper(k_pointer K){
    r_pointer R;
    cout << "Keyword " << K->key << endl;
    R=K->relasi;
    while(R!=NULL){
        cout << "-> " << R->paper->judul << endl;
        R=R->next;
    }
    cout << endl;
}
void lihatPaperAndKey(p_pointer P,keywordList Lk){
    r_pointer R;
    k_pointer K;

    cout << "judul Paper : " << P->judul << endl;
    cout << "Keyword : ";
    K=Lk.first;
    while(K!=NULL){
        R=K->relasi;
        while(R!=NULL){
            if(R->paper==P){
                cout << K->key << " ";
            }
            R=R->next;
        }
        K=K->next;
    }
    cout << endl;
}
void popularKeywordPaper(keywordList Lk){
    k_pointer K,outK;
    r_pointer R;
    int i;
    int maxPaper,maxKey;
    maxPaper=0;
    maxKey=0;
    outK=NULL;
    K=Lk.first;
    while(K!=NULL){
        i=0;
        R=K->relasi;
        while(R!=NULL){
            i=i+1;
            R=R->next;
        }
        if(i>maxKey){
            maxKey=i;
            outK=K;
        }
        K=K->next;
    }
    cout << "Keyword yang populer adalah " << outK->key << endl;
    lihatKeywordAndPaper(outK);
}
