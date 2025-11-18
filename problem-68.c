#include <stdio.h>
#include <string.h>
//입력
//첫째 줄에 데이터의 개수  n (3 <= n <=100)

//둘째 줄부터  
// n + 1 줄에 학생 이름과 과목 점수가 공백으로 구분되서 입력 단 이름의 길이는 최대 10 바이트 이내

//출력
//첫 번째 과목을 1등한 학생의 이름과 두 번째, 세 번째 과목의 석차를 공백으로 구분하여 출력한다. 단 첫 번째 과목의 1등은 1명이라고 가정

//입력 예시   
//4
//Jeon 95 80 100
//Kim 59 85 75
//Lee 90 100 75
//Bae 100 82 80

//출력 예시
//Bae 3 2

typedef struct
{
    char name[20];
    int f_score;
    int s_score;
    int t_score;
}student;

// 학생들의 3과목 점수 비교용 함수
int compare(student a, student b)
{
    if(a.f_score > b.f_score)
        return 1;
    else if(a.f_score < b.f_score)
        return -1;
    else
        return 0;
}

int main()
{
    int n; 
    scanf("%d", &n);
    student s[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", s[i].name, &s[i].f_score, &s[i].s_score, &s[i].t_score);
    }

    // 1등 찾기
    int first = 0;
    for(int i = 1; i < n; i++)
    {
        if(compare(s[i], s[first]) > 0)
        {
            first = i;
        }
    }

    // 1등의 2번째 과목 석차
    int second = 1;
    for(int i = 0; i < n; i++)
    {
        if(i != first && s[i].s_score > s[first].s_score)
        {
            second++;
        }
    }
    // 1등의 3번째 과목 석차
    int third = 1;
    for(int i = 0; i < n; i++)
    {
        if(i != first && s[i].t_score > s[first].t_score)
        {
            third++;
        }
    }
    // 출력
    printf("%s %d %d\n", s[first].name, second, third);
    return 0;
}