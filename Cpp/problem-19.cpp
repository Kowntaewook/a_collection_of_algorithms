#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[101][101];
bool visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int sy, int sx, int m, int n)
{
    queue<int> qy, qx; // y좌표, x좌표 따로 저장
    qy.push(sy);
    qx.push(sx);
    visited[sy][sx] = true; // 시작점 방문 처리

    int area = 1; // 영역 크기 

    while(!qy.empty())
    {
        int y = qy.front(); qy.pop(); 
        int x = qx.front(); qx.pop();

        for(int dir = 0; dir < 4; dir++) // 상하좌우 탐색
        {
            int ny = y + dy[dir]; // 다음 y좌표
            int nx = x + dx[dir]; // 다음 x좌표

            if(ny < 0 || ny >= m || nx < 0 || nx >= n)  // 범위 벗어나면 건너뛰기
                continue;
            if(visited[ny][nx] || board[ny][nx] == 1) // 이미 방문 or 칠해진 영역 건너뛰기
                continue;

            visited[ny][nx] = true; // 방문 처리
            qy.push(ny); // y좌표에 넣기
            qx.push(nx); // x좌표에 넣기
            area++; 
        }
    }
    return area; // 영역 크기 반환
}

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k); 

    // 직사각형 칠하기
    for(int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 

        for(int y = y1; y < y2; y++)
        {
            for(int x = x1; x < x2; x++)
            {
                board[y][x] = 1;
            }
        }
    }

    vector<int> areas; // 영역 크기 저장용 벡터

    for(int y = 0; y < m; y++)
    {
        for(int x = 0; x < n; x++)
        {
            if(!visited[y][x] && board[y][x] == 0) // 방문 X 칠해지지않은 영역
            {
                int a = bfs(y, x, m, n); // 크기 계산
                areas.push_back(a); 
            }
        }
    }

    sort(areas.begin(), areas.end()); // 오름차순 정렬

    printf("%d\n", (int)areas.size()); // 개수 출력
    for(int i = 0; i < areas.size(); i++)
    {
        printf("%d ", areas[i]); // 크기 출력
    }
    printf("\n");
    return 0;
}
