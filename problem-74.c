#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    // 배열의 마지막을 가리키는 포인터 변수
    int *ptr = arr + 5;
    // 변수 ptr에 저장된 값을 감소시키는 형태의 연산을 기반으로 모든 배열요소에 접근 배열에 저장된 모든 정수를 더하여 그 결과를 출력
    for(int i = 0; i < 5; i++)
    {
        ptr--;
        printf("%d ", *ptr); 
    }
    return 0;
}