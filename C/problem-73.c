#include <stdio.h>
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    // 포인터 변수 ptr 저장된 값을 변경 시키지 않고 ptr을 대상으로 덧셈 연산을 해 그 결과로 반환되는 주소 값을 통해서 모든 배열요소에 접근하여 값을 2씩 증가시키기
    int *ptr = arr;

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", *ptr + 2);
        ptr++;
    }

    
    return 0;
}
