#include <stdio.h>
#include <stdlib.h>

int arr[10] = {5, 7, 9, 0, 3, 1, 6, 2, 4, 8};

// pivot 값을 하나를 정하고 큰 수는 오른쪽으로 작은수는 왼쪽으로 정렬


void quick_sort(int i, int j)
{
    if(i >= j)
    {
        return;
    }
    int k = i+1, l = j;
    int pivot = i;
    while(k < l)
    {
        while(arr[k] < arr[pivot] && k < j)
        {
            k++;                        // k는 j보다 작아지면 안된다.
        }
        while(arr[l] > arr[pivot] && l > i)
        {
            l--;                        // l은 i보다 작아지면 안된다.
        }

        if(k < l)
        {
            int temp = arr[k]; // 비교하면서 교환하기
            arr[k] = arr[l];
            arr[l] = temp;
        }                                                                                    
        // 교차 하면 pivot으로 교환
        if(k >= l)
        {
            int temp = arr[pivot];
            arr[pivot] = arr[l];
            arr[l] = temp;
        }
    }
    quick_sort(i, l-1); // 왼쪽 부분 정렬
    quick_sort(l+1, j);
    return;
}

int main()
{
    int start = 0, end = 9;
    quick_sort(start, end);
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 1;
}