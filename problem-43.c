#include <stdio.h>
int main(){
    char ch[100];
    int i;
    printf("문자열 입력: ");
    scanf("%s", ch);

    char max = ch[0];  // 첫 번째를 최대로 초기화
    for(i = 0; ch[i] != '\0'; i++){ // 문자열 끝 찾기 조건
        if(ch[i] > max){  // max와 비교
            max = ch[i];
        }
    }
    printf("최대 문자: %c\n", max);
    
    return 0;
}