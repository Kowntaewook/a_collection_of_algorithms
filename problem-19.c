#include <stdio.h>
struct Flags {
    unsigned int a : 1;
    unsigned int b : 2;
    unsigned int c : 3;
};
int main(){
    struct Flags flag = {1, 2, 5};
    printf("%d", flag.c);
    return 0;
}