#include <stdio.h>
#include <string.h>
int main(){
    char str[15];
    scanf("%s", str);

    // if(str[0] == 'l' && str[1] == 'o' && str[2] == 'v' && str[3] == 'e')
    // {
    //     printf("I love you.");
    // }
    if(strcmp(str, "love") == 0)
    {
        printf("I love you.");
    }
    
    return 0;
}
