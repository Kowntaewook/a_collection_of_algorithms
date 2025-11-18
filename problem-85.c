#include <stdio.h>
int main()
{
    int hour, min, sec;
    //scanf("%d %d %d", &hour, &min, &sec);

    int Gmin;
    scanf("%d", &Gmin);

    //6015 / 60 = 100 == 1시간 40분 == hour + 1
    //6015 % 60 = 15 ==  40 + 40 = 80 = 1시간 20분 == hour + 1 hour == 19 min == 20, sec == 45 + 15 = 60, 60 == 1 min min ++ 1 min == 41

    // 모든걸 초로 바꾸고 다시 시분초로 하기

    int sechour = Gmin / 3600;
    int restsec = Gmin % 3600;
    int secmin = restsec / 60;
    int secsec = restsec % 60;

    //printf("%d %d %d", sechour, secmin, secsec);

    int result = hour + sechour;
    int result2 = min + secmin;
    int result3 = sec + secsec;

    if(result2 >= 60)
    {
        int resulth = result2 / 60;
        int resth = result2 % 60;
        hour + resulth;
    }
    else if(result3 >= 60)
    {
        int resultm = result3 / 60;
        min + resultm;
    }

    return 0;
}