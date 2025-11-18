#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 1000000
#define MAX 1001

int graph[MAX][MAX];
int graph_rev[MAX][MAX];
int dist[MAX];
int N, M, X;

void dijk(int start, int g[MAX][MAX])
{
    for(int i = 1; i <= N; i++)
        dist[i] = INF;
    dist[start] = 0;

    int visited[MAX] = {0,};
    for(int i = 1; i <= N; i++)
    {
        int min = INF, min_idx = -1;
        for(int j = 1; j <= N; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                min_idx = j;
            }
        }
        if(min_idx == -1) break;
        visited[min_idx] = 1;

        for(int j = 1; j <= N; j++)
        {
            if(!visited[j] && g[min_idx][j] != INF)
            {
                if(dist[j] > dist[min_idx] + g[min_idx][j])
                    dist[j] = dist[min_idx] + g[min_idx][j];
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &X);

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
        {
            graph[i][j] = (i==j ? 0 : INF);
            graph_rev[i][j] = (i==j ? 0 : INF);
        }

    for(int i = 0; i < M; i++)
    {
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);
        graph[u][v] = t;
        graph_rev[v][u] = t;
    }

    int dist_from_X[MAX], dist_to_X[MAX];

    dijk(X, graph);
    for(int i = 1; i <= N; i++)
        dist_from_X[i] = dist[i];

    dijk(X, graph_rev);
    for(int i = 1; i <= N; i++)
        dist_to_X[i] = dist[i];

    int max_time = 0;
    for(int i = 1; i <= N; i++)
    {
        int time = dist_from_X[i] + dist_to_X[i];
        if(time > max_time) max_time = time;
    }

    printf("%d\n", max_time);
    return 0;
}
