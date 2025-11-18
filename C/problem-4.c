
#include <stdio.h>
int main(){
    int arr[] = {10, 20, 30};
    int *ptr = arr;
    ptr++;
    printf("%d", *ptr);
    return 0;
}
