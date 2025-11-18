#include <stdio.h>
#include <queue>

using namespace std;

int board[101][101];     // 등고선 값 저장
bool visited[101][101];  // 방문 여부 체크

int dx[4] = {1, -1, 0, 0};  // 상하좌우
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y, int n) {
    queue<int> q;
    q.push(x);
    q.push(y);

    visited[x][y] = true;
    board[x][y] = 1;

    while (!q.empty()) {
        int curx = q.front(); q.pop();
        int cury = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            // 범위 벗어나면 스킵
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            board[nx][ny] = board[curx][cury] + 1;
            q.push(nx);
            q.push(ny);
        }
    }
}

int main() {
    int n, x, y;
    scanf("%d", &n);
    scanf("%d %d", &x, &y);

    // 입력 좌표는 1-based → 0-based 로 보정
    x--;
    y--;

    bfs(x, y, n);

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}