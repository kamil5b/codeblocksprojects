#include "header.h"

int main()
{
    ListPasien Lpas;
    ListPenyakit Lpen;

    buatListPasien(Lpas);
    buatListPenyakit(Lpen);

    menu(Lpas,Lpen);
    return 0;
}
