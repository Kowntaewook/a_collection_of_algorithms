#include <stdio.h>

void num(int a){

    if(a>0){   
        printf("%d \n",a);
        num(a-1);
    }
    else{
        return;
    }

}


int main(){
    
    int a;
    scanf("%d", &a);
    num(a);
    return 0;

}