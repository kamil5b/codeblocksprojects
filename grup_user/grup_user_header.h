#ifndef GRUP_USER_HEADER_H_INCLUDED
#define GRUP_USER_HEADER_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct User *user_pointer;
typedef struct Group *group_pointer;
typedef struct relation *r_pointer;

struct User {
    user_pointer next;
    int grup;
    string nama;
    r_pointer r;
    user_pointer prev;
};

struct Group{
    string nama;
    int member;
    group_pointer next;
    group_pointer prev;
};

struct relation{
    r_pointer next;
    group_pointer grup;
};

struct listUser{
    user_pointer first;
    user_pointer last;
};

struct listGroup {
    //CDLL
    group_pointer first;
    group_pointer last;
};

void createUser(listUser &Lu);
void createGroup(listGroup &Lg);

void newUser(string nama,listUser &Lu); //insert last
void newGroup(string nama, listGroup &Lg); //insert last

void joinGroup(user_pointer &U,group_pointer &G);

void deleteGroup(group_pointer &G,listGroup &Lg,listUser &Lu);
void deleteUser(user_pointer &U,listUser &Lu);

group_pointer popularGroup(listGroup Lg);

user_pointer searchUser(string nama, listUser Lu);
group_pointer searchGroup(string nama, listGroup Lg);

void showGroupMember(group_pointer G,listUser Lu);
void showUserGroup(user_pointer U);
void showMinimal3Group(listUser L);

void menu(listUser &Lu, listGroup &Lg);

#endif // GRUP_USER_HEADER_H_INCLUDED
