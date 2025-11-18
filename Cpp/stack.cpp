#include <stdio.h>
#include <stack>
using namespace std;

stack<int> s;


/*int main() {
    // 삽입(5) - 삽입(2) - 삽입(3) - 삽입(7) - 삭제() - 삽입(1) - 삽입(4) - 삭제()
    s.push(5);
    s.push(2);
    s.push(3);
    s.push(7);
    s.pop();
    s.push(1);
    s.push(4);
    s.pop();//5 2 3 1
    // 스택의 최상단 원소부터 출력
    while (!s.empty()) {
        printf("%d ",s.top()); 
        s.pop();
    }
} */

//  5 2 3 1 로 거꾸로 출력하기

int main()
{
    s.push(5);
    s.push(2);
    s.push(3);
    s.push(7);
    s.pop();
    s.push(1);
    s.push(4);
    s.pop();

    // 스택을 하나 더 만들어서 역으로 쌓아 올리기
    stack<int> s2;
    
    while (!s.empty()) {
        s2.push(s.top());
        s.pop();
    }
    
    while (!s2.empty()) {
        printf("%d ",s2.top());
        s2.pop();
    }
}