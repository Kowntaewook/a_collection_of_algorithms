/* 
시간 제한 1초
입력조건 : 첫째 즐에 수열에 속헤 있는 수의 개수 N이 주어진다. (1 <= N <= 500)
둘째 줄부터 N + 1 번째 줄까지 N개의 수가 입력된다. 수의 범위는 1 이상 100,000 이하이다.
출력 조건 입력으로 주어진 수열이 내림차순으로 정렬된 결과를 공백으로 구분하여 출력한다. 동일한 수의 순서는 자유롭게 출력해도 괜찮다.
입력 예시
3
15
27
12
출력 예시
27 15 12
*/

#include <stdio.h>
#include <stdlib.h>

// 정렬용 함수

void sort(int *arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++) //  버블 정렬 사용
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i]; 
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[500] = {0};
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
