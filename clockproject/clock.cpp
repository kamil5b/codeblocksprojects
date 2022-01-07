#include "clock.h"

bool IsValid(int HH, int MM, int SS){
    if(HH < 0 || HH > 23){
        return false;
    }
    if(MM < 0 || MM > 59){
        return false;
    }

    if(SS < 0 || SS > 59){
        return false;
    }
    return true;
}

Clock MakeClock(int HH,int MM,int SS){
    Clock c;
    if(IsValid(HH,MM,SS)){
        c.HH=HH;
        c.MM=MM;
        c.SS=SS;
    }
    return c;
}

//SELECTOR
Hour GetHour(Clock c){
    return c.HH;
}
Minute GetMinute(Clock c){
    return c.MM;
}
Second GetSecond(Clock c){
    return c.SS;
}

//VALUE CHANGER
void SetHour(Clock &c, int newHH){
    if(newHH >= 0 && newHH <= 23){
        c.HH = newHH;
    }
}
void SetMinute(Clock &c, int newMM){
    if(newMM >= 0 && newMM <= 59){
        c.MM = newMM;
    }
}
void SetSecond(Clock &c, int newSS){
    if(newSS >= 0 && newSS <= 59){
        c.SS = newSS;
    }
}
