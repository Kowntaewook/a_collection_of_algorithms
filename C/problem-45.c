#include <stdio.h>
int main(){
    char str[50];
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
            printf("%c", str[i]);
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
            printf("%c", str[i]);
        }
        else
        {
            printf("%c", str[i]);
        }
    }

    return 0;
}
