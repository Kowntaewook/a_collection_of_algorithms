#include <stdio.h>

struct point
{
    int xpos;
    int ypos;
};

struct person
{
    char name[20];
    char phoneNum[20];
    int age;
};


int main()
{
    struct point pos={10, 20}; // xpos = 10, ypos = 20 으로 초기화
    struct person man={"이승기", "010-1212-0001", 21};  // char name[20] = 이승기, char phoneNum[20] = 010-1212-0001, int age = 21

    printf("%p %p \n", &pos, &pos.xpos);  //pos 주소값 출력 xpos의 주소값 출력
    printf("%p %p \n", &man, man.name);   //"이승기", "010-1212-0001, 21"이 저장되어 있는 man의 주소값 출력 man.name == char name 이므로 "이승기" 가 저장된 주소값 출력
    
    return 0;
}
