#include <stdio.h>

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int num[1000];

    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    // 가장 큰 수와 두 번째로 큰 수 찾기
    int first = 0, second = 0;
    for(int i = 0; i < n; i++) {
        if(num[i] > first) {
            second = first;
            first = num[i];
        } else if(num[i] > second) {
            second = num[i];
        }
    }

    // 계산
    int set_count = m / (k + 1);
    int remain = m % (k + 1);

    int result = set_count * (first * k + second) + remain * first;

    printf("%d\n", result);
    return 0;
}

