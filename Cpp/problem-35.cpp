/* 트리 
T
는 아래 그림 1과 같은 구조를 가지고 있 으며 원은 ‘정점’이라 하고, 정점과 정점을 연결하 는 선을 ‘에지’라 한다. 특히 가장 위에 위치한 정 점을 ‘루트’라 하는데 오직 하나만 있다. 
N
개의 정점들은 숫자 
1
부터 
N
으로 표현하고 루트는 항상 
1
이다.

두 정점 
v
와 
w
를 연결하는 경로는 정점들의 순서리스트 
(
v
0
,
v
1
,
.
.
.
,
v
m
)
로, 정점 
v
i
와 
v
i
+
1
은 에지로 연결되고 
v
0
, 
v
m
=
w
이다. 트리에서는 임의의 두 정점 
v
와 
w
사이에 항상 두 정점 을 연결하는 경로가 오직 하나만 존재한다. 예를 들어, 그림 1에서 정점 
3
과 
11
 사이의 유일한 경 로는 
(
3
,
4
,
1
,
7
,
11
)
이다.



각 정점 
v
에서 루트 
r
과 연결하는 유일한 경로 
P
에 대해서 정점 
v
와 에지로 연결된 정점 중에서 
P
상에 있는 정점을 
v
의 ‘부모 정점’이라고 한다. 예를 들어, 그림 1에서 
4
,
7
,
9
의 부모 정점 은 
1
이고, 
2
와 
11
의 부모 정점은 
7
이다.

트리 
T
에서 어떤 두 정점을 연결하는 에지를 제거하면 그 두 정점 외에도 경로가 존재하지 않는 정점 쌍이 있을 수 있다. 여러분은 “정점 
v
와 
w
 를 연결하는 경로가 존재하는가?”와 같은 질의에 답해야 한다. 예를 들어, 그림 1에서 
7
과 
11
 사 이의 에지를 제거하면 
8
과 
5
를 연결하는 경로는 존재하지 않는다.

트리 정보가 주어지고, 에지의 제거 정보와 질의 가 임의의 순서로 주어질 때, 작업을 순서대로 수 행하며 질의에 대한 답을 출력하는 프로그램을 작 성하시오.

입력
첫 번째 줄 에는 트리의 정점의 개수와 질의의 개수를 나타내 는 두 정수 
N
과 
Q
 (
1
≤
N
,
Q
≤
200
,
000
)가 주어진다.

다음 
N
−
1
개의 줄의 
i
번째 줄에는 정점 
i
+
1
의 부모 정점을 나타내는 정수 
a
가 주어 진다 (
1
≤
a
≤
N
).

다음 
(
N
−
1
)
+
Q
개의 줄 중에서 
(
N
−
1
)
개는 (1)의 형태로, 
Q
개는 (2)의 형 태로 주어진다.

(1) 두 정수 
x
와 
b
가 주어진다 (
x
=
0
,
2
≤
b
≤
N
). 이것은 
b
의 부모 정점과 
b
를 연결하는 에지를 제거함을 의미한다. 각 줄의 
b
는 모두 다르다.

(2) 세 정수 
x
,
c
,
d
가 주어진 다 (
x
=
1
,
1
≤
c
,
d
≤
N
). 이것은 
c
와 
d
를 연결하는 경로가 존재하는 지 묻는 질의를 의미한다.

출력
질의에 대한 답을 순서대로 
Q
개의 줄에 출력한다. 각 줄마다 경로가 존재하면 
Y
E
S
를 아니면 
N
O
를 출력한다.

입력 예시   
3 3
1
1
1 2 3
0 3
1 2 3
1 1 2
0 2

출력 예시
YES
NO
YES */

#include <stdio.h>

int n, q;
int parent[200001];
int a[200000];
int b[200000];
int que_t[200000];
int que_x[200000];
int que_y[200000];
bool ans[200000];


int findParent(int x)
{
    if(x == parent[x])
        return x;
    return parent[x] = findParent(parent[x]);
}

void unionP(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    scanf("%d %d", &n, &q);

    for(int i = 1; i <= n; i++)
        parent[i] = i;
    for(int i = 2; i <= n; i++)
    {
        int p;
        scanf("%d", &p);
        a[i - 2] = p;
        b[i - 2] = i;
    }

    for(int i = 0; i < n - 1 + q; i++){
        int t;
        scanf("%d", &t);

        que_t[i] = t;
        if(t == 0)
        {
            int x;
            scanf("%d", &x);
            que_x[i] = x;
        }
        else
        {
            int x, y;
            scanf("%d %d", &x, &y);
            que_x[i] = x;
            que_y[i] = y;
        }
    }
    int edge_idx = n -2;

    for(int i = n - 2 + q - 1; i >= 0; i--)
    {
        if(que_t[i] == 0)
        {
            int node = que_x[i];
            unionP(a[node - 2], b[node - 2]);
        }
        else
        {
            int x = que_x[i];
            int y = que_y[i];
            if(findParent(x) == findParent(y))
            {
                ans[i] = true;
            }
            else
            {
                ans[i] = false;
            }
        }
    }

    for(int i = 0; i < n - 1 + q; i++)
    {
        if(que_t[i] == 1)
        {
            if(ans[i])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }  
    return 0;
}