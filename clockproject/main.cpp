#include "clock.h"
int main()
{
    Clock c1 = MakeClock(2,30,4);
    cout << c1.HH << endl;
    cout << GetHour(c1) << endl;
    SetHour(c1,4);
    cout << c1.HH << endl;
    cout << GetHour(c1) << endl;
    return 0;
}
