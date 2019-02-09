#include <stdio.h>
#include <string.h>

void insertSort(int* arr, int left, int right) {
    
    int value = 0;
    for (int i = left + 1; i < right; i++)
    {
        if(arr[i-1] <= arr[i])
            continue;
        
        value = arr[i];

        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[i])
            {
                memmove(&arr[j + 1], &arr[j], sizeof (arr[0]) * (i - j));
                arr[j] = value;
                break;
            }
        }
    }
}

int main() {
    int arr[] = { 5, 7, 89, 3, 2, 2, 2};
    int size = sizeof arr / sizeof arr[0];
    insertSort(arr, 0, size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}