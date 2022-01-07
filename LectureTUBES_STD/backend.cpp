#include "header.h"


void createList(lecturerList &Ll,studentList &Ls){
    Ll.first=NULL;
    Ll.last=NULL;

    Ls.first=NULL;
}
address_l createLecturer(string nama,string kode){
    address_l P;
    P = new Lecturer;
    P->nama=nama;
    P->kode=kode;
    P->next=NULL;
    P->prev=NULL;
    P->supervised=0;
    P->student=NULL;
    return P;
}
address_s createStudent(string nama,string id){
    address_s P;
    P = new Student;
    P->nama=nama;
    P->ID=id;
    P->next=NULL;
    P->supervised=0;
    return P;
}
address_r createRelation(address_s S){
    address_r P;
    P = new Relation;
    P->next=NULL;
    P->student=S;
    return P;
}

void addLecturer(lecturerList &L,address_l P){
    if(L.last==NULL){
        L.last=P;
        L.first=P;
    }else{
        L.last->next=P;
        P->prev=L.last;
        L.last=P;
    }
}
void addStudent(studentList &L,address_s P){
    if(L.first==NULL){
        L.first=P;
    }else{
        P->next=L.first;
        L.first=P;
    }
}
void addRelation(address_l &L,address_r &P){
    if(L->student==NULL){
        L->student=P;
    }else{
        P->next=L->student;
        L->student=P;
    }
    L->supervised++;
    P->student->supervised++;
}

address_l searchLecturer(lecturerList &L,string kode){
    address_l P;
    P=L.first;
    while(P!=NULL&&P->kode!=kode&&P->nama!=kode){
        P=P->next;
    }
    return P;
}
address_s searchStudent(studentList &L,string ID){
    address_s P;
    P=L.first;
    while(P!=NULL&&P->ID!=ID&&P->nama!=ID){
        P=P->next;
    }
    return P;
}


void deleteRelation(address_l &L, address_r &P){
    if(L->student!=NULL){
        if(P!=NULL){
            if(P==L->student){
                L->student=P->next;
                P->next=NULL;
            }else{
                address_r Q=L->student;
                while(Q->next!=P&&Q!=NULL){
                    Q=Q->next;
                }
                if(Q!=NULL){
                    Q->next=P->next;
                    P->next=NULL;
                }
            }
            delete P;
            P=NULL;
        }
    }
}

void deleteLecturer(lecturerList &L,address_l &P,studentList Ls){
    if(L.first!=NULL){
        if(P!=NULL){
            address_l Q;
            if(P==L.first&&P==L.last){
                L.first=NULL;
                L.last=NULL;
            }else if(P==L.first){
                L.first=P->next;
                L.first->prev=NULL;
                P->next=NULL;
            }else if(P==L.last){
                L.last=P->prev;
                L.last->next=NULL;
                P->prev=NULL;
            }else{
                Q=L.first;
                while(Q->next!=P&&Q!=NULL){
                    Q=Q->next;
                }
                if(Q!=NULL){
                    Q->next=P->next;
                    P->next->prev=Q;
                    P->next=NULL;
                    P->prev=NULL;
                }
            }
            address_r R=P->student;
            address_r Rtemp;
            while(R!=NULL){
                Rtemp=R->next;
                R->student->supervised--;
                deleteRelation(P,R);
                R=Rtemp;
            }

            delete P;
            P=NULL;
        }
    }
}

void deleteStudent(studentList &L,address_s &P,lecturerList Ll){
    if(L.first!=NULL){
        if(P!=NULL){
            if(P==L.first){
                L.first=P->next;
                P->next=NULL;
            }else{
                address_s Q=L.first;
                while(Q->next!=P&&Q!=NULL){
                    Q=Q->next;
                }
                if(Q!=NULL){
                    Q->next=P->next;
                    P->next=NULL;
                }
            }
            if(Ll.first!=NULL){
                address_l temp=Ll.first;
                address_r R,Rtemp;
                while(temp!=NULL){
                    R=temp->student;
                    while(R!=NULL){
                        if(R->student==P){
                            Rtemp=R->next;
                            temp->supervised--;
                            deleteRelation(temp,R);
                            R=Rtemp;
                        }
                        R=R->next;
                    }
                    temp=temp->next;
                }
            }

            delete P;
            P=NULL;
        }
    }
}

void showStudentsLecturer(address_s S,lecturerList L){
    if(S!=NULL){
        showStudentInfo(S);
        address_l Lec=L.first;
        address_r R;
        while(Lec!=NULL){
            R=Lec->student;
            while(R!=NULL){
                if(R->student==S){
                    showLecturerInfo(Lec);
                }
                R=R->next;
            }
            Lec=Lec->next;
        }
    }
}
void showLecturersStudent(address_l L){
    if(L!=NULL){
        showLecturerInfo(L);
        address_r R=L->student;
        while(R!=NULL){
            showStudentInfo(R->student);
            R=R->next;
        }
    }
}

void showLecturerInfo(address_l L){
    if(L!=NULL){
        cout << "Nama dosen\t: " << L->nama << endl;
        cout << "Kode dosen\t: " << L->kode << endl;
        cout << "Mengawasi " << L->supervised << " Mahasiswa" << endl;
    }
}
void showStudentInfo(address_s S){
    if(S!=NULL){
        cout << "Nama Mahasiswa : " << S->nama << endl;
        cout << "ID Mahasiswa   : " << S->ID << endl;
        cout << "Diawasi " << S->supervised << " Dosen" << endl;
    }
}

int minStudentsLecturer(studentList L){
    int minValue;
    address_s P=L.first;
    minValue=P->supervised;

    while(P!=NULL){
        if(P->supervised<minValue){
            minValue=P->supervised;
        }
        P=P->next;
    }
    return minValue;
}
int maxStudentsLecturer(studentList L){
    int maxValue;
    address_s P=L.first;
    maxValue=P->supervised;

    while(P!=NULL){
        if(P->supervised>maxValue){
            maxValue=P->supervised;
        }
        P=P->next;
    }
    return maxValue;
}
int minLecturersStudent(lecturerList L){
    int minValue;
    address_l P=L.first;
    minValue=P->supervised;

    while(P!=NULL){
        if(P->supervised<minValue){
            minValue=P->supervised;
        }
        P=P->next;
    }
    return minValue;
}
int maxLecturersStudent(lecturerList L){
    int maxValue;
    address_l P=L.first;
    maxValue=P->supervised;

    while(P!=NULL){
        if(P->supervised>maxValue){
            maxValue=P->supervised;
        }
        P=P->next;
    }
    return maxValue;
}
