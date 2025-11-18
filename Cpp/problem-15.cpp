#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool visited[201][201]; // 방문 여부
int dist[201][201]; // 거리

void bfs(int n, int m, vector<vector<int>>& maze) // n == 행, m == 열 maze == 미로
{
    queue<int> q;
    q.push(0); // (0,0) → 0 * m + 0 = 0
    visited[0][0] = true;
    dist[0][0] = 1;

    while(!q.empty())
    {
        int index = q.front(); q.pop();
        int x = index / m;
        int y = index % m;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(maze[nx][ny] == 0 || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push(nx * m + ny); // 다시 좌표를 인덱스로 바꿔서 저장
        }
    }

    printf("%d\n", dist[n - 1][m - 1]);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int>> maze(n, vector<int>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs(n, m, maze);
    return 0;
}
