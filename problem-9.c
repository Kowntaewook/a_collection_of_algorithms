#include <stdio.h>
int main(){
    int a = 100;
    int *p = &a;
    int **pp = &p;
    printf("%d", **pp);
    return 0;
}

