//개선된 다익스트라 다시 짜기
// without iostream
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

int n, m, start;
vector<pair<int, int>> graph[100001];
int d[100001];
bool visited[100001];

// 다익스트라
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    d[start] = 0;
    while(pq.empty() == false) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visited[now])
            continue;
        visited[now] = true;
        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int cost = graph[now][i].second;
            if(d[next] > dist + cost) {
                d[next] = dist + cost;
                pq.push({d[next], next});
            }
        }
    }
}

int main() {
    int n, m, start;
    scanf("%d %d", &n, &m);
    scanf("%d", &start);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
    }

    for(int i = 1; i <= n; i++) {
        d[i] = INF;
        visited[i] = false;
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