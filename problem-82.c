//문제 설명
//두 정수 A, B를 입력받고 A부터 B까지의 곱을 구하라.
//입력 설명
//두 정수 A, B를 공백으로 구분하여 입력 받아라.
//출력 설명
//A부터 B까지의 모든 수를 곱한 결과를 출력하여라.
//입력 예시 Copy
//2 5
//출력 예시 Copy
//120

#include <stdio.h>
int main()
{
    int n;
    int m;
    scanf("%d %d", &n, &m);

    int result = 1;

    for(int i = n; i <= m; i++)
    {
        result *= i;
    }
    printf("%d\n", result);
    return 0;
}