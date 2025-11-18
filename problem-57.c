#include <stdio.h>
#include <string.h>

struct B
{
    char name[10];
    char born[10];
    char live[10];
};

int main()
{
    int i;
    struct B arr[3];  

    // 입력
    for(i = 0; i < 3; i++) 
    {
        scanf("%s", arr[i].name);
        scanf("%s", arr[i].born);
        scanf("%s", arr[i].live);
    }

    
    for(i = 1; i < 3; i++)
    {
        printf("%d %s %s %s\n", i, arr[i].name, arr[i].born, arr[i].live); 
    }

    return 0;
}
