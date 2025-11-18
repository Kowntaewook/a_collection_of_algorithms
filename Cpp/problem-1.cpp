/*현우는 숫자를 좋아한다. 항상 숫자를 가지고 장난을 하고 숫자로 무언가 만들기를 취미생활로 즐기고 있다.

하루는 어떤 숫자를 쓰고, 그 수를 거꾸로 쓰기로 했다.

어떤 수 N이 입력되면 그 수를 거꾸로 출력하는 프로그램을 작성하시오.

예)

입력 : 2571

출력 : 1752

 

입력 : 1200

출력 : 0021

입력
입력되는 수 N은 0이상의 정수이다. (N과 역순 N 모두 int범위 이내이다.)

출력
입력된 수를 거꾸로 출력한다.

 

입력 예시   
123456

출력 예시
654321 */

#include <stdio.h>
#include <stack>

using namespace std;

stack<int> s;

stack<int> s2;

int main()
{
    int n;
    scanf("%d", &n);
    // 0이 입력되면 0을 출력 그 외엔 역순으로 출력
    if(n == 0 && s.empty())
    {
        printf("0");
    }
    else
    {
        while (n != 0) {
            s.push(n % 10);
            n /= 10;
        }
        
        while (!s.empty()) {
            s2.push(s.top());
            s.pop();
        }
        
        while (!s2.empty()) {
            printf("%d",s2.top());
            s2.pop();
        }
    
    }

}