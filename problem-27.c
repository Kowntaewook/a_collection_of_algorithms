#include <stdio.h>

int n, m, k;
int mapp[7][7];
int f, fs[110];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int f2(int y, int x) {
    if(1 <= y && y <= n && 1 <= x && x <= n) return 1;
    else return 0;
}

void func(int y, int x) {
    mapp[y][x] = f;
    int qy[200] = {0};
    int qx[200] = {0};
    int qs = 0, qe = 0;
    
    qy[qe] = y;
    qx[qe++] = x;
    
    while(qs != qe) {
        int qsy = qy[qs];
        int qsx = qx[qs++];
        
        for(int i=0 ; i<4 ; i++) {
            int nxy = qsy + dy[i];
            int nxx = qsx + dx[i];
            if(f2(nxy, nxx) == 1 && mapp[nxy][nxx] == -1) {
                mapp[nxy][nxx] = f;
                qy[qe] = nxy;
                qx[qe++] = nxx;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            scanf("%d", &mapp[i][j]);
            if(mapp[i][j] == 0) mapp[i][j] = -1;
            else mapp[i][j] = 0;
        }
    }
    
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(mapp[i][j] == -1) {
                f++;
                func(i, j);
            }
        }
    }
    
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            if(mapp[i][j] > 0) {
                fs[mapp[i][j]]++;
            }
        }
    }
    
    for(int i=1 ; i<=f ; i++) {
        m -= (fs[i] + k - 1) / k;
    }
    
    if(m >= 0 && f > 0) printf("%d\n", m);
    else printf("-1\n");
}