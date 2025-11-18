/*문제 설명
어떤 영어 한 단어가 입력되면 각 알파벳이 몇번 나왔는지 출력하는 프로그램을 작성하시오







입력 설명
영어 단어가 입력되고 입력 받는 문장의 길이는 50미만이다.
출력 설명
각 알파벳의 갯수를 출력한다. 단 알파벳이 하나도 안나온 경우는 출력되어선 안된다. (알파벳은 소문자만을 센다)
입력 예시 Copy
hello
출력 예시 Copy
e : 1개
h : 1개
l : 2개
o : 1개*/

#include <stdio.h>
int main()
{
    int count[26] = {0};
    char word[51];

    scanf("%s", word);
    for(int i = 0; word[i] != '\0'; i++)
    {
        if(word[i] >= 'a' && word[i] <= 'z')
        {
            count[word[i] - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(count[i] > 0)
        {
            printf("%c : %d개\n", 'a' + i, count[i]);
        }
    }
    return 0;
}
