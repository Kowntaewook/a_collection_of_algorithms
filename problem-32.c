#include <stdio.h>

void f(int a){

    if(a<=0){ 
        return;
    }

    else{
        f(a-1);
        printf("%d \n",a);
    }
    
}
void g(int a){

    if(a>0){ 
        printf("%d \n",a);
        g(a-1);
    }

    else{
        return;
    }
    
}
int main(){

    f(10);
    g(10);
    return 0;
}