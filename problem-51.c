#include <stdio.h>
int main()
{
    int num1,num2;
    scanf("%d %d", &num1, &num2);
    int result = 0;
    int result2=0;

    for(int i = 0; i < num1; i++)
    {
        
        if(num1 % i ==0 && num2 % i == 0) // 최대 공약 
        {
            result = i;
            result2 = num1 * num2 / result;
        }
    }
    printf("%d\n", result);
    printf("%d", result2);

    return 0;
}