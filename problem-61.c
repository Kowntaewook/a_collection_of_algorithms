#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d", &a, &b);
    scanf("%d", &c);
    int d=0, e=0;
    int result = 0, result2 = 0, result3 = 0, result4 = 0;

    //첫 줄은 각각의 침대에 있는 쓰레기 수 입력,
    //둘째 줄은 며칠 밤을 옮겼는지 입력,
    //나머지 줄은 입력된 날만큼  누가 쓰레기를 얼마나 옮겼는지를 입력한다.
    //(단, 하루에 한 명만 옮길 수 있으며, 유찬이가 옮기면 1, 승보가 옮기면 2 이다.)


    for(int i = 0; i < c; i++)
    {
        scanf("%d %d", &d, &e);

        if(d == 1)
        {
            result += e;
        }
        else if(d == 2)
        {
            result2 += e;
        }

    }
    
    result3 += a-(result-result2);
    result4 += b-(result2-result);

    printf("%d\n%d", result3, result4);

    return 0;
}