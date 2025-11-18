#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    char str[100001];
    scanf("%s", str);

    stack<char> s;
    int cnt = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            s.push('(');
        }
        else
        {
            s.pop();

            if (str[i - 1] == '(')
            {
                // 레이저
                cnt += s.size();
            }
            else
            {
                // 막대기 끝
                cnt += 1;
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}
