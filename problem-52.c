#include <stdio.h>
#include <string.h>

int main()
{
    struct employee
    {
        char ID[20];
        int PAY;
    };
    struct employee a;

    
    printf("주민 등록 번호 입력: ", stdout);
    scanf("%s", a.ID);
    
    printf("급여 정보 입력: ", stdout);
    scanf("%d", &a.PAY);

    printf("주민 등록 번호: %s\n", a.ID);
    printf("급여 정보: %d\n", a.PAY);
    
}