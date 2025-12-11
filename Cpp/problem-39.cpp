/* 
중순위 : D - B - H - E = I - A - F - C - J - G - C
전순위 : A - B - D - E - H - I - C - F - G - J - K
후순위 : D - H - E - B - F - J - K - G - C - A
구조체로 코드 구현
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	char data;
	struct _node* left;
	struct _node* right;
} Node;

Node *tree[11];
char data[11] = { 'A', 'B', 'D', 'E', 'H', 'I', 'C', 'F', 'G', 'J', 'K'};
int l[11] = { 1, 2, -1, 4, -1, -1, 7, -1, 9, -1, -1};
int r[11] = { 6, 3, -1, 5, -1, -1, 8, -1, 10, -1, -1};

void mTree(int i)
{
    if(i == -1)
        return;

    else
    {
        tree[i] = (Node*)malloc(sizeof(Node));
        tree[i]->data = data[i];
        mTree(l[i]);
        mTree(r[i]);
        if(l[i] != -1)
            tree[i]->left = tree[l[i]];
        else
            tree[i]->left = NULL;
        if(r[i] != -1)
            tree[i]->right = tree[r[i]];
        else
            tree[i]->right = NULL;
    }
}
void preOrder(Node* ptr)
{
    if(ptr)
    {
        printf("%c ", ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void inOrder(Node* ptr)
{
    if(ptr)
    {
        inOrder(ptr->left);
        printf("%c ", ptr->data);
        inOrder(ptr->right);
    }
}

void postOrder(Node* ptr)
{
    if(ptr)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%c ", ptr->data);
    }
}

int main()
{
    mTree(0);
    printf("전순위 : ");
    preOrder(tree[0]);
    printf("\n중순위 : ");
    inOrder(tree[0]);
    printf("\n후순위 : ");
    postOrder(tree[0]);
    printf("\n");
    return 0;
} 

/*
중순위 : D - B - H - E = I - A - F - C - J - G - C
전순위 : A - B - D - E - H - I - C - F - G - J - K
후순위 : D - H - E - B - F - J - K - G - C - A
배열로 구현
*/

/*#include <stdio.h>

char tree[100];

void pOrder(int i)
{
    if(i >= 100 || tree[i] == '\0')
        return;
    printf("%c ", tree[i]);
    pOrder(2 * i + 1);
    pOrder(2 * i + 2);
}

void iOrder(int i)
{
    if(i >= 100 || tree[i] == '\0')
        return;
    iOrder(2 * i + 1);
    printf("%c ", tree[i]);
    iOrder(2 * i + 2);
}

void postOrder(int i)
{
    if(i >= 100 || tree[i] == '\0')
        return;
    postOrder(2 * i + 1);
    postOrder(2 * i + 2);
    printf("%c ", tree[i]);
}

int main()
{
    tree[0] = 'A';
    tree[1] = 'B';
    tree[2] = 'C';
    tree[3] = 'D';
    tree[4] = 'E';
    tree[5] = 'F';
    tree[6] = 'G';
    tree[9] = 'H';
    tree[10] = 'I';
    tree[13] = 'J';
    tree[14] = 'K';
    
    printf("전순위 : ");
    pOrder(0);
    printf("\n중순위 : ");
    iOrder(0);
    printf("\n후순위 : ");
    postOrder(0);
    printf("\n");
    
    return 0;
}*/