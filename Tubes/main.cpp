#include <iostream>
#include "programmer.h"
#include "project.h"
#include "penugasan.h"
#include "menu.h"

using namespace std;

int main()
{
    list_programmer L1;
    list_project L2;
    list_penugasan L;

    createListPenugasan(L);
    createListProgram(L1);
    createListProject(L2);

    menu(L1,L2,L);

    return 0;
}
