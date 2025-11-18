#include <stdio.h>
#include <limits.h>

#define MAX_NODES 1001

int st, en;
int dst[MAX_NODES];
int n, m;
int lnk[MAX_NODES][MAX_NODES];
int queue[MAX_NODES], front = 0, rear = 0;

void push(int x) {
    queue[rear++] = x;
}

int pop() {
    return queue[front++];
}

int empty() {
    return front == rear;
}

int main() {
    scanf("%d %d", &st, &en);
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        lnk[a][b] = 1;
        lnk[b][a] = 1;
    }
    
    for (int i = 1; i <= n; i++) dst[i] = INT_MAX;
    dst[st] = 0;
    push(st);
    
    while (!empty()) {
        int qf = pop();
        
        for (int nxt = 1; nxt <= n; nxt++) {
            if (lnk[qf][nxt] && dst[nxt] > dst[qf] + 1) {
                dst[nxt] = dst[qf] + 1;
                push(nxt);
            }
        }
    }
    
    if (dst[en] == INT_MAX) printf("-1\n");
    else printf("%d\n", dst[en]);
    
    return 0;
}