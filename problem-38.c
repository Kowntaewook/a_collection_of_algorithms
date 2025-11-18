#include <stdio.h>

void num(int a){
    printf("%d\n",a);
    if(a == 1){
        return;
    }
    else if(a%2 != 0){
        num(3*a+1);
    }
    else if(a % 2 == 0){
        num(a/2);
    }

    else{
        printf("%d", a);
    }

}

int main(){
    int a;
    scanf("%d", &a);

    if(a == 0){
        printf("%d", a);
    }
    else{
        num(a);
    }
}