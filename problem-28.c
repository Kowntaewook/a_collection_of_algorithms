#include <stdio.h>

typedef struct student {
    int value;
    int index;
    int result;
} STUDENT;

int n;
STUDENT info[100000], tmp[100000];
int result[100000];

void f(int p, int q) {
    if(p >= q) return;
    int r = (p + q) / 2;
    f(p, r);
    f(r+1, q);
    
    int a = p, b = r + 1;
    for(int i=p ; i<=q ; i++) {
        if(b > q || (a <= r && info[a].value <= info[b].value)) {
            tmp[i] = info[a++];
        } else {
            tmp[i] = info[b++];
            tmp[i].result += r - a + 1; // 왼쪽 배열에서 남은 값들의 수만큼 result 증가
        }
    }
    for(int i=p ; i<=q ; i++) {
        info[i] = tmp[i];
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &info[i].value);
        info[i].index = i;
    }
    f(0, n-1);
    for(int i=0 ; i<n ; i++) {
        result[info[i].index] = info[i].result;
    }
    for(int i=0 ; i<n ; i++) {
        printf("%d ", result[i] + 1);
    }
    return 0;
}
