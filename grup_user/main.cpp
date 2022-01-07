#include "grup_user_header.h"

int main(){

    listGroup global_group;
    listUser global_user;

    createGroup(global_group);
    createUser(global_user);

    menu(global_user,global_group);

    return 0;
}
