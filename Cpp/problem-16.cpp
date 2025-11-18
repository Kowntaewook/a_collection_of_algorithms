/*문제1)

<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.



입력
첫 번째 줄에는 지도의 크기 N(정사각형으므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고,

그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

입력 예시   
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

출력 예시
3
7
8
9 */

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[25][25];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// bfs function

void bfs(int x, int y, int n, vector<vector<int>>& map, vector<int>& result)
{
    queue<int> q;
    q.push(x);
    q.push(y);
    
    visited[x][y] = true;
    int count = 1;

    while(!q.empty())
    {
        int curx = q.front();
        q.pop();
        int cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cur + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if(visited[nx][ny] || map[nx][ny] == 0)
                continue;
            visited[nx][ny] = true;
            q.push(nx);
            q.push(ny);
            count++;
        }
    }
    result.push_back(count);
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<vector<int>> map(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    vector<int> result;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 1 && !visited[i][j]) 
            {
                bfs(i, j, n, map, result);
            }
        }
    }
    printf("%d\n", result.size());
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}