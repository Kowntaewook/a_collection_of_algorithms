/*문제 설명
다음과 같은 n*n 배열 구조를 출력해보자.

입력이 3인 경우 다음과 같이 출력한다.
1 2 3
4 5 6
7 8 9

입력이 5인 경우는 다음과 같이 출력한다.
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

입력이 n인 경우의 2차원 배열을 출력해보자.

입력 설명
첫 번째 줄에 배열의 크기 n이 입력된다.
(1<=n<=100) 

출력 설명
n*n 크기의 배열을 설명과 같이 채워 출력한다.

입력 예시 Copy
4
출력 예시 Copy
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16*/

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n][n];
    int num = 1;

    for(int i = 0; i < n; i++)
    {
        for(int i = 0; i < n; i++)
        {
            arr[i][i] = num++;
        }
        for(int i = 0; i < n; i++)
        {
            printf("%d", arr[i][i]);
            if(i < n - 1)
            {
                printf(" ");
                
            }
            else
            {
                printf("\n");
            }
        }
    }
    return 0;
}