#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000 // 무한으로 값 설정

int n, m, start;
vector<pair<int, int>> graph[100001];
int d[100001];
bool visited[100001];

// 다익스트라
void dijkstra(int start) {
    // {거리, 노드}를 저장, 거리 작은 순으로 꺼내야 하므로 priority_queue에 음수 사용
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()) {
        int dist = -pq.top().first; // 음수로 넣었으므로 다시 양수로
        int now = pq.top().second;
        pq.pop();

        if(visited[now]) continue;
        visited[now] = true;

        for(auto &edge : graph[now]) {
            int next = edge.first;
            int cost = edge.second;

            if(d[next] > dist + cost) {
                d[next] = dist + cost;
                pq.push({-d[next], next});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d", &start);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c}); // a번 노드에서 b번 노드로 가는 비용 c
    }

    for(int i = 1; i <= n; i++) {
        d[i] = INF; // 최단 거리 초기화
        visited[i] = false; // 방문 초기화
    }

    dijkstra(start);

    for(int i = 1; i <= n; i++) {
        if(d[i] == INF)
            printf("INFINITY\n");
        else
            printf("%d\n", d[i]);
    }

    return 0;
}
