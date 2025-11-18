#include <stdio.h>

int checkPrime(int num){

    int prime = 1; 
    if (num <= 1) {
        prime = 0; 
    } else {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                prime = 0; 
                break;
            }
        }
    }

    return prime;
}


int main(){
    int num;
    scanf("%d", &num);
    if (checkPrime(num)==1) {
        printf("Prime : %d", num);
    }
    else{
        printf("Not Prime : %d", num);
    }
    return 0;   
}
