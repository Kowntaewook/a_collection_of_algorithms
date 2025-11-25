/*바다는 크레파스보다 진한 푸르고 육중한 비늘을 무겁게 뒤채면서 숨을 쉰다.

그러나 그 숨보다 더 깊은 것은 지금 국가 간의 갈등일 것이다.

사소한 오해에서 시작된 갈등은 걷잡을 수 없이 커져, 범세계적 전쟁으로 확산되었다.

당신은 세계에서 유일한 중립국의 정보요원이다.

나머지 국가는 전부 입장 표명을 하지 않았거나 전쟁에 참여하였다.

세계 평화를 위해 당신이 해야 할 첫 번째 일은 현재 상황을 빠르게 파악하는 것이다.

국가 
P
와 
Q
가 동맹이고 
Q
와 
R
이 동맹이면 
P
와 
R
도 동맹이다.

N
개 국가의 총 
M
개 동맹국 선언이 주어지면 연합 관계를 제시해주는 프로그램을 만들자.

여기서 연합 관계란 동맹을 맺은 국가들끼리의 집합을 의미한다.

만약 어떤 국가가 다른 국가와 동맹을 하나도 맺지 않으면 그 국가는 그 자체로 한 연합이라고 취급한다.

입력
첫째 줄에는 국가의 수 
N
과 선언의 수 
M
이 주어진다. 각 국가의 이름은 
1
~
N
까지의 정수이다. (
N
은 
1
이상 
1
,
000
 이하, 
M
은 
0
 이상 
1
,
000
 이하)

둘째 줄부터 
M
+
1
번째 줄까지는 동맹국 선언이 제시된다. 각 동맹국 선언은 
A
 
B
의 형식으로 이루어진다. 이는 
A
와 
B
가 동맹국 선언을 했음을 의미한다.예를 들어, 
1
 
3
이라는 선언은 국가 
1
과 국가 
3
이 동맹국이라는 의미이다.

출력
각 국가가 속한 연합에서 가장 작은 숫자를 가진 국가를 출력한다. 
1
번 국가부터 
n
번 국가까지 순서대로 공백으로 분리하여 출력하여라.

입력 예시   
5 3
1 3
2 3
4 5

출력 예시
1 1 1 4 4  */

// Disjoint
#include <stdio.h>


int n, m;
int parent[1001];

int findParent(int x) {
    if (x == parent[x]) 
        return x;
    return findParent(parent[x]);
}

void unionP(int a, int b)
{
    int pa = findParent(a);
    int pb = findParent(b);
    if(pa < pb)
        parent[pb] = pa;
    else
        parent[pa] = pb;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        parent[i] = i;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        unionP(a, b);
    }
    
    for(int i = 1; i <= n; i++)
    {
        printf("%d", findParent(i));
        if(i != n)
            printf(" ");
        else
            printf("\n");
    }

    return 0;
}