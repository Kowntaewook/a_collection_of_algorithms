/*문제 설명    
당신의 상관은 당신이 작년에 회사의 실적에 얼마나 도움이 되었는지 횟수를 세었다.



불행히도 당신의 상관은 때때로 횟수를 틀리게 읽는다.



다행히도 당신의 상관은 잘못된 숫자를 읽은 것을 인식하면 ‘zero’라고 말한다. 이는 ‘직전의 숫자는 무시한다’는 것을 의미한다.



불행히도 당신의 상관은 실수를 반복할 수 있고, 매 실수 마다 ‘zero’라고 말한다.



예를 들면 당신의 상관이 ‘One, three, five, four, zero, zero, seven, zero, zero, six’라고 말한 것은 7을 의미하는 것인데 다음의 표를 보면 알 수 있다.

상관의 명령

현재 숫자

설명

"one, three, five, four"

1, 3, 5, 4

4개의 숫자를 기록

"zero, zero"

1, 3

마지막 두 숫자를 삭제

"seven"

1, 3, 7

이전의 숫자 끝에 7을 추가

"zero, zero"

1

마지막 두 숫자를 삭제

"six"

1, 6

마지막 남은 숫자들, 합은 7

어느 순간이나 당신의 상관은 ‘zero’라고 말할 수 있으며, 만약 모든 숫자들이 무시되면 그 합은 0이 된다.



상관이 말하는 문구를 입력받아 정확한 합을 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 
0
(
z
e
r
o
)을 포함하는 정수 
K
를 입력받는다. 그 다음 
K
줄동안 
1
부터 
100
까지의 정수 또는 
0
을 입력 받는다.

[입력값의 정의역] 
1
<=
k
<=
100
,
000

출력
정확한 합을 출력한다.

입력 예시   
10
1
3
5
4
0
0
7
0
0
6

출력 예시
7 */

#include <stdio.h>
#include <stack>

using namespace std;

stack<int> s;

int main()
{
    int k;
    scanf("%d", &k);

    for(int i = 0; i < k; i++)
    {
        int num;
        scanf("%d", &num);

        if(num == 0)
        {
            s.pop();
        }
        else
        {
            s.push(num);
        }
    }

    int sum = 0;
    while(!s.empty())
    {
        sum += s.top();
        s.pop();
    }

    printf("%d", sum);
}