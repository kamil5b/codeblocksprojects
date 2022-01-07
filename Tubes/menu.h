#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "penugasan.h"
#include "programmer.h"
#include "project.h"

using namespace std;

void menu(list_programmer &L1, list_project &L2, list_penugasan &L);
void loginadmin(list_programmer &L1, list_project &L2, list_penugasan &L);
void loginmanager(list_programmer &L1, list_project &L2, list_penugasan &L);
void loginprogramer(list_programmer &L1, list_project &L2, list_penugasan &L);



#endif // MENU_H_INCLUDED
