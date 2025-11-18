#include <stdio.h>

void num(int a) {
    if (a == 1) {  // 종료 조건 (1이 되면 출력 시작)
        printf("%d\n", a);
        return;
    }

    if (a % 2 == 0) {
        num(a / 2);  // 짝수일 경우
    } else {
        num(3 * a + 1);  // 홀수일 경우
    }

    printf("%d\n", a);  // 역순으로 출력
}

int main() {
    int a;
    scanf("%d", &a);
    num(a);
}
