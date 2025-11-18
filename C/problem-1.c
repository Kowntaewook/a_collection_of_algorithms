#include <stdio.h>
int main(){
    int i = 0;
    int count = 0;
    do {
        count++;
        i++;
    } while(i < 3);
    printf("%d", count);
    return 0;
}
