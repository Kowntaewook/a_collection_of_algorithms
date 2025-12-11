#include <stdio.h>

int parent[100001];
char ans[100001];
int cnt = 0;

int find(int a)
{
    if(parent[a] == a)
    {
        return a;
    }
    else
    {
        return parent[a] = find(parent[a]);
    }
}

void union_set(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if(a != b)
    {
        parent[b] = a;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);
        
        if(op == 0)
        {
            union_set(a, b);
        }
        else if(op == 1)
        {
            if(find(a) == find(b))
            {
                ans[cnt] = 'Y';
            }
            else
            {
                ans[cnt] = 'N';
            }
            cnt++;
        }
    }

    for(int i = 0; i < cnt; i++)
    {
        if(ans[i] == 'Y')
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
