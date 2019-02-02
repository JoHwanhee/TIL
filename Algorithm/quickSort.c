#include <stdio.h>

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int *arr, int _left, int _right) {
	int left = _left;
	int right = _right;
	int pivot = left - 1;
	
	while( left < right ) {
		while( arr[left] < arr[pivot] ) left ++;
		while( arr[right] > arr[pivot] ) right --;
		
		if( left < right )
		    swap(&arr[left], &arr[right]);
	}
	
	swap(&arr[pivot], &arr[right]);
	pivot = right;
	
	return pivot;
}

void quickSort(int *arr, int left, int right){
	if(left < right ) {
    	int pivot = partition(arr, left, right);
    	quickSort(arr, 1, pivot - 1);
    	quickSort(arr, pivot + 2, right);
	}
}

int main(void) {
	int arr[10] = {6,5,1,3,7,8,2,4,9,0};
	quickSort(arr, 1, 9);
	
	for(int i = 0; i < 10; i ++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}
