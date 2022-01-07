#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <cctype>
#include <string>
#include <locale>
#include <fstream>
#include <stdlib.h>


using namespace std;

typedef struct Lecturer *address_l;
typedef struct Relation *address_r;
typedef struct Student *address_s;

//LECTURER PARENT
struct Lecturer {
    string kode;
    string nama;
    address_l next;
    address_r student;
    int supervised;
    address_l prev;
};

struct Relation {
    address_s student;
    address_r next;
};

struct Student {
    string nama;
    string ID;
    int supervised;
    address_s next;
};

struct lecturerList{
    address_l first;
    address_l last;
};

struct studentList{
    address_s first;
};

void createList(lecturerList &Ll,studentList &Ls);
address_l createLecturer(string nama,string kode);
address_s createStudent(string nama,string id);
address_r createRelation(address_s S);

void addLecturer(lecturerList &L,address_l P);
void addStudent(studentList &L,address_s P);
void addRelation(address_l &L,address_r &P);

address_l searchLecturer(lecturerList &L,string kode);
address_s searchStudent(studentList &L,string ID);

void deleteRelation(address_l &L, address_r &P);
void deleteStudent(studentList &L,address_s &P,lecturerList Ll);
void deleteLecturer(lecturerList &L,address_l &P,studentList Ls);

void showStudentsLecturer(address_s S,lecturerList L);
void showLecturersStudent(address_l L);

void showLecturerInfo(address_l L);
void showStudentInfo(address_s S);

int minStudentsLecturer(studentList L);
int maxStudentsLecturer(studentList L);
int minLecturersStudent(lecturerList L);
int maxLecturersStudent(lecturerList L);

//Misc
void fixedLecturerList(lecturerList &L);
void fixedStudentList(studentList &Ls);
void fixedRelation(studentList &Ls,lecturerList &Ll);

void printFileLecturer(lecturerList L);
void printFileStudent(studentList L);
void printFileRelation(lecturerList L);

//MENU
void menu(lecturerList &Ll,studentList &Ls);
void menu1(lecturerList &Ll,studentList &Ls);
void menu2(lecturerList &Ll,studentList &Ls);
void menu3(lecturerList &Ll,studentList &Ls);
void menu4(lecturerList &Ll,studentList &Ls);
void menu5(lecturerList &Ll,studentList &Ls);
void menu6(lecturerList &Ll,studentList &Ls);
void menu7(lecturerList &Ll,studentList &Ls);
void menu8(lecturerList &Ll,studentList &Ls);
void menu9(lecturerList &Ll,studentList &Ls);
void exit(lecturerList &Ll,studentList &Ls);


#endif // HEADER_H_INCLUDED
