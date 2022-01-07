#include "penugasan.h"
using namespace std;

void createListPenugasan (list_penugasan &L){
    L.first=NULL;
    L.last=NULL;
}
address_penugasan createElmPenugasan (address_programmer prog,address_project proj,string status, string tugas){
    address_penugasan P;
    P=new elmlist_penugasan;
    status(P)=status;
    tugas(P)=tugas;
    prog(P)=prog;
    proj(P)=proj;
    next(P)=NULL;
}
void insertFirstPenugasan (list_penugasan &L, address_penugasan &P) //CONNECT
{
    if(L.first==NULL){
        L.first=P;
        L.last=P;
    }else{
        next(P)=L.first;
        L.first=P;
    }
}
void deletePenugasan (list_penugasan &L, address_penugasan &P) //DISCONNECT
{
    address_penugasan Q=L.first;
    if(P==L.first&&P==L.last){
        createListPenugasan(L);
    }else{
        while(Q!=NULL&&next(Q)!=P){
            Q=next(Q);
        }
        if(P==L.last){
            L.last=Q;
        }
        next(Q)=next(P);
        next(P)=NULL;
    }
}
void deletePenugasanProgrammer(list_penugasan &L, address_programmer P){
    address_penugasan R=L.first;
    address_penugasan Rtemp;
    while(R!=NULL){
        if(prog(R)==P){
            Rtemp=next(R);
            deletePenugasan(L,R);
            delete R;
            R=Rtemp;
        }else{
            R=next(R);
        }
    }
}
void deletePenugasanProject(list_penugasan &L, address_project P){
    address_penugasan R=L.first;
    address_penugasan Rtemp;
    while(R!=NULL){
        if(proj(R)==P){
            Rtemp=next(R);
            deletePenugasan(L,R);
            delete R;
            R=Rtemp;
        }else{
            R=next(R);
        }
    }
}
address_penugasan searchPenugasan (list_penugasan L, address_programmer prog,address_project proj){
    address_penugasan P;
    P=L.first;
    while(P!=NULL&&(prog(P)!=prog||proj(P)!=proj)){
        P=next(P);
    }
    return P;
}

void ubahStatus(list_penugasan &L, address_penugasan &P){
    string status;
    cout << info(prog(P)) << " sebagai " << tugas(P) << " dengan status " << status(P) << " dalam project " << info(proj(P)) << endl;
    cout << "Ubah status menjadi : ";
    cin >> status;
    status(P)=status;
    cout << "Berhasil merubah status menjadi " << status << endl;
}
void alihTugas(list_penugasan &L, address_penugasan &P){
    string tugas;
    cout << info(prog(P)) << " sebagai " << tugas(P) << " dengan status " << status(P) << " dalam project " << info(proj(P)) << endl;
    cout << "Ubah tugas menjadi : ";
    cin >> tugas;
    tugas(P)=tugas;
    cout << "Berhasil merubah status tugas " << tugas << endl;
}

void viewProjectsProgrammer(address_project P, list_penugasan L){
    address_penugasan R=L.first;
    cout << "Nama project : " << info(P) <<endl;
    cout << "Programmer dalam project ini : " << endl;
    int i=1;
    while(R!=NULL){
        if(proj(R)==P){
            cout << i << ". "<< info(prog(R)) << " sebagai " << tugas(R) << " dengan status " << status(R) << endl;
            i++;
        }
        R=next(R);
    }
}
void viewProgrammersProject(address_programmer P,list_penugasan L){
    address_penugasan R=L.first;
    cout << "Nama Programmer : " << info(P) <<endl;
    cout << "Project yang sedang dikerjakan : " << endl;
    int i=1;
    while(R!=NULL){
        if(prog(R)==P){
            cout << i << ". "<< info(proj(R)) << " sebagai " << tugas(R) << " dengan status " << status(R) << endl;
            i++;
        }
        R=next(R);
    }
}
void viewAllProjectandProgrammer (list_project Lpro,list_penugasan Lpen){
    address_project P=Lpro.first;
    address_penugasan R;
    int i;
    if(P!=NULL){
        do{
            cout << "Nama Project : " << info(P) << endl;
            R=Lpen.first;
            i=0;
            while(R!=NULL){
                i++;
                R=next(R);
            }
            cout << "Total Programmer : " << i <<endl;
            P=next(P);
        }while(P!=Lpro.first);
    }else{
        cout << "List kosong" << endl;
    }
}
void viewAllProgrammerandProject (list_programmer Lpro,list_penugasan Lpen){
    address_programmer P=Lpro.first;
    address_penugasan R;
    int i;
    if(P!=NULL){
        do{
            cout << "Nama Programmer : " << info(P) << endl;
            R=Lpen.first;
            i=0;
            while(R!=NULL){
                i++;
                R=next(R);
            }
            cout << "Total Project : " << i <<endl;
            P=next(P);
        }while(P!=Lpro.first);
    }else{
        cout << "List kosong" << endl;
    }
}


