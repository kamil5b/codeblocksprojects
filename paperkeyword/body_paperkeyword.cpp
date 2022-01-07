#include "header_paperkeyword.h"

void createList(listKeyword &Lk, listPaper &Lp, listRelation &Lr){
    first(Lk)=NULL;
    first(Lp)=NULL;
    first(Lr)=NULL;

    last(Lk)=NULL;
    last(Lp)=NULL;
    last(Lr)=NULL;
}

p_address createPaper(string title){
    p_address P;
    P = new paper;
    info(P)=title;
    next(P)=NULL;
    prev(P)=NULL;
}
k_address createKeyword(string key){
    k_address K;
    K = new keyword;
    info(K)=key;
    next(K)=NULL;
    prev(K)=NULL;
}
r_address createRelation(p_address &P,k_address &K){
    r_address R;
    R=new relation;
    p(R)=P;
    k(R)=K;
    next(R)=NULL;
    prev(R)=NULL;
}

void insertPaper(p_address &P, listPaper &Lp){
    if(last(Lp)==NULL){
        first(Lp)=P;
        last(Lp)=P;
    }else{
        next(P)=first(Lp);
        prev(first(Lp))=P;
        first(Lp)=P;
    }
}
void insertKeyword(k_address &K, listKeyword &Lk){
    if(last(Lk)==NULL){
        first(Lk)=K;
        last(Lk)=K;
    }else{
        next(K)=first(Lk);
        prev(first(Lk))=K;
        first(Lk)=K;
    }
}
void insertRelation(r_address &R, listRelation &Lr){
    if(last(Lr)==NULL){
        first(Lr)=R;
        last(Lr)=R;
    }else{
        next(R)=first(Lr);
        prev(first(Lr))=R;
        first(Lr)=R;
    }
}

void deletePaper(p_address &P,listPaper &Lp,listRelation &Lr){
    r_address R,Rec;
    if(P==first(Lp)&&P==last(Lp)){
        first(Lp)=NULL;
        last(Lp)=NULL;
    }else if(P==first(Lp)){
        first(Lp)=next(P);
        prev(first(Lp))=NULL;
        next(P)=NULL;
    }else if(P==last(Lp)){
        last(Lp)=prev(P);
        next(first(Lp))=NULL;
        prev(P)=NULL;
    }else{
        prev(next(P))=prev(P);
        next(prev(P))=next(P);
        next(P)=NULL;
        prev(P)=NULL;
    }

    R=first(Lr);
    while(R!=NULL){
        if(p(R)==P){
            Rec=R;
            R=next(R);
            deleteRelation(Rec,Lr);
        }else{
            R=next(R);
        }
    }
}
void deleteKeyword(k_address &K,listKeyword &Lk,listRelation &Lr){
    r_address R,Rec;
    if(K==first(Lk)&&K==last(Lk)){
        first(Lk)=NULL;
        last(Lk)=NULL;
    }else if(K==first(Lk)){
        first(Lk)=next(K);
        prev(first(Lk))=NULL;
        next(K)=NULL;
    }else if(K==last(Lk)){
        last(Lk)=prev(K);
        next(first(Lk))=NULL;
        prev(K)=NULL;
    }else{
        prev(next(K))=prev(K);
        next(prev(K))=next(K);
        next(K)=NULL;
        prev(K)=NULL;
    }

    R=first(Lr);
    while(R!=NULL){
        if(k(R)==K){
            Rec=R;
            R=next(R);
            deleteRelation(Rec,Lr);
        }else{
            R=next(R);
        }
    }
}
void deleteRelation(r_address &R,listRelation &Lr){
    if(R==first(Lr)&&R==last(Lr)){
        first(Lr)=NULL;
        last(Lr)=NULL;
    }else if(R==first(Lr)){
        first(Lr)=next(R);
        prev(first(Lr))=NULL;
        next(R)=NULL;
    }else if(R==last(Lr)){
        last(Lr)=prev(R);
        next(first(Lr))=NULL;
        prev(R)=NULL;
    }else{
        prev(next(R))=prev(R);
        next(prev(R))=next(R);
        next(R)=NULL;
        prev(R)=NULL;
    }

}

p_address searchPaper (string title,listPaper &Lp){
    p_address P;
    P=first(Lp);
    while(P!=NULL&&info(P)!=title){
        P=next(P);
    }
    return P;
}
k_address searchKeyword (string key,listKeyword &Lk){
    k_address K;
    K=first(Lk);
    while(K!=NULL&&info(K)!=key){
        K=next(K);
    }
    return K;
}

void showKeyword(k_address K,listRelation Lr){
    r_address R;
    R=first(Lr);
    cout << "Keyword : " << info(K) << endl;
    cout << "Paper : " << endl;
    while(R!=NULL){
        if(k(R)==K){
            cout << "-> " << info(p(R)) << endl;
        }
        R=next(R);
    }
}
void showPaper(p_address P,listRelation Lr){
    r_address R;
    R=first(Lr);
    cout << "Paper : " << info(P) << endl;
    cout << "Keyword : " << endl;
    while(R!=NULL){
        if(p(R)==P){
            cout << "-> " << info(k(R)) << endl;
        }
        R=next(R);
    }
}
void popularKeyword(listKeyword Lk, listRelation Lr){
    int i,popular;
    k_address K,popularK;
    r_address R;

    popularK=NULL;
    popular=0;
    K=first(Lk);
    while(K!=NULL){
        R=first(Lr);
        while(R!=NULL){
            i++;
            R=next(R);
        }
        if(popular<i){
            popular=i;
            popularK=K;
        }
        K=next(K);
    }
    cout << "The most popular keyword is " << info(popularK) << endl;
    showKeyword(popularK,Lr);
}
