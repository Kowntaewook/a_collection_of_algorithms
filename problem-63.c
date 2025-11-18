#include <stdio.h>
int main()
{
    //정수 n (1 < n < 1000) 을 입력받아, 각 자릿수 중 가장 큰 숫자를 출력합니다.
    int a;
    scanf("%d", &a);
    int max = 0;

    while(a > 0)
    {
        int b = a % 10; // a의 일의 자리 숫자
        if(b > max)
        {
            max = b; // max에 b를 대입
        }
        a /= 10; // a를 10으로 나누어 다음 자릿수로 이동
    }
    printf("%d\n", max);
    return 0;
}