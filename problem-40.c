#include <stdio.h>

void star(int count) {

    if (count == 0) {
        return;
    }

    printf("*");
    star(count-1);  

}

void triangle(int a){
    if (a == 0){
        return;
    }

    triangle(a-1);
    star(a);
    printf("\n");
}

int main(){
    int a;
    scanf("%d", &a);
    triangle(a);
}