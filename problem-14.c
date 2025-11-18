#include <stdio.h>
int f(int a, int b){ return a + b; }
int g(int a, int b){ return a - b; }
int main(){
    int x = 10, y = 5;
    int (*a)(int, int);
    a = (x > y) ? f : g;
    printf("%d", a(x, y));
    return 0;
}