#include <stdio.h>

void num(int a){
    if(a == 0){
        return;
    }

    else {
        num(a/2);
        printf("%d", a%2);
    }

}

int main(){
    int a;
    scanf("%d", &a);
    
    if (a == 0){
        printf("%d", a);
    }
    else{
        num(a);
    }
}
