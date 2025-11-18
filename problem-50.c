#include <stdio.h>
int main()
{
    float s, e;
    float total_hours = 0;  // 16시 30분은 16.5
    int total_pay = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%f %f", &s, &e);
        float overtime = e - s - 1.0; // 최초 1시간 제외
        if (overtime < 0) overtime = 0;
        if (overtime > 4) overtime = 4;
        total_hours += overtime;
        total_pay += (int)(overtime * 2) * 5000; // 30분 단위 = 0.5시간
    }

    if (total_hours >= 15) 
    {
        total_pay *= 0.95;
    }
    else if(total_hours <= 5)
    {
        total_pay *= 1.05;
    }
    printf("%d\n", total_pay);
    
    return 0;
}