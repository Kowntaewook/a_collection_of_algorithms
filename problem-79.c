//회문 구분하기 대소문자까지 일치해야함
// 주소 지정으로 하기?
// ptr?
#include <stdio.h>
#include <string.h>

void Palindrome(char *str)
{
    int len = strlen(str);
    int i, j;
    int flag = 1;
    for(i = 0, j = len - 1; i < j; i++, j--)
    {
        if(str[i] != str[j])
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
    {
        printf("회문입니다.");
    }
    else
    {
        printf("회문이 아닙니다.");
    }
}

int main()
{
    char str[100];
    printf("문자열 입력: ");
    scanf("%s", str);
    Palindrome(str);
    return 0;
}
