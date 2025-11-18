#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
    }
}

void insert_sort(int arr[], int n)
{
    /*for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }*/

    for(int i = 1; i < n; i++)
    {
        for(int j = i; j >=0; j--)
        {
            if(arr[j]<arr[j-1])
            {
                int t = arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=t;
            }
            else
            {
                break;
            }
        }
    }
    printf("\n");
}


int main()
{
    int all[10] = {0};
    int count = 0;

    srand(time(NULL));
    while (count < 10) {
        int random = rand() % 20 + 1;
        int is_duplicate = 0;

        for (int i = 0; i < count; i++) {
            if (all[i] == random) {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate) {
            all[count++] = random;
        }
    }

    printf("정렬 전 배열: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", all[i]);
    }
    printf("\n");

    int choice;
    printf("1. 버블 정렬\n2. 선택 정렬\n3. 삽입 정렬\n입력: ");
    scanf("%d", &choice);

    if (choice == 1) {
        bubble_sort(all, 10);
        printf("버블 정렬 결과: ");
    } 
    else if (choice == 2) {
        selection_sort(all, 10);
        printf("선택 정렬 결과: ");
    }
    else if(choice == 3)
    {
        insert_sort(all, 10);
        printf("삽입 정렬 결과: ");
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", all[i]);
    }
    printf("\n");

    return 0;
}