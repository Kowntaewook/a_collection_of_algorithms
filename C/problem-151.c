#include <stdio.h>

#define MAX 100001

typedef struct {
    int u, v;
} Edge;

int parent[MAX];
int treeParent[MAX];
int visited[MAX];
Edge edges[MAX];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        treeParent[i] = 0;
        visited[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }

    int queue[MAX];  
    int front = 0, rear = 0;

    visited[1] = 1;
    queue[rear++] = 1;

    while (front < rear) {
        int cur = queue[front++];
        for (int i = 0; i < n - 1; i++) {
            int u = edges[i].u;
            int v = edges[i].v;

            int pu = find(u);
            int pv = find(v);

            if (pu != pv) {
                if (visited[u] && !visited[v]) {
                    treeParent[v] = u;
                    visited[v] = 1;
                    unionSet(u, v);
                    queue[rear++] = v;
                }
                else if (!visited[u] && visited[v]) {
                    treeParent[u] = v;
                    visited[u] = 1;
                    unionSet(u, v);
                    queue[rear++] = u;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        printf("%d\n", treeParent[i]);
    }

    return 0;
}
