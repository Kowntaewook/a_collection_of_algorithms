//문제 설명
//1부터 N까지의 홀수만 더하여 합을 출력하세요.
//입력 설명
//정수 N을 입력하시오.(1<=N<=1000)
//출력 설명
//1부터 N까지의 수 중 홀수만을 더하여 합을 출력하시오.
//입력 예시 Copy
//7
//출력 예시 Copy
//16

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;

    for(int i = 1; i <= n; i++)
    {
        if(i % 2 != 0)
        {
            sum += i;
        }
    }
    printf("%d\n", sum);
    return 0;
}