#include <stdio.h>
int main(){
    int num[5];
    int result=0;
    int result2=0;

    for(int i=0; i<num; i++){
        scanf("%d", &num[i]);
        for(int j=0; j<num; j++){
            if(num[j] < num[i]){
                result=num[j]-50;
                break;  
            }
        }
    }

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            if(num[j] < num[i]){
               num[]   // tlqkf 이거 두번째 최소값 어캐하노이 ㅠㅠ
            }
        }
    }

    return 0;
}
    