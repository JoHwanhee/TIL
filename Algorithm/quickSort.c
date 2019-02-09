#include <stdio.h>

void quickSort(int* arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp;
    do
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    
    if (left < j)
        quickSort(arr, left, j);

    if (i < right)
        quickSort(arr, i, right);
}

int main() {
    int arr[] = { 5, 7, 89, 3, 2, 2, 2};
    int size = sizeof arr / sizeof arr[0];
    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}
