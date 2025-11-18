/* N X M 크기의 얼음 틀이 있다 구명이 뚫려 있는 부분은 0, 칸막이가 존재하는 부분은 1로 표시된다. 구멍이 뚫려 있는 부분끼리 상, 하, 좌, 우로 붙어 있는 경우 서로 연결되어 있는 것으로 간주한다. 이때 얼음 틀의 모양이 주어졌을떄 생성되는 총 아이스크림의 개수를 구하는 프로그램을 작성하시오. 다음의 4 x 5 얼음 틀 예시에서는 아이스크림이 총 3개 생성된다.
예시 출력
00110
00011
11111
00000*/

/*입력 조건 : 첫 번쨰 줄에 얼음 틀의 세로의 길이 N과 가로 길이 M이 주어진다.
두번쨰 줄부터 N + 1번째 줄까지 얼음 틀의 형태가 주어진다.
이때 구멍이 뚫려있는 부분은 0, 그렇지 않은 부분은 1이다.
출력 조건 : 한 번에 만들 수 있는 아이스크림의 개수를 출력한다.*/

#include <stdio.h>
#include <queue>

using namespace std;

queue<int> q;
bool visited[100][100];
int graph[100][100];

int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// dfs
void dfs(int x, int y)
{
    visited[x][y] = true;
    for(int i = 0; i < 4; i ++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if(visited[nx][ny] == false && graph[nx][ny] == 0)
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(graph[i][j] == 0 && visited[i][j] == false)
            {
                dfs(i, j);
                result += 1;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}