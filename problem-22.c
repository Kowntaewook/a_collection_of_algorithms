#include <stdio.h>
#include <stdlib.h>
int main(){
    int **arr = (int**)malloc(2 * sizeof(int*));
    for(int i = 0; i < 2; i++){
        arr[i] = (int*)malloc(3 * sizeof(int));
        for(int j = 0; j < 3; j++){
            arr[i][j] = i + j;
        }
    }
    int sum = arr[0][1] + arr[1][2];
    for(int i = 0; i < 2; i++){
        free(arr[i]);
    }
    free(arr);
    printf("%d", sum);
    return 0;
}