/*1 ~ 15까지의 이진 트리 만들기 부모 노드와 자식 노드 단위로 끊어서 출력
1차원 배열만 사용*/

#include <stdio.h>

int main()
{
    int tree[16];

    for(int i = 1; i <= 15; i++)
    {
        tree[i] = i;
    }

    // no queue

    for(int i = 1; i <= 7; i++)
    {
        printf("%d ", tree[i]);
        printf("%d ", tree[i * 2]);
        printf("%d \n", tree[i * 2 + 1]);
    }
    return 0;
}