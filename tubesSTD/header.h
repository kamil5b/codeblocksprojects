#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/* RAFLY AHMAD YANUAR - 1301194119
   SURYA TIMUR RIZKILLAH ARYATI - 1301194441

*/

#include <iomanip>
#include <conio.h>
#include "PARENT.h"
#include "CHILD.h"
#include "RELASI.h"
#include <cstdlib>

void MENU();

void insert_parent();
void insert_child();
void relasikan_PC();
void relasikan_CP();
void delete_parent();
void delete_child();
void viewAll();
void searchView_child();
void searchView_parent();
void searchView_Tipe();
void close();

#endif
