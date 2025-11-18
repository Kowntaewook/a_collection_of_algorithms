

#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; t++)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int max = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(arr[i] > max)
            {
                max = arr[i];
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == max)
            {
                count++;
            }
        }
        printf("%d", count);
    }
    return 0;
}
