#include <iostream>
#include "header.h"

using namespace std;

int main(){
    lecturerList Ll;
    studentList Ls;
    createList(Ll,Ls);
    fixedLecturerList(Ll);
    fixedStudentList(Ls);
    fixedRelation(Ls,Ll);
    menu(Ll,Ls);
}
