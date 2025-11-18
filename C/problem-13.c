#include <stdio.h>
int main(){
    int a = 1, b = 0;
    if(a && b || !b)
        printf("True");
    else
        printf("False");
    return 0;
}
