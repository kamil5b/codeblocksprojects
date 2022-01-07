#include "TUBESDWIJLAL.h"
int main()
{
    ListKeyword L1;
    ListArticle L;
    address_article P;
    address_keyword Q;
    createList(L);
    createListKeyword(L1);
    createArticle(P, "horror story", "mr x" , "Raditya Dika Production", 2011, "tentang rumah nenek");
    mainmenu(L,L1);
    return 0;
}
