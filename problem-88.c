#include <stdio.h>
int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2); // 행, 열 입력

    int num[num1][num2];

    for (int i = 0; i < num1; i++)
    {
        for (int j = 0; j < num2; j++)
        {
            scanf("%d", &num[i][j]); // 2차원 배열 입력
        }
    }

    int max_of_min = -2147483648; // 매우 작은 수로 초기화 (int 최솟값)

    for (int i = 0; i < num1; i++)
    {
        int row_min = num[i][0]; // 행의 첫 번째 값으로 초기화
        for (int j = 1; j < num2; j++)
        {
            if (num[i][j] < row_min)
            {
                row_min = num[i][j]; // 행에서 최소값 찾기
            }
        }

        if (row_min > max_of_min)
        {
            max_of_min = row_min; // 가장 큰 최소값 업데이트
        }
    }

    printf("%d\n", max_of_min); // 결과 출력

    return 0;
}
