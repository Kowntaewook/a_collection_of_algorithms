/*트리 순회
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	128 MB	76475	50157	38647	67.370%
문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.



예를 들어 위와 같은 이진 트리가 입력되면,

전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
가 된다.

입력
첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.

출력
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

예제 입력 1 
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .
예제 출력 1 
ABDCEFG
DBAECFG
DBEGFCA */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
};


typedef struct node Node;
Node *tree[26];
char data[26];
char preoder[26];
char inoder[26];
char postoder[26];

int pre_cnt = 0;
int in_cnt = 0;
int post_cnt = 0;

void preorder(Node *root)
{
    if(root != NULL)
    {
        preoder[pre_cnt++] = root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        inoder[in_cnt++] = root->data;
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        postoder[post_cnt++] = root->data;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        char root, left, right;
        getchar();
        scanf("%c %c %c", &root, &left, &right);
        data[root - 'A'] = root;
        if(left != '.')
        {
            data[left - 'A'] = left;
            if(tree[root - 'A'] == NULL)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->data = root;
                newNode->left = NULL;
                newNode->right = NULL;
                tree[root - 'A'] = newNode;
            }
            if(tree[left - 'A'] == NULL)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->data = left;
                newNode->left = NULL;
                newNode->right = NULL;
                tree[left - 'A'] = newNode;
            }
            tree[root - 'A']->left = tree[left - 'A'];
        }
        if(right != '.')
        {
            data[right - 'A'] = right;
            if(tree[root - 'A'] == NULL)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->data = root;
                newNode->left = NULL;
                newNode->right = NULL;
                tree[root - 'A'] = newNode;
            }
            if(tree[right - 'A'] == NULL)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->data = right;
                newNode->left = NULL;
                newNode->right = NULL;
                tree[right - 'A'] = newNode;
            }
            tree[root - 'A']->right = tree[right - 'A'];
        }
    }
    preorder(tree['A' - 'A']);
    inorder(tree['A' - 'A']);
    postorder(tree['A' - 'A']);
    printf("%s\n", preoder);
    printf("%s\n", inoder);
    printf("%s\n", postoder);
    return 0;
}