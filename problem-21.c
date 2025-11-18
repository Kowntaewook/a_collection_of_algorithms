#include <stdio.h>
int f(int x){ return x * x; }
int g(int x){ return f(x) * x; }
int main(){
    int (*a[2])(int) = { f, g };
    printf("%d", a[1](2));
    return 0;
}
