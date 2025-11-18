#include <stdio.h>
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    // 6, 5, 4, 3, 2, 1 순서로 출력 하지만 배열의 앞과 뒤를 가리키는 포인터 변수 두개를 사용해서 저장된 값의 순서를 바꾸기
    // 6 5 4 3 2 1 출력        

    int *ptr1 = arr;
    int *ptr2 = arr + 5;

    // 두 변수 사용해서 6, 5, 4, 3, 2, 1
    for(int i = 0; i < 3; i++)
    {
        int temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1++;
        ptr2--;
    }
    // 꺼꾸로 출력
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}