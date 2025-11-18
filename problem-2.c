#include <stdio.h>
int main(){
    char str[] = "hello";
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    printf("%d", i);
    return 0;
}