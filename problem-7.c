#include <stdio.h>
void f(){
    static int a = 0;
    a++;
    printf("%d ", a);
}
int main(){
    f();
    f();
    f();
    return 0;
}