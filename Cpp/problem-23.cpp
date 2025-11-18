/*첫째 줄에 도시의 개수 N 통로의 개수 M 메시지를 보내고자 하는 도시 C
1 <= N <= 30000 1 <= M <= 2000000 1 <= C <= N
둘째 줄부터 M + 1번 쨰 줄에 걸쳐서 통로에대한 정보 X,Y,Z가 주어진다 이는 특정 도시 X에서 다른 특정 도시 Y로 이어지는 통로에 있으며 메시지가 전달되는 시간이 Z라는 의미이다.
1 <= X Y <= N 1 <= Z <= 1000
입력 예시 : 
3 2 1
1 2 4
1 3 2
출력 예시 : 
2 4*/

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
#define INF 1000000000
int n, m, start; 
vector<pair<int, int>> graph[30001];
int d[30001];
bool visited[30001];

void dijk(int start) {
    for(int i = 1; i <= n; i++)
        d[i] = INF;
    d[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(pq.size()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(visited[now])
            continue;
        visited[now] = true;
        
        for(int i = 0; i < graph[now].size(); i++) 
        {
            int next = graph[now][i].first;
            int cost = graph[now][i].second;

            if(d[next] > dist + cost) 
            {
                d[next] = dist + cost;
                pq.push({d[next]*-1, next});
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &start);

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
    }
    dijk(start);
    int cnt = 0;
    int max = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] != INF && i != start)
        {
            cnt++;
            if(max < d[i])
                max = d[i];
        }
    }
    printf("%d %d\n", cnt, max);
    return 0; 
}