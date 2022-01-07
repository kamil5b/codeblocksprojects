#include "header.h"

void fixedLecturerList(lecturerList &L){
    string nama,kode;
    address_l P;

    ifstream infile;
    infile.open("lecturer.txt");

    if (infile.fail()){
        cerr << "Error membuka file dosen" <<endl;
        exit(1);
    }

    int i=1;
    while(!infile.eof()){
        if(i%2!=0){
            getline(infile, nama);
        }else{
            getline(infile, kode);
            P=createLecturer(nama,kode);
            addLecturer(L,P);
        }
        i++;
    }
}

void fixedStudentList(studentList &Ls){
    string nama,id;
    address_s P;

    ifstream infile;
    infile.open("student.txt");

    if (infile.fail()){
        cerr << "Error membuka file Mahasiswa" <<endl;
        exit(1);
    }

    int i=1;
    while(!infile.eof()){
        if(i%2!=0){
            getline(infile, nama);
        }else{
            getline(infile, id);
            P=createStudent(nama,id);
            addStudent(Ls,P);
        }
        i++;
    }
}

void fixedRelation(studentList &Ls,lecturerList &Ll){
    string id,kode;
    address_s S;
    address_l L;
    address_r R;
    S=NULL;
    L=NULL;

    ifstream infile;
    infile.open("relation.txt");

    if (infile.fail()){
        cerr << "Error membuka file Relasi" <<endl;
        exit(1);
    }

    int i=1;
    while(!infile.eof()){
        if(i%2!=0){
            infile >> id;
            S=searchStudent(Ls,id);
        }else{
            infile >> kode;
            L=searchLecturer(Ll,kode);
            if(L!=NULL&&S!=NULL){
                R=createRelation(S);
                addRelation(L,R);
            }
        }
        i++;
    }
}

void printFileLecturer(lecturerList L){
    ofstream myfile;
    address_l P=L.first;


    myfile.open ("lecturer.txt");
    while(P!=NULL){
        myfile << P->nama <<"\n";
        myfile << P->kode <<"\n";
        P=P->next;
    }
    myfile.close();
}

void printFileStudent(studentList L){
    ofstream myfile;
    address_s P=L.first;


    myfile.open ("student.txt");
    while(P!=NULL){
        myfile << P->nama <<"\n";
        myfile << P->ID <<"\n";
        P=P->next;
    }
    myfile.close();
}

void printFileRelation(lecturerList L){
    address_l P;
    address_r R;
    ofstream myfile;

    P=L.first;
    myfile.open("relation.txt");
    while(P!=NULL){
        R=P->student;
        while(R!=NULL){
            myfile << R->student->ID << "\n";
            myfile << P->kode << "\n";
            R=R->next;
        }
        P=P->next;
    }

}
