/*트리의 순회
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
5 초	128 MB	39955	14680	10341	33.759%
문제
n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n(1 ≤ n ≤ 100,000)이 주어진다. 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.

출력
첫째 줄에 프리오더를 출력한다.

예제 입력 1 
3
1 2 3
1 3 2
예제 출력 1 
2 1 3 */

#include <stdio.h>
#include <vector>
using namespace std;
vector<int> inorder;
vector<int> postorder;

void preorder(int is, int ie, int ps, int pe)
{
    if (is > ie || ps > pe)
        return;
    int root = postorder[pe];
    printf("%d ", root);
    int idx = is;
    while (inorder[idx] != root)
        idx++;
    int len = idx - is;
    preorder(is, idx - 1, ps, ps + len - 1);
    preorder(idx + 1, ie, ps + len, pe - 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        inorder.push_back(temp);
    }

    
    for(int j = 0; j < n; j++)
    {
        int temp;
        scanf("%d", &temp);
        postorder.push_back(temp);
    }
    preorder(0, n - 1, 0, n - 1);
    printf("\n");

    return 0;
}