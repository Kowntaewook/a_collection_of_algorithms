#include <stdio.h>
int main(){
    int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int (*p)[3] = arr;
    printf("%d", *(*(p+1) + 2));
    return 0;
}