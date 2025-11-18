/* 문제 설명    
N
개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.

어느 날 이 
N
명의 학생이 
X
 (
1
≤
X
≤
N
)번 마을에 모여서 파티를 벌이기로 했다. 이 마을 사이에는 총 
M
개의 단방향 도로들이 있고 
i
번째 길을 지나는데 
T
i
(
1
≤
T
i
≤
100
)의 시간을 소비한다.

각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.

이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. 
N
명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.

입력
첫째 줄에 
N
(
1
<=
N
<=
1
,
000
), 
M
(
1
<=
M
<=
10
,
000
), 
X
가 공백으로 구분되어 입력된다.

두 번째 줄부터 
M
+
1
번째 줄까지 
i
번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 
T
i
가 들어온다.

모든 학생들은 집에서 
X
에 갈수 있고, 
X
에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.

출력
첫 번째 줄에 
N
명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.

입력 예시   
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

출력 예시
10 */

#include <stdio.h>
#include <vector>
#include <queue> 

using namespace std;

#define INF 1e9

int n,m;

vector<pair<int, int>> graph[26];
int d[26];
bool visited[26];

void dijks(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;

    while(pq.empty() == false) {
        int dist = -pq.top().first;
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
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        char a, b;
        int c;
        scanf("%c %c %d", &a, &b, &c);

        graph[a - 'A'].push_back({b - 'A', c});
        graph[b - 'A'].push_back({a - 'A', c});
    }

    for(int i = 0; i < 26; i++) {
        d[i] = INF;
        visited[i] = false;
    }

    dijks('A' - 'A');
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(d[i] == INF)
            continue;
        ans = max(ans, d[i]);
    }

    printf("%d\n", ans); 
    return 0;
}