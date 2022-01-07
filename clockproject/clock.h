#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED
#include <iostream>

using namespace std;

typedef int Hour;
typedef int Minute;
typedef int Second;
struct Clock{
    Hour HH;
    Minute MM;
    Second SS;
};

bool IsValid(int, int,int);
Clock MakeClock(int,int,int);

//SELECTOR
Hour GetHour(Clock);
Minute GetMinute(Clock);
Second GetSecond(Clock);

//VALUE CHANGER
void SetHour(Clock &c, int newHH);
void SetMinute(Clock &c, int newMM);
void SetSecond(Clock &c, int newSS);

#endif // CLOCK_H_INCLUDED
