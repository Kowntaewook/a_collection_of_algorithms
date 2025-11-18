#include <stdio.h>
#include <queue>

using namespace std;

bool visited[9];
vector<int> graph[9];

queue<int> q;

// output == 1 2 7 6 8 3 4 5

// DFS 함수 정의

void dfs(int x)
{
    visited[x] = true;
    printf("%d ", x);
    for(int i = 0; i < graph[x].size(); i++)
    {
        int y = graph[x][i];
        if(visited[y] == false)
        {
            dfs(y);
        }
    }
}

int main()
{
    // node 1
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    // node 2
    graph[2].push_back(1);
    graph[2].push_back(7);
    // node 3
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    // node 4
    graph[4].push_back(3);
    graph[4].push_back(5);
    // node 5
    graph[5].push_back(3);
    graph[5].push_back(4);
    // node 6
    graph[6].push_back(7);
    // node 7
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    // node 8
    graph[8].push_back(1);
    graph[8].push_back(7);
    dfs(1);
    return 0;                                 
}