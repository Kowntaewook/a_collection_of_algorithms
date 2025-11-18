#include <stdio.h>
int* f(){
    static int a[3] = {7, 8, 9};
    return a;
}
int main(){
    int *p = f();
    printf("%d", *p+3);
    return 0;
}
