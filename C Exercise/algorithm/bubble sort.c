#include "stdio.h"

// 从低到高
void bubble_sort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // 如果前面的数比后面的数字大
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
     
    }
    
    for (size_t i = 0; i < size; i++)
    {
        printf("arr[%d] = %d ", i, arr[i]);
    }
    
}

int main()
{
    int content[5] = {12, 90, 91, 23, 7};

    bubble_sort(content, sizeof(content) / sizeof(content[0]));

    return 0;
}


