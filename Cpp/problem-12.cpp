#include <stdio.h>
#include <queue>

using namespace std;

int map[7][7];
bool visited[7][7];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// DFS로 방문하는 함수
void dfs(int x, int y, int color, queue<pair<int, int>> &q) {
    visited[x][y] = true;
    q.push({x, y});

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= 7 || ny < 0 || ny >= 7)
            continue;

        if (!visited[nx][ny] && map[nx][ny] == color) {
            dfs(nx, ny, color, q);
        }
    }
}

int main() {
    // 입력
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int result = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (!visited[i][j]) {
                queue<pair<int, int>> q;
                dfs(i, j, map[i][j], q);

                if (q.size() >= 3)
                    result++;
            }
        }
    }

    printf("%d\n", result);
    return 0;
}
