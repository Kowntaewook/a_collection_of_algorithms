// 첫째 줄에 도시의 개수 N 도로의 개수 M 거리 정보 K 출발 도시의 번호 X가 주어집니다.
//2 <= N <= 300000 1 <= M <= 1000000 1 <= K <= 3000000 1 <= X <= N
// 둘째 줄부터 M개의 줄에 걸쳐서 두 개의 자연수 A, B가 주어지며 각 자연수는 공백으로 구분합니다.
//이는 A번 도시에서 B번 도시로 이동하는 단방향 도로가 존재한다는 의미입니다. 1 <= A, B <= N
//마지막 줄에 X부터 가장 먼 도시의 거리를 출력합니다.
//X에서 X로 가는 최단 거리는 항상 0이라고 가정합니다.
/*출력 조건 X로부터 출발하여 도달할 수 있는 도시 중에서 최단 거리가 K인 모든 도시의 번호를 한줄에 하나씩 오름차순으로 출력
이때 도달할 수 있는 도시중에서 최단 거리가 K인 도시가 하나도 존재하지 않는다면 -1을 출력*/

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, x;
vector<int> graph[300001];
int dist[300001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if(dist[next] == -1)
            {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}


int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &x);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }
    for(int i = 1; i <= n; i++)
    {
        dist[i] = -1;
    }
    bfs(x);
    
    bool found = false;
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] == k)
        {
            printf("%d\n", i);
            found = true;
        }
    }
    if(!found)
    {
        printf("-1\n");
    }
    return 0;
}