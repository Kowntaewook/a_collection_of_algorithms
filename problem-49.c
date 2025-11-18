#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int count = 0;
    int count2 = 0;

    scanf("%s", str);  // cC == CC C 와 CC는 대소문자 구별 하지 않는다.

    // C는 2가지 경우 CC는 4가지 경우 존재 가능
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == 'C'|| str[i] == 'c')
        {
            count++;
            if(str[i+1] == 'C' || str[i+1] == 'c')
            {
                count2++;
            }
        }

    }
    printf("%d\n", count);
    printf("%d", count2);

    return 0;
}