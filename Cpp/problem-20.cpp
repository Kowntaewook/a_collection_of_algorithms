#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000

int n, m;
vector<pair<int, int>> graph[26];
int d[26];
bool visited[26];

void dijk(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (visited[now]) continue;
        visited[now] = true;

        for (auto &next : graph[now]) {
            int cost = dist + next.second;
            if (cost < d[next.first]) {
                d[next.first] = cost;
                pq.push({-cost, next.first});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        char a, b;
        int c;
        scanf(" %c %c %d", &a, &b, &c); 
        graph[a - 'A'].push_back({b - 'A', c});
        graph[b - 'A'].push_back({a - 'A', c});
    }
    char start_c, end_c;
    scanf(" %c %c", &start_c, &end_c); 
    int start = start_c - 'A';
    int end = end_c - 'A';

    for (int i = 0; i < n; i++) d[i] = INF;
    dijk(start);

    if (d[end] == INF) printf("-1\n");
    else printf("%d\n", d[end]);
    return 0;
}
