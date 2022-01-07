#include "grup_user_header.h"

void createUser(listUser &Lu){
    Lu.first=NULL;
    Lu.last=NULL;
}
void createGroup(listGroup &Lg){
    Lg.first=NULL;
    Lg.last=NULL;
}

void newUser(string nama,listUser &Lu){
    user_pointer U;
    U = new User;

    U->nama=nama;
    U->grup=0;
    U->next=NULL;
    U->prev=NULL;
    U->r=NULL;

    if(Lu.last==NULL){
        Lu.last=U;
        Lu.first=U;
    }else{
        Lu.last->next=U;
        U->prev=Lu.last;
        Lu.last=U;
    }

}
void newGroup(string nama, listGroup &Lg){
    group_pointer G;
    G = new Group;

    G->nama=nama;
    G->member=0;
    G->next=G;
    G->prev=G;

    if(Lg.last==NULL){
        Lg.last=G;
        Lg.first=G;
    }else{
        G->prev=Lg.last;
        G->next=Lg.first;
        Lg.last->next=G;
        Lg.first->prev=G;
        Lg.last=G;
    }

}

void joinGroup(user_pointer &U,group_pointer &G){
    r_pointer R,Ru;
    R = new relation;

    R->next=NULL;
    R->grup=G;

    Ru=U->r;
    if(Ru==NULL){
        U->r=R;
    }else{
        while(Ru->next==NULL){
            Ru=Ru->next;
        }
        Ru->next=R;
    }
    U->grup=U->grup + 1;
    G->member = G->member + 1;
}

void deleteGroup(group_pointer &G,listGroup &Lg,listUser &Lu){
    user_pointer U;
    r_pointer R,temp;

    if(G!=NULL){
         G->prev->next=G->next;
         G->next->prev=G->prev;
        if(G==Lg.first&&Lg.last==G){
            Lg.first = NULL;
            Lg.last=NULL;
        }else if(G==Lg.first){
            Lg.first=G->next;
            Lg.first->prev=Lg.last;
            Lg.last->next=Lg.first;
            G->next=G;
            G->prev=G;
        }else if(G==Lg.last){
            Lg.last=G->prev;
            Lg.first->prev=Lg.last;
            Lg.last->next=Lg.first;
            G->next=G;
            G->prev=G;
        }else{
            G->next=G;
            G->prev=G;
        }
        U=Lu.first;
        while(U!=NULL){
            R=U->r;
            while(R!=NULL){
                if(R->grup==G){
                    if(R==U->r){
                        U->r=R->next;
                        R->next=NULL;
                    }else{
                        temp=U->r;
                        while(temp->next!=R && temp!=NULL){
                            temp=temp->next;
                        }
                        temp->next=R->next;
                        R->next=NULL;
                    }
                }
                R=R->next;
            }
            U=U->next;
        }
    }
}
void deleteUser(user_pointer &U,listUser &Lu){
    if(U!=NULL){
        if(U==Lu.first){
            Lu.first=U->next;
            Lu.first->prev=NULL;
            U->next=NULL;
        }else if(U==Lu.last){
            Lu.last=U->prev;
            Lu.last->next=NULL;
            U->prev=NULL;
        }else{
            U->prev->next=U->next;
            U->next->prev=U->prev;
            U->next=NULL;
            U->prev=NULL;
        }
    }
}

group_pointer popularGroup(listGroup Lg){
    group_pointer G,out;
    int Max=0;
    out=NULL;
    G=Lg.first;
    if(G!=NULL){
        do{
            if(G->member > Max){
                Max=G->member;
                out=G;
            }
            G=G->next;
        }while(G!=Lg.first);
    }
    return out;
}

user_pointer searchUser(string nama, listUser Lu){
    user_pointer U;
    U=Lu.first;
    while(U!=NULL&&U->nama!=nama){
        U=U->next;
    }
    return U;
}
group_pointer searchGroup(string nama, listGroup Lg){
    group_pointer G;
    G=Lg.first;

    if(G!=NULL){
        do{
            if(G->nama!=nama){
                return G;
            }
            G=G->next;
        }while(G!=Lg.first);
    }
    return NULL;
}

void showGroupMember(group_pointer G,listUser Lu){
    user_pointer U;
    r_pointer R;

    cout << "Member group of " << G->nama <<endl;
    U=Lu.first;
    while(U!=NULL){
        R=U->r;
        while(R!=NULL){
            if(R->grup==G){
                cout << "-> " << U->nama << endl;
            }
            R=R->next;
        }

        U=U->next;
    }
}
void showUserGroup(user_pointer U){
    r_pointer R;
    R=U->r;
    cout << U->nama << " is joining " << U->grup << " group";
    if(U->grup > 1){
        cout << "s";
    }
    cout << endl;
    while(R!=NULL){
        cout << "-> " << R->grup->nama << endl;
        R=R->next;
    }
}
void showMinimal3Group(listUser L){
    user_pointer U;
    U=L.first;
    while(U!=NULL){
        if(U->grup >= 3){
            cout << "-> " << U->nama << endl;
        }
        U=U->next;
    }
}
