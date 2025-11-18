#include <stdio.h>

void num(int a, int b){
    if(a>b){
        return;
    }

    else{
        if(a%2 != 0){
            printf("%d ", a);
        }
        num(a+1, b);    
    }
}


int main(){
    int a,b;

    scanf("%d %d", &a, &b);

    num(a,b);
}
