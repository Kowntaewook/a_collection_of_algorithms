// 변수 num에 저장된 값의 제곱을 계산하는 함수를 정의 하고 이를 호출하는 main 함수를 작성
// Call-by-value 기반의 SquareBYValue
// Call-by-reference 기반의 SquareByReference
// SquareByValue는 함수의 인자로 전달된 값의 제곱을 반환
// Reference는 정수가 저장되어 있는 변수의 주소값을 인자로 받아서 해당 변수에 저장된 값의 제곱을 그 변수에 다시 저장
#include <stdio.h>
void SqareByValue(int num) // 함수 기능 : num의 제곱 계산
{
    num = num * num; // num의 제곱 계산
    printf("num: %d \n", num);
}

void SquareByReference(int * num)
{
    *num = *num * *num; // num의 제곱 계산
    printf("num: %d \n", *num);
}

int main()
{
    int num = 10;
    printf("num : %d \n", num);
    SqareByValue(num); // num의 제곱을 계산
    printf("num : %d \n", num);
    SquareByReference(&num); // num의 제곱을 계산
    printf("num : %d \n", num);
    return 0;
}