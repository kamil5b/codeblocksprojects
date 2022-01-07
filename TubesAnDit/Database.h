#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include "kampus.h"
#include "fakultas.h"
#include "relasi.h"

using namespace std;

void insertKampus (List1 &LP);
void deleteKampus (List1 &LP, List_R &LR);
void viewKampus (List1 LP);
void updateKampus (List1 &L);
void insertFakultas (List2 &LB);
void updateFakultas (List2 &LB);
void viewFakultas (List2 LB);
void insertRelasi (List1 LP, List2 LB, List_R &LR);
void header();
void headerInsert();
void headerInsertKampus();
void headerInsertFakultas();
void headerInsertRelasi();
void headerUpdate();
void headerView();
void headerDelete();
void menus();
void menuInsert();
void menuUpdate();
void menuView();
void menuDelete();
void deleteFakultas (List2 &LF, List_R &LR);

#endif // DATABASE_H_INCLUDED
