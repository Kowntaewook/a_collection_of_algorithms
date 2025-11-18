#include <stdio.h>
#include <stack>

using namespace std;

int main() {
    int n;
    char num[201];  

    scanf("%d", &n);
    scanf("%s", num);

    stack<char> s;
    int cnt = 0;

    
    for (int i = n - 1; i >= 0; i--) {
        s.push(num[i]);
        cnt++;
        if (cnt % 3 == 0 && i != 0) {
            s.push(',');  
        }
    }

    while (!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
    printf("\n");

    return 0;
}
